// TaskController.java
package model;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

@WebServlet("/task")
public class TaskController extends HttpServlet {
    @SuppressWarnings("unchecked")
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String action = request.getParameter("action");
        HttpSession session = request.getSession();
        Map<String, Machine> machines = new HashMap<>();
        if (machines == null) {
            machines = new HashMap<>();
            session.setAttribute("machines", machines);
        }

        String message = "";
        Object result = null;

        switch (action) {
            case "createMachine":
                String machineName = request.getParameter("machineName");
                if (machineName != null && !machineName.isEmpty()) {
                    if (machines.containsKey(machineName)) {
                        message = "Machine already exists.";
                    } else {
                        machines.put(machineName, new Machine(machineName));
                        session.setAttribute("currentMachine", machineName);
                        message = "Machine '" + machineName + "' created and selected.";
                    }
                } else {
                    message = "Machine name cannot be empty.";
                }
                break;

            case "changeMachine":
                String selectedMachine = request.getParameter("machineName");
                if (machines.containsKey(selectedMachine)) {
                    session.setAttribute("currentMachine", selectedMachine);
                    message = "Current machine changed to '" + selectedMachine + "'.";
                } else {
                    message = "Machine '" + selectedMachine + "' does not exist.";
                }
                break;

            case "addSparePart":
                String currentMachineName = (String) session.getAttribute("currentMachine");
                if (currentMachineName == null) {
                    message = "No machine selected. Please create or select a machine first.";
                    break;
                }
                Machine machine = machines.get(currentMachineName);
                String partName = request.getParameter("partName");
                int partNumber = Integer.parseInt(request.getParameter("partNumber"));
                double price = Double.parseDouble(request.getParameter("partPrice"));

                machine.addSparePart(partName, partNumber, price);
                message = "Spare part added to machine '" + currentMachineName + "'.";
                break;

            case "searchSparePart":
                currentMachineName = (String) session.getAttribute("currentMachine");
                if (currentMachineName == null) {
                    message = "No machine selected.";
                    break;
                }
                machine = machines.get(currentMachineName);
                int searchNumber = Integer.parseInt(request.getParameter("partNumber"));
                SparePart foundPart = machine.searchSparePart(searchNumber);
                if (foundPart != null) {
                    result = foundPart;
                    message = "Spare part found.";
                } else {
                    message = "Spare part not found.";
                }
                break;

            case "showAllSpareParts":
                currentMachineName = (String) session.getAttribute("currentMachine");
                if (currentMachineName == null) {
                    message = "No machine selected.";
                    break;
                }
                machine = machines.get(currentMachineName);
                Set<SparePart> allParts = machine.getAllSpareParts();
                result = allParts;
                message = "All spare parts for machine '" + currentMachineName + "'.";
                break;

            case "changePrice":
                currentMachineName = (String) session.getAttribute("currentMachine");
                if (currentMachineName == null) {
                    message = "No machine selected.";
                    break;
                }
                machine = machines.get(currentMachineName);
                int partNumToChange = Integer.parseInt(request.getParameter("partNumber"));
                double newPrice = Double.parseDouble(request.getParameter("newPrice"));
                SparePart partToChange = machine.searchSparePart(partNumToChange);
                if (partToChange != null) {
                    partToChange.setPrice(newPrice);
                    message = "Price updated.";
                } else {
                    message = "Spare part not found.";
                }
                break;

            default:
                message = "Invalid action.";
                break;
        }

        request.setAttribute("message", message);
        request.setAttribute("result", result);
        request.getRequestDispatcher("result.jsp").forward(request, response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doPost(request, response);
    }
}
