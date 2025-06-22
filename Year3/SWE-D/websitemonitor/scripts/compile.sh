#!/bin/bash

SRC_DIR="/home/lam/Code/Year3/SWE-D/websitemonitor/src"
CLASS_DIR="/home/lam/Code/Year3/SWE-D/websitemonitor/class"
JSOUPLIB="/home/lam/Code/Year3/SWE-D/websitemonitor/lib/jsoup-1.20.1.jar"
LIBTEST_DIR="/home/lam/Code/Year3/SWE-D/websitemonitor/lib/junit-platform-console-standalone-1.13.0.jar"

mkdir -p "$CLASS_DIR"

echo "Compiling Java files from $SRC_DIR to $CLASS_DIR..."
javac -d "$CLASS_DIR" -cp "$JSOUPLIB:$LIBTEST_DIR" $(find "$SRC_DIR" -name "*.java")

if [ $? -eq 0 ]; then
    echo "Compilation successful!"
else
    echo "Compilation failed. Please check for errors above."
    exit 1
fi
