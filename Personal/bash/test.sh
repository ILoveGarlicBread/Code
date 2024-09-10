#!/bin/bash
ac_adapter=$(acpi -a | cut -d' ' -f3 | cut -d- -f1)

if [ "$ac_adapter" = "on" ]; then
	notify-send "AC Adapter" "The AC Adapter is on."
else
	notify-send "AC Adapter" "The AC Adapter is off."
fi
