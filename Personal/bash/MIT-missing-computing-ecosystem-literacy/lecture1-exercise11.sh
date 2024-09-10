#!/bin/bash
# Write a command that reads out your laptop battery’s power level
# or your desktop machine’s CPU temperature from /sys.

BatteryPowerLevel=$(cat /sys/class/power_supply/BAT0/capacity)
Status=$(cat /sys/class/power_supply/BAT0/status)
echo "Battery power level: $BatteryPowerLevel%"
echo "Status: $Status"
