boi p1;
boi p2;
bullet p1Bullet;
bullet p2Bullet;
boolean[] p1Key;
boolean[] p2Key;
boolean p1Load = true;
boolean p2Load = true;
boolean end = false;
boolean title = true;
boolean flashCnt = true;
int titleColor, endTimer = 0;
int winner = 0;

void setup() {
  size(800, 800);
  ellipseMode(CENTER);
  rectMode(CENTER);
  p1 = new boi(200, int(random(100, 650)), 1, 0);
  p2 = new boi(600, int(random(100, 650)), -1, 0);
  p1Key = new boolean[5];
  p2Key = new boolean[5];
}

void draw() {
  if(title) {
    background(0, 200, 50);
    fill(0, 100, 200);
    rect(400, 600, 400, 100);
    
    fill(titleColor);
    textSize(50);
    text("YOUR STANDARD", 200, 200);
    text("TWO PLAYER", 250, 300);
    text("SHOOTER GAME", 210, 400);
    
    textSize(20);
    text("(WASD R vs. IJKL P)", 310, 500);
    
    textSize(100);
    fill(255);
    text("PLAY", 282, 636);
    
    if(mousePressed) {
      if(mouseX > 200 && mouseX < 600 && mouseY > 550 && mouseY < 650) {
        title = false;
        p1 = new boi(200, int(random(100, 650)), 1, 0);
        p2 = new boi(600, int(random(100, 650)), -1, 0);
        p1Key = new boolean[5];
        p2Key = new boolean[5];
      }
      else {
        if(titleColor < 255)
          titleColor ++;
        else
          titleColor = 0;
      }
    }
  }
    
  else {
    background(0);
    fill(0, 200, 50);
    rect(400, 400, 750, 750);
    p1.update();
    p1.show();
    p1.shoot();
    p1.hit();
  }
  
  if(end && endTimer < 200) {
    background(0);
    textSize(100);
    if(flashCnt) {
      if(winner == 1)
        text("WASD Player", 100, 400);
      else if(winner == 2)
        text("IJKL Player", 100, 400);
      text("Wins!", 300, 600);
      flashCnt = false;
    }
    else 
      flashCnt = true;
    endTimer ++;
  }
  
  else if(endTimer == 200) {
    endTimer = 0;
    end = false;
    title = true;
  }
}

void keyPressed() {
  if(key == 'w')
    p1Key[0] = true;
  if(key == 'a')
    p1Key[1] = true;
  if(key == 's')
    p1Key[2] = true;
  if(key == 'd')
    p1Key[3] = true;
  if(key == 'r')
    p1Key[4] = true;
    
  if(key == 'i')
    p2Key[0] = true;
  if(key == 'j')
    p2Key[1] = true;
  if(key == 'k')
    p2Key[2] = true;
  if(key == 'l')
    p2Key[3] = true;
  if(key == 'p')
    p2Key[4] = true;
}

void keyReleased() {
  if(key == 'w')
    p1Key[0] = false;
  if(key == 'a')
    p1Key[1] = false;
  if(key == 's')
    p1Key[2] = false;
  if(key == 'd')
    p1Key[3] = false;
  if(key == 'r')
    p1Key[4] = false;
    
  if(key == 'i')
    p2Key[0] = false;
  if(key == 'j')
    p2Key[1] = false;
  if(key == 'k')
    p2Key[2] = false;
  if(key == 'l')
    p2Key[3] = false;
  if(key == 'p')
    p2Key[4] = false;
}



class boi {
  
  int x, y;
  int xVel, yVel;
  int xDir, yDir;
  int lives = 5;
  
  boi(int posx, int posy, int dirx, int diry) {
    x = posx;
    y = posy;
    xDir = dirx;
    yDir = diry;
  }
  
  
  void update() {
    if(p1Key[0] && p1Key[2])
      p1.yVel = 0;
    else if(p1Key[0])
      p1.yVel = -2;
    else if(p1Key[2])
      p1.yVel = 2;
    else
      p1.yVel = 0;
    
    if(p1Key[1] && p1Key[3])
      p1.xVel = 0;
    else if(p1Key[1])
      p1.xVel = -2;
    else if(p1Key[3])
      p1.xVel = 2;
    else
      p1.xVel = 0;
      
    if(p2Key[0] && p2Key[2])
      p2.yVel = 0;
    else if(p2Key[0])
      p2.yVel = -2;
    else if(p2Key[2])
      p2.yVel = 2;
    else
      p2.yVel = 0;
    
    if(p2Key[1] && p2Key[3])
      p2.xVel = 0;
    else if(p2Key[1])
      p2.xVel = -2;
    else if(p2Key[3])
      p2.xVel = 2;
    else
      p2.xVel = 0;
      
    p1.xDir = p1.xVel / 2;
    p1.yDir = p1.yVel / 2;
    p2.xDir = p2.xVel / 2;
    p2.yDir = p2.yVel / 2;
      
    p1.x += p1.xVel;
    p1.y += p1.yVel;
    p2.x += p2.xVel;
    p2.y += p2.yVel;
    
    p1.x = constrain(p1.x, 45, 755);
    p1.y = constrain(p1.y, 45, 755);
    p2.x = constrain(p2.x, 45, 755);
    p2.y = constrain(p2.y, 45, 755);
  }
  
  
  
  void shoot() {
    if(p1Key[4] && p1Load && (abs(p1.xDir) + abs(p1.yDir)) > 0) {
      p1Bullet = new bullet(p1.x, p1.y, p1.xDir * 5, p1.yDir * 5);
      p1Load = false;
    }
    else if(!p1Load && !p1Bullet.collision()) {
      p1Bullet.update();
      p1Bullet.show();
    }
    else
      p1Load = true;
      
    if(p2Key[4] && p2Load && (abs(p2.xDir) + abs(p2.yDir)) > 0) {
      p2Bullet = new bullet(p2.x, p2.y, p2.xDir * 5, p2.yDir * 5);
      p2Load = false;
    }
    else if(!p2Load && !p2Bullet.collision()) {
      p2Bullet.update();
      p2Bullet.show();
    }
    else
      p2Load = true;
  }  
  
  
  
  void hit() {
    if(p2Load == false) {
      if(dist(p1.x, p1.y, p2Bullet.xTemp, p2Bullet.yTemp) < 27.5) {
        if(p1.lives > 1) {
          p1.lives --;
          p2Bullet.xTemp = p2.x;
          p2Bullet.yTemp = p2.y;
          p2Load = true;
        }
        else if(p1.lives == 1) {
          p2Load = true;
          end = true;
          winner = 2;
        }
      }
    }
    
    if(p1Load == false) {
      if(dist(p2.x, p2.y, p1Bullet.xTemp, p1Bullet.yTemp) < 27.5) {
        if(p2.lives > 1) {
          p2.lives --;
          p1Bullet.xTemp = p1.x;
          p1Bullet.yTemp = p1.y;
          p1Load = true;
        }
        else if(p2.lives == 1) {
          p1Load = true;
          end = true;
          winner = 1;
        }
      }
    }
  }
  
  
  
  void show() {
    fill(180, 50, 10);
    ellipse(p1.x, p1.y, 40, 40);
    if(p1Load) {
      fill(200, 200, 0);
      if(abs(p1.xDir) + abs(p1.yDir) == 1) {
        if(p1.xDir == -1)
          ellipse(p1.x - 20, p1.y, 15, 15);
        else if(p1.xDir == 1)
          ellipse(p1.x + 20, p1.y, 15, 15);
        else if(p1.yDir == -1)
          ellipse(p1.x, p1.y - 20, 15, 15);
        else if(p1.yDir == 1)
          ellipse(p1.x, p1.y + 20, 15, 15);
      }
      else if(abs(p1.xDir) + abs(p1.yDir) == 2) {
        if(p1.xDir == -1 && p1.yDir == -1)
          ellipse(p1.x - 14, p1.y - 14, 15, 15);
        else if(p1.xDir == -1 && p1.yDir == 1)
          ellipse(p1.x - 14, p1.y + 14, 15, 15);
        else if(p1.xDir == 1 && p1.yDir == -1)
          ellipse(p1.x + 14, p1.y -14, 15, 15);
        else if(p1.xDir == 1 && p1.yDir == 1)
          ellipse(p1.x + 14, p1.y + 14, 15, 15);
      }
      else
        ellipse(p1.x, p1.y, 10, 10);
    }
    
    
    fill(0, 50, 200);
    ellipse(p2.x, p2.y, 40, 40);
    if(p2Load) {
      fill(200, 200, 0);
      if(abs(p2.xDir) + abs(p2.yDir) == 1) {
        if(p2.xDir == -1)
          ellipse(p2.x - 20, p2.y, 15, 15);
        else if(p2.xDir == 1)
          ellipse(p2.x + 20, p2.y, 15, 15);
        else if(p2.yDir == -1)
          ellipse(p2.x, p2.y - 20, 15, 15);
        else if(p2.yDir == 1)
          ellipse(p2.x, p2.y + 20, 15, 15);
      }
      else if(abs(p2.xDir) + abs(p2.yDir) == 2) {
        if(p2.xDir == -1 && p2.yDir == -1)
          ellipse(p2.x - 14, p2.y - 14, 15, 15);
        else if(p2.xDir == -1 && p2.yDir == 1)
          ellipse(p2.x - 14, p2.y + 14, 15, 15);
        else if(p2.xDir == 1 && p2.yDir == -1)
          ellipse(p2.x + 14, p2.y -14, 15, 15);
        else if(p2.xDir == 1 && p2.yDir == 1)
          ellipse(p2.x + 14, p2.y + 14, 15, 15);
      }
      else
        ellipse(p2.x, p2.y, 10, 10);
    }
  }
  
}



class bullet {
  
  int xTemp, yTemp;
  int xSpeed, ySpeed;
  
  bullet(int initX, int initY, int speedX, int speedY) {
    xTemp = initX;
    yTemp = initY;
    xSpeed = speedX;
    ySpeed = speedY;
  }
  
  void update() {
    xTemp += xSpeed;
    yTemp += ySpeed;
  }
  
  void show() {
    fill(200, 200, 0);
    ellipse(xTemp, yTemp, 15, 15);
  }
  
  boolean collision() {
    if(xTemp < 32.5 || xTemp > 767.5 || yTemp < 32.5 || yTemp > 767.5)
      return true;
    else
      return false;
  }
  
}
