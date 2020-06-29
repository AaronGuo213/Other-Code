//alert("hello world");

console.log("hello world");
console.error("this is an error");

let int = 30;
console.log(int);

//single element
const form = document.getElementById("myForm");
console.log(form);

//const items = document.querySelectorAll(".item");
//items.forEach((item) => console.log(item));

console.log(document.getElementById('sidebar'));
console.log(document.querySelector('h1')); //gets one element
console.log(document.querySelectorAll('li')); //gets more than one element


const il = document.querySelector(".Links");
//il.remove();
il.children[1].children[1].textContent = "hehe secrets";
il.children[1].children[0].innerHTML = "<h4>Hello</h4>"


/*const btn = document.querySelector(".button");
//btn.style.background = 'red';
btn.addEventListener('click', (e)=> {
    e.preventDefault();
    //console.log(e); //use to get the accessible data
    console.log(e.target);
});*/

const newForm = document.querySelector(".myForm");
const nameInput = document.querySelector("#name");
const emailInput = document.querySelector("#email");
const msg = document.querySelector("#msg");
const errorMsg = document.querySelector(".errorMsg");
const users = document.querySelector("#users");

newForm.addEventListener('submit', onSubmit);

function onSubmit(e) {

    e.preventDefault();

    if(nameInput.value === '' || emailInput.value === '') {
        errorMsg.classList.add('error');
        errorMsg.innerHTML = 'Please enter all fields';
        errorMsg.style.background = 'red';
        setTimeout(() => errorMsg.remove(), 3000);
    }

    else {
        console.log('success!');
        const li = document.createElement('li');
        li.appendChild(document.createTextNode(nameInput.value + ' ' + emailInput.value));
        users.appendChild(li);
        nameInput.value = '';
        emailInput.value = '';
    }

}