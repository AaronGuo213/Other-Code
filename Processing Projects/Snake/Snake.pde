int scl = 40;
boolean eaten = false;
snake boi;
food eatme;

void setup() {
  size(800, 800);
  rectMode(CENTER);
  frameRate(10);
  boi = new snake(420, 420, 0, -1);
  eatme = new food();
  eatme.place();
}

void draw() {
  background(0, 100, 50);
  boi.update();
  eatme.show();
  boi.show();
  if(boi.death()) {
    boi.total = 0;
    boi.x = 420;
    boi.y = 420;
  }
}

class snake {
  
  int x, y;
  int xVel, yVel;
  int total = 0;
  IntList tailx = new IntList();
  IntList taily = new IntList();
  
  snake(int xPos, int yPos, int xV, int yV) {
    x = xPos;
    y = yPos;
    xVel = xV;
    yVel = yV;
  }
  
  void update() {
    if(dist(boi.x, boi.y, eatme.xFood, eatme.yFood) == 0) {
      boi.total ++;
      eatme.place();
      tailx.append(x);
      taily.append(y);
      eaten = true;
    }
    
    if(eaten == false) {
      for(int i = 0; i < total - 1; i++) {
        tailx.set(i, tailx.get(i + 1));
        taily.set(i, taily.get(i + 1));
      }
      if(total > 0) {
        tailx.set(total - 1, boi.x);
        taily.set(total - 1, boi.y);
      }
    }
    else
      eaten = false;
    
    x += xVel * scl;
    y += yVel * scl;
  }
  
  void show() {
    fill(255);
    for(int i = 0; i < total; i ++)
      rect(tailx.get(i), taily.get(i), scl, scl);
    rect(x, y, scl, scl);
  }
  
  void direction(int x, int y) {
    xVel = x;
    yVel = y;
  }
  
  boolean death() {
    for(int i = 0; i < total; i ++) {
      if(x == tailx.get(i) && y == taily.get(i))
        return true;
    }
    
    if(x < 0 || x > 800 || y < 0 || y > 800)
      return true;
    else 
      return false;
  }
  
}

class food {
  
  int clms, rows;
  int xFood, yFood;
  
  void place() {
    clms = height / scl - 1;
    rows = width / scl - 1;
    
    xFood = floor(random(clms)) * scl + 20;
    yFood = floor(random(clms)) * scl + 20;
    
  }
  
  void show() {
    fill(200, 200, 0);
    rect(xFood, yFood, scl / 2, scl / 2);
  }
 
}

void keyPressed() {
  if(keyCode == UP)
    boi.direction(0, -1);
  else if(keyCode == DOWN)
    boi.direction(0, 1);
  else if(keyCode == LEFT)
    boi.direction(-1, 0);
  else if(keyCode == RIGHT)
    boi.direction(1, 0);
}
