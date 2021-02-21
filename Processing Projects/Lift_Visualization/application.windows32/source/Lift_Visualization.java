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

public class Lift_Visualization extends PApplet {

float x0 = 200, y0 = 250, d;
float x, y;
float x1, y1, t1 = 0.5f, d1 = 100;
float x2, y2, t2 = 2, d2 = 70;
float theta1, theta2, thetaF;

public void setup() {
  
  background(0);
}

public void draw() {
  background(0);
  fill(255);
  
  // determining angles
  x = mouseX;
  y = mouseY;
  if(dist(x, y, x0, y0) >= d1-d2 && dist(x, y, x0, y0) <= d1+d2) {
    // finding best angle for arm 1
    float bestID = 0;
    float best = -1000;
    for(t1 = PI/2; t1 <= 5*PI/4; t1+=0.01f) {
      // tries every angle and chooses the one that could lead to the second arm reaching
      float xtry = x0 + d1 * cos(t1);
      float ytry = y0 - d1 * sin(t1);
      float dist = dist(xtry, ytry, x, y);
      if(abs(d2-dist) < 5) {
        best = dist;
        bestID = t1;
        break;
      }
    }
    if(bestID != 0)
      t1 = bestID;
    
    // finding best angle for arm 2
    bestID = 0;
    best = -1000;
    for(t2 = 0; t2 <= 2*PI; t2+=0.01f) {
      // looks for the best angle
      float xtry = x1 + d2 * cos(t2);
      float ytry = y1 - d2 * sin(t2);
      float dist = dist(xtry, ytry, x, y);
      if(abs(dist) < abs(best)) {
        best = dist;
        bestID = t2;
      }
    }
    t2 = bestID;
  }
  
  // calculations
  x1 = x0 + d1 * cos(t1);
  y1 = y0 - d1 * sin(t1);
  x2 = x1 + d2 * cos(t2);
  y2 = y1 - d2 * sin(t2);
  
  //drawing
  // base pivot
  ellipse(x0, y0, 20, 20);
  // arm 1
  theta1 = atan2(y0, x0);
  theta2 = -t1;
  d = sqrt(x0 * x0 + y0 * y0);
  thetaF = theta1 - theta2;
  rectMode(CENTER);
  rotate(theta2);
  rect(d * cos(thetaF) + d1/2, d * sin(thetaF), d1, 5);
  rotate(-theta2);
  // pivot 1
  ellipse(x1, y1, 20, 20);
  // arm 2
  theta1 = atan2(y1, x1);
  theta2 = -t2;
  d = sqrt(x1 * x1 + y1 * y1);
  thetaF = theta1 - theta2;
  rectMode(CENTER);
  rotate(theta2);
  rect(d * cos(thetaF) + d2/2, d * sin(thetaF), d2, 5);
  rotate(-theta2);
  // end of arm 2
  ellipse(x2, y2, 20, 20);
}
  public void settings() {  size(400, 400); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Lift_Visualization" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
