/* See LICENSE file for copyright and license details. */
#ifndef TEXT_H
#define TEXT_H

#define _GNU_SOURCE       // expose GNU extensions like getline

#include <sys/types.h>    // ssize_t
#include <stdio.h>        // FILE
#include <stdlib.h>       // size_t

struct linebuf {
	char **lines;
	long nlines;
	long capacity;
};
#define EMPTY_LINEBUF {NULL, 0, 0,}
void getlines(FILE *, struct linebuf *);

ssize_t agetline(char **, size_t *, FILE *);

void concat(FILE *, const char *, FILE *, const char *);
#endif /* TEXT_H */
