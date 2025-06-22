<%@ page import="jsp.Machine, jsp.Part, java.util.Map, java.util.Set, java.util.HashMap" %>
<html>
  <body>
    <% String task=request.getParameter("task"); %>
    <% String message = "";%>
    <%String currentMachineName = (String) session.getAttribute("currentMachine");%>
    <% Map<String, Machine> machines = (Map<String, Machine>) session.getAttribute("machines");
     Part foundPart = null;
    Set<Part> foundParts = null;
    
    if (machines == null){
      machines = new HashMap<>();
      session.setAttribute("machines", machines);
    }
    %>
    
    <%

    switch (task) {
      case "createMachine":
        String newMachineName = request.getParameter("machineName");
        Machine newMachine = new Machine("machineName");
        if (machines.containsKey(newMachineName)) {
          message = "Duplicated name";
        } else {
          machines.put(newMachineName, newMachine);
          message = "Machine added successfully";
        }
        break;
      case "changeMachine":
        String machineName = request.getParameter("machineName");
        if (machines.containsKey(machineName)) {
          Machine currentMachine = machines.get(machineName);
          session.setAttribute("currentMachine", machineName);
          message = "Current machine changed successfully";
        } else {
          message = "There is no machine named " + machineName;
        }
        break;
      case "searchPart":
        String partName = request.getParameter("partName");
        currentMachineName =(String) session.getAttribute("currentMachine");
        Machine currentMachine = machines.get(currentMachineName);
        foundPart = currentMachine.searchPart(partName);
        break;
      case "addPart":
        partName = request.getParameter("partName");
        int partNumber = Integer.valueOf(request.getParameter("partNumber"));
        int partPrice = Integer.valueOf(request.getParameter("partPrice"));
        currentMachineName = (String) session.getAttribute("currentMachine");
        currentMachine = machines.get(currentMachineName);
        currentMachine.addPart(partName, partNumber, partPrice);
        message = "Part " + partName + " added to " + currentMachineName + " successfully";
        break;
      case "showAllParts":
        currentMachineName = (String) session.getAttribute("currentMachine");
        currentMachine = machines.get(currentMachineName);
        foundParts = currentMachine.returnAllParts();
        break;
      case "changePartPrice":
        currentMachineName = (String) session.getAttribute("currentMachine");
        currentMachine = machines.get(currentMachineName);
        partName = request.getParameter("partName");
        partPrice = Integer.valueOf(request.getParameter("partPrice"));
        currentMachine.searchPart("partName").setPrice(partPrice);
        message = "Part price changed successfully";
        break;

    }

    %>
    <h2> Result for <%= task %> </h2>
    <%= message %>
    
    <%
      if(foundParts != null){
    %>
    <table> 
      <tr><th>Name</th><th>Number</th><th>Price</th></tr>
      <% for(Part part : foundParts){
      %>
      <tr>
        <td> <%= part.getName() %> </td>
        <td> <%= part.getNumber() %> </td>
        <td> <%= part.getPrice() %> </td>
      </tr>
    <%
        }
        %>
    </table>
        <%
        } else if(foundPart != null){
        %>
        <ul>
          <li> Name: <%= foundPart.getName()%></li>
          <li> Number: <%= foundPart.getNumber()%></li>
          <li> Price: <%= foundPart.getPrice()%></li>
        </ul>
        <%
        }
    %>


    <br><br><h1> Select a task </h1>
    <form action='input.jsp' method=POST>
      <select name="task"> 
        <option value="createMachine"> Create new machine </option>
        <option value="changeMachine"> Change current machine </option>
        <option value="searchPart"> Search part in </option>
        <option value="addPart"> Add a new part </option>
        <option value="showAllParts"> Show all parts </option>
        <option value="changePartPrice"> Change part price </option>
      </select><br><br>
        <input type="submit" value="Submit">
      </form>

    <%currentMachineName = (String) session.getAttribute("currentMachine");%>
    <h5> For debugging: current machine is <%= currentMachineName %> </h5>
  </body>
</html>
