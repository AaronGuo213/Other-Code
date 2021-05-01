#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
//This program takes in a list of names separated by (,), (.), or (:)
//Should check for every name and if all names are spelled correctly
//The program will print the nonname words like "back row" 

vector<vector<string>> nameDB = {
        {"Alexander Arriola", "Adam Benton", "Andrew Boyd", "Alanna Boze", "Ashley Buffone-Swift", "Aaron Cerda", "Alexandra Chumley", "Andrew Coward", "Amyrah Doty", "Aidan Eliasson", "Aidan Forsey-Smerek", "Aksh Garg", "Artin Ghamari", "Addison Gilbert", "Alexsys Gill", "Aaron Guo", "Aidan Gutierrez", "Andrew Ha", "Amanda Hangartner", "Ayden Harper", "Anika Hauser", "Avery Howard", "Armaan Jhangiani", "Aurora Khatibi Garrity", "Amanda King", "Ameenah Leigh", "Anissa Leigh", "Andre Lendi", "Andrea Lin", "Anthony Lucido", "Abigail Maemoto", "Aaron Martinez", "Arjun Mathew", "Aryana Mendoza", "Alice Min", "Alexander Pierce", "Adrian Poroj", "Alyssa Prado", "Alexis Randolph", "Aidan Regan", "Ashley Reynolds", "Anton Richard", "Ashley Schmid", "Avery Simonian", "AnnMarie Sorenson", "Angela Strong", "Audrey Tomasello", "Andrew Vasilion", "Aidan Wattson", "Alexandra Wescott", "Ashley Yi", "Arshia Youssefie"},
        {"Ben Alvarado Dia", "Bodi Brannen", "Bradley Brothers", "Brooke Cleveland", "Bryce Cooper", "Beau Demerjian", "Breaunna Garcia", "Brian Ha", "Benjamin Hawk", "Beom Joon Kim", "Brett Olson", "Bradley Sharp", "Brooke Stiebel", "Benjamin Trotter"},
        {"Cyrus Abdo", "Callie Abeson", "Connor Appel", "Cameron Bond", "Chloe Boss", "Christian Cartwright", "Cameron Collier", "Casilda Corral Gutierrez", "Cole Dean", "Chloe Dowling", "Cameron Greene", "Cristen Haddad", "Claire Hardesty", "Cambell Harrigian", "Christian Hokama", "Candy Holguin", "Chaya Holyfield", "Carrie Knickrehm", "Cameron Lally", "Colin Lantz", "Chan Lee", "Claudia Lee", "Curtis Liu", "Carolina Martel", "Chloe Martin", "Chibueze Onyeador", "Christopher Peters", "Cassandra Pheiffer", "Christian Ramirez", "Carson Rhodes", "Charlotte Shook", "Charles Spivey", "Collin Stewart", "Conner Sullivan", "Charlotte Teets", "Caroline Tenney", "Chandler Trivell", "Christos Tsangaris", "Chayce Tulley", "Cole Welcher"},
        {"Daniel Amir", "Daniel Belzberg", "Dominic Bidondo-Yore", "Dominic Ciolino", "Davis Corman", "Dylan Ferraro", "Devyn Hall", "Dylan Hassanzai", "David Headon", "Daniel Hess", "David Kim", "Devon McVicar", "Dylan Nelligan", "Dune Palmer", "David Perelmuter", "Dori Rich", "Daisy Robertson", "Dushan Samuela", "Deen Veera", "David Wells"},
        {"Elise Basic", "Elizabeth Campbell", "Eliana Denham", "Emily Drawer", "Ella Frost", "Emily Gesseck", "Emma Hill", "Ethan Hladek", "Ellen Hubbard", "Emily Katnic", "Ethan Kimmes", "Ethan King", "Elisa Liberati", "Emma Nelson", "Emma Saul", "Esa Shabazz", "Ethan Shanofsky", "Emma Shapiro", "Eric Sheng", "Elijah Simpson", "Emma St. Hilaire", "Elaina Truong", "Emily Typrowicz", "Ellie        Van Wier"},
        {"Fareed Ahmed", "Francisco Bonilla", "Fiona Calandrelli", "Finlay Kehrli", "Frank LaBreche", "Farinaz Osati"},
        {"Giulliana Ardon", "Grace Bernard", "Graysen Bradley", "Gabriela Elizabeth Collatos", "Griffin Colomer", "Gabrielle Guzman", "Gabriella Jonas", "Graydon Leong Kaye", "Grace Liu", "George Mashy", "Gavin Peters", "Griffen Puhl", "Gavin Roberts", "Garrett Rudy", "Gabriel Silk", "Grant Thornburgh", "Gabrielle Wapner"},
        {"Henry Boyle", "Hunter Dunlavey", "Hailey Fitt", "Harmony Ishikawa", "Hanna Karnes", "Hayden Kharrazi", "Hunter Mackenzie", "Hannah Nenadic", "Holly Stiebel", "Hana Tomizawa", "Hallie Umrarong"},
        {"Ian Blanco", "Iruka-Dara Chidi", "Ifeoluwa Ibraheem", "Ian Kim", "Ilaria Koncius", "Isabella Martinez", "Isabella Piccirillo"},
        {"Jack Allegaert", "Jasper Belliveau", "Jaden Bigley", "Jaden Camel", "Jim Campbell", "Joseph Chelebian", "Jack Correa", "Julianna Covarrubias", "Julian Dixon", "Jadon Douglas", "Jared Douglas", "Jenna Fitzpatrick", "Jacob Friedman", "John Granick", "Jack Griego", "Joshua Houlbrooke", "Jennifer Kamholz", "Juliette Koepke", "Justin Koepke", "Jack LaPlant", "John Mac Menamie", "Jessica Majka", "Joze Marinkovic", "John Maurizio", "Jackson McKeeve", "Joelle Montelongo", "Jackson Moore", "Julio Morel", "Jessica Ottaway", "John Padian", "John Perry", "Jason Reyes", "Justin Sohn", "Jake Spivey", "Jingdi Tan", "Jonathan Walter", "Jon Ward", "Jack White", "Jaxon Winkler", "Jack Yang"}, 
        {"Kamal Baker", "Kevin Cross", "Kapilaksha Dheeriya", "Kevin Ghaffari", "Kaylie Harley", "Katelyn Hart", "Kelsey Hatamiya", "Kaycee Hong", "Katherine Hoyne", "Komaljit Kaur", "Kiley Keenan", "Kristopher Kuerten", "Kaylin Lee", "Kylie McElroy", "Kevin McGibbon", "Kyla McLay", "Kai Tristan Mohl", "Kevin Rahman", "Karl Velazquez", "Koa Vetterlein"},
        {"Lyndsey Alfaro", "Liam Bohner", "Lance Cleveland", "Lucas Everhart", "Lauren Feingold", "Leilani Fonoimoana", "Lauren Hammond", "Lily Hamson", "Luke Hassanzai", "Luke Hobus", "Lucas Hong", "Lauren Larking", "Leonard Liang", "Lucas Mattera", "Lisa Miao", "Lauren Naehu", "Landon Ota", "Lily Pantoja", "Luc Rettberg", "Leslie Soriano"},
        {"Michael Artino", "Maria Cabanas Zawadzky", "Maxwell Chas", "Meera David", "Mia Dellovade", "Meiers Dixon", "Morgan Fresch", "Matthew Frey", "Madison Grant", "Meagan Hendershot", "Maleha Innocent", "Morgan Irvine", "Matthew Kang", "Mark Lee", "Max Leeds", "Matthew Liang", "Marina Lugliani", "Matthew Maes", "Michael Malone", "Mia Marco", "Michael McBride", "Margaret McLeod", "Michael Mitsanas", "Michael Nagy", "Marko Nikoletic", "Megan O'Brien", "McKenzie Olsen", "Mykiah Plummer", "Mateo Poncia", "Maja Rancic", "Maya Roberson", "Mackenzie Shannon", "Mikayla Smith", "Megan Trainotti", "Mia Vafadari", "Maya Whitcomb", "Mackenzie Whitehead", "Meg Yoshida", "Maxwell Zarchy"},
        {"Nilaab Ahmadi", "Nicholas Baumann", "Nolan Brandt", "Nicole Chung", "Natalie Diaz", "Nicholas Hirt", "Nima Izadi", "Noah Lin", "Nicole Liontos", "Nikolaos Mantikas", "Nicholas Michaels", "Nathanael Nam", "Nate Nordine", "Natalia Pope", "Nicole Rasmussen", "Natalie Reyes", "Noemi Ruelas", "Nikole Rugnetta", "Nicole Russo", "Natasha Stein", "Nathan Stein", "Natalie Stubblebine", "Nikita Swatek", "Nicholas Vodanovich"},
        {"Owen Ladinig", "Olivia Malit"},
        {"Paolo Brinderson", "Patricio Cabagna", "Peyton Eberhard", "Paige Foster", "Parker Fry", "Pili Marco", "Peter Mirich", "Paige Porter", "Phillipe Wiederkehr", "Parker Zane"},
        {},
        {"Rachel Allen", "Ryan Anderson", "Rebecca Aycock", "Ryan Baeza", "Rodrigo Boixo Fernandez De La Cigona", "Rachel Bond", "Rhett Borda", "Ryan Bozanic", "Ryan Choi", "Richard Criley", "Ra'nya Crowder", "Rayanne Fadich", "Rhys Hendershot", "Ryan Hori", "Rebecca Kim", "Ryan Klibanov", "Ryann Levendusky", "Ronald Lockwood", "Robert Marshall", "Rowan Moore", "Ryan Olarte", "Rachel Post", "Ryan Samani", "Riley Skinner", "Ripley Uyeda"},
        {"Sofia Bandy", "Sophia Brborich", "Samantha Chelf", "Shay Desai", "Sofia Fasoletti", "Sophie Geniesse", "Sarah Jun", "Stephen Kastelan", "Sofia Katzaroff", "Samantha Laurin", "Spencer Levin", "Samuel Levine", "Sarah Liu", "Sydney Lyle", "Shannon Lynch", "Sydney Merchant", "Sara Metcalfe", "Samuel Miller", "Shaya Moayedi", "Sydney Naya", "Simone Ochalek", "Savannah Peden", "Skye Perez", "Shelby Ponce", "Shawnee Prieto", "Sarah Rancic", "Samuel Rohde", "Sayan Simanian", "Sydney Singh", "Skyler Snakenborg", "Shon Stallings", "Sofia Yarymovych"},
        {"Tyler Bagley", "Trace Basich", "Talia Blair", "Troy Burad", "Tyler Ewald", "Tor Gasteiger", "Trent Giacalone", "Tatiana Grimes", "Talia Hajjar", "Taylor Hirsch", "Thomas Lercari", "Tyler Madani", "Tiana Mann", "Talia Patti", "Triston Rose", "Tomoi Stapleton", "Toby Stoler", "Taylor Stroud"},
        {},
        {"Vance Arenstein", "Vincent Furriel", "Victoria Moll", "Vidyuth Thattai", "Vince Villasenor"},
        {"Williams Criley", "William Engstrom", "William Kirchofer", "Whitney Todosiev", "Willow Wollman", "William Wong"},
        {},
        {},
        {"Zoey Belliveau", "Zachary Huang", "Zachary Kakazu", "Zoe Klein"}
};

int findSpaceIndex(string fullName) {

    int length = fullName.length();
    for(int i = length-1; i >= 0; i--) {
        if(fullName.at(i) == '\t' || fullName.at(i) == ' ') {
            return i;
        }
    }
    return 0;

}

string separate(string fullName) {

    int index = findSpaceIndex(fullName);
    string rtn = fullName.substr(0, index) + " " + fullName.substr(index+1, fullName.length());
    return rtn;

}

void find(vector<string> names) { //compares each name to the names in the database

    cout << "People that aren't in the database (different names)" << endl;
    for(int i = 0; i < names.size(); i++) {

        string currentName = names.at(i);
        int firstLetter = (int)(currentName.at(0));
        if(firstLetter < 97)
            firstLetter -= 65;
        else
            firstLetter -= 97;

        if(firstLetter < 26) {
            bool nameFound = false;
            for(int j = 0; j < nameDB[firstLetter].size(); j++) {
                if(currentName == nameDB[firstLetter][j]) {
                    nameFound = true;
                    nameDB[firstLetter][j] = "done";
                    break;
                }
            }
            if(!nameFound)
                cout << currentName << endl;
        }

    }
    cout << "\n";

}

void showUnused() {

    cout << "People who haven't done it:" << endl;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < nameDB[i].size(); j++) {
            if(nameDB[i][j] != "done") {
                cout << nameDB[i][j] << endl;
            }
        }
    }

}

int main() { //driver

    while(true) { // run over and over again
        string list = ".";
        vector<string> names;
        cout << "Input names on separate lines, enter an empty line to finish:\n";
        while(list != "") {
            getline(cin, list);
            if(list != "") {
                names.push_back(separate(list));
            }
        }
        cout << endl;
        find(names);
        cout << endl << endl << endl;
        showUnused();
    }

}