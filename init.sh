#!/bin/sh
#init script if i never setup up dinit

echo "starting /sbin/init"
echo "mounting proc, sys, and dev"
mount -t proc proc /proc 2>/dev/null || echo "proc dooesnt work"
mount -t sysfs sysfs /sys 2>/dev/null || echo "sysfs doesnt work"
mount -t devtmpfs devtmpfs /dev 2>/dev/null || echo "creating device nodes manually"

[ ! -e /dev/console ] && mknod /dev/console c 5 1
[ ! -e /dev/null ] && mknod /dev/null c 1 3
[ ! -e /dev/zero ] && mknod /dev/zero c 1 5

#stop tty errors (attempt 1)
for i in 0 1 2 3 4 5 6; do
    [ ! -e /dev/tty$i ] && mknod /dev/tty$i c 4 $i
done

#path
export PATH=/bin:/sbin:/usr/bin:/usr/sbin

#home directory
export HOME=/root

#testing unless i actually setup users
export USER=root

echo "/sbin/init finished"

#stop tty errors (attempt 2)
exec setsid cttyhack sh


