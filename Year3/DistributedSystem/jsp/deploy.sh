#!/bin/bash
echo "Compiling java files..."
javac -cp /usr/share/tomcat10/lib/servlet-api.jar *.java
echo "Copying java files..."
sudo cp /home/lam/Code/Year3/DistributedSystem/jsp/*.class /usr/share/tomcat10/webapps/lam/WEB-INF/classes/jsp/
echo "Copying jsp files..."
sudo sudo cp /home/lam/Code/Year3/DistributedSystem/jsp/*.jsp /usr/share/tomcat10/webapps/lam/
echo "Restarting tomcat..."
sudo systemctl restart tomcat10.service

