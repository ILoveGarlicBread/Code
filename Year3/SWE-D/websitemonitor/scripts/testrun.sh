#!/bin/bash

java -jar lib/junit-platform-console-standalone-1.13.0.jar --scan-classpath --class-path "class:lib/jsoup-1.20.1.jar"
if [ $? -eq 0 ]; then
    echo "Test run successful!"
else
    echo "Remember to run from project root, you dumbass"
    exit 1
fi
