/*
//Hello World
void setup(){
  size(400, 400);
  background(255, 100, 100);
}

void draw(){
stroke(0);
line(25, 25, 50, 50);
}

*/

//Hello Line

int endPntX = 200;
int endPntY = 200;

void setup() {
  size(400, 400);
  stroke(255);
}
  
void draw() {
  background(10, 10, 5);
  line(endPntX, endPntY, mouseX, mouseY);
}

void mousePressed() {
  endPntX = mouseX;
  endPntY = mouseY;
}
