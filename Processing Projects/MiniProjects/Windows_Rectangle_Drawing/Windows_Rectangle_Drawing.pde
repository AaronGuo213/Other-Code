  int initX;
  int initY;
  int dragX;
  int dragY;
  boolean dragCheck = false;
  boolean dragging = false;

void setup() {
  size(400, 400);
  background(255);
  rectMode(CORNERS);
}

void draw() {
  background(255);
  if(mousePressed) {
    rect(initX, initY, dragX, dragY);
  }
  else {
    dragCheck = false;
    initX = 0;
    initY = 0;
    dragX = 0;
    dragY = 0;
  }
}

void mouseDragged() {
  if(dragCheck == false) {
    dragCheck = true;
    initX = mouseX;
    initY = mouseY;
  }
  else {
    dragX = mouseX;
    dragY = mouseY;
  }
}
  
