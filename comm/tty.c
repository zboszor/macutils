#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <setjmp.h>
#include "../util/masks.h"
#include "protocol.h"
#include "globals.h"

void cleanup();
void timedout();
int tgetc();
void tputc();

static jmp_buf timobuf;

static struct termios otty, ntty;
static int ttyfd;
static int signal_set;

void setup_tty()
{
    ttyfd = fileno(stderr);
    if(!signal_set) {
	(void)signal(SIGHUP, cleanup);
	(void)signal(SIGINT, cleanup);
	(void)signal(SIGQUIT, cleanup);
	(void)signal(SIGTERM, cleanup);
	if(time_out) {
	    (void)signal(SIGALRM, timedout);
	}
	signal_set = 1;
    }
    (void)tcgetattr(ttyfd, &otty);
    ntty = otty;
    ntty.c_lflag &= ~(ICANON | ISIG | ECHO);
    ntty.c_iflag &= IXOFF;
    ntty.c_oflag &= ~(OPOST);
    ntty.c_cflag &= ~(PARENB | PARODD);
    ntty.c_cc[VMIN] = 1;
    ntty.c_cc[VTIME] = 0;
    (void)tcsetattr(ttyfd, TCSAFLUSH, &ntty);
}

void reset_tty()
{
    (void)sleep(1); /* Wait for output to drain */
    (void)tcsetattr(ttyfd, TCSAFLUSH, &otty);
}

void cleanup(sig) int sig;
{
    reset_tty();
    exit(sig);
}

void timedout()
{
    (void)signal(SIGALRM, timedout);
    longjmp(timobuf, 1);
}

int tgetc(timeout)
int timeout;
{
char c;
int i;

    if(time_out) {
	if(setjmp(timobuf)) {
	    return TMO;
	}
	(void)alarm(timeout);
    }
    i = read(ttyfd, &c, 1);
    if(time_out) {
	(void)alarm(0);
    }
    if(i == 0) {
	return EOT;
    } else {
	return c & BYTEMASK;
    }
}

int tgetrec(char *buf, int count, int timeout)
{
int i, tot = 0, cc = count;

    if(time_out) {
	if(setjmp(timobuf)) {
	    return TMO;
	}
	(void)alarm(timeout);
    }
    while(tot < count) {
	i = read(ttyfd, buf, cc);
	if(i < 0) {
	    continue;
	}
	tot += i;
	cc -= i;
	buf += i;
    }
    if(time_out) {
	(void)alarm(0);
    }
    return 0;
}

void tputc(c)
int c;
{
char cc;

    cc = c & BYTEMASK;
    (void)write(ttyfd, &cc, 1);
}

void tputrec(buf, count)
char *buf;
int count;
{
    (void)write(ttyfd, buf, count);
}

