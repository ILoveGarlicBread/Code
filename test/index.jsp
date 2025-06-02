<html>
<body>
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
</body>
</html>

