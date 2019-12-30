%{
#include <stdio.h>
#define YYSTYPE double /* data type of yacc stack */
int yylex();
int yyerror(const char *s);
int warning(const char *s, const char *t);
%}
%token  NUMBER
%left  '+' '-'  /* left associative, same precedence */
%left  '*' '/'  /* left associative, same precedence */
%%
list:     /* nothing */
       | list '\n'
       | list expr '\n'  { printf("\t%.8g\n", $2); }
       ;
expr:   NUMBER         { $$ = $1; }
       | expr '+' expr { $$ = $1 + $3; }
       | expr '-' expr { $$ = $1 - $3; }
       | expr '*' expr { $$ = $1 * $3; }
       | expr '/' expr { $$ = $1 / $3; }
       | '(' expr ')'  { $$ = $2; }
%%
#include <stdio.h>
#include <ctype.h>
#include <math.h>

char *progname;  /* for error messages */
int lineno = 1;

int main(int argc, char *argv[]) {
  progname = argv[0];
  yyparse();
  return 0;
}

int yylex() {
  int c;
  while ((c = getchar()) == ' ' || c == '\t') { ; }
  if (c == EOF) { return 0; }
  if (c == '.' || isdigit(c)) {
    ungetc(c, stdin);
    scanf("%lf", &yylval);
    return NUMBER;
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
