/* spname: return correctly spelled filename */
/*
 * spname(oldname, newname) char *oldname, *newname;
 *  returns -1 if no reasonable match to oldname,
 *           0 if exact match,
 *           1 if corrected.
 *  stores corrected name in newname.
 */
#include <dirent.h>
#define DIRSIZ  100

int mindist(char *dir, char *guess, char *best);
int spdist(char *s, char *t);

int spname(char *oldname, char *newname) {
  char *p, guess[DIRSIZ+1], best[DIRSIZ+1];
  char *new = newname, *old = oldname;

  for (;;) {
    while (*old == '/') {*new++ = *old++;}
    *new = '\0';
    if (*old == '\0') {return strcmp(oldname, newname) != 0;}
    p = guess;
    for ( ; *old != '/' && *old != '\0'; old++) {
      if (p < guess+DIRSIZ) {*p++ = *old;}
    }
    *p = '\0';
    if (mindist(newname, guess, best) >= 3) {
      return -1;
    }
    for (p = best; (*new = *p++); ) {new++;}
  }
}

int mindist(char *dir, char *guess, char *best) {
  int d, nd;
  DIR *fd;
  struct dirent *nbuf;

  if (dir[0] == '\0') {dir = ".";}
  d = 3;
  fd = opendir(dir);
  if (!fd) {
    return d;
  }
  while ((nbuf = readdir(fd)) != NULL) {
    nd = spdist(nbuf->d_name, guess);
    if (nd <= d && nd != 3) {
      strcpy(best, nbuf->d_name);
      d = nd;
      if (d == 0) {break;}
    }
  }
  closedir(fd);
  return d;
}

/* spdist: return distance between two names */
/*
 *  very rough spelling metric:
 *  0 if the strings are identical
 *  1 if two chars are transposed
 *  2 if one char wrong, added or deleted
 *  3 otherwise
 */
#define EQ(s,t) (strcmp(s,t) == 0)

int spdist(char *s, char *t) {
  while (*s++ == *t) {if (*t++ == '\0') {return 0;}}
  if (*--s) {
    if (*t) {
      if (s[1] && t[1] && *s == t[1] && *t == s[1] && EQ(s+2,t+2)) {return 1;}
    }
    if (EQ(s+1,t)) {return 2;}
  }
  if (*t && EQ(s,t+1)) {return 2;}
  return 3;
}
