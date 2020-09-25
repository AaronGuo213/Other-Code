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

public class Velocity_Selector extends PApplet {

boolean options = false, particleField;
boolean particleClicked = false, fieldClicked = false, exitClicked;
boolean reset = false, goal = false;
boolean massPlusClicked, massMinusClicked, chargePlusClicked, chargeMinusClicked, speedPlusClicked, speedMinusClicked;
boolean EFieldUpClicked, EFieldDownClicked, EFieldPlusClicked, EFieldMinusClicked;
boolean BFieldInClicked, BFieldOutClicked, BFieldPlusClicked, BFieldMinusClicked;
float EField = 0, EFieldDir = 1;
float BField = 0, BFieldDir = -1;
float initMass = 10, initCharge = 0, initSpeed = 0;
particle dog;

public void setup() {
  
  background(0, 100, 100);
  ellipseMode(CENTER);
  rectMode(CENTER);
  textAlign(CENTER);
  frameRate(60);
  dog = new particle(initCharge, initMass, initSpeed);
}

public void draw() {
  background(0, 100, 100);
  fill(0, 150, 0);
  rect(400, 400, 800, 200);
  if(!options)
    dog.update();
  dog.show();
  textSize(50);
  fill(200, 0, 0);
  text("Velocity Selector", 400, 790);
  options();
  reset();
}

public void mousePressed() {
  if(mouseX > 0 && mouseX < 350 && mouseY > 0 && mouseY < 50)
    particleClicked = true;
  else if(mouseX > 450 && mouseX < 800 && mouseY > 0 && mouseY < 50)
    fieldClicked = true;
    
  if(options) {
    if((mouseX > 620 && mouseX < 650 && mouseY > 50 && mouseY < 80) || !(mouseX > 150 && mouseX < 650 && mouseY > 50 && mouseY < 750))
      exitClicked = true;
  }
    
  if(options && !particleField) {
    if(mouseX > 500 && mouseX < 550 && mouseY > 150 && mouseY < 200)
      massPlusClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 200 && mouseY < 250)
      massMinusClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 350 && mouseY < 400)
      chargePlusClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 400 && mouseY < 450)
      chargeMinusClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 550 && mouseY < 600)
      speedPlusClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 600 && mouseY < 650)
      speedMinusClicked = true;
  }
  
  else if(options && particleField) {
    if(mouseX > 500 && mouseX < 550 && mouseY > 190 && mouseY < 225)
      EFieldUpClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 225 && mouseY < 260)
      EFieldDownClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 260 && mouseY < 295)
      EFieldPlusClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 295 && mouseY < 330)
      EFieldMinusClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 470 && mouseY < 505)
      BFieldInClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 505 && mouseY < 540)
      BFieldOutClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 540 && mouseY < 575)
      BFieldPlusClicked = true;
    if(mouseX > 500 && mouseX < 550 && mouseY > 575 && mouseY < 610)
      BFieldMinusClicked = true;
  }
}

public void mouseReleased() {
  if(mouseX > 0 && mouseX < 350 && mouseY > 0 && mouseY < 50 && particleClicked) {
    options = true;
    particleField = false;
  }
  else if(mouseX > 450 && mouseX < 800 && mouseY > 0 && mouseY < 50 && fieldClicked) {
    options = true;
    particleField = true;
  }
  particleClicked = false;
  fieldClicked = false;
  
  if(options) {
    if((mouseX > 620 && mouseX < 650 && mouseY > 50 && mouseY < 80) || !(mouseX > 150 && mouseX < 650 && mouseY > 50 && mouseY < 750) && exitClicked) {
      options = false;
      exitClicked = false;
      reset = true;
    }
  }
  
  if(options && !particleField) {
    if(mouseX > 500 && mouseX < 550 && mouseY > 150 && mouseY < 200 && massPlusClicked && initMass < 20)
      initMass ++;
    if(mouseX > 500 && mouseX < 550 && mouseY > 200 && mouseY < 250 && massMinusClicked && initMass > 1)
      initMass --;
    if(mouseX > 500 && mouseX < 550 && mouseY > 350 && mouseY < 400 && chargePlusClicked && initCharge < 20)
      initCharge ++;
    if(mouseX > 500 && mouseX < 550 && mouseY > 400 && mouseY < 450 && chargeMinusClicked && initCharge > -20)
      initCharge --;
    if(mouseX > 500 && mouseX < 550 && mouseY > 550 && mouseY < 600 && speedPlusClicked && initSpeed < 20)
      initSpeed ++;
    if(mouseX > 500 && mouseX < 550 && mouseY > 600 && mouseY < 650 && speedMinusClicked && initSpeed > 0)
      initSpeed --;
  }
  
  else if(options && particleField) {
    if(mouseX > 500 && mouseX < 550 && mouseY > 190 && mouseY < 225 && EFieldUpClicked)
      EFieldDir = -1;
    if(mouseX > 500 && mouseX < 550 && mouseY > 225 && mouseY < 260 && EFieldDownClicked)
      EFieldDir = 1;
    if(mouseX > 500 && mouseX < 550 && mouseY > 260 && mouseY < 295 && EFieldPlusClicked && EField < 20)
      EField ++;
    if(mouseX > 500 && mouseX < 550 && mouseY > 295 && mouseY < 330 && EFieldMinusClicked && EField > 0)
      EField --;
    if(mouseX > 500 && mouseX < 550 && mouseY > 470 && mouseY < 505 && BFieldInClicked)
      BFieldDir = -1;
    if(mouseX > 500 && mouseX < 550 && mouseY > 505 && mouseY < 540 && BFieldOutClicked)
      BFieldDir = 1;
    if(mouseX > 500 && mouseX < 550 && mouseY > 540 && mouseY < 575 && BFieldPlusClicked && BField < 20)
      BField ++;
    if(mouseX > 500 && mouseX < 550 && mouseY > 575 && mouseY < 610 && BFieldMinusClicked && BField > 0)
      BField --;
  }
}

public void options() {
  
  fill(200, 200, 0);
  rect(175, 25, 350, 50);
  rect(625, 25, 350, 50);
  fill(0);
  textSize(30);
  text("Particle Options", 175, 35);
  text("Field Options", 625, 35);
  
  if(options) {
    fill(40, 100, 160);
    rect(400, 400, 500, 700);
    if(!particleField) {
      fill(200, 200, 0);
      rect(400, 200, 300, 100);
      rect(400, 400, 300, 100);
      rect(400, 600, 300, 100);
      fill(0, 200, 50);
      rect(525, 175, 50, 50);
      rect(525, 225, 50, 50);
      rect(525, 375, 50, 50);
      rect(525, 425, 50, 50);
      rect(525, 575, 50, 50);
      rect(525, 625, 50, 50);
      fill(200, 0, 0);
      rect(635, 65, 30, 30);
      
      textSize(50);
      fill(150);
      text("Particle Options", 400, 135);
      textSize(30);
      fill(0);
      text("Mass: " + initMass + "E-10 kg", 375, 210);
      text("Charge: " + initCharge + " nC", 375, 410);
      text("Speed: " + initSpeed + " m/s", 375, 610);
      fill(200, 50, 0);
      text("+", 525, 185);
      text("+", 525, 585);
      text("+", 525, 385);
      fill(0, 50, 200);
      text("-", 525, 235);
      text("-", 525, 435);
      text("-", 525, 635);
    }
    
    else if(particleField) {
      fill(200, 200, 0);
      rect(400, 225, 300, 70);
      rect(400, 295, 300, 70);
      rect(400, 505, 300, 70);
      rect(400, 575, 300, 70);
      fill(0, 200, 50);
      rect(525, 207.5f, 50, 35);
      rect(525, 242.5f, 50, 35);
      rect(525, 277.5f, 50, 35);
      rect(525, 312.5f, 50, 35);
      rect(525, 487.5f, 50, 35);
      rect(525, 522.5f, 50, 35);
      rect(525, 557.5f, 50, 35);
      rect(525, 592.5f, 50, 35);
      fill(200, 0, 0);
      rect(635, 65, 30, 30);
      
      textSize(50);
      fill(150);
      text("Field Options", 400, 105);
      fill(0);
      text("Electric Field", 400, 165);
      text("Magnetic Field", 400, 445);
      textSize(30);
      if(EFieldDir == 1)
        text("E-Field: Down", 375, 235); 
      else if(EFieldDir == -1)
        text("E-Field: Up", 375, 235); 
      text("E-Field: " + EField + " N/C", 375, 305);
      if(BFieldDir == 1)
        text("B-Field: •", 375, 515);
      if(BFieldDir == -1)
        text("B-Field: x", 375, 515);
      text("B-Field: " + BField + " T", 375, 585);
      fill(200, 50, 0);
      text("+", 525, 217.5f);
      text("+", 525, 287.5f);
      text("+", 525, 497.5f);
      text("+", 525, 567.5f);
      fill(0, 50, 200);
      text("-", 525, 252.5f);
      text("-", 525, 322.5f);
      text("-", 525, 532.5f);
      text("-", 525, 602.5f);
    }
    
  }
  
}
  

class particle {
  
  float x = 25, y = 400;
  float xVel, yVel, theta;
  float charge, mass;
  float EForce, BForce;
  float yForce, xForce;
  float yAccel, xAccel;
  
  particle(float plusminus, float masss, float speed) {
    charge = plusminus;
    mass = masss;
    xVel = speed;
  }
  
  public void update() {
    theta = findTheta(xVel, yVel);
    EForce = ((charge * pow(10, -9)) * EField * EFieldDir);
    BForce = ((charge * pow(10, -9)) * sqrt(xVel * xVel + yVel * yVel) * BField * BFieldDir);
    yForce = EForce + BForce * cos(theta);
    xForce = BForce * sin(theta);
    yAccel = yForce / (mass * pow(10, -10));
    xAccel = xForce / (mass * pow(10 ,-10));
    
    yVel += yAccel / 60;
    xVel += xAccel / 60;
    y += yVel / 60 * 20;
    x += xVel / 60 * 20;
    
    if((y + mass) > 500 || (y - mass) < 300 || (x - mass) < 0)
      reset = true;
    else if((x - mass) > 800) {
      goal = true;
    }
  }
  
  public void show() {
    if(charge > 0)
      fill(200, 50, 0);
    else if(charge < 0)
      fill(0, 50, 200);
    else if(charge == 0)
      fill(0);
    ellipse(x, y, mass * 2, mass * 2);
    textSize(mass * 2);
    fill(0);
    if(charge > 0)
      text("+", x, y + mass / 1.7f);
    else if(charge < 0)
      text("-", x, y + mass / 1.7f);
  }
    
}

public void reset() {
  if(goal) {
    fill(200, 200, 0);
    textSize(200);
    text("GOAL!", 400, 400);
    goal = false;
    if(mousePressed)
      reset = true;
  }
  if(reset) {
    dog = new particle(initCharge, initMass, initSpeed);
    reset = false;
    dog.x = 25;
    dog.y = 400;
  }
}

public float findTheta(float xVel, float yVel) {
  float theta;
  if(!(xVel == 0) && xVel > 0) {
    theta = atan(yVel / xVel);
    if(theta > 0)
      theta = 2 * 3.14159f - theta;
    else if(theta < 0)
      theta = -theta;
  }
    
  else if(!(xVel == 0) && xVel < 0) {
    theta = atan(yVel / xVel);
    if(theta > 0) {
      theta -= 3.14159f;
      theta = -theta;
    }
    else if(theta < 0) {
      theta += 3.14159f;
      theta = 2 * 3.14159f - theta;
    }
  }
  else if(yVel > 0)
      theta = -90;   
  else if(yVel < 0)
      theta = 90;
  else
    theta = 0;
      
  return theta;
}
    
  public void settings() {  size(800, 800); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Velocity_Selector" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
