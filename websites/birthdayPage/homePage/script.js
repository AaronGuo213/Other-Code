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
        headerText += "Good Morning,<br>Aaron!";
    else if(hour >= 12 && hour < 18)
        headerText += "Good Afternoon,<br>Aaron!";
    else if(hour >= 18 || hour < 3)
        headerText += "Good Evening,<br>Aaron!";

    headerText += "</h1>\n"
    headerText += "<h2>Today is ";

    var dayArr = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    var monthArr = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
    headerText += dayArr[day] + ",<br>";
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

    // Selecting colors
    var colorArr = [["white", "skyblue"], ["pink", "red"], ["limegreen", "green"], ["skyblue", "violet"], ["yellow", "hotpink"], ["indigo", "yellow"], ["tan", "orangered"], ["darkorange", "firebrick"], ["indigo", "royalblue"], ["black", "orange"], ["rgb(94, 48, 15)", "goldenrod"], ["green", "red"]];
    clock.style.backgroundColor = colorArr[month-1][0];
    clock.style.color = colorArr[month-1][1];

    clock.innerHTML = headerText;

}

function formatTime(input) {
    if(input < 10)
        return "0" + input;
    return input;
}

/*===========
QUOTE METHODS
===========*/

function updateQuote() {
    // arbitrary base date to calculate week number from
    var base =  new Date("3/1/2020");
    // calculating number of days between now and base date
    var numberOfDays = Math.floor((now - base) / (24 * 60 * 60 * 1000));   
    // calculating week number 
    var weekNum = Math.floor((numberOfDays) / 7) % 108;
    var randomStr = "5ba4681372094a982b673510a42968b03751b935120a86740934165728ba58b37a401296608251a4b397a124985607b37416b928a503";
    var quoteHTML = "<h1>";
    var rule = [
        "Rule 1: Stand up straight with your shoulders back",
        "Rule 2: Treat yourself like you are someone you are responsible for helping",
        "Rule 3: Make friends with people who want the best for you",
        "Rule 4: Compare yourself with who you were yesterday, not with who someone else is today",
        "Rule 5: Do not let your children do anything that makes you dislike them",
        "Rule 6: Set your house in perfect order before you criticize the world",
        "Rule 7: Pursue what is meaningful (not what is expedient)",
        "Rule 8: Tell the truth - or, at least, don't lie",
        "Rule 9: Assume that the person you are listening to might know something you don't",
        "Rule 10: Be precise in your speech",
        "Rule 11: Do not bother children when they are skate-boarding",
        "Rule 12: Pet a cat when you encounter one on the street",
    ]
    var id = randomStr.charAt(weekNum) == 'a' ? 10 : randomStr.charAt(weekNum) == 'b' ? 11 : parseInt(randomStr.charAt(weekNum));
    quoteHTML += rule[id] + "</h1>"; // puts in quote for the week
    var quote = document.querySelector(".quote");
    quote.innerHTML = quoteHTML;
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
data.splice(data.length, 0, new Person("Elijah", "Huang", "Eli", "Male", 3, 11, 2004));
data.splice(data.length, 0, new Person("Noah", "Lin", "", "Male", 4, 3, 2003));
data.splice(data.length, 0, new Person("Jack", "Yang", "", "Male", 25, 3, 2003));
data.splice(data.length, 0, new Person("Lauren", "Naehu", "", "Female", 14, 2, 2003));
data.splice(data.length, 0, new Person("Alice", "Min", "", "Female", 15, 5, 2003));
data.splice(data.length, 0, new Person("Kaylin", "Lee", "", "Female", 7, 2, 2003));
data.splice(data.length, 0, new Person("Ali", "Abdelnaby", "", "Male", 20, 10, 2003));
data.splice(data.length, 0, new Person("Susan", "Pavelka", "Ms. Pavelka", "Female", 27, 10, 0));
data.splice(data.length, 0, new Person("Curtis", "Liu", "", "Male", 9, 5, 2003));
data.splice(data.length, 0, new Person("Timmy", "Ha", "", "Male", 14, 3, 2001));
data.splice(data.length, 0, new Person("Jenny", "Quach", "", "Female", 19, 4, 2002));
data.splice(data.length, 0, new Person("Sabrina", "Tang", "", "Female", 19, 4, 2002));
data.splice(data.length, 0, new Person("Tony", "Guo", "", "Male", 18, 11, 2003));
data.splice(data.length, 0, new Person("May", "Quach", "Ba Ngoai", "Female", 7, 6, 1955));
data.splice(data.length, 0, new Person("Hung", "Quach", "Ong Ngoai", "Male", 19, 4, 1952));
data.splice(data.length, 0, new Person("Nicole", "Chung", "", "Female", 28, 8, 2003));
data.splice(data.length, 0, new Person("Daniel", "Belzberg", "", "Male", 24, 2, 2003));
data.splice(data.length, 0, new Person("Vidyuth", "Thattai", "Vidy", "Male", 31, 3, 2003));
data.splice(data.length, 0, new Person("Ash", "Guo", "", "Male", 13, 11, 2017));
data.splice(data.length, 0, new Person("Marko", "Nikoletic", "", "Male", 16, 5, 2002));
data.splice(data.length, 0, new Person("Meiers", "Dixon", "", "Male", 5, 3, 2003));
data.splice(data.length, 0, new Person("David", "Maemoto", "Dave", "Male", 24, 6, 2004));
data.splice(data.length, 0, new Person("Karl", "Velazquez", "", "Male", 19, 7, 2003));
data.splice(data.length, 0, new Person("Dominic", "Yore", "Dom", "Male", 8, 8, 2002));
data.splice(data.length, 0, new Person("Cole", "Welcher", "", "Male", 22, 12, 2002));
data.splice(data.length, 0, new Person("Tony", "Cha", "", "Male", 14, 2, 2005));
data.splice(data.length, 0, new Person("Silas", "John", "", "Male", 14, 2, 2003));
data.splice(data.length, 0, new Person("John", "Kim", "", "Male", 26, 8, 2003));
data.splice(data.length, 0, new Person("Ian", "Blanco", "Blanco", "Male", 6, 6, 2003));
data.splice(data.length, 0, new Person("Yeye", "Guo", "", "Male", 28, 4, 1938));
data.splice(data.length, 0, new Person("Mike", "Quach", "Uncle Mike", "Male", 7, 10, 1973));
data.splice(data.length, 0, new Person("Kevin", "Quach", "Uncle Kevin", "Male", 31, 3, 1975));
data.splice(data.length, 0, new Person("Helen", "Quach", "Aunt Helen", "Female", 22, 5, 1972));
data.splice(data.length, 0, new Person("Judy", "Ha", "Aunt Judy", "Female", 5, 5, 1976));
data.splice(data.length, 0, new Person("Thy", "Quach", "Thigh", "Female", 7, 2, 1985));
data.splice(data.length, 0, new Person("Ut", "Quach", "Ut", "Female", 20, 5, 1989));
data.splice(data.length, 0, new Person("Ryan", "Quach", "", "Male", 21, 8, 2001));
data.splice(data.length, 0, new Person("Nai Nai", "Guo", "", "Female", 15, 5, 1945));
data.splice(data.length, 0, new Person("Wanping", "Yu", "Wanping Ayi", "Female", 9, 9, 1968));
data.splice(data.length, 0, new Person("Gordon", "Guo", "Guoteng", "Male", 11, 11, 1990));
data.splice(data.length, 0, new Person("Jian Xin", "Guo", "Tony's Dad", "Male", 3, 1, 1966));
data.splice(data.length, 0, new Person("Dong Mei", "Pan", "Tony's Mom", "Female", 13, 10, 1967));
data.splice(data.length, 0, new Person("Zhao Yang", "Guo", "Zhen's Dad", "Male", 19, 9, 1971));
data.splice(data.length, 0, new Person("Ya Lien", "Zheng", "Zhen's Mom", "Female", 29, 6, 1971));
data.splice(data.length, 0, new Person("April", "Peters", "", "Female", 30, 1, 2015));
data.splice(data.length, 0, new Person("Robert", "Peters", "Uncle Robert", "Male", 19, 4, 1978));
data.splice(data.length, 0, new Person("David", "Rosanes", "Uncle David", "Male", 20, 2, 1990));
data.splice(data.length, 0, new Person("Tyler", "Ewald", "Ewald", "Male", 3, 1, 2003));
data.splice(data.length, 0, new Person("Lorraine", "Norris", "Mrs. Norris", "Female", 11, 9, 1970));
data.splice(data.length, 0, new Person("Hayden", "Greene", "", "Male", 21, 7, 2005));
data.splice(data.length, 0, new Person("Brian", "Greene", "Cam's Dad", "Male", 10, 5, 0));
data.splice(data.length, 0, new Person("Luna", "Greene", "", "Female", 10, 6, 2019));
data.splice(data.length, 0, new Person("Pam", "Ewald", "Ms. Ewald", "Female", 3, 11, 1965));
data.splice(data.length, 0, new Person("Jack", "Burns", "Uncle Jack", "Male", 13, 9, 1967));
data.splice(data.length, 0, new Person("Randy", "Tang", "Uncle Randy", "Male", 18, 3, 1969));
data.splice(data.length, 0, new Person("Jack Jr.", "Burns", "", "Male", 27, 11, 2001));
data.splice(data.length, 0, new Person("Delaney", "Burns", "", "Female", 16, 6, 2004));
data.splice(data.length, 0, new Person("Matthew", "Tang", "", "Male", 30, 9, 2003));
data.splice(data.length, 0, new Person("Morgan", "Burns", "", "Female", 27, 11, 2001));
data.splice(data.length, 0, new Person("Krista", "Burns", "Aunt Krista", "Female", 16, 5, 1966));
data.splice(data.length, 0, new Person("Sophia", "Norris", "", "Female", 7, 11, 2004));
data.splice(data.length, 0, new Person("Greta", "Norris", "", "Female", 7, 11, 2004));
data.splice(data.length, 0, new Person("Troy", "Burad", "", "Male", 23, 3, 2003));
data.splice(data.length, 0, new Person("Lainey", "Cote", "", "Female", 11, 10, 2003));
data.splice(data.length, 0, new Person("Sydney", "Singh", "", "Female", 12, 3, 2003));
data.splice(data.length, 0, new Person("Hanna", "Karnes", "", "Female", 22, 9, 2002));
data.splice(data.length, 0, new Person("Sam", "Nam", "", "Male", 2, 10, 2000));
data.splice(data.length, 0, new Person("Robby", "Marshall", "", "Male", 3, 10, 2003));
data.splice(data.length, 0, new Person("John", "Macmenamie", "JMac", "Male", 26, 10, 2002));
data.splice(data.length, 0, new Person("Margarita", "Kanarsky", "Professor Kanarsky", "Female", 6, 10, 0));
data.splice(data.length, 0, new Person("Amyrah", "Doty", "", "Female", 8, 10, 2003));
data.splice(data.length, 0, new Person("Gavin", "Peters", "", "Male", 23, 10, 2002));
data.splice(data.length, 0, new Person("Cara", "Greene", "Cam's Mom", "Female", 14, 7, 0));
data.splice(data.length, 0, new Person("Apollo", "Ewald", "", "Male", 17, 10, 2014));
data.splice(data.length, 0, new Person("Thomas", "Ewald", "Tyler's Dad", "Male", 31, 5, 1967));
data.splice(data.length, 0, new Person("Alex", "Ewald", "", "Male", 30, 4, 2004));
data.splice(data.length, 0, new Person("Carolyn", "Ewald", "Tyler's Stepmom", "Female", 18, 3, 1968));
data.splice(data.length, 0, new Person("Grant", "Liu", "", "Male", 28, 10, 2008));
data.splice(data.length, 0, new Person("Michael", "Swatek", "Mr. Swatek", "Male", 2, 11, 0));
data.splice(data.length, 0, new Person("Malia", "Shitabata", "", "Female", 25, 11, 2000));
data.splice(data.length, 0, new Person("Abbie", "Maemoto", "", "Female", 5, 12, 2002));
data.splice(data.length, 0, new Person("Grace's Dad", "Liu", "Grace's Dad", "Male", 16, 12, 0));
data.splice(data.length, 0, new Person("Grace's Mom", "Liu", "Grace's Mom", "Female", 18, 7, 0));
data.splice(data.length, 0, new Person("Amber", "Liu", "", "Female", 30, 4, 2015));
data.splice(data.length, 0, new Person("ba co", "Quach", "ba co", "Female", 15, 12, 1922));
data.splice(data.length, 0, new Person("Jordan", "Ewald", "", "Male", 22, 1, 2000));
data.splice(data.length, 0, new Person("Ian", "Kim", "", "Male", 8, 11, 2002));
data.splice(data.length, 0, new Person("Amyrah", "Dotti", "", "Female", 8, 10, 2003));
data.splice(data.length, 0, new Person("Trent", "Giacalone", "", "Male", 16, 2, 2003));
data.splice(data.length, 0, new Person("Talia", "Hajjar", "", "Female", 30, 4, 2003));
data.splice(data.length, 0, new Person("Zach", "Huang", "Ziggy", "Male", 2, 12, 2002));
data.splice(data.length, 0, new Person("Cammy", "Nguyen", "Co Nam", "Female", 30, 5, 1978));
data.splice(data.length, 0, new Person("Chris", "Vasey", "", "Male", 27, 4, 2006));
data.splice(data.length, 0, new Person("Aidan", "Eliasson", "", "Male", 9, 4, 2003));
data.splice(data.length, 0, new Person("Scott", "Shimoyama", "", "Male", 7, 4, 2004));
data.splice(data.length, 0, new Person("Aidan", "Forsey", "", "Male", 13, 7, 2003));
data.splice(data.length, 0, new Person("Spencer", "Levin", "", "Male", 14, 9, 2002));
data.splice(data.length, 0, new Person("Dolan", "Leeman", "", "Male", 21, 10, 2005));
data.splice(data.length, 0, new Person("Bodi", "Brannen", "", "Male", 15, 10, 2002));
data.splice(data.length, 0, new Person("Steel", "Weiss", "", "Male", 30, 4, 2005));
//hehe secret code

/*=============
You're good now
=============*/

function daysTillBDay(person) {
    if(person.birthday.month == 0) { // if birthday is unknown
        return 1000;
    }
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
    var lastBDayThisWeek;
    for(var i = 0; i < index.length; i++) {

        if(days[i] > 7 && !phase) { //goes to month events after week events finished
            if(i == 0)
                listContent += "<li><span class='point'>No birthdays within a week from now.</span></li>"
            listContent += "<h2>This Month</h2>";
            phase = true;
            lastBDayThisWeek = i;
        }
        if(people[index[i]].birthday.month != month && phase) {
            if(i == lastBDayThisWeek)
                listContent += "<li><span class='point'>No more birthdays for the rest of the month. :(</span></li>"
            break;
        }

        //age of the person + suffix
        var age = year - people[index[i]].birthday.year;
        if(month == 12 && people[index[i]].birthday.month == 1) {
            age ++; // add 1 to the age if the birthday is in the following year
        } 
        var suffix;
        if(age % 10 == 1) suffix = "st";
        else if(age % 10 == 2) suffix = "nd";
        else if(age % 10 == 3) suffix = "rd";
        else suffix = "th";

        //uses nickname is there is one, or first name otherwise
        var commonName = people[index[i]].nickname=="" ? people[index[i]].firstName : people[index[i]].nickname;
        var fullName = people[index[i]].firstName + " " + people[index[i]].lastName;
        if(days[i] == 0) { //if today is the day, then make the name rainbow
            var nameTag = "<span class='rainbowName'>" + commonName + "'s<span class=popup><span class=fName>" + fullName + "</span></span></span>";
        }
        else { //otherwise make it normal
            var nameTag = "<span class='name'>" + commonName + "'s<span class=popup><span class=fName>" + fullName + "</span></span></span>";
        }
        // finishes the sentence
        var ageStr;
        if(people[index[i]].birthday.year == 0) {
            ageStr = "";
        }
        else{
            ageStr = age + suffix;
        }
        listContent += "<li><span class='point'>" + nameTag + " " + ageStr + " birthday is ";
        if(days[i] == 0) {
            listContent += "today! Say happy birthday to ";
            listContent += people[index[i]].gender=="Female" ? "her!" : "him!"
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

var hi = 255;
var lo = 0;
var r = lo, g = lo, b = lo;
var names;

function updateNameColor() {
    for(var i = 0; i < names.length; i++) {
        if(i % 3 == 0)
            names[i].style.color = "rgb(" + r + ", " + g + ", " + b + ")";
        if(i % 3 == 1)
            names[i].style.color = "rgb(" + g + ", " + b + ", " + r + ")";
        if(i % 3 == 2)
            names[i].style.color = "rgb(" + b + ", " + r + ", " + g + ")";
    }
}

function chooseRandomColor() {

    var whichColor = Math.random()*3;
    var secondColor = Math.random()*2;
    var randomVal = Math.floor(Math.random()*(hi-lo));
    if(whichColor < 1) {
        r = hi;
        if(secondColor < 1)
            g = randomVal;
        else    
            b = randomVal;
    }
    else if(whichColor < 2) {
        g = hi;
        if(secondColor < 1)
            b = randomVal;
        else    
            r = randomVal;
    }
    else {
        b = hi;
        if(secondColor < 1)
            r = randomVal;
        else    
            g = randomVal;
    }

}

function rainbowName() {

    names = document.querySelectorAll(".rainbowName");
    chooseRandomColor();
    updateNameColor();
    setInterval(updateRainbow, 10);

}

function updateRainbow() {

    if(r == hi) {
        if(b != lo)
            b --;
        else if(g != hi)
            g ++;
        else    
            r --;
    }

    else if(g == hi) {
        if(r != lo)
            r --;
        else if(b != hi)
            b ++;
        else    
            g --;
    }

    else if(b == hi) {
        if(g != lo)
            g --;
        else if(r != hi)
            r ++;
        else    
            b --;
    }

    updateNameColor();

}

/*=================
ASH PICTURE METHODS
=================*/

const numPhotos = 87;
var op1 = 1;
var op2 = 0;
var isChanging = true;
var nextChange;
var queue = new Array(numPhotos);
var queueID;

function resetQueue() {

    for(var i = 0; i < numPhotos; i++) {
        queue[i] = i + 1;
    }
    var num1, num2, temp;
    for(var i = 0; i < 1e5; i++) {
        num1 = Math.floor(Math.random()*numPhotos);
        num2 = Math.floor(Math.random()*numPhotos);
        temp = queue[num1];
        queue[num1] = queue[num2];
        queue[num2] = temp;
    }
    queueID = 0;
    console.log(queue);

}

function choosePhoto() {

    if(queueID == numPhotos) {
        resetQueue();
    }
    var str = "\"../images/ASH COLLAGE/ASH (" + queue[queueID] + ").jpg\"";
    console.log(queue[queueID]);
    queueID ++;
    return str;

}

function getCurrentPhoto() {

    var str = "\"../images/ASH COLLAGE/ASH (" + queue[queueID-1] + ").jpg\"";
    return str;

}

function getLastPhoto() {

    if(queueID-2 >= 0) {
        var str = "\"../images/ASH COLLAGE/ASH (" + queue[queueID-2] + ").jpg\"";
        queueID --;
        return str;
    }

    else {
        return "\"../images/ASH COLLAGE/ASH (" + queue[0] + ").jpg\"";
    }

}

function firstPhoto() {

    var str = "<img src=" + choosePhoto() + " alt=\"missing ash\" width=\"30%\" class=\"nextImg\"></img>";
    var img = document.querySelector(".images");
    img.innerHTML = str;

}

function updateFrameHeights() {
    // setting the height of the old frame
    document.querySelector(".prevFrame").style.height = document.querySelector(".frame").clientHeight + "px";
    // setting the height of the frame
    document.querySelector(".frame").style.height = document.querySelector(".nextImg").clientHeight + (window.innerHeight* (0.08+0.03)) + "px"; // using image height and accounting for space above and below image

}

function switchPhoto(manual) {

    if(isChanging || manual) {
        // switching photos
        var str = "<img src=" + getCurrentPhoto() + " alt=\"missing ash\" width=\"30%\" class=\"currentImg\"></img>\n";
        var str2 = "<img src=" + choosePhoto() + " alt=\"missing ash\" width=\"30%\" class=\"nextImg\"></img>";
        var img = document.querySelector(".images");
        img.innerHTML = str+str2;
        op1 = 1;
        op2 = 0;
        controlOpacities();
    }

}

function rewindPhoto() {

    // switching photos
    var str = "<img src=" + getCurrentPhoto() + " alt=\"missing ash\" width=\"30%\" class=\"currentImg\"></img>\n";
    var str2 = "<img src=" + getLastPhoto() + " alt=\"missing ash\" width=\"30%\" class=\"nextImg\"></img>";
    var img = document.querySelector(".images");
    img.innerHTML = str+str2;
    op1 = 1;
    op2 = 0;
    controlOpacities();
    console.log(queue[queueID-1]);

}

function controlOpacities() {

    if(op2 < 1) {
        op2 += 0.01;
        op1 -= 0.01;
        if(op2 > 1) {
            op2 = 1;
        }
        setOpacitites();
        setTimeout(controlOpacities, 10);
    }

}

function setOpacitites() {

    var picture1 = document.querySelectorAll(".currentImg");
    var picture2 = document.querySelectorAll(".nextImg");
    var prevFrame = document.querySelector(".prevFrame");
    picture1[0].style.opacity = op1;
    picture2[0].style.opacity = op2;
    prevFrame.style.opacity = op1;

}

/*================
ASH BUTTON METHODS
================*/

function pausePlay() {
    isChanging = !isChanging;
    replaceButtons();
}

function goForwards() {
    switchPhoto(true);
    clearInterval(nextChange);
    nextChange = setInterval(switchPhoto, 5000, false);
    replaceButtons();
}

function goBackwards() {
    rewindPhoto();
    clearInterval(nextChange);
    nextChange = setInterval(switchPhoto, 5000, false);
    replaceButtons();
}

function replaceButtons() { // used to switch || to > and back or to remove the border when clicked
    var str = "<button class=\"pausePlay\" onclick=\"pausePlay()\">" + (isChanging ? "||" : ">") + "</button>"; // flipping between pause and play signs
    str += "<button class=\"backwards\" onclick=\"goBackwards()\"><<</button>\n<button class=\"forwards\" onclick=\"goForwards()\">>></button>"; // forwards and backwards button (needed otherwise they would disappear)
    var html = document.querySelector(".ashButtons");
    html.innerHTML = str;
}

/*====================
WHAT ACTUALLY GETS RUN
====================*/

resetQueue();
createHeader();
updateTime();
updateQuote();
firstPhoto();
setTimeout(updateFrameHeights, 1);
setInterval(updateFrameHeights, 100);
setInterval(createHeader, 100);
setInterval(updateTime, 100);
setInterval(updateQuote, 1000);
nextChange = setInterval(switchPhoto, 5000, false);
updateTaskList(data);
rainbowName();
