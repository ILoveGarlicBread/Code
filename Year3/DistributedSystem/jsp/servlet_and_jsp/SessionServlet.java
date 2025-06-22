import java.io.*;
import java.util.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet("/Session")
public class SessionServlet extends HttpServlet {

    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws IOException, ServletException
    {
 		doPost(request, response);
    }

    public void doPost(HttpServletRequest req, HttpServletResponse res)
    throws IOException, ServletException
    {
	  PrintWriter out = res.getWriter ();
	  HttpSession session = req.getSession();
	  Enumeration es = session.getAttributeNames ();
	  while (es.hasMoreElements()) {
	     String name = (String)es.nextElement();
	     String value = (String)session.getAttribute(name);
	     out.println(name + " = " + value);
      }

      Enumeration er = req.getParameterNames();

      while (er.hasMoreElements()) {
            String name = (String)er.nextElement();
            String value = req.getParameter(name);
            session.setAttribute(name, value);
      }
    }
}
