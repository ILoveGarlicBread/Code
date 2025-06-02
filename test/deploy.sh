#!/bin/bash

# Set paths
PROJECT_DIR="/home/lam/Downloads/test"
SRC_DIR="$PROJECT_DIR/model"
JSP_DIR="$PROJECT_DIR"
TOMCAT_WEBAPP_DIR="/usr/share/tomcat10/webapps/lam/"

echo "Compiling Java files..."
javac -cp /usr/share/tomcat10/lib/servlet-api.jar $SRC_DIR/*.java

echo "Copying JSP files to Tomcat..."
sudo mkdir -p "$TOMCAT_WEBAPP_DIR"
sudo cp "$JSP_DIR"/*.jsp "$TOMCAT_WEBAPP_DIR/"

echo "Copying class files..."
sudo mkdir -p "$TOMCAT_WEBAPP_DIR/WEB-INF/classes/model"
sudo cp -r "$SRC_DIR"/*.class "$TOMCAT_WEBAPP_DIR/WEB-INF/classes/model"

echo "Restarting Tomcat service..."
sudo systemctl restart tomcat10.service

echo "Deployment complete!"

