#!/bin/bash
javac ./UDPServer.java
javac ./UDPClient.java 
echo ""
java UDPServer &
java UDPClient
