import java.io.*;
import java.util.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet("/CWrite")
public class CWriteServlet extends HttpServlet {

    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws IOException, ServletException
    {
 		doPost(request, response);
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws IOException, ServletException
    {

	  PrintWriter out = response.getWriter ();

	  Cookie c = new Cookie("TestCookie","0");
	  response.addCookie(c);
	  out.println("Cookie set");
    }
}
