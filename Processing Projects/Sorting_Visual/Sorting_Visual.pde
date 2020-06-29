final int total = 99;
int[] order = new int[total];
final int L = 800, H = 600;
final int delay = 280, delay2 = 1;
int count = -120, count2 = 0, count3 = 0;
int split = 0, low = 0, high = total - 1;
Rectangle[] rect = new Rectangle[total];

void setup() {
 
  size(800, 600);
  background(0, 0, 200);
  rectMode(CENTER);
  frameRate(120);
  int wideness = L / (total * 2 + 1);
  for(int i = 0; i < total; i++)
    rect[i] = new Rectangle(wideness * (2 * i + 1) + wideness / 2);
  for(int i = 0; i < total; i++)
    order[i] = i;
  
}

void draw() {
 
  background(0, 100, 200);
  for(int i = 0; i < total; i++) {
    rect[i].update();
    rect[i].show();
  }
  
  if(count <= delay * 2) {
    if(count % delay == 0) {
      if(count / delay == 1) {
        low = 0;
        high = split - 1;
      }
      else if(count / delay == 2) {
        low = split;
        high = total - 1;
      }
      int pivotID = order[high];
      int numLess = low;
      for(int i = low; i <= high; i++) {
        if(rect[pivotID].getHeight() > rect[order[i]].getHeight()) {
          rect[order[numLess]].setTarget(i);
          rect[order[i]].setTarget(numLess);
          switchOrder(numLess, i);
          numLess ++;
        }
      }
      rect[pivotID].setTarget(numLess);
      rect[order[numLess]].setTarget(high);
      switchOrder(high, numLess);
      if(count == 0)
        split = numLess > 0 ? numLess : 1;
    }
  }
  
  else if(count >= delay * 3 && count % delay2 == 0) {
    frameRate(480);
    count3 = 0;
    while(true) {
    if(rect[order[count2]].getHeight() > rect[order[count2+1]].getHeight()) {
      rect[order[count2]].setTarget(count2 + 1);
      rect[order[count2+1]].setTarget(count2);
      switchOrder(count2, count2+1);
      break;
    }
    else {
      count2++;
      count3++;
    }
    if(count2 == total - 1)
      count2 = 0;
    if(count3 == total)
      break;
    }
  }
  count ++;
  
}

void switchOrder(int pos1, int pos2) {
  int a = order[pos1];
  order[pos1] = order[pos2];
  order[pos2] = a;
}

class Rectangle {
 
  int x, y;
  int targetX;
  int l, h;
  int velocity;
  
  public Rectangle(int xPos) {
    x = xPos;
    targetX = x;
    l = L / (total + total + 1);
    h = (int)(Math.random() * 400);
    while(h < 20)
      h = (int)(Math.random() * 400);
    y = 580 - h / 2;
    velocity = 3;
  }
  
  public void show() {
    fill((int)(h * 255 / 400));
    rect(x, y, l, h);
  }
  
  public void update() {
    if(targetX != x) {
      if(Math.abs(targetX - x) < velocity)
        x = targetX;
      else if(targetX > x)
        x += velocity;
      else
        x -= velocity;
    }
  }
  
  public int getHeight() {
    return h;
  }
  
  public void setTarget(int pos) {
    int wideness = L / (total * 2 + 1);
    targetX = wideness * (2 * pos + 1) + wideness / 2;
  }
  
}
