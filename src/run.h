#ifndef __RUN_H__
#define __RUN_H__

#include <stdio.h>

typedef struct {
	char *t;
	int len;
} Term;

typedef struct clo {
	Term        t;
	struct env *e;
} Closure;

typedef struct env {
	int      top;
	Closure *c;
} Environment;

static Term get_termf(FILE *, char *);
static Term get_termt(Term);

static Term mkterm(char *);
static Closure mkclosure(Term, Environment *);
static Environment mkenv(void);

static void push(Closure, Environment *);
static Closure pop(Environment *);

static void eval(Term, Environment *);
static void app(Term, Term, Environment *);
static void lam(Term, Environment *);
static void zero(Environment *);
static void succ(int, Environment *);

void run_main(char *);

#endif /* run.h */
