var now = new Date();
let year = now.getFullYear();
let month = now.getMonth() + 1;
let date = now.getDate();
let day = now.getDay();
let hour = now.getHours(); //army time
let minute = now.getMinutes();
let second = now.getSeconds();

//Title
function createHeader() {

    let mainHeader = document.querySelector(".mainHeader");
    let headerText = "<h1>";

    if(hour >= 3 && hour < 12)
        headerText += "Good Morning, Aaron";
    else if(hour >= 12 && hour < 18)
        headerText += "Good Afternoon, Aaron";
    else if(hour >= 18 || hour < 3)
        headerText += "Good Evening, Aaron";

    headerText += "</h1>\n"
    headerText += "<h2>Today is ";

    var dayArr = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    var monthArr = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
    headerText += dayArr[day] + ", ";
    headerText += monthArr[month-1] + " "; //0 is january, so must -1
    headerText += date + ", " + year + "</h2>";

    mainHeader.innerHTML = headerText;

}

function updateTime() {

    now = new Date();
    year = now.getFullYear();
    month = now.getMonth() + 1;
    date = now.getDate();
    day = now.getDay();
    hour = now.getHours(); //army time
    minute = now.getMinutes();
    second = now.getSeconds();

    //Title
    var clock = document.querySelector(".clock");
    var headerText = "<h1>" + formatTime(hour) + ":" + formatTime(minute) + ":" + formatTime(second) + "</h1>"; //time

    clock.innerHTML = headerText;

}

function formatTime(input) {
    if(input < 10)
        return "0" + input;
    return input;
}

/*==============
SEARCH BAR STUFF
==============*/

const search = document.querySelector("#search");
function goSearch() {

    if(!searchThesaurus())
    if(!searchYoutube())
        searchGoogle();

    search.value = "";

}

function searchGoogle() { //searchbar google search
    if(search.value == "")
        window.location = "http://google.com";
    else 
        window.location = "http://google.com/search?q=" + search.value;
}

function searchThesaurus() { //searchbar keyword for thesaurus
    if(search.value.substring(0, 9).toLowerCase() == "thesaurus") {
        if(search.value.toLowerCase() == "thesaurus")
            window.location = "https://www.thesaurus.com";
        else
            window.location = "https://www.thesaurus.com/browse/" + search.value.substring(9) + "?s=t";
        return true;
    }
    return false;
}

function searchYoutube() { //searchbar keyword for youtube
    if(search.value.toLowerCase() == "youtube" || search.value.toLowerCase() == "you") {
        window.location = "https://www.youtube.com";
        return true;
    }
    return false;
}

/*============
BIRTHDAY STUFF
============*/

/*===============
DO NOT TOUCH/EDIT
===============*/

class birthday {
    constructor(day, Month, Year) {
        this.date = day;
        this.month = Month;
        this.year = Year;
    }
}

class Person {
    constructor(fName, lName, nName, sex, day, Month, Year) {
        this.firstName = fName;
        this.lastName = lName;
        this.nickname = nName;
        this.gender = sex;
        this.birthday = new birthday(day, Month, Year);
    }
}

var data = [];
//nothing to see here
data.splice(data.length, 0, new Person("Zhen", "Guo", "", "Female", 16, 10, 2001));
data.splice(data.length, 0, new Person("Allen", "Guo", "Pops", "Male", 11, 11, 1968));
data.splice(data.length, 0, new Person("Thychau", "Guo", "Mama", "Female", 24, 9, 1976));
data.splice(data.length, 0, new Person("Cameron", "Greene", "Cam", "Male", 14, 8, 2003));
data.splice(data.length, 0, new Person("Allison", "Guo", "", "Female", 18, 11, 2004));
data.splice(data.length, 0, new Person("Alex", "Guo", "Buk", "Male", 12, 11, 2001));
data.splice(data.length, 0, new Person("Grace", "Liu", "", "Female", 3, 12, 2003));
data.splice(data.length, 0, new Person("Shelby", "Ponce", "", "Female", 9, 6, 2003));
data.splice(data.length, 0, new Person("Aaron", "Guo", "", "Male", 7, 6, 2003));
data.splice(data.length, 0, new Person("Zach", "Huang", "", "Male", 2, 12, 2002));
data.splice(data.length, 0, new Person("Elijah", "Huang", "Eli", "Male", 3, 11, 2004));
data.splice(data.length, 0, new Person("Noah", "Lin", "", "Male", 4, 3, 2003));
data.splice(data.length, 0, new Person("Jack", "Yang", "", "Male", 25, 3, 2003));
data.splice(data.length, 0, new Person("Lauren", "Naehu", "", "Female", 14, 2, 2003));
data.splice(data.length, 0, new Person("Alice", "Min", "", "Female", 15, 5, 2003));
data.splice(data.length, 0, new Person("Kaylin", "Lee", "", "Female", 7, 2, 2003));
data.splice(data.length, 0, new Person("Lorraine", "Norris", "Mrs. Norris", "Female", 11, 9, 0));
data.splice(data.length, 0, new Person("Wanping", "Tang", "Wanping Ayi", "Female", 9, 9, 0));
data.splice(data.length, 0, new Person("Ali", "Abdelnaby", "", "Male", 20, 10, 2003));
data.splice(data.length, 0, new Person("Susan", "Pavelka", "Ms. Pavelka", "Female", 27, 10, 0));
data.splice(data.length, 0, new Person("Curtis", "Liu", "", "Male", 9, 5, 2003));
data.splice(data.length, 0, new Person("Nai Nai", "Guo", "", "Female", 15, 5, 0));
data.splice(data.length, 0, new Person("Timmy", "Ha", "", "Male", 14, 3, 2001));
data.splice(data.length, 0, new Person("Jenny", "Quach", "", "Female", 19, 4, 2002));
data.splice(data.length, 0, new Person("Sabrina", "Tang", "", "Female", 19, 4, 2002));
data.splice(data.length, 0, new Person("Tony", "Guo", "", "Male", 18, 11, 2003));
data.splice(data.length, 0, new Person("May", "Quach", "Ba Ngoai", "Female", 7, 6, 1955));
data.splice(data.length, 0, new Person("Hung", "Quach", "Ong Ngoai", "Male", 19, 4, 1952));
data.splice(data.length, 0, new Person("Nicole", "Chung", "", "Female", 28, 8, 2003));
data.splice(data.length, 0, new Person("Tyler", "Ewald", "", "Male", 3, 1, 2003));
data.splice(data.length, 0, new Person("Daniel", "Belzberg", "", "Male", 24, 2, 2003));
data.splice(data.length, 0, new Person("Vidyuth", "Thattai", "Vidy", "Male", 31, 3, 2003));
data.splice(data.length, 0, new Person("Ash", "Guo", "", "Male", 13, 11, 2017));
data.splice(data.length, 0, new Person("Marko", "Nikoletic", "", "Male", 16, 5, 2002));
data.splice(data.length, 0, new Person("Troy", "Burad", "", "Male", 23, 3, 2003));
data.splice(data.length, 0, new Person("Meiers", "Dixon", "", "Male", 5, 3, 2003));
data.splice(data.length, 0, new Person("Tony", "￿Cha", "", "Male", 14, 2, 2005));
data.splice(data.length, 0, new Person("David", "Maemoto", "Dave", "Male", 24, 6, 2004));
data.splice(data.length, 0, new Person("Karl", "Velazquez", "", "Male", 19, 7, 2003));
data.splice(data.length, 0, new Person("Dominic", "Yore", "Dom", "Male", 8, 8, 2002));
data.splice(data.length, 0, new Person("Cole", "Welcher", "", "Male", 22, 12, 2002));
//hehe secret code

/*=============
You're good now
=============*/

function daysTillBDay(person) {
    let days = person.birthday.date - date;
    var tempYear = year; //maybe the next year is a leap year
    for(let i = month; i != person.birthday.month || days < 0; i++) { //adding days from months apart
        if(i == 2)
            days += tempYear%4==0 ? 29 : 28;
        else if(i < 8)
            days += i%2==0 ? 30 : 31;
        else 
            days += i%2==0 ? 31 : 30;
        if(i == 12) {
            i = 0;
            tempYear ++;
        }
    }
    return days;
}

function updateTaskList(people) {

    var days = [daysTillBDay(people[0])];
    var index = [0];
    var currentDays;
    for(var i = 1; i < people.length; i++) { //orders the birthdays
        currentDays = daysTillBDay(people[i]);
        for(var j = 0; j <= days.length; j++) {
            if(j == days.length || currentDays < days[j]) {
                days.splice(j, 0, currentDays);
                index.splice(j, 0, i);
                break;
            }
        }
    }

    var listContent = "<h2>This Week</h2>";
    var phase = false; //determines week or month events
    for(var i = 0; i < index.length; i++) {

        if(days[i] > 7 && !phase) { //goes to month events after week events finished
            if(i == 0)
                listContent += "<li>No birthdays within a week from now.</li>"
            listContent += "<h2>This Month</h2>";
            phase = true;
        }
        if(!(people[index[i]].birthday.month == month && people[index[i]].birthday.year == year) && phase) {
            if(i == 0)
                listContent += "<li>No more birthdays for the rest of the month. :(</li>"
            break;
        }

        //age of the person + suffix
        var age = year - people[index[i]].birthday.year;
        var suffix;
        if(age % 10 == 1) suffix = "st";
        else if(age % 10 == 2) suffix = "nd";
        else if(age % 10 == 3) suffix = "rd";
        else suffix = "th";

        //uses nickname is there is one, or first name otherwise
        var commonName = people[index[i]].nickname=="" ? people[index[i]].firstName : people[index[i]].nickname;
        var fullName = people[index[i]].firstName + " " + people[index[i]].lastName;
        var nameTag = "<span class='name'>" + commonName + "'s<span class=popup><span class=fName>" + fullName + "</span></span></span>";
        //creates sentence
        var ageStr = people[index[i]].year == undefined ? "" : age + suffix;
        listContent += "<li><span class='point'>" + nameTag + " " + ageStr + " birthday is ";
        if(days[i] == 0) {
            listContent += "today! Say happy birthday to ";
            listContent += people[i].gender=="female" ? "her!" : "him!"
        }
        else if(days[i] == 1)
            listContent += "tomorrow.";
        else
            listContent += "in " + days[i] + " days."
        listContent += "</span></li>";

    }

    var list = document.querySelector(".taskList");
    list.innerHTML = listContent;

}

/*====================
WHAT ACTUALLY GETS RUN
====================*/

createHeader();
updateTime();
setInterval(createHeader, 100);
setInterval(updateTime, 100);
updateTaskList(data);
