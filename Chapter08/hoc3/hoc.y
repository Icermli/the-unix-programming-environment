%{
#include <stdio.h>
#include "hoc.h"
double  mem[26];  /* memory for variables 'a'..'z' */
int execerror(const char *s, const char *t);
void fpecatch();
int yylex();
int yyerror(const char *s);
int warning(const char *s, const char *t);
%}
%union {          /* stack type */
  double val;     /* actual value */
  double *vals;
  Symbol *sym;
  char   **strs;
}
%token <val>   NUMBER
%token <sym>   VAR BLTIN UNDEF CNST
%type  <val>   expr asgn exec
%type  <vals>  tpl
%type  <strs>  stpl
%right '='
%left  '+' '-'  /* left associative, same precedence */
%left  '*' '/' '%' /* left associative, same precedence */
%left  UNARYMINUS UNARYPLUS
%left  '!'
%right '^'
%%
list:     /* nothing */
       | list '\n'
       | list asgn '\n'
       | list expr '\n'  { printf("\t%.8g\n", $2); }
       | list expr ';'  { printf("\t%.8g\n", $2); }
       | list exec '\n'  { printf("\tdone!\n"); }
       | list error '\n' { yyerrok; }
       ;
expr:   NUMBER
       | VAR           { $$ = mem[$1]; }
       | VAR '=' expr  { $$ = mem[$1] = $3; }
       | expr '+' expr { $$ = $1 + $3; }
       | expr '-' expr { $$ = $1 - $3; }
       | expr '*' expr { $$ = $1 * $3; }
       | expr '/' expr {
          if ($3 == 0.0)
            execerror("division by zero", "");
          $$ = $1 / $3; }
       | '(' expr ')'  { $$ = $2; }
       | '-' expr %prec UNARYMINUS { $$ = -$2; }
       ;
%%
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <signal.h>
#include <setjmp.h>

char *progname;  /* for error messages */
int lineno = 1;
jmp_buf begin;

int main(int argc, char *argv[]) {
  void fpecatch();

  progname = argv[0];
  setjmp(begin);
  signal(SIGFPE, fpecatch);
  yyparse();
  return 0;
}

int execerror(const char *s, const char *t) {
  warning(s, t);
  longjmp(begin, 0);
  return 0;
}

void fpecatch() {
  execerror("floating point exeception", (char *) 0);
}

int yylex() {
  int c;
  while ((c = getchar()) == ' ' || c == '\t') { ; }
  if (c == EOF) { return 0; }
  if (c == '.' || isdigit(c)) {
    ungetc(c, stdin);
    scanf("%lf", &yylval.val);
    return NUMBER;
  }
  if (islower(c)) {
    yylval.index = c - 'a'; /* ASCII only */
    return VAR;
  }
  if (c == '\n') { lineno++; }
  return c;
}

int yyerror(const char *s) {
  warning(s, (char* )0);
  return 0;
}

int warning(const char *s, const char *t) {
  fprintf(stderr, "%s: %s", progname, s);
  if (t) { fprintf(stderr, " %s", t); }
  fprintf(stderr, " near line %d\n", lineno);
  return 0;
}
