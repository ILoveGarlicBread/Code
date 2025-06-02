<%@ page language="java" %>
<%
    String action = request.getParameter("action");

    if ("showAllSpareParts".equals(action)) {
        // Skip input form and go straight to servlet
        request.getRequestDispatcher("task").forward(request, response);
        return; // stop further processing of this JSP
    }
%>

<h2>Provide Input for: <%= action %></h2>

<% if ("createMachine".equals(action)) { %>
    <form action="task" method="post">
        <input type="hidden" name="action" value="createMachine">
        Machine Name: <input type="text" name="machineName">
        <input type="submit" value="Create">
    </form>
<% } else if ("addSparePart".equals(action)) { %>
    <form action="task" method="post">
        <input type="hidden" name="action" value="addSparePart">
        Name: <input type="text" name="partName"><br>
        Number: <input type="text" name="partNumber"><br>
        Price: <input type="text" name="partPrice"><br>
        <input type="submit" value="Add Part">
    </form>
<% } else if ("changePrice".equals(action)) { %>
    <form action="task" method="post">
        <input type="hidden" name="action" value="changePrice">
        Number: <input type="text" name="partNumber"><br>
        New Price: <input type="text" name="newPrice"><br>
        <input type="submit" value="Update Price">
    </form>
<% } else if ("searchSparePart".equals(action)) { %>
    <form action="task" method="post">
        <input type="hidden" name="action" value="searchSparePart">
        Part Number: <input type="text" name="partNumber"><br>
        <input type="submit" value="Search">
    </form>
<% } else if ("changeMachine".equals(action)) { %>
    <form action="task" method="post">
        <input type="hidden" name="action" value="changeMachine">
        Machine Name: <input type="text" name="machineName"><br>
        <input type="submit" value="Change">
    </form>
<% } %>

