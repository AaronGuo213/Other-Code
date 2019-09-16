void setup() {
  size(800, 800);
  background(0);
  rectMode(CENTER);
}

void draw() {
  pushMatrix(); //copies the original screen
  translate(400, 400); //moves the grid 400 right and 400 down
  rotate(PI / 4); //rotates the grid 45 degrees clockwise
  rect(0, 0, 600, 400); //draws square
  popMatrix(); //returns to the original screen with the square
}
