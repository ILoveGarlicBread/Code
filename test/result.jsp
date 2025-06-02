<%@ page import="model.SparePart,java.util.Set" %>
<html>
<body>
<h2>Result</h2>
<p><%= request.getAttribute("message") %></p>

<%
    Object res = request.getAttribute("result");
    if (res != null) {
        if (res instanceof model.SparePart) {
            model.SparePart part = (model.SparePart) res;
%>
            <p>Spare Part Details:</p>
            <ul>
                <li>Name: <%= part.getName() %></li>
                <li>Number: <%= part.getNumber() %></li>
                <li>Price: <%= part.getPrice() %></li>
            </ul>
<%
        } else if (res instanceof Set) {
            Set<SparePart> parts = (Set<SparePart>) res;
%>
            <p>All Spare Parts:</p>
            <table border="1" cellpadding="5">
                <tr><th>Name</th><th>Number</th><th>Price</th></tr>
<%
            for (SparePart p : parts) {
%>
                <tr>
                    <td><%= p.getName() %></td>
                    <td><%= p.getNumber() %></td>
                    <td><%= p.getPrice() %></td>
                </tr>
<%
            }
%>
            </table>
<%
        }
    }
%>

<br>
<h2>Select a task</h2>
<form action="input.jsp" method="post">
    <select name="action" required>
        <option value="">-- Choose Task --</option>
        <option value="createMachine">Create a new machine</option>
        <option value="changeMachine">Change current machine</option>
        <option value="addSparePart">Add new spare part</option>
        <option value="searchSparePart">Search spare part by name</option>
        <option value="showAllSpareParts">Show all spare parts</option>
        <option value="changePrice">Change price of spare part</option>
    </select><br><br>
    <input type="submit" value="Continue">
</form>

</body></html>

