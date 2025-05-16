// package util;

import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.file.Files;
import java.nio.file.Path;

public class WebsitesUtils {

  public static void downloadWebPageContent(String websiteName, String url)
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

  // public boolean compareWebPageContent(String url) throws IOException,
  // InterruptedException {
  // HttpClient httpClient = HttpClient.newHttpClient();
  // HttpRequest request = HttpRequest.newBuilder()
  // .uri(URI.create(url))
  // .build();
  // HttpResponse<byte[]> response = httpClient.send(request,
  // HttpResponse.BodyHandlers.ofByteArray());
  // boolean updated = false;
  // if ()
  // return
  // }
}
