<html>
  <body>
    <% String task = request.getParameter("task"); %>
    <h1> Input for <%= task %> </h1>
    <% if (task.equals("createMachine")) {%>
      <form action="result.jsp" method=POST> 
        <input type="hidden" name="task" value="createMachine"> 
        Machine name: 
        <input type="text" name="machineName"><br><br>
        <input type="submit" value="Submit">
      </form>
    <%} else if (task.equals("changeMachine")){%>
      <form action="result.jsp" method=POST>
        <input type="hidden" name="task" value="changeMachine"> 
        Machine Name:
        <input type="text" name=machineName><br><br>
        <input type="submit" value="Submit">
      </form>
    <%} else if (task.equals("searchPart")){%>
      <form action="result.jsp" method=POST>
        <input type="hidden" name="task" value="searchPart"> 
        Part Name:
        <input type="text" name=partName><br><br>
        <input type="submit" value="Submit">
      </form>
    <%} else if (task.equals("addPart")){%>
      <form action="result.jsp" method=POST>
        <input type="hidden" name="task" value="addPart"> 
        Part Name: <br>
        <input type="text" name=partName><br>
        Part Number:<br>
        <input type="text" name=partNumber><br>
        Part Price:<br>
        <input type="text" name=partPrice><br><br>
        <input type="submit" value="Submit">
      </form>
    <%} else if(task.equals("showAllParts")) {%>
        <jsp:forward page="result.jsp">
        <jsp:param name="task" value="showAllParts"/>
        </jsp:forward>
    <%}else if(task.equals("changePartPrice")){%>
    <form action="result.jsp" method=POST>
      <input type="hidden" name="task" value="changePartPrice">
      Part Name: <br>
      <input type="text" name="partName"><br>
      Part Price: <br>
      <input type"text" name="partPrice"><br><br>
      <input type="submit" value="Submit">
    </form>
    <%}%>

  </body>
</html>
