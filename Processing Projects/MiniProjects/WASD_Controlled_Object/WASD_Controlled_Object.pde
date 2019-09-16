boi Aaron;
boolean[] Key;

void setup() {
  size(800, 800);
  ellipseMode(CENTER);
  Aaron = new boi(400, 400);
  Key = new boolean[4];
}

void draw() {
  background(0, 200, 50);
  Aaron.update();
  Aaron.show();
}

void keyPressed() {
  if(key == 'w')
    Key[0] = true;
  if(key == 'a')
    Key[1] = true;
  if(key == 's')
    Key[2] = true;
  if(key == 'd')
    Key[3] = true;
}

void keyReleased() {
  if(key == 'w')
    Key[0] = false;
  if(key == 'a')
    Key[1] = false;
  if(key == 's')
    Key[2] = false;
  if(key == 'd')
    Key[3] = false;
}



class boi {
  
  int x, y;
  int xVel, yVel;
  
  
  boi(int posx, int posy) {
    x = posx;
    y = posy;
  }
  
  
  void update() {
    if(Key[0] && Key[2])
      yVel = 0;
    else if(Key[0])
      yVel = -5;
    else if(Key[2])
      yVel = 5;
    else
      yVel = 0;
    
    if(Key[1] && Key[3])
      xVel = 0;
    else if(Key[1])
      xVel = -5;
    else if(Key[3])
      xVel = 5;
    else
      xVel = 0;
      
    x += xVel;
    y += yVel;
  }
  
  
  void show() {
    fill(180, 50, 10);
    ellipse(x, y, 40, 40);
  }
  
}
