import java.io.*;
import java.util.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet("/CRead")
public class CReadServlet extends HttpServlet {

    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws IOException, ServletException
    {
 		doPost(request, response);
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws IOException, ServletException
    {
	    PrintWriter out = response.getWriter ();

		Cookie[] cookies = request.getCookies();
		if (cookies == null){
		  out.println("No Cookies");
		  return;
		}
		Cookie c = null;
		for (int i=0; i<cookies.length; i++) {
	  	  if (cookies[i].getName().equals("TestCookie")) {
  	    	c = cookies[i];
  	    	break;
	  	  }
		}
		if (c != null) {
	  	  String value = c.getValue();
	  	  out.println("Cookie found: " + value);
		}
	 	else out.println("Cookie not found");
    }
}
