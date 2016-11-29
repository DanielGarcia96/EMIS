var names = { users:[], passwords:[] };

function storeUser() {
    var name = document.getElementById("name").value;
    var password = document.getElementById("password").value;
    names.passwords.push(password);
    names.users.push(name);
}

function printUsers() {
    var table = document.getElementById("msg");
    var i;

    for(i=table.rows.length; i<=names.users.length; i++) {
        var r = table.insertRow(i)
        var n = r.insertCell(0);
        var p = r.insertCell(1);
        n.innerHTML = names.users[i-1];
        p.innerHTML = names.passwords[i-1];
    }
   
}
