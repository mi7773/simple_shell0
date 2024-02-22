#ifndef MAIN_H
#define MAIN_H

extern char **environ;

int active(void);
int nactive(void);
char *getpath(void);
char **patharr(void);
char **coarr(char *buf);

#endif /* MAIN_H */
