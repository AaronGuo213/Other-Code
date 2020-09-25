import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Pool extends PApplet {

Ball ball[];
Player p1, p2, currentPlayer, winner;
boolean ballsMadeThisRound[], ballsMade[];
float lastCueAngle, cueDist, cueBallPwr, lockedX, lockedY;
boolean angleLocked = false, scratched = false;
PImage cue;
public enum State {
  running,
  breaking,
  turn,
  adv
}
State currentState = State.breaking;
public enum Type {
  solid,
  stripe,
  eight,
  cue,
  undetermined
}
Type firstBallHit = Type.undetermined;
float ballPos[][] = {
  {656, 256}, 
  {256, 256}, 
  {256 - 9*sqrt(3), 247}, 
  {256 - 27*sqrt(3), 265},
  {256 - 36*sqrt(3), 238}, 
  {256 - 18*sqrt(3), 274}, 
  {256 - 27*sqrt(3), 229},
  {256 - 36*sqrt(3), 292},
  {256 - 18*sqrt(3), 256},
  {256 - 27*sqrt(3), 283},
  {256 - 36*sqrt(3), 220},
  {256 - 9*sqrt(3), 265},
  {256 - 18*sqrt(3), 238},
  {256 - 36*sqrt(3), 256},
  {256 - 36*sqrt(3), 274},
  {256 - 27*sqrt(3), 247}
};

public void setup() {
  background(50, 130, 50);
  
  frameRate(120);
  ball = new Ball[16];
  ballsMadeThisRound = new boolean[16];
  ballsMade = new boolean[16];
  p1 = new Player();
  p2 = new Player();
  currentPlayer = p1;
  for(int i = 0; i <= 15; i++) {
    ball[i] = new Ball(i, ballPos[i][0], ballPos[i][1]);
  }
  ball[0].xVel = 0;
  ball[0].yVel = 0;
  cue = loadImage("pool cue 2.png");
}

public void draw() {
  background(50, 130, 50);
  drawTable();
  ball[0].update();
  ball[0].show();
  for(int i = 1; i <= 15; i++) {
    ball[i].update();
    ball[i].show();
  }
  if(currentState == State.turn)
    runTurn();
  else if(currentState == State.running)
    runUpdate();
  else if(currentState == State.adv)
    runAdv(false);
  if(currentState == State.breaking)
    runAdv(true);
}

public void drawTable() {
  rectMode(CENTER);
  fill(170, 100, 0);
  rect(456, 256, 912, 512);
  fill(50, 130, 50);
  rect(456, 256, 830, 430);
  fill(75, 195, 75);
  rect(456, 256, 800, 400);
  ellipseMode(CENTER);
  fill(0);
  ellipse(56, 56, 40, 40);
  ellipse(856, 56, 40, 40);
  ellipse(856, 456, 40, 40);
  ellipse(56, 456, 40, 40);
  ellipse(456, 50, 40, 40);
  ellipse(456, 462, 40, 40);
  textSize(30);
  if(currentPlayer == p2) {
    fill(0);
    text("Player 1", 200, 550);
    fill(255, 0, 0);
    text("Player 2", 600, 550);
  }
  else {
    fill(255, 0, 0);
    text("Player 1", 200, 550);
    fill(0);
    text("Player 2", 600, 550);
  }
}

public void drawCue(float dist, float cueAngle) {
  imageMode(CENTER);
  rectMode(CENTER);
  float x, y;
  float centerX = ball[0].x;
  float centerY = ball[0].y;
  float ballAngle = atan2(centerY, centerX);
  float theta = ballAngle - cueAngle;
  float d = sqrt(centerX * centerX + centerY * centerY);
  rotate(cueAngle);
  x = d * cos(theta) + dist;
  y = d * sin(theta) + 5;
  image(cue, x, y);
  fill(255);
  rect(x + 270 + 500, y - 5, 1000, 2);
  rotate(-cueAngle);
}

public class Ball {
  
  /*static int solidsLeft;
  static int stripesLeft;*/
  
  boolean scored;
  Type ballType;
  int number; //0 is cue
  float d = 18;
  float x, y, xVel, yVel;
  int rColor, gColor, bColor;
  
  public Ball(int theNum, float theX, float theY) {
    scored = false;
    number = theNum;
    if(number > 8)
      ballType = Type.stripe;
    else if(number == 8)
      ballType = Type.eight;
    else if(number > 0)
      ballType = Type.solid;
    else
      ballType = Type.cue;
    x = theX;
    y = theY;
    xVel = 0;
    yVel = 0;
    getColor();
  }
  
  public void show() {
    fill(rColor, gColor, bColor);
    ellipse(x, y, d, d);
    if(ballType == Type.eight || ballType == Type.stripe) {
      fill(255);
      ellipse(x, y, 12, 12);
    }
    textSize(8);
    fill(0);
    if(number > 9)
      text(number, x - 5, y + 4);
    else if(number > 0)
      text(number, x - 2, y + 4);
  }
  
  public void update() {
    if(scored) {
      x = (912 / 16) * number;
      y = 580;
    }
    
    else {
      //updating position, velocity, and accel
      x += xVel;
      y += yVel;
      xVel -= xVel / 200;
      yVel -= yVel / 200;
      if(abs(xVel) < 0.05f && abs(yVel) < 0.05f)
        xVel = yVel = 0;
      
      //if hitting a rail
      if(x - d/2 <= 56) {
        xVel *= -1;
        x = 56 + d/2;
      }
      if(x + d/2 >= 856) {
        xVel *= -1;
        x = 856 - d/2;
      }
      if(y - d/2 <= 56) {
        yVel *= -1;
        y = 56 + d/2;
      }
      if(y + d/2 >= 456) {
        yVel *= -1;
        y = 456 - d/2;
      }
        
      //if landing in a pocket
      if(dist(x, y, 56, 56) <= 20 || dist(x, y, 856, 56) <= 20 || dist(x, y, 856, 456) <= 20 || dist(x, y, 56, 456) <= 20 || dist(x, y, 456, 462) <= 20 || dist(x, y, 456, 50) <= 20) {
        scored = true;
        ballsMade[number] = true;
        ballsMadeThisRound[number] = true;
      }
    }
  }
  
  private void getColor() {
    int newNum = number > 8 ? number - 8 : number;
      
    if(newNum == 0 || newNum == 1 || newNum == 3 || newNum == 5)
      rColor = 255;
    else if(newNum == 2 || newNum == 6 || newNum == 8)
      rColor = 0;
    else
      rColor = newNum == 4 ? 102 : 153;
      
    if(newNum < 2)
      gColor = 255;
    else if(newNum == 5)
      gColor = 153;
    else if(newNum == 6)
      gColor = 102;
    else
      gColor = 0;
      
    if(newNum == 0 || newNum == 2)
      bColor = 255;
    else if(newNum == 4)
      bColor = 204;
    else 
      bColor = 0;
  }
  
};

public class Player {
  
  Type myType;
  
  public Player() {
    myType = Type.undetermined;
  }
  
  public void updateType(int solidsMade, int stripesMade, boolean scratched) {
    boolean ballsLeft = false;
    if(myType == Type.undetermined) {
      if(solidsMade > 0 && stripesMade == 0 && !scratched)
        myType = Type.solid;
      else if(solidsMade == 0 && stripesMade > 0 && !scratched)
        myType = Type.stripe;
    }
    if(myType == Type.solid) {
      for(int i = 1; i < 8; i++) {
        if(ballsMade[i] == false)
          ballsLeft = true;
      }
      if(!ballsLeft)
        myType = Type.eight;
    }
    else if(myType == Type.stripe) {
      for(int i = 9; i < 16; i++) {
        if(ballsMade[i] == false)
          ballsLeft = true;
      }
      if(!ballsLeft)
        myType = Type.eight;
    }
    
    if(p1.myType == Type.solid)
      p2.myType = Type.stripe;
    else if(p1.myType == Type.stripe)
      p2.myType = Type.solid;
    else if(p2.myType == Type.solid)
      p2.myType = Type.stripe;
    else if(p2.myType == Type.stripe)
      p2.myType = Type.solid;
  }
  
};

public boolean detectCollision(Ball a, Ball b) {
  if(a.xVel - b.xVel == 0 && a.yVel - b.yVel == 0)
    return false;
  if(dist(a.x, a.y, b.x, b.y) <= a.d) {
    float thetaC = atan2(b.y-a.y, b.x-a.x);
    float thetaV = atan2(a.yVel - b.yVel, a.xVel - b.xVel);
    //println(thetaC * 180 / PI + " | " + thetaV * 180 / PI + " | " + abs(thetaC - thetaV) * 180 / PI);
    if(abs(thetaC - thetaV) <= PI/2 || abs(thetaC - thetaV) >= 3*PI/2)
      return true;
  }
  return false;
}

public void collide(Ball a, Ball b) {
  float vxi, vyi, v, aVel, bVel;
  float thetaC, thetaV, thetaF, thetaA;
  vxi = a.xVel - b.xVel;
  vyi = a.yVel - b.yVel;
  v = sqrt((float)(Math.pow(vxi, 2) + Math.pow(vyi, 2)));
  thetaC = atan2(b.y-a.y, b.x-a.x);
  thetaV = atan2(vyi, vxi);
  thetaF = PI/2 - abs(thetaC - thetaV);
  thetaA = thetaC >= thetaV ? thetaC - PI/2 : thetaC + PI/2;
  aVel = v * cos(thetaF);
  bVel = v * sin(thetaF);
  //println(thetaC * 180 / PI + " | " + thetaV * 180 / PI + " | " + thetaF * 180 / PI + " | " + thetaA * 180 / PI);
  //println(aVel + " | " + bVel);
  a.xVel = aVel * cos(thetaA) + b.xVel;
  a.yVel = aVel * sin(thetaA) + b.yVel;
  b.xVel = bVel * cos(thetaC) + b.xVel;
  b.yVel = bVel * sin(thetaC) + b.yVel;
}

public void runAdv(boolean isABreak) {
  ball[0].scored = false;
  ball[0].x = mouseX;
  ball[0].y = mouseY;
  if(isABreak && ball[0].x <= 656 + ball[0].d / 2)
    ball[0].x = 656 + ball[0].d / 2;
  if(ball[0].x - ball[0].d/2 <= 56) {
      ball[0].x = 56 + ball[0].d/2;
  }
  if(ball[0].x + ball[0].d/2 >= 856) {
    ball[0].x = 856 - ball[0].d/2;
  }
  if(ball[0].y - ball[0].d/2 <= 56) {
    ball[0].y = 56 + ball[0].d/2;
  }
  if(ball[0].y + ball[0].d/2 >= 456) {
    ball[0].y = 456 - ball[0].d/2;
  }
  if(mousePressed)
    if(!(dist(ball[0].x, ball[0].y, 56, 56) <= 20 || dist(ball[0].x, ball[0].y, 856, 56) <= 20 || dist(ball[0].x, ball[0].y, 856, 456) <= 20 || dist(ball[0].x, ball[0].y, 56, 456) <= 20 || dist(ball[0].x, ball[0].y, 456, 462) <= 20 || dist(ball[0].x, ball[0].y, 456, 50) <= 20))
      currentState = State.turn;
}

public void runTurn() {
  float cueBallXVel, cueBallYVel;
  if(!mousePressed) {
    if(!angleLocked) {
      lastCueAngle = atan2(ball[0].y - mouseY, ball[0].x - mouseX);
    }
    else {
      if(cueBallPwr == 0) {
        angleLocked = false;
      }
      cueBallXVel = cueBallPwr * cos(lastCueAngle);
      cueBallYVel = cueBallPwr * sin(lastCueAngle);
      cueDist -= cueBallPwr;
      if(cueDist <= -7) {
        ball[0].xVel = cueBallXVel;
        ball[0].yVel = cueBallYVel;
        currentState = State.running;
        angleLocked = false;
        cueDist = 0;;
      }
    }
  }
  else if(mousePressed) {
    if(!angleLocked) {
      lockedX = mouseX;
      lockedY = mouseY;
    }
    angleLocked = true;
    cueDist = sqrt((float)(Math.pow(mouseX - lockedX, 2) + Math.pow(mouseY - lockedY, 2))); //gets distance moved back
    cueDist *= cos(lastCueAngle - atan2(lockedY - mouseY, lockedX - mouseX)); //finds component in the direction parallel to cue
    cueDist = cueDist < 0 ? 0 : cueDist;
    cueDist = cueDist > 200 ? 200 : cueDist;
    cueBallPwr = cueDist / 15;
  }
  drawCue(-270 - cueDist, lastCueAngle);
}

public void runUpdate() {
  for(int a = 0; a <= 15; a++) {
    if(!ball[a].scored) {
      for(int b = a + 1; b <= 15; b++) {
        if(!ball[b].scored && detectCollision(ball[a], ball[b])) {
          //println(a + " | " + b);
          collide(ball[a], ball[b]);
          if(a == 0 && firstBallHit == Type.undetermined) {
            if(b > 8)
              firstBallHit = Type.stripe;
            else if(b == 8)
              firstBallHit = Type.eight;
            else if(b > 0)
              firstBallHit = Type.solid;
          }
        }
      }
    }
  }
  boolean allStopped = true;
  for(int i = 0; i <= 15; i++) {
    if((ball[i].xVel != 0 || ball[i].yVel != 0) && !ball[i].scored) {
      allStopped = false;
    }
  }
  if(allStopped) {
    endRound();
  }
}

public void endRound() {
  boolean eightMade = false, cueMade = false, scratched = false, canCont = false;
  int stripesMade = 0, solidsMade = 0;
  for(int i = 0; i < 16; i++) { //counts all of each ball scored
    if(ballsMadeThisRound[i]) {
      if(i > 8)
        stripesMade ++;
      else if(i == 8)
        eightMade = true;
      else if(i > 0)
        solidsMade ++;
      else if(i == 0)
        cueMade = true;
    }
  }
  
  if(cueMade) {
    scratched = true;
    ball[0].scored = false;
  }
  if(firstBallHit == Type.undetermined)
    scratched = true;
  else if(currentPlayer.myType == Type.undetermined && firstBallHit == Type.eight)
    scratched = true;
  else if(currentPlayer.myType != Type.undetermined && firstBallHit != currentPlayer.myType)
    scratched = true;
  if(currentPlayer.myType == Type.solid && stripesMade > 0)
    scratched = true;
  else if(currentPlayer.myType == Type.stripe && solidsMade > 0)
    scratched = true;
    
  if(eightMade) {
    if(currentPlayer.myType == Type.eight && !scratched)
      winner = currentPlayer;
    else
      winner = currentPlayer == p1 ? p2 : p1;
  }
  
  if((currentPlayer.myType == Type.solid || currentPlayer.myType == Type.undetermined) && solidsMade > 0)
    canCont = true;
  else if((currentPlayer.myType == Type.stripe || currentPlayer.myType == Type.undetermined) && stripesMade > 0)
    canCont = true;
    
  if(currentPlayer.myType == Type.undetermined)
    currentPlayer.updateType(solidsMade, stripesMade, scratched);
     
  if(scratched) {
    currentPlayer = currentPlayer == p1 ? p2 : p1;
    currentState = State.adv;
  }
  
  else {
    if(!canCont)
      currentPlayer = currentPlayer == p1 ? p2 : p1;
    currentState = State.turn;
  }
  
  if(currentPlayer.myType == Type.undetermined)
    println("undetermined");
  else if(currentPlayer.myType == Type.solid)
    println("solid");
  else if(currentPlayer.myType == Type.stripe)
    println("stripe");
  else if(currentPlayer.myType == Type.eight)
    println("eight");
  if(canCont)
    print("Can Continue | ");
  else
    print("Cannot Continue | ");
  if(scratched)
    println("Scratched");
  else
    println("No Scratch");
  if(currentPlayer == p1)
    println("Player 1's Turn\n");
  else
    println("Player 2's Turn\n");
    
  for(int i = 0; i < 16; i++) { //resets the new round
    ballsMadeThisRound[i] = false;
  }
  firstBallHit = Type.undetermined;
}
  public void settings() {  size(912, 612); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Pool" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
