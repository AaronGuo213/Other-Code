float x = 400, y = 400; //position of object
float heading = 0; //angle of object
int radius = 100;
float vel = 400; //tangential velocity
boolean clockwise = true;
final int framerate = 30;
float xCenter, yCenter; //position of the center of the circle
float radAngle, relativeAngle; //angle of radius relative to object, angle of object relative to radius
float angleVel = vel / radius * 180 / PI; //angular velocity

boolean enter, up, down; //controls
boolean enterAtck = false;

void setup() {
  
  size(800, 800);
  background(0);
  ellipseMode(CENTER);
  frameRate(30);
  
}

void draw() {
  
  background(0);
  fill(255);
  ellipse(x, 800-y, 10, 10); //object
  
  //locates the center of the circle
  if(clockwise) radAngle = heading - 90;
  else radAngle = heading + 90;
  relativeAngle = -(180 - radAngle);
  angleVel = vel / radius * 180 / PI;
  xCenter = x + radius * cos(radAngle * PI / 180);
  yCenter = y + radius * sin(radAngle * PI / 180);
  //draws center
  fill(255, 0, 0);
  ellipse(xCenter, 800-yCenter, 5, 5);
  
  //updates the object position and heading according to angular velocity
  if(clockwise) {
    relativeAngle += angleVel / frameRate;
    heading += angleVel / frameRate;
  }
  else {
    relativeAngle -= angleVel / frameRate;
    heading -= angleVel / frameRate;
  }
  x = xCenter + radius * cos(relativeAngle * PI / 180);
  y = yCenter + radius * sin(relativeAngle * PI / 180);
  
  //flips direction
  if(!enter)
    enterAtck = false;
  else if(!enterAtck) {
    enterAtck = true;
    clockwise = !clockwise;
  }
  
  //radius edits
  if(up && !down)
    radius ++;
  else if(down && !up)
    radius --;
  
}

void keyPressed() {
  if(keyCode == ENTER)
    enter = true;
  if(keyCode == UP)
    up = true;
  if(keyCode == DOWN)
    down = true;
}

void keyReleased() {
  if(keyCode == ENTER)
    enter = false;
  if(keyCode == UP)
    up = false;
  if(keyCode == DOWN)
    down = false;
}
