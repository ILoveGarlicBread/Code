package jsp;

import java.io.*;
import java.util.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;
import java.util.Map;
import java.util.Set;
import java.util.HashMap;

@WebServlet("/Session")
public class SessionServlet extends HttpServlet {
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
    doPost(request, response);
  }

  public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
    HttpSession session = request.getSession();
    String task = request.getParameter("task");
    Map<String, Machine> machines = new HashMap<>();
    String message = "";
    Object result = new Object();
    switch (task) {
      case "createMachine":
        String newMachineName = request.getParameter("machineName");
        Machine newMachine = new Machine("machineName");
        if (machines.containsKey(newMachineName)) {
          message = "Duplicated name";
        } else {
          machines.put(newMachineName, newMachine);
          request.setAttribute("currentMachine", newMachineName);
          message = "Machine added successfully";
        }
        break;
      case "changeMachine":
        String currentMachineName = request.getParameter("machineName");
        if (machines.containsKey(currentMachineName)) {
          Machine currentMachine = machines.get(currentMachineName);
          request.setAttribute("currentMachine", currentMachineName);
          message = "Current machine changed successfully";
        } else {
          message = "There is no machine named " + currentMachineName;
        }
        break;
      case "searchPart":
        String partName = request.getParameter("partName");
        currentMachineName = request.getParameter("currentMachine");
        Machine currentMachine = machines.get(currentMachineName);
        result = currentMachine.searchPart("partName");
        break;
      case "addPart":
        partName = request.getParameter("partName");
        int partNumber = Integer.valueOf(request.getParameter("partNumber"));
        int partPrice = Integer.valueOf(request.getParameter("partPrice"));
        currentMachineName = request.getParameter("currentMachine");
        currentMachine = machines.get(currentMachineName);
        currentMachine.addPart(partName, partNumber, partPrice);
        message = "Part " + partName + " added to " + currentMachineName + " successfully";
        break;
      case "showAllParts":
        currentMachineName = request.getParameter("currentMachine");
        currentMachine = machines.get(currentMachineName);
        result = currentMachine.returnAllParts();
        break;
      case "changePartPrice":
        currentMachineName = request.getParameter("currentMachine");
        currentMachine = machines.get(currentMachineName);
        partName = request.getParameter("partName");
        partPrice = Integer.valueOf(request.getParameter("partPrice"));
        currentMachine.searchPart("partName").setPrice(partPrice);
        message = "Part price changed successfully";
        break;

    }
    request.setAttribute("result", result);
    request.setAttribute("message", message);
    RequestDispatcher dispatcher = request.getRequestDispatcher("result.jsp");
    dispatcher.forward(request, response);

  }
}
