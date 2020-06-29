String[] inputCode, outputCode;
boolean mode = false; //false = BDay DB, true = add BDay
int input = -1;
String[] personInfo = {"", "", "", "Male", "", "", ""};
String[][] peopleInfo;
int numPeople;
int indent = 25;
int error = 0;
int numPages, currentPage = 0, currentPerson = -1;
//for ordering the people
int orderMode = -1;
boolean isOrderedBackwards = false;
//for editing people
boolean isEditing = false;
String[] editedPerson;

void setup() {
  size(800, 800);
  rectMode(CENTER);
  translate(0, 800);
  frameRate(60);
  loadData();
}

void draw() {
  background(0);
  textAlign(CENTER);
  strokeWeight(1);
  
  //database tab
  if(!mode) fill(0, 150, 150);
  else fill(0, 200, 200);
  rect(200, 50, 400, 100);
  fill(0);
  textSize(30);
  text("Birthday Database", 200, 60);
  
  //add brithday tab
  if(mode) fill(0, 150, 150);
  else fill(0, 200, 200);
  rect(600, 50, 400, 100);
  fill(0);
  textSize(30);
  text("Add a Birthday", 600, 60);
  
  if(mode)
    updateAddBirthday();
    
  else
    updateBirthdayDB();
    
}

void mousePressed() {
 
  if(mouseY <= 100) {
    if(mouseX <= 400) {
      mode = false;
      loadData();
    }
    else
      mode = true;
  }
  
  else if(mode) {
    
    if(mouseY >= 265 && mouseY < 315)
      input = 0;
    else if(mouseY >= 315 && mouseY < 365)
      input = 1;
    else if(mouseY >= 365 && mouseY < 415)
      input = 2;
    else if(mouseY >= 415 && mouseY < 465) {
      input = 3;
      if(personInfo[3].equals("Male")) personInfo[3] = "Female";
      else personInfo[3] = "Male";
    }
    else if(mouseY >= 465 && mouseY < 515)
      input = 4;
    else if(mouseY >= 515 && mouseY < 565)
      input = 5;
    else if(mouseY >= 565 && mouseY < 615)
      input = 6;
    else if(mouseX >= 175 && mouseX <= 325 && mouseY >= 650 && mouseY <= 700)
      clearInfo();
    else if(mouseX >= 475 && mouseX <= 625 && mouseY >= 650 && mouseY <= 700)
      addBirthday();
    
  }
  
  else if(!mode) {
    
    if(mouseY >= 160 && mouseY < 665) {
      int prevPerson = currentPerson;
      if(mouseY >= 160 && mouseY < 215)
        currentPerson = 0;
      else if(mouseY >= 215 && mouseY < 265)
        currentPerson = 1;
      else if(mouseY >= 265 && mouseY < 315)
        currentPerson = 2;
      else if(mouseY >= 315 && mouseY < 365)
        currentPerson = 3;
      else if(mouseY >= 365 && mouseY < 415)
        currentPerson = 4;
      else if(mouseY >= 415 && mouseY < 465)
        currentPerson = 5;
      else if(mouseY >= 465 && mouseY < 515)
        currentPerson = 6;
      else if(mouseY >= 515 && mouseY < 565)
        currentPerson = 7;
      else if(mouseY >= 565 && mouseY < 615)
        currentPerson = 8;
      else if(mouseY >= 615 && mouseY < 665)
        currentPerson = 9;
      if(currentPerson == prevPerson) {
        editPerson(currentPerson + 10*currentPage);
      }
    }
    
    else if(mouseX >= 340 && mouseX <= 460 && mouseY >= 705 && mouseY <= 755) {
      if(currentPerson != -1 && (currentPerson + currentPage*10 < numPeople))
        deletePerson(peopleInfo[currentPerson + currentPage*10]);
    }
    
    else {
      currentPerson = -1;
    }
    
    if(mouseX >= 45 && mouseX <= 95 && mouseY >= 705 && mouseY <= 755) {
      if(currentPage == 0)
        currentPage = numPages;
      currentPage --;
    }
    
    else if(mouseX >= 705 && mouseX <= 755 && mouseY >= 705 && mouseY <= 755) {
      currentPage ++;
      if(currentPage == numPages)
        currentPage = 0;
    }
    
    else if(mouseY >= 100 && mouseY < 160) {
      if(mouseX < 180) {
        if(orderMode == 0)
          isOrderedBackwards = !isOrderedBackwards;
        orderMode = 0;
      }
      else if(mouseX >= 180 && mouseX < 350) {
        if(orderMode == 1)
          isOrderedBackwards = !isOrderedBackwards;
        orderMode = 1;
      }
      else if(mouseX >= 600) {
        if(orderMode == 2)
          isOrderedBackwards = !isOrderedBackwards;
        orderMode = 2;
      }
      if(orderMode != -1)
        reorderPeople();
    }
    
  }
  
}

void keyPressed() {
  
  if(mode && input != -1 && input != 3) {
    if(key == '\n' || key == '\t') {
      if(input == 6)
        addBirthday();
      else
        input ++;
    }
    else if(keyCode == UP) {
      if(input > 0)
        input --;
    }
    else if(keyCode == DOWN) {
      if(input < 6)
        input ++;
    }
    else if(key == '\b') {
      if(!personInfo[input].equals("")) //cuts a char off
        personInfo[input] = personInfo[input].substring(0, personInfo[input].length()-1);
    }
    else if(keyCode != SHIFT)
      personInfo[input] += key;
  }
  
  else if(input == 3) {
    if(key == ' ') {
      if(personInfo[3].equals("Male")) personInfo[3] = "Female";
      else personInfo[3] = "Male";
    }
    
    if(key == '\n' || key == '\t' || keyCode == DOWN)
      input ++;
    else if(keyCode == UP)
      input --;
  }    
  
}

void updateAddBirthday() {
  fill(255);
  textSize(50);
  String title = isEditing ? "Edit info:" : "Enter info:";
  text(title, 400, 200);
  
  textAlign(LEFT);
  textSize(30);
  fill(input == 0 ? 150 : 255);
  text("First Name: " + personInfo[0], indent, 300); //265-315
  fill(input == 1 ? 150 : 255);
  text("Last Name: " + personInfo[1], indent, 350);
  fill(input == 2 ? 150 : 255);
  text("Nickname(if applicable): " + personInfo[2], indent, 400);
  fill(input == 3 ? 150 : 255);
  text("Gender: " + personInfo[3], indent, 450);
  fill(input == 4 ? 150 : 255);
  text("Month: " + personInfo[4], indent, 500);
  fill(input == 5 ? 150 : 255);
  text("Date: " + personInfo[5], indent, 550);
  fill(input == 6 ? 150 : 255);
  text("Year: " + personInfo[6], indent, 600);
  
  fill(255, 0, 0);
  rect(250, 675, 150, 50);
  fill(0);
  textAlign(CENTER);
  text("Clear", 250, 685);
  
  fill(0, 100, 255);
  rect(550, 675, 150, 50);
  fill(0);
  textAlign(CENTER);
  text("Submit", 550, 685);
  
  if(error == 1) {
    fill(255, 0, 0);
    text("Not everything required is entered.", 400, 750);
  }
}

void clearInfo() {
  
  for(int i = 0; i < personInfo.length; i++) {
    personInfo[i] = "";
  }
  personInfo[3] = "Male";
  
}

void addBirthday() {
  
  if(isReady()) { //if everything needed is filled out
  
    error = 0;
    if(isEditing) { //will delete old and replace with new
      deletePerson(editedPerson);
      isEditing = false;
    }
  
    //editing the js file
    inputCode = loadStrings("C:/Users/13107/Desktop/Meaningful_Stuff/Vex_and_Code/Other_Code/websites/birthdayPage/homePage/script.js");
    int keyLn;
    for(keyLn = 0; keyLn < inputCode.length; keyLn++)
      if(inputCode[keyLn].equals("//hehe secret code"))
        break;
        
    outputCode = new String[inputCode.length+1];
    for(int i = 0; i < keyLn; i++)
      outputCode[i] = inputCode[i];
      
    outputCode[keyLn] = "data.splice(data.length, 0, new Person(";
    outputCode[keyLn] += "\"" + personInfo[0] + "\", ";
    outputCode[keyLn] += "\"" + personInfo[1] + "\", ";
    outputCode[keyLn] += "\"" + personInfo[2] + "\", ";
    outputCode[keyLn] += "\"" + personInfo[3] + "\", ";
    outputCode[keyLn] += personInfo[5] + ", ";
    outputCode[keyLn] += personInfo[4] + ", ";
    if(personInfo[6].equals("?")) personInfo[6] = "0";
    outputCode[keyLn] += personInfo[6];
    outputCode[keyLn] += "));";
    
    for(int i = keyLn; i < inputCode.length; i++)
      outputCode[i+1] = inputCode[i];
    saveStrings("C:/Users/13107/Desktop/Meaningful_Stuff/Vex_and_Code/Other_Code/websites/birthdayPage/homePage/script.js", outputCode);
    
    //for the database page
    inputCode = loadStrings("C:/Users/13107/Desktop/Meaningful_Stuff/Vex_and_Code/Other_Code/websites/birthdayPage/birthdayDatabase/script.js");
    for(keyLn = 0; keyLn < inputCode.length; keyLn++)
      if(inputCode[keyLn].equals("//hehe secret code"))
        break;
        
    outputCode = new String[inputCode.length+1];
    for(int i = 0; i < keyLn; i++)
      outputCode[i] = inputCode[i];
      
    outputCode[keyLn] = "data.splice(data.length, 0, new Person(";
    outputCode[keyLn] += "\"" + personInfo[0] + "\", ";
    outputCode[keyLn] += "\"" + personInfo[1] + "\", ";
    outputCode[keyLn] += "\"" + personInfo[2] + "\", ";
    outputCode[keyLn] += "\"" + personInfo[3] + "\", ";
    outputCode[keyLn] += personInfo[5] + ", ";
    outputCode[keyLn] += personInfo[4] + ", ";
    outputCode[keyLn] += personInfo[6];
    outputCode[keyLn] += "));";
    
    for(int i = keyLn; i < inputCode.length; i++)
      outputCode[i+1] = inputCode[i];
    saveStrings("C:/Users/13107/Desktop/Meaningful_Stuff/Vex_and_Code/Other_Code/websites/birthdayPage/birthdayDatabase/script.js", outputCode);
    
    clearInfo();
    input = 0;

  }
  
  else {
    error = 1;
  }
  
}

boolean isReady() {
  boolean rtn = true;
  for(int i = 0; i < personInfo.length; i++) {
    if(i == 2) i++;
    if(personInfo[i].equals(""))
      rtn = false;
  }
  return rtn;
}

void updateBirthdayDB() {
  
  int miniIndent = 10;
  textSize(30);
  textAlign(LEFT);
  fill(255);
  stroke(255);
  text("First Name", miniIndent, 150);
  line(180, 100, 180, 670);
  text("Last Name", miniIndent + 180, 150);
  line(350, 100, 350, 670);
  text("Nickname", miniIndent + 350, 150);
  line(520, 100, 520, 670);
  text("M/F", miniIndent + 520, 150);
  line(600, 100, 600, 670);
  text("Birthday", miniIndent + 600, 150);
  line(0, 160, 800, 160);
  line(0, 670, 800, 670);
  
  //all the people and the info about them
  int[] linePos = {0, 180, 350, 520, 600};
  for(int i = 0; i < (currentPage == numPages-1 && numPeople%10 != 0 ? numPeople%10 : 10); i++) {
    fill(currentPerson == i ? 150 : 255);
    for(int j = 0; j < 5; j++) {
      String output = peopleInfo[currentPage*10+i][j];
      if(j == 3) 
        output = output.equals("Male") ? "M" : "F";
      else if(j == 4) {
        output = peopleInfo[currentPage*10+i][4] + "/" + peopleInfo[currentPage*10+i][5] + "/";
        output += Integer.parseInt(peopleInfo[currentPage*10+i][6]) == 0 ? "????" : peopleInfo[currentPage*10+i][6]; //if year isnt known
      }
      text(output, miniIndent+linePos[j], 200+i*50);
    }
  }
  
  //buttons
  fill(100);
  rect(70, 730, 50, 50);
  stroke(0);
  strokeWeight(3);
  line(55, 730, 85, 745);
  line(55, 730, 85, 715);
  
  strokeWeight(1);
  stroke(255);
  fill(100);
  rect(730, 730, 50, 50);
  stroke(0);
  strokeWeight(3);
  line(745, 730, 715, 745);
  line(745, 730, 715, 715);
  
  //delete button
  fill(255, 0, 0);
  stroke(0);
  strokeWeight(1);
  rect(400, 730, 120, 50);
  fill(0);
  textAlign(CENTER);
  text("DELETE", 400, 740);
  
}

void loadData() {
    
  inputCode = loadStrings("C:/Users/13107/Desktop/Meaningful_Stuff/Vex_and_Code/Other_Code/websites/birthdayPage/homePage/script.js");
  int startLn = 0, endLn = 0;
  for(int i = 0; i < inputCode.length; i++) {
    if(inputCode[i].equals("//nothing to see here"))
      startLn = i;
    if(inputCode[i].equals("//hehe secret code"))
      endLn = i;
  }
  
  numPeople = endLn - startLn - 1;
  peopleInfo = new String[numPeople][7];
  
  //deconstructs the js code back into data
  for(int i = 0; i < numPeople; i++) {
    int count = 0;
    for(int j = 0; j < inputCode[startLn+i+1].length(); j++) {
      String str = "";
      if(count < 4) { //for the strings
        if(inputCode[startLn+i+1].charAt(j) == '"') {
          j ++;
          while(inputCode[startLn+i+1].charAt(j) != '"') {
            str += inputCode[startLn+i+1].charAt(j);
            j ++;
          }
          peopleInfo[i][count] = str;
          count ++;
        }
      }
      else { //for the numbers
        if(inputCode[startLn+i+1].charAt(j) == ' ') {
          j ++;
          while(inputCode[startLn+i+1].charAt(j) != ',' && inputCode[startLn+i+1].charAt(j) != ')') {
            str += inputCode[startLn+i+1].charAt(j);
            j ++;
          }
          peopleInfo[i][count] = str;
          count ++;
        }
      }
    }
  }
  
  for(int i = 0; i < numPeople; i++) { //changes to month-day-year format
    String temp = peopleInfo[i][4];
    peopleInfo[i][4] = peopleInfo[i][5];
    peopleInfo[i][5] = temp;
  }
  
  numPages = numPeople / 10; //for displaying the people
  if(numPeople % 10 != 0) numPages++;
  
}

void deletePerson(String[] person) {
  
  //for the home page
  inputCode = loadStrings("C:/Users/13107/Desktop/Meaningful_Stuff/Vex_and_Code/Other_Code/websites/birthdayPage/homePage/script.js");
  int keyLn;
  String firstName = person[0], lastName = person[1];
  for(keyLn = 0; keyLn < inputCode.length; keyLn++)
    if(inputCode[keyLn].indexOf(firstName) != -1 && inputCode[keyLn].indexOf(lastName) != -1)
      break;
    
  outputCode = new String[inputCode.length-1];
  for(int i = 0; i < keyLn; i++)
    outputCode[i] = inputCode[i];
  for(int i = keyLn+1; i < inputCode.length; i++)
    outputCode[i-1] = inputCode[i];
  saveStrings("C:/Users/13107/Desktop/Meaningful_Stuff/Vex_and_Code/Other_Code/websites/birthdayPage/homePage/script.js", outputCode);
  
  //for the database page
  inputCode = loadStrings("C:/Users/13107/Desktop/Meaningful_Stuff/Vex_and_Code/Other_Code/websites/birthdayPage/birthdayDatabase/script.js");
  for(keyLn = 0; keyLn < inputCode.length; keyLn++)
    if(inputCode[keyLn].indexOf(firstName) != -1 && inputCode[keyLn].indexOf(lastName) != -1)
      break;
    
  outputCode = new String[inputCode.length-1];
  for(int i = 0; i < keyLn; i++)
    outputCode[i] = inputCode[i];
  for(int i = keyLn+1; i < inputCode.length; i++)
    outputCode[i-1] = inputCode[i];
  saveStrings("C:/Users/13107/Desktop/Meaningful_Stuff/Vex_and_Code/Other_Code/websites/birthdayPage/birthdayDatabase/script.js", outputCode);
  
  for(int i = 0; i < outputCode.length; i++)
    println(outputCode[i]);
  
  numPeople --;
  numPages = numPeople/10;
  if(numPeople%10 == 0)
    currentPage --;
  
  //updates chart
  loadData();

}

void reorderPeople() {
  //selection sort
  String[][] sortedPeople = new String[peopleInfo.length][7];
  if(orderMode == 2) {
    int[] numedDates = new int[peopleInfo.length]; //quantifying the birthdays in order to sort
    for(int i = 0; i < peopleInfo.length; i++)
      numedDates[i] = Integer.parseInt(peopleInfo[i][4]) * 31 + Integer.parseInt(peopleInfo[i][5]); //parseInt converts string to int
      
    for(int i = 0; i < sortedPeople.length; i++) {
      int earliestDate = isOrderedBackwards ? 0 : 500;
      int earliestIndex = -1;
      for(int j = 0; j < numedDates.length; j++) {
        if(numedDates[j] != 0) {
          if(numedDates[j] < earliestDate && !isOrderedBackwards) {
            earliestDate = numedDates[j];
            earliestIndex = j;
          }
          if(numedDates[j] > earliestDate && isOrderedBackwards) {
            earliestDate = numedDates[j];
            earliestIndex = j;
          }
        }
      }
      sortedPeople[i] = peopleInfo[earliestIndex];
      numedDates[earliestIndex] = 0;
    }
  }
  
  else {
    for(int i = 0; i < sortedPeople.length; i++) {
      String earliestString = isOrderedBackwards ? "A" : "|";
      int earliestIndex = -1;
      for(int j = 0; j < peopleInfo.length; j++) {
        if(peopleInfo[j] != null) {
          if(peopleInfo[j][orderMode].toLowerCase().compareTo(earliestString.toLowerCase()) < 0 && !isOrderedBackwards) {
            earliestString = peopleInfo[j][orderMode];
            earliestIndex = j;
          }
          else if(peopleInfo[j][orderMode].toLowerCase().compareTo(earliestString.toLowerCase()) > 0 && isOrderedBackwards) {
            earliestString = peopleInfo[j][orderMode];
            earliestIndex = j;
          }
        }
      }
      sortedPeople[i] = peopleInfo[earliestIndex];
      peopleInfo[earliestIndex] = null;
    }
  }
  peopleInfo = sortedPeople;
}

void editPerson(int id) { //sets up to edit
  isEditing = true;
  mode = true;
  personInfo = peopleInfo[id];
  editedPerson = new String[7];
  for(int i = 0; i < 7; i++) {
    editedPerson[i] = new String(peopleInfo[id][i]);
  }
}
