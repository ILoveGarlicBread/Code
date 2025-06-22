<%@ page import="jsp.Machine, jsp.Part, java.util.Map, java.util.Set, java.util.HashMap" %>
<html>
  <body>
    <% String task=request.getParameter("task"); %>
    <% String message = "";%>
    <%
    // Object for display stuff
        Part foundPart = null;
    Set<Part> foundParts = null;
    Map<String, Machine> machines = (Map<String, Machine>) session.getAttribute("machines");
    // check for machine null
    if(machines == null){
      machines = new HashMap<>();
      session.setAttribute("machines", machines);
    }

    %>
    <h1> Result for <%= task %> </h1>
    <%  

    switch (task) {
      case "createMachine":
        String newMachineName = request.getParameter("machineName");
        Machine newMachine = new Machine("machineName");
        if (machines.containsKey(newMachineName)) {
          message = "Duplicated name";
        } else {
          machines.put(newMachineName, newMachine);
          message = "Machine added successfully, remeber to use changeMachine first before using addPart and other functions";
        }
        break;
      case "changeMachine":
        String currentMachineName = request.getParameter("machineName");
        if (machines.containsKey(currentMachineName)) {
          Machine currentMachine = machines.get(currentMachineName);
          session.setAttribute("currentMachine", currentMachineName);
          message = "Current machine changed successfully";
        } else {
          message = "There is no machine named " + currentMachineName;
        }
        break;
      case "searchPart":
        String partName = request.getParameter("partName");
        currentMachineName = (String) session.getAttribute("currentMachine");
        Machine currentMachine = machines.get(currentMachineName);
        foundPart = currentMachine.searchPart(partName);
        break;
      case "addPart":
        partName = request.getParameter("partName");
        int partNumber = Integer.valueOf(request.getParameter("partNumber"));
        int partPrice = Integer.valueOf(request.getParameter("partPrice"));
        currentMachineName =(String) session.getAttribute("currentMachine");
        currentMachine = machines.get(currentMachineName);
        if(currentMachine == null){
          message = "No machine has been chosen, try changeMachine first";
          break;
        }
        currentMachine.addPart(partName, partNumber, partPrice);
        message = "Part " + partName + " added to " + currentMachineName + " successfully";
        break;
      case "showAllParts":
        currentMachineName =(String) session.getAttribute("currentMachine");
        currentMachine = machines.get(currentMachineName);
        if(currentMachine == null){
          message="currentMachine is null";
          break;
        }
        foundParts = currentMachine.returnAllParts();
        break;
      case "changePartPrice":
        currentMachineName = (String)session.getAttribute("currentMachine");
        currentMachine = machines.get(currentMachineName);
        partName = request.getParameter("partName");
        partPrice = Integer.valueOf(request.getParameter("partPrice"));
        foundPart = currentMachine.searchPart(partName);
        if(foundPart == null){
          message = "no part found with name " + partName;
          break;
        }
        foundPart.setPrice(partPrice);
        message = "Part price changed successfully";
        break;
      }


    %>
    <%= message %>
    <%
    if(foundPart != null){
    %>
    <ul>
      <li> Name: <%= foundPart.getName()%> </li>
      <li> Number: <%= foundPart.getNumber()%> </li>
      <li> Price: <%= foundPart.getPrice()%> </li>
    </ul>
    <%
    
    }else if(foundParts != null){
    %>
      <table>
        <tr><th>Name</th><th>Number</th><th>Price</th></tr>
    <% 
        for(Part part : foundParts){
        %>
          <tr>
          <td> <%= part.getName()%></td>
          <td> <%= part.getNumber()%></td>
          <td> <%= part.getPrice()%></td>
          </tr>
        <%

        }
    %>
    </table>
          
    <%
      
    }
    %>

    <%
    //loopback to input, select.jsp is used one
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
      <br>
      <br>
      <br>
      <br>
      <% 
      // some debugging stuff
      String currentMachineName = (String) session.getAttribute("currentMachine");
      %>
      <h5> Debugging: <h5>
          Current Machine: <%= currentMachineName %><br>
          Null is expected if changeMachine haven't been triggerred

  </body>
</html>
