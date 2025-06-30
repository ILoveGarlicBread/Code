#!/bin/bash
MAIN_LIB="/home/lam/Downloads/apache-activemq-6.1.6-bin/apache-activemq-6.1.6/activemq-all-6.1.6.jar"
ACTIVEMQ_LIB="/home/lam/Downloads/apache-activemq-6.1.6-bin/apache-activemq-6.1.6/lib"
ACTIVEMQ_OPTIONAL_LIB="/home/lam/Downloads/apache-activemq-6.1.6-bin/apache-activemq-6.1.6/lib/optional"

# Corrected classpath: include the activemq-all JAR directly
# and then the contents of the lib and lib/optional directories.
java -cp "${MAIN_LIB}:${ACTIVEMQ_LIB}/*:${ACTIVEMQ_OPTIONAL_LIB}/*" "$1"
