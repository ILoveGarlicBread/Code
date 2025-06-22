#!/bin/bash

# Define the source directory
SRC_DIR="src"

# Define the class output directory
CLASS_DIR="class"

# Define the path to the Jsoup JAR
JSOUPLIB="lib/jsoup-1.20.1.jar"

# Define the name of your executable JAR
APP_JAR="websitemonitor.jar"

# --- Packaging Step ---
echo "--- Creating executable JAR ---"

# Create a temporary directory for JAR contents
mkdir -p "$CLASS_DIR/META-INF"

# Create the MANIFEST.MF file
echo "Manifest-Version: 1.0" > "$CLASS_DIR/META-INF/MANIFEST.MF"
echo "Main-Class: Main" >> "$CLASS_DIR/META-INF/MANIFEST.MF" # Your main class is `Main`

# Create the JAR, including compiled classes and the Jsoup library
# We need to explicitly add jsoup.jar to the JAR for it to be a true "fat JAR" if needed,
# or ensure it's on the classpath at runtime inside the container.
# For simplicity, we'll assume Jsoup will be handled via the Dockerfile's classpath.
# The JAR will contain only your compiled .class files.

# Navigate into the class directory to create the JAR correctly
(cd "$CLASS_DIR" && jar -cvfm "../$APP_JAR" META-INF/MANIFEST.MF .)

if [ $? -ne 0 ]; then
    echo "JAR creation failed."
    exit 1
fi

echo "Executable JAR '$APP_JAR' created in project root."

# Clean up temporary manifest file
rm -rf "$CLASS_DIR/META-INF"

echo "Build process complete."
