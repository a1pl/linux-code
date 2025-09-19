/* See LICENSE file for copyright and license details. */
#define _POSIX_C_SOURCE 200809L

#include <unistd.h>  // for sync()
#include <stdlib.h>
#include <stdio.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int main(int argc, char *argv[]) {
    int pflag = 0, rflag = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j]; j++) {
                switch (argv[i][j]) {
                    case 'p': pflag = 1; break;
                    case 'r': rflag = 1; break;
                    default:
                        eprintf("usage: %s [-p] [-r]\n", argv[0]);
                        return 1;
                }
            }
        }
    }

    if (pflag && rflag) {
        eprintf("Cannot use -p and -r together\n");
        return 1;
    }

    // musl defines sync() in unistd.h with _POSIX_C_SOURCE >= 200809L
    sync();

    if (pflag) {
        eprintf("Power-off requested (stub)\n");
    } else if (rflag) {
        eprintf("Reboot requested (stub)\n");
    } else {
        eprintf("Halt requested (stub)\n");
    }

    return 0;
}

