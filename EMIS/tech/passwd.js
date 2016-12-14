var includepattern1 = /[A-Z]+/;
var includepattern2 = /[0-9]+/;
var kickoutpattern = /[;'()]+/;
var emailpattern = /^.*@.*/;

var colors = ["red", "darkorange", "blue", "green"];

function validPassword() {
    var pass_str = document.getElementById("password").value;
    var errMsg = document.getElementById("passwordErrMsg");
    if(pass_str.length == 0 || kickoutpattern.test(pass_str)) {
        errMsg.style.color = "red";
        errMsg.innerHTML = "Invalid Password";
        return false;
    }
    if(!includepattern1.test(pass_str) || !includepattern2.test(pass_str) ||
        pass_str.length <= 10) {
        
        errMsg.style.color = "red";
        errMsg.innerHTML = "Invalid Password";
        return false;
    }
    errMsg.style.color = "black";
    errMsg.innerHTML = "";
    return true;
}

function validateEmail() {
    var email = document.getElementById("inputEmail").value;
    var errorMsg = document.getElementById("emailError");
    if(emailpattern.test(email)) {
	    errorMsg.style.color = "black";
	    errorMsg.innerHTML = "";
        return true;
    }
    else {
	    errorMsg.style.color = "red";
	    errorMsg.innerHTML = "This is not a proper email address";
        return false;
    }
}

function calculateStrength(str) {
    return (includepattern1.exec(str).length + 
           includepattern2.exec(str).length) *
           (str.length-4) * 2;
}

function displayStrength() {
    var str = document.getElementById("password").value;
    var bar = document.getElementById("myMeter");
    var verdict = document.getElementById("valid");
    
    if(validPassword() == true) {
        var strength = calculateStrength(str);
        if(strength < 35) {
            verdict.innerHTML = "Weak";
            bar.style.background = colors[0];
            bar.value = 100-strength;
        }
        else if(strength >= 25 && strength < 50) {
            verdict.innerHTML = "Decent";
            bar.style.background = colors[1];
            bar.value = 100-strength;
        }
        else if(strength >= 50 && strength < 75) {
            verdict.innerHTML = "Strong";
            bar.style.background = colors[2];
            bar.value = 100-strength;
        }
        else {
            verdict.innerHTML = "Excellent";
            bar.style.background = colors[3];
            bar.value = 100-strength;
        }
    }
    else {
        bar.style.background = colors[0];
        bar.value = 100;
        verdict.innerHTML = "Password must be at least 10 characters long and contain a capital letter and a number.";
    }
}
