import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet("/Hallo")
public class HalloServlet extends HttpServlet {
  public void doGet(HttpServletRequest request,
      HttpServletResponse response)
      throws ServletException, IOException {
    response.setContentType("text/html");
    PrintWriter out = response.getWriter();
    out.println("<HTML>\n" +
        "<HEAD><TITLE>Hello</TITLE></HEAD>\n" +
        "<BODY>\n" +
        "<H1>Hello Servlet-User</H1>\n" +
        "</BODY></HTML>");
  }
}
