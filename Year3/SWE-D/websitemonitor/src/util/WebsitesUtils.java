package util;

import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.file.Files;
import java.nio.file.StandardOpenOption;
import java.nio.file.Path;

public class WebsitesUtils {
  private String websiteName;
  private String url;

  public WebsitesUtils(String websiteName, String url) {
    this.websiteName = websiteName;
    this.url = url;
  }

  public void downloadWebPageContent()
      throws IOException, InterruptedException {
    // String savePath =
    // "/home/lam/Code/Year3/SWE-D/websitemonitor/contentsnapshot/";
    // ProcessBuilder pb = new ProcessBuilder("curl", "-s", url, "-o", savePath +
    // websiteName + ".html");
    // Process process = pb.inheritIO().start();
    // int exitCode = process.waitFor();
    //
    // if (exitCode == 0) {
    // System.out.println("Downloaded successfully: " + websiteName);
    // } else {
    // System.err.println("curl failed with exit code " + exitCode);
    // // curl has error code 92 on some websites: problem with http2 stream
    // HttpClient httpClient = HttpClient.newHttpClient();
    // HttpRequest request = HttpRequest.newBuilder()
    // .uri(URI.create(url))
    // .build();
    //
    // HttpResponse<byte[]> response = httpClient.send(request,
    // HttpResponse.BodyHandlers.ofByteArray());
    // savePath = "/home/lam/Code/Year3/SWE-D/websitemonitor/contentsnapshot/" +
    // websiteName + ".html";
    // if (response.statusCode() == 200) {
    // byte[] responseBody = response.body();
    // Path file = Path.of(savePath);
    // Files.write(file, responseBody);
    // System.out.println("Downloaded successfully: " + websiteName);
    // }
    // }

    HttpClient httpClient = HttpClient.newHttpClient();
    HttpRequest request = HttpRequest.newBuilder()
        .uri(URI.create(url))
        .build();

    HttpResponse<byte[]> response = httpClient.send(request,
        HttpResponse.BodyHandlers.ofByteArray());
    String savePath = "contentsnapshot/" +
        websiteName + ".html";
    if (response.statusCode() == 200) {
      byte[] responseBody = response.body();
      Path file = Path.of(savePath);
      Files.write(file, responseBody);
    }
  }

  public boolean compareWebPageContent(CompareMethod method) throws IOException,
      InterruptedException {
    HttpClient httpClient = HttpClient.newHttpClient();
    HttpRequest request = HttpRequest.newBuilder()
        .uri(URI.create(url))
        .build();
    HttpResponse<String> response = httpClient.send(request,
        HttpResponse.BodyHandlers.ofString());
    String readPath = "contentsnapshot/" + websiteName + ".html";
    boolean changed = false;
    if (response.statusCode() == 200) {
      String currentSnapshot = response.body();
      Path file = Path.of(readPath);
      String previousSnapshot = Files.readString(file);
      changed = method.hasChanged(currentSnapshot, previousSnapshot);
      if (changed) {
        Files.writeString(file, currentSnapshot, StandardOpenOption.TRUNCATE_EXISTING);
      }

      // if (!currentSnapshot.equals(previousSnapshot)) {
      // Files.writeString(file, currentSnapshot,
      // StandardOpenOption.TRUNCATE_EXISTING);
      // return true;
      // } else {
      // return false;
      // }
    }
    return changed;

  }
}
