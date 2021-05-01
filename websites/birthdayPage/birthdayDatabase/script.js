const now = new Date();
let year = now.getFullYear();
let month = now.getMonth() + 1;
let date = now.getDate();
let day = now.getDay();
let hour = now.getHours(); //army time
let minutes = now.getMinutes();

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
    getAge() {
        if(this.birthday.year == 0 || this.birthday.month == 0 || this.birthday.day == 0) // if birthday is unknown
            return "?";

        var age = year - this.birthday.year;
        if(this.birthday.month > month)
            age --;
        else if(this.birthday.month == month && this.birthday.date > date)
            age --;
        return age;
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

function updateTable() {

    var table = document.querySelector(".database");
    var tableHTML = "<tr><th onclick=\"reorder(0)\">First Name</th><th onclick=\"reorder(1)\">Last Name</th><th>Nickname</th><th>Gender</th><th onclick=\"reorder(2)\">Birthday</th><th onclick=\"reorder(3)\">Age</th></tr>"
    for(var i = 0; i < data.length; i++) {
        tableHTML += "<tr>";
        tableHTML += "<th>" + data[i].firstName + "</th>";
        tableHTML += "<th>" + data[i].lastName + "</th>";
        tableHTML += "<th>" + data[i].nickname + "</th>";
        tableHTML += "<th>" + data[i].gender + "</th>";
        tableHTML += "<th>" + data[i].birthday.month + "/" + data[i].birthday.date + "/" + (data[i].birthday.year == 0 ? "????" : data[i].birthday.year) + "</th>";
        tableHTML += "<th>" + data[i].getAge() + "</th>";
        tableHTML += "</tr>";
    }
    table.innerHTML = tableHTML;

}

var prevMode = -1;
var isReversed = false;
function reorder(mode) {

    if(prevMode == mode)
        isReversed = !isReversed; //reversal done at the end of the function
    else    
        isReversed = false;
    prevMode = mode;

    //selection sort
    var orderedData = [];

    if(mode < 2) { //first/last name
        for(var i = 0; i < data.length; i++) {
            var best = "zzzz";
            var bestID;
            for(var j = 0; j < data.length; j++) {
                if(data[j] != null) {
                    if(data[j].firstName.toLowerCase().localeCompare(best) < 0 && mode == 0) {
                        best = data[j].firstName.toLowerCase();
                        bestID = j;
                    }
                    else if(data[j].lastName.toLowerCase().localeCompare(best) < 0 && mode == 1) {
                        best = data[j].lastName.toLowerCase();
                        bestID = j;
                    }
                }
            }
            orderedData[i] = data[bestID];
            data[bestID] = null;
        }
    }

    else if(mode == 2) { //birthday
        for(var i = 0; i < data.length; i++) {
            var best = 500;
            var bestID;
            for(var j = 0; j < data.length; j++) {
                if(data[j] != null) {
                    var birthdayNum = data[j].birthday.date + data[j].birthday.month * 31;
                    if(birthdayNum < best) {
                        best = birthdayNum;
                        bestID = j;
                    }
                }
            }
            orderedData[i] = data[bestID];
            data[bestID] = null;
        }
    }

    else if(mode == 3) { //age
        for(var i = 0; i < data.length; i++) {
            var best = 5000;
            var bestID;
            for(var j = 0; j < data.length; j++) {
                if(data[j] != null) {
                    if(data[j].getAge() == "?") { //puts the unknown age at the end
                        if(!isReversed && best == 5000) //only is added to the list if  all other known ages are put in
                            bestID = j;
                        else if(isReversed) { //gets put in first so when reversed it will be at the end
                            best = -1;
                            bestID = j;
                        }
                    }
                    else if(data[j].getAge() < best) {
                        best = data[j].getAge();
                        bestID = j;
                    }
                }
            }
            orderedData[i] = data[bestID];
            data[bestID] = null;
            console.log(best);
        }
    }

    if(isReversed) {
        var temp;
        for(var i = 0; i < orderedData.length/2; i++) {
            temp = orderedData[i];
            orderedData[i] = orderedData[orderedData.length-1-i];
            orderedData[orderedData.length-1-i] = temp;
        }
    }

    data = orderedData;
    updateTable();

}

/*====================
WHAT ACTUALLY GETS RUN
====================*/

updateTable();
