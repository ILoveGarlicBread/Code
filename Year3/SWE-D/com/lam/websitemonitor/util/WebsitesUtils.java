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
    HttpClient httpClient = HttpClient.newHttpClient();
    HttpRequest request = HttpRequest.newBuilder()
        .uri(URI.create(url))
        .build();

    HttpResponse<byte[]> response = httpClient.send(request, HttpResponse.BodyHandlers.ofByteArray());
    String savePath = "/home/lam/Code/Year3/SWE-D/com/lam/websitemonitor/contentsnapshot/" + websiteName + ".html";
    if (response.statusCode() == 200) {
      byte[] responseBody = response.body();
      Path file = Path.of(savePath);
      Files.write(file, responseBody);
    }
  }

  public boolean compareWebPageContent() throws IOException,
      InterruptedException {
    HttpClient httpClient = HttpClient.newHttpClient();
    HttpRequest request = HttpRequest.newBuilder()
        .uri(URI.create(url))
        .build();
    HttpResponse<String> response = httpClient.send(request,
        HttpResponse.BodyHandlers.ofString());
    String readPath = "/home/lam/Code/Year3/SWE-D/com/lam/websitemonitor/contentsnapshot/" + websiteName + ".html";
    if (response.statusCode() == 200) {
      String currentSnapshot = response.body();
      Path file = Path.of(readPath);
      String previousSnapshot = Files.readString(file);

      if (!response.equals(previousSnapshot)) {
        Files.writeString(file, currentSnapshot, StandardOpenOption.TRUNCATE_EXISTING);
        return true;
      } else {
        return false;
      }
    }
    return false;

  }
}
