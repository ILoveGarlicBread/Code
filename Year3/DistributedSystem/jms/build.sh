#!/bin/bash
SRC_DIR="/home/lam/Code/Year3/DistributedSystem/jms/src"
CLASS_DIR="/home/lam/Code/Year3/DistributedSystem/jms/class"
MAIN_LIB="/home/lam/Downloads/apache-activemq-6.1.6-bin/apache-activemq-6.1.6/activemq-all-6.1.6.jar"
ACTIVEMQ_LIB="/home/lam/Downloads/apache-activemq-6.1.6-bin/apache-activemq-6.1.6/lib"
ACTIVEMQ_OPTIONAL_LIB="/home/lam/Downloads/apache-activemq-6.1.6-bin/apache-activemq-6.1.6/lib/optional"

javac -cp "${MAIN_LIB}:${ACTIVEMQ_LIB}/*:${ACTIVEMQ_OPTIONAL_LIB}/*" -d $CLASS_DIR  $(find "$SRC_DIR" -name "*.java")
