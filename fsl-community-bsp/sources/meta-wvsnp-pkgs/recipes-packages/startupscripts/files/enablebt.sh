#! /bin/sh
# /etc/init.d/enablebt.sh

sleep 3
echo 149 > /sys/class/gpio/export
sleep 1
echo out > /sys/class/gpio/gpio149/direction
sleep 1
echo 0 > /sys/class/gpio/gpio149/value
sleep 1
echo 1 > /sys/class/gpio/gpio149/value
sleep 1

brcm_patchram_plus -d --timeout=6.0 --patchram /lib/firmware/brcm/bcm4330.hcd --baudrate 3000000 --no2bytes --tosleep=2000 --enable_hci /dev/ttymxc2 > /dev/null 2>&1 & sleep 10
sleep 4
hciconfig hci0 up
sleep 5
bluetoothd
