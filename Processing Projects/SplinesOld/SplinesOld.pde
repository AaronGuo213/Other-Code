final float SCALE = 100;
int numWayPoints = 2;
int numSplines = 1;
WayPoint[] wayPoints;
Spline[] splines;
WayPoint selected = null;
boolean leftPressed = false, rightPressed = false, upPressed = false, downPressed = false;

void setup() {
  
  size(1000, 1000);
  ellipseMode(CENTER);
  rectMode(CORNER);
  wayPoints = new WayPoint[2];
  wayPoints[0] = new WayPoint(1, 1, 90, 10);
  wayPoints[1] = new WayPoint(9, 9, 0, 10);
  splines = new Spline[1];
  splines[0] = new Spline(wayPoints[0], wayPoints[1], 20);
  splines[0].update();
  //for(int i = 0; i < spline.numSegments; i++)
    //println(spline.endPoints[i][0] + ", " + spline.endPoints[i][1]);
  
}

void draw() {
  
  background(0);
  wayPoints[0].show();
  wayPoints[1].show();
  splines[0].update();
  splines[0].show();
  infoBox();
  if(selected != null) {
    if(leftPressed && !rightPressed)
      selected.setHeading(selected.getHeading() + 1);
    else if(rightPressed && !leftPressed)
      selected.setHeading(selected.getHeading() - 1);
  }
  if(upPressed && !downPressed && splines[0].numSegments < 100)
    splines[0].numSegments ++;
  else if(downPressed && !upPressed && splines[0].numSegments > 5)
    splines[0].numSegments --;
  
}

void mousePressed() {
  for(int i = 0; i < numWayPoints; i++) {
    wayPoints[i].setSelection(false);
    selected = null;
  }
  for(int i = 0; i < numWayPoints; i++) {
    if(dist(mouseX, mouseY, wayPoints[i].getX()*SCALE, 1000-wayPoints[i].getY()*SCALE) <= 15) {
      wayPoints[i].setSelection(true);
      selected = wayPoints[i];
      break;
    }
  }
}

void mouseDragged() {
  if(selected != null) {
    selected.setX(mouseX / SCALE);
    selected.setY((1000-mouseY) / SCALE);
  }
}

void infoBox() {
  if(mouseButton == 0) {
    for(Spline i: splines) {
      for(int j = 0; j < i.numSegments+1; j++) {
          if(dist(mouseX, mouseY, i.endPoints[j].x*SCALE, 1000-i.endPoints[j].y*SCALE) <= 10) {
            //highlighting the endPoint
            fill(255, 0, 0);
            stroke(255);
            strokeWeight(2);
            ellipse(i.endPoints[j].x*SCALE, 1000-i.endPoints[j].y*SCALE, 10, 10);
            //info box
            fill(0, 255, 255);
            rect((i.endPoints[j].x+0.1)*SCALE, 1000-(i.endPoints[j].y-0.1)*SCALE, 2*SCALE, 1*SCALE);
            textSize(15);
            fill(0);
            text("x: " + i.endPoints[j].x, (i.endPoints[j].x+0.13)*SCALE, 1000-(i.endPoints[j].y-0.25)*SCALE);
            text("y: " + i.endPoints[j].y, (i.endPoints[j].x+0.13)*SCALE, 1000-(i.endPoints[j].y-0.40)*SCALE);
            text("vel: " + i.endPoints[j].vel, (i.endPoints[j].x+0.13)*SCALE, 1000-(i.endPoints[j].y-0.55)*SCALE);
            text("heading: " + i.endPoints[j].heading*180/PI, (i.endPoints[j].x+0.13)*SCALE, 1000-(i.endPoints[j].y-0.70)*SCALE);
            text("curvature: " + abs(i.endPoints[j].curvature), (i.endPoints[j].x+0.13)*SCALE, 1000-(i.endPoints[j].y-0.85)*SCALE);
            text("radius: " + i.endPoints[j].radius, (i.endPoints[j].x+0.13)*SCALE, 1000-(i.endPoints[j].y-1)*SCALE);
            //drawing the circle that is being followed
            float centerX, centerY;
            float tempAngle = i.endPoints[j].heading + PI/2;
            centerX = 1 / i.endPoints[j].curvature * cos(tempAngle) + i.endPoints[j].x;
            centerY = 1 / i.endPoints[j].curvature * sin(tempAngle) + i.endPoints[j].y;
            stroke(255, 255, 0);
            strokeWeight(1);
            noFill();
            arc(centerX*SCALE, 1000-centerY*SCALE, i.endPoints[j].diameter*SCALE, i.endPoints[j].diameter*SCALE, 0, 2*PI);
            break;
          }
      }
    }
  }
}

void keyPressed() {
  if(keyCode == LEFT)
    leftPressed = true;
  if(keyCode == RIGHT)
    rightPressed = true;
  if(keyCode == UP)
    upPressed = true;
  if(keyCode == DOWN)
    downPressed = true;
}

void keyReleased() {
  if(keyCode == LEFT)
    leftPressed = false;
  if(keyCode == RIGHT)
    rightPressed = false;
  if(keyCode == UP)
    upPressed = false;
  if(keyCode == DOWN)
    downPressed = false;
}


class WayPoint {
  
  float x, y, vel;
  float heading;
  boolean selected;
  
  public WayPoint(float x_, float y_, float heading_, float vel_) {
      x= x_;
      y= y_;
      heading = heading_;
      vel = vel_;
      selected = false;
  }
  
  public void show() {
    stroke(0);
    if(selected) {
      fill(255);
      ellipse(x*SCALE, 1000-y*SCALE, 25, 25);
    }
    fill(255, 0, 0);
    ellipse(x*SCALE, 1000-y*SCALE, 15, 15);
  }
  
  public void setX(float newX) {
    x = newX;
  }
  
  public float getX() {
    return x;
  }
  
  public void setY(float newY) {
    y = newY;
  }
  
  public float getY() {
    return y;
  }
  
  public void setHeading(float newHeading) {
    heading = newHeading;
  }
  
  public float getHeading() {
    return heading;
  }
  
  public float getHeadingRad() {
    return heading * PI / 180;
  }
  
  public float getVel() {
    return vel;
  }
  
  public void setSelection(boolean rcv) {
    selected = rcv;
  }
  
  public boolean isSelected() {
    return selected;
  }
  
}

class EndPoint {
  
  float x, y, heading;
  float vel;
  float curvature, radius;
  float diameter;
  
  public EndPoint(float x_, float y_, float heading_, float vel_, float curvature_) {
    x = x_;
    y = y_;
    curvature = curvature_;
    vel = vel_;
    heading = heading_;
    radius = curvature == 0 ? 0 : 1/abs(curvature);
    diameter = 2 * radius;
  }
  
}

class Spline {
  
  WayPoint start, end;
  float a, b, c, d;
  float i, j, k, l;
  int numSegments;
  EndPoint[] endPoints;
  
  public Spline(WayPoint start_, WayPoint end_, int numSegments_) {
    start = start_;
    end = end_;
    numSegments = numSegments_;
  }
  
  public Spline(WayPoint start_, WayPoint end_) {
    start = start_;
    end = end_;
    numSegments = 10;
  }
  
  public void update() {
    a = start.getVel() * cos(start.getHeadingRad()) + end.getVel() * cos(end.getHeadingRad()) + 2 * start.getX() - 2 * end.getX();
    b = -2 * start.getVel() * cos(start.getHeadingRad()) - end.getVel() * cos(end.getHeadingRad()) - 3 * start.getX() + 3 * end.getX();
    c = start.getVel() * cos(start.getHeadingRad());
    d = start.getX();
    
    i = start.getVel() * sin(start.getHeadingRad()) + end.getVel() * sin(end.getHeadingRad()) + 2 * start.getY() - 2 * end.getY();
    j = -2 * start.getVel() * sin(start.getHeadingRad()) - end.getVel() * sin(end.getHeadingRad()) - 3 * start.getY() + 3 * end.getY();
    k = start.getVel() * sin(start.getHeadingRad());
    l = start.getY();
    
    endPoints = new EndPoint[numSegments+1];
    float t, x, y, heading, vel, curvature;
    float x_, y_, x__, y__;
    for(int n = 0; n <= numSegments; n++) {
      t = (float)n / (float)numSegments;
      x = a*t*t*t + b*t*t + c*t + d;
      y = i*t*t*t + j*t*t + k*t + l;
      x_ = 3*a*t*t + 2*b*t + c;
      y_ = 3*i*t*t + 2*j*t + k;
      x__ = 6*a*t + 2*b;
      y__ = 6*i*t + 2*j;
      heading = atan2(y_, x_);
      vel = sqrt(x_*x_ + y_*y_);
      curvature = (x_*y__ - y_*x__) / pow((x_*x_ + y_*y_), 1.5);
      endPoints[n] = new EndPoint(x, y, heading, vel, curvature);
    }
  }
  
  public void show() {
    //println(a + " | " + b + " | " + c + " | " + d + " || " + i + " | " + j + " | " + k + " | " + l);
    stroke(5);
    for(int i = 0; i < numSegments; i++) {
      fill(255);
      stroke(255);
      if(i > 0)
        ellipse(endPoints[i].x*SCALE, 1000-endPoints[i].y*SCALE, 5, 5);
      stroke(200, 0, 0);
      strokeWeight(3);
      line(endPoints[i].x*SCALE, 1000-endPoints[i].y*SCALE, endPoints[i+1].x*SCALE, 1000-endPoints[i+1].y*SCALE);
    }
  }
  
}
