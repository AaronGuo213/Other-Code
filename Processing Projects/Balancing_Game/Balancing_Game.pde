float angle = 0;
float angVel = 0;
float circleRadius = 12;
final float g = 0.1, moment = 1, r = 1;
final float dt = 0.017;
float prevX = 800;
boolean started = false;

void setup() {
  size(1600, 800);
  background(0);
  frameRate(60);
}

void draw() {
  background(0);
  if(!started) {
    ellipse(800, 700, 2*circleRadius, 2*circleRadius);
    drawStick(800, 700, angle);
  }
  else {
    ellipse(mouseX, 700, 2*circleRadius, 2*circleRadius);
    drawStick(mouseX, 700, angle);
    update(mouseX);
  }
}

void mouseClicked() {
  if(mouseX - 800 <= circleRadius) {
    started = true;
  }
}

void drawStick(float x1, float y1, float currentAngle) {
  currentAngle -= PI/2;
  float theta1, theta2, thetaF, d;
  float x, y;
  final float stickLength = 200, stickWidth = 10;
  final float dist = circleRadius + stickLength/2;
  theta1 = atan2(y1, x1);
  theta2 = currentAngle;
  d = sqrt(x1 * x1 + y1 * y1);
  thetaF = theta1 - theta2;
  fill(255);
  rectMode(CENTER);
  rotate(theta2);
  x = d * cos(thetaF) + dist;
  y = d * sin(thetaF);
  rect(x, y, stickLength, stickWidth);
  rotate(-theta2);
  //rect(x1, y1, 20, 20);
}

void update(float xPos) {
  float alpha = getGravAlpha();
  alpha += getCircleAlpha(prevX, xPos);
  //float alpha = getCircleAlpha(prevX, xPos);
  angVel += alpha * dt;
  angle += angVel;
  println(angVel);
  prevX = xPos;
}

float getGravAlpha() {
  return g * sin(angle) * r / moment;
}

float getCircleAlpha(float previousX, float currentX) {
  float xVel = (currentX-previousX) / dt;
  final float constant = 0.0002;
  float alpha = -xVel * constant;
  return alpha;
}
