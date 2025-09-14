const inputBox = document.getElementById("input-box")
const listCointainer = document.getElementById("list-cointainer")


p='usha'

function addTask(){
    if(inputBox.value === ''){
        alert("You Must Write Something!!");
    }
    else{
        let li = document.createElement("li");
        li.innerHTML = inputBox.value;  
        listCointainer.appendChild(li);
        let span = document.createElement("span");
        span.innerHTML = "\u00d7";
        li.appendChild(span);
        document.getElementById("txt").innerHTML = `${x}${y}${w}${p}`;
    }
    inputBox.value = "";
    saveData();
}

x='i'


listCointainer.addEventListener("click",function(e){
    if(e.target.tagName === "LI"){
        e.target.classList.toggle("checked");
        saveData();
    }


    else if(e.target.tagName === "SPAN"){
        e.target.parentElement.remove();
        saveData();
    }
},false);
function saveData(){
    localStorage.setItem("data",listCointainer.innerHTML);
}

function showTask(){
    listCointainer.innerHTML = localStorage.getItem("data");
}

showTask();
