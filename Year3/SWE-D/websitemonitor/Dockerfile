# Use an official OpenJDK runtime as a parent image
# We choose a recent LTS version (Java 17) based on Alpine Linux for a smaller image
FROM eclipse-temurin:24-jdk-alpine

# Set the working directory inside the container
WORKDIR app

# Copy the executable JAR you built (websitemonitor.jar) into the container at /app
# This assumes you ran the build_jar.sh script and websitemonitor.jar is in the root directory.
COPY websitemonitor.jar /app/websitemonitor.jar

# Copy the Jsoup library into a 'lib' directory inside the container.
# This is crucial because your application depends on Jsoup.
COPY lib/jsoup-1.20.1.jar /app/lib/jsoup-1.20.1.jar

# (Optional) If your application needs to write snapshots, create the directory
# This assumes the path /home/lam/Code/Year3/SWE-D/websitemonitor/contentsnapshot/ is mapped inside the container
# If the path in WebsitesUtils.java is absolute, you'll need to change it to a relative path or map a volume.
# For simplicity, let's assume content will be in /app/contentsnapshot
RUN mkdir -p /app/contentsnapshot

# Command to run your application when the container starts
# We use java -jar, and specifically add jsoup to the classpath.
# Note: For production, you might want to use ENTRYPOINT and CMD separately for better flexibility.
CMD ["java", "-cp", "/app/websitemonitor.jar:/app/lib/jsoup-1.20.1.jar", "Main"]

# If your application listens on a specific port, expose it (e.g., if it were a web server)
# EXPOSE 8080
