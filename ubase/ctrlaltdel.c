/* See LICENSE file for copyright and license details. */
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include "util.h"
#include "arg.h"
#include "queue.h"


#define LINUX_REBOOT_MAGIC1 0xfee1dead
#define LINUX_REBOOT_MAGIC2 672274793
#define LINUX_REBOOT_CMD_CAD_ON  0x89ABCDEF
#define LINUX_REBOOT_CMD_CAD_OFF 0x00000000


static void
usage(void)
{
	eprintf("usage: %s -h | -s\n", argv0);
}

int
main(int argc, char *argv[])
{
	int hflag = 0, sflag = 0, cmd;

	ARGBEGIN {
	case 'h':
		hflag = 1;
		break;
	case 's':
		sflag = 1;
		break;
	default:
		usage();
	} ARGEND;

	if (argc || !(hflag ^ sflag))
		usage();

	cmd = hflag ? LINUX_REBOOT_CMD_CAD_ON : LINUX_REBOOT_CMD_CAD_OFF;

	if (syscall(__NR_reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2,
	            cmd, NULL) < 0)
		eprintf("reboot:");

	return 0;
}
