final float SCALE = 100;
final int FRAMERATE = 60;
final float MAX_VEL = 4, MAX_ACCEL = 3, VEL_CONST = 2;
int numSegments = 20;
int numWayPoints = 2;
int numSplines = 1;
ArrayList<WayPoint> wayPoints;
ArrayList<Spline> splines;
WayPoint selected = null;
boolean leftPressed = false, rightPressed = false, upPressed = false, downPressed = false, enterPressed = false;
boolean minusPressed = false, plusPressed = false, shiftPressed = false, lessPressed = false, morePressed = false;
boolean playing = false, enterAtck = false;
boolean backPressed = false, backAtck = false;
Robot robot;
float LookAheadDist = 0.3;

void setup() {
  
  size(1000, 1000);
  ellipseMode(CENTER);
  wayPoints = new ArrayList<WayPoint>();
  wayPoints.add(new WayPoint(1, 1, 90, 10)); //index 0
  wayPoints.add(new WayPoint(9, 9, 0, 10)); //index 0
  splines = new ArrayList<Spline>();
  splines.add(new Spline(wayPoints.get(0), wayPoints.get(1)));
  splines.get(0).update();
  frameRate(60);
  //for(int i = 0; i < spline.numSegments; i++)
    //println(spline.endPoints.get(i)[0] + ", " + spline.endPoints.get(i)[1]);
  
}

void draw() {
  
  background(0);
  for(int i = 0; i < numWayPoints; i++)
    wayPoints.get(i).show();
  for(int i = 0; i < numSplines; i++) {
    splines.get(i).update();
    splines.get(i).show();
  }
  infoBox();
  
  if(playing) {
    robot.show();
    robot.followPath();
  }
  
  else {
    if(selected != null) {
      if(leftPressed && !rightPressed)
        selected.setHeading(selected.getHeading() + 1);
      else if(rightPressed && !leftPressed)
        selected.setHeading(selected.getHeading() - 1);
      
      if(upPressed && !downPressed && selected.getTension() < 40)
        selected.setTension(selected.getTension() + 1);
      else if(downPressed && !upPressed && selected.getTension() > 5)
        selected.setTension(selected.getTension() - 1);
    }
    
    if(plusPressed && !minusPressed && numSegments < 100)
      numSegments ++;
    else if(minusPressed && !plusPressed && numSegments > 5)
      numSegments --;
      
    if(morePressed && !lessPressed && LookAheadDist < 1)
      LookAheadDist += 0.01;
    else if(lessPressed && !morePressed && LookAheadDist > 0.2)
      LookAheadDist -= 0.01;
      
    if(!backPressed)
      backAtck = false;
    else if(!backAtck) {
      backAtck = true;
      if(numSplines > 0) {
        splines.remove(numSplines-1);
        numSplines --;
        wayPoints.remove(numWayPoints-1);
        numWayPoints --;
      }
    }
      
    //shows lookahead circle
    noFill();
    strokeWeight(1);
    stroke(0, 100, 255);
    arc((wayPoints.get(0).getX())*SCALE, 1000-(wayPoints.get(0).getY())*SCALE, LookAheadDist*2*SCALE, LookAheadDist*2*SCALE, 0, 2*PI);
  }
    
  if(!enterPressed)
    enterAtck = false;
  else if(!enterAtck) {
    enterAtck = true;
    //robot = new Robot(splines.get(0), LookAheadDist);
    robot = new Robot(combineAll(splines), LookAheadDist);
    playing = !playing;
  }
  
  if(shiftPressed)
    frameRate(5);
  else
    frameRate(60);
  
}

void mousePressed() {
  for(int i = 0; i < numWayPoints; i++) {
    wayPoints.get(i).setSelection(false);
    selected = null;
  }
  for(int i = 0; i < numWayPoints; i++) {
    if(dist(mouseX, mouseY, wayPoints.get(i).getX()*SCALE, 1000-wayPoints.get(i).getY()*SCALE) <= 15) {
      wayPoints.get(i).setSelection(true);
      selected = wayPoints.get(i);
      break;
    }
  }
  if(mouseButton == RIGHT)
    addWayPoint();
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
      for(int j = 0; j < numSegments+1; j++) {
          if(dist(mouseX, mouseY, i.endPoints.get(j).x*SCALE, 1000-i.endPoints.get(j).y*SCALE) <= 10) {
            //highlighting the endPoint
            fill(255, 0, 0);
            stroke(255);
            strokeWeight(2);
            ellipse(i.endPoints.get(j).x*SCALE, 1000-i.endPoints.get(j).y*SCALE, 10, 10);
            //info box
            fill(0, 255, 255);
            rectMode(CORNER);
            rect((i.endPoints.get(j).x+0.1)*SCALE, 1000-(i.endPoints.get(j).y-0.1)*SCALE, 2*SCALE, 1*SCALE);
            textSize(15);
            fill(0);
            text("x: " + i.endPoints.get(j).x, (i.endPoints.get(j).x+0.13)*SCALE, 1000-(i.endPoints.get(j).y-0.25)*SCALE);
            text("y: " + i.endPoints.get(j).y, (i.endPoints.get(j).x+0.13)*SCALE, 1000-(i.endPoints.get(j).y-0.40)*SCALE);
            text("target vel: " + i.endPoints.get(j).vel, (i.endPoints.get(j).x+0.13)*SCALE, 1000-(i.endPoints.get(j).y-0.55)*SCALE);
            text("heading: " + i.endPoints.get(j).heading*180/PI, (i.endPoints.get(j).x+0.13)*SCALE, 1000-(i.endPoints.get(j).y-0.70)*SCALE);
            text("curvature: " + abs(i.endPoints.get(j).curvature), (i.endPoints.get(j).x+0.13)*SCALE, 1000-(i.endPoints.get(j).y-0.85)*SCALE);
            text("radius: " + i.endPoints.get(j).radius, (i.endPoints.get(j).x+0.13)*SCALE, 1000-(i.endPoints.get(j).y-1)*SCALE);
            break;
          }
      }
    }
  }
}

void addWayPoint() {
  wayPoints.add(new WayPoint(mouseX/SCALE, (1000-mouseY)/SCALE, 0, 10));
  numWayPoints ++;
  splines.add(new Spline(wayPoints.get(numWayPoints-2), wayPoints.get(numWayPoints-1)));
  numSplines ++;
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
  if(keyCode == ENTER)
    enterPressed = true;
  if(key == '-')
    minusPressed = true;
  if(key == '=')
    plusPressed = true;
  if(keyCode == SHIFT)
    shiftPressed = true;
  if(key == ',')
    lessPressed = true;
  if(key == '.')
    morePressed = true;
  if(keyCode == BACKSPACE)
    backPressed = true;
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
  if(keyCode == ENTER)
    enterPressed = false;
  if(key == '-')
    minusPressed = false;
  if(key == '=')
    plusPressed = false;
  if(keyCode == SHIFT)
    shiftPressed = false;
  if(key == ',')
    lessPressed = false;
  if(key == '.')
    morePressed = false;
  if(keyCode == BACKSPACE)
    backPressed = false;
}


class WayPoint {
  
  float x, y, tension;
  float heading;
  boolean selected;
  
  public WayPoint(float x_, float y_, float heading_, float tension_) {
      x= x_;
      y= y_;
      heading = heading_;
      tension = tension_;
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
  
  public void setTension(float newTension) {
    tension = newTension;
  }
  
  public float getTension() {
    return tension;
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
  
  public EndPoint(float x_, float y_, float heading_, float vel_, float curvature_) {
    x = x_;
    y = y_;
    curvature = curvature_;
    vel = vel_;
    heading = heading_;
    radius = curvature == 0 ? 0 : 1/abs(curvature);
  }
  
}

class Spline {
  
  WayPoint start, end;
  float a, b, c, d;
  float i, j, k, l;
  ArrayList<EndPoint> endPoints;
  float endVel = 0;
  
  public Spline(WayPoint start_, WayPoint end_) {
    start = start_;
    end = end_;
  }
  
  public void setEndVel(float endVel_) {
    endVel = endVel_;
  }
  
  public void update() {
    a = start.getTension() * cos(start.getHeadingRad()) + end.getTension() * cos(end.getHeadingRad()) + 2 * start.getX() - 2 * end.getX();
    b = -2 * start.getTension() * cos(start.getHeadingRad()) - end.getTension() * cos(end.getHeadingRad()) - 3 * start.getX() + 3 * end.getX();
    c = start.getTension() * cos(start.getHeadingRad());
    d = start.getX();
    
    i = start.getTension() * sin(start.getHeadingRad()) + end.getTension() * sin(end.getHeadingRad()) + 2 * start.getY() - 2 * end.getY();
    j = -2 * start.getTension() * sin(start.getHeadingRad()) - end.getTension() * sin(end.getHeadingRad()) - 3 * start.getY() + 3 * end.getY();
    k = start.getTension() * sin(start.getHeadingRad());
    l = start.getY();
    
    endPoints = new ArrayList<EndPoint>();
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
      curvature = (x_*y__ - y_*x__) / pow((x_*x_ + y_*y_), 1.5);
      vel = min(abs(VEL_CONST / curvature), MAX_VEL);
      endPoints.add(new EndPoint(x, y, heading, vel, curvature));
    }
    adjustVel();
  }
  
  private void adjustVel() {
    float segmentDist;
    endPoints.get(numSegments).vel = endVel;
    for(int i = numSegments-1; i >= 0; i--) {
      segmentDist = dist(endPoints.get(i).x, endPoints.get(i).y, endPoints.get(i+1).x, endPoints.get(i+1).y);
      endPoints.get(i).vel = min(endPoints.get(i).vel, sqrt(pow(endPoints.get(i+1).vel, 2) + 2*MAX_ACCEL*segmentDist));
    }
  }
  
  public void show() {
    //println(a + " | " + b + " | " + c + " | " + d + " || " + i + " | " + j + " | " + k + " | " + l);
    stroke(5);
    for(int i = 0; i < numSegments; i++) {
      fill(255);
      stroke(255);
      if(i > 0)
        ellipse(endPoints.get(i).x*SCALE, 1000-endPoints.get(i).y*SCALE, 5, 5);
      stroke(200, 0, 0);
      strokeWeight(3);
      line(endPoints.get(i).x*SCALE, 1000-endPoints.get(i).y*SCALE, endPoints.get(i+1).x*SCALE, 1000-endPoints.get(i+1).y*SCALE);
    }
  }
  
}

Spline combineAll(ArrayList<Spline> ArrL) {
  Spline rtn = new Spline(ArrL.get(0).start, ArrL.get(ArrL.size()-1).end);
  rtn.endPoints = new ArrayList<EndPoint>();
  for(int s = 0; s < ArrL.size(); s++) {
    for(int e = 0; e < numSegments; e++) {
      rtn.endPoints.add(ArrL.get(s).endPoints.get(e));
    }
  }
  rtn.endPoints.add(ArrL.get(ArrL.size()-1).endPoints.get(numSegments));
  return rtn;
}

class Robot {
  
  float x, y, heading, vel, lastVel = 0;
  int lastClosePointIndex;
  float lookAheadDist;
  float goalX, goalY;
  int lastGoalIndex = 0;
  float lastGoalT = 0;
  Spline path;
  
  public Robot(Spline newPath, float lookAheadDist_) {
    path = newPath;
    x = path.endPoints.get(0).x;
    y = path.endPoints.get(0).y;
    heading = path.endPoints.get(0).heading;
    lastClosePointIndex = 0;
    lookAheadDist = lookAheadDist_;
  }
  
  public void show() {
    float newX = x * SCALE, newY = 1000- y * SCALE;
    float plotX, plotY;
    float theta1, theta2, thetaF, d;
    theta1 = atan2(newY, newX);
    theta2 = -heading;
    d = sqrt(newX*newX + newY*newY);
    thetaF = theta1-theta2;
    rectMode(CENTER);
    noStroke();
    fill(150);
    rotate(theta2);
    plotX = d*cos(thetaF);
    plotY = d*sin(thetaF);
    rect(plotX, plotY, 20, 20);
    fill(0);
    stroke(0);
    strokeWeight(3);
    ellipse(plotX, plotY, 5, 5);
    rotate(-theta2);
    //shows lookahead circle
    noFill();
    strokeWeight(1);
    stroke(0, 100, 255);
    arc(x*SCALE, 1000-y*SCALE, lookAheadDist*2*SCALE, lookAheadDist*2*SCALE, 0, 2*PI);
  }
  
  public void followPath() {
    //shows the closest point
    fill(255);
    int closestPointIndex = closestPoint();
    fill(0, 255, 0);
    strokeWeight(3);
    stroke(0, 255, 0);
    ellipse(path.endPoints.get(closestPointIndex).x*SCALE, 1000-path.endPoints.get(closestPointIndex).y*SCALE, 5, 5);
    //finds and shows point of intersection btwn lookahead circle and path
    for(int i = (numSegments*numSplines)-1; i >=0; i--) {
      float intersection = findIntersection(i);
      if(intersection >= 0 && (i > lastGoalIndex || (i == lastGoalIndex && intersection >= lastGoalT))) { //makes sure the goal point is moving forward
        lastGoalIndex = i;
        lastGoalT = intersection;
        goalX = path.endPoints.get(i).x + (path.endPoints.get(i+1).x - path.endPoints.get(i).x)*intersection;
        goalY = path.endPoints.get(i).y + (path.endPoints.get(i+1).y - path.endPoints.get(i).y)*intersection;
        break;
      }
    }
    strokeWeight(3);
    stroke(0, 100, 255);
    fill(0, 100, 255);
    ellipse(goalX*SCALE, 1000-goalY*SCALE, 5, 5);
    //draws circle path that is to be followed
    float curvature = getCurvature();
    float radius = 1 / abs(curvature);
    float centerX, centerY;
    float radialAngle = heading + PI/2;
    centerX = -1 / curvature * cos(radialAngle) + x;
    centerY = -1 / curvature * sin(radialAngle) + y;
    stroke(255, 255, 0);
    strokeWeight(1);
    noFill();
    if(abs(curvature) < 0.01) {
      float angle = atan2(goalY-y, goalX-x);
      line((x-15*cos(angle))*SCALE, 1000-(y-15*sin(angle))*SCALE, (x+15*cos(angle))*SCALE, 1000-(y+15*sin(angle))*SCALE);
    }
    else
      arc(centerX*SCALE, 1000-centerY*SCALE, 1/abs(curvature)*2*SCALE, 1/abs(curvature)*2*SCALE, 0, 2*PI);
    //rate limiter
    vel = path.endPoints.get(closestPointIndex).vel;
    vel = lastVel + constrain(vel-lastVel, -MAX_ACCEL*2/FRAMERATE, MAX_ACCEL/FRAMERATE);
    lastVel = vel;
    //updates position and movement of the robot
    if(curvature != 0) { //arc movement
      float angleVel = vel / radius; //angular velocity = tangential velocity * radius
      float relativeAngle = curvature < 0 ? heading - PI/2 : heading + PI/2; //angle of robot position relative to the center of the circle
      boolean clockwise = curvature > 0;
      angleVel = abs(angleVel) * (clockwise ? -1 : 1);
      relativeAngle += angleVel / FRAMERATE;
      heading += angleVel / FRAMERATE;
      x = centerX + cos(relativeAngle) * radius;
      y = centerY + sin(relativeAngle) * radius;
    }
    else { //straight line movement
      x += vel * cos(heading);
      y += vel * sin(heading);
    }
    //if the velocity is 0, the robot has reached the end and path following ends
    if(vel == 0 && closestPointIndex != 0)
      playing = false;
  }
  
  private int closestPoint() {
    float closestDist;
    int index = lastClosePointIndex;
    closestDist = dist(x, y, path.endPoints.get(lastClosePointIndex).x, path.endPoints.get(lastClosePointIndex).y);
    for(int i = lastClosePointIndex+1; i <= numSegments*numSplines; i++) {
      if(dist(x, y, path.endPoints.get(i).x, path.endPoints.get(i).y) <= closestDist) {
        closestDist = dist(x, y, path.endPoints.get(i).x, path.endPoints.get(i).y);
        index = i;
      }
    }
    lastClosePointIndex = index;
    return index;
  }
  
  class Vector {
    float x, y;
    public Vector(float x1, float y1, float x2, float y2) {
      x = x2-x1;
      y = y2-y1;
    }
    public float dot(Vector v) {
      return x*v.x + y*v.y;
    }
  }
  
  private float findIntersection(int index) {
    float startX = path.endPoints.get(index).x, startY = path.endPoints.get(index).y, endX = path.endPoints.get(index+1).x, endY = path.endPoints.get(index+1).y;
    Vector d = new Vector(startX, startY, endX, endY);
    Vector f = new Vector(x, y, startX, startY);
    float a, b, c, discriminant, r = lookAheadDist;
    float t1, t2;
    a = d.dot(d);
    b = 2*f.dot(d);
    c = f.dot(f) - r*r;
    discriminant = b*b - 4*a*c;
    if(discriminant < 0)
      return -1;
    else {
      float rtn = -1;
      discriminant = sqrt(discriminant);
      t1 = (-b - discriminant) / (2*a);
      t2 = (-b + discriminant) / (2*a);
      if(t1 >= 0 && t1 <= 1) rtn = t1;
      if(t2 >= 0 && t2 <= 1) if(t2 > rtn) rtn = t2;
      return rtn;
    }
  }
  
  private float getCurvature() {
    float a, b, c, X, sign;
    a = -tan(heading);
    b = 1;
    c = tan(heading) * x - y;
    X = abs(a * goalX + b * goalY + c) / sqrt(a*a + b*b);
    sign = signum(sin(heading)*(goalX-x) - cos(heading)*(goalY-y));
    return 2*X / (lookAheadDist*lookAheadDist) * sign;
  }
  
  private float signum(float a) {
    if(a > 0) return 1;
    if(a < 0) return -1;
    return 0;
  }
  
  public void newPath(Spline newPath_) {
    path = newPath_;
  }
  
}
