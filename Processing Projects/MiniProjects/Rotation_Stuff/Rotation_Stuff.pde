float angle, dist = 30;
float d, x, y;
float theta1, theta2, thetaF;
float x1 = 300, y1 = 300;

void setup() {
  size(400, 400);
  background(0);
}

void draw() {
  theta1 = atan2(y1, x1);
  theta2 = atan2(mouseY - y1, mouseX - x1);
  d = sqrt(x1 * x1 + y1 * y1);
  thetaF = theta1 - theta2;
  fill(255);
  rectMode(CENTER);
  background(0);
  rotate(theta2);
  x = d * cos(thetaF) + dist;
  y = d * sin(thetaF);
  rect(x, y, 10, 10);
  rotate(-theta2);
  rect(x1, y1, 20, 20);
  println(thetaF * 180 / PI);
  
  /*rotate(PI/4);
  rect(200, 200, 10, 10);
  rotate(-PI/4);*/
}
