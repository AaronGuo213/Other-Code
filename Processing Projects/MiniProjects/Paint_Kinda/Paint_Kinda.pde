int[][][] pixelColor = new int[1000][1000][3];
int currentR = 0, currentG = 0, currentB = 0;
int brushSize = 5;

void setup() {
  size(1000, 1000);
  background(255);
  frameRate(30);
  rectMode(CENTER);
  ellipseMode(CENTER);
  for(int i = 0; i < 1000; i++)
    for(int j = 0; j < 1000; j++)
      for(int k = 0; k < 3; k++)
        pixelColor[i][j][k] = -1;
}

void draw() {
  /*for(int i = 0; i < 500; i++)
    for(int j = 0; j < 500; j++)
      for(int k = 0; k < 3; k++)
        pixelColor[i][j][k] = 0;
  
  for(int i = 0; i < 1000; i++)
    for(int j = 0; j < 1000; j++)
      for(int k = 0; k < 3; k++) 
        if(pixelColor[i][j][k] >= 0)
        {
          stroke(pixelColor[i][j][0], pixelColor[i][j][1], pixelColor[i][j][2]);
          fill(pixelColor[i][j][0], pixelColor[i][j][1], pixelColor[i][j][2]);
          rect(i, j, 1, 1);
        }
  
  for(int i = 0; i < 1000; i++)
    for(int j = 0; j < 1000; j++)
      for(int k = 0; k < 3; k++)
        pixelColor[i][j][k] = -1;*/
}

void mousePressed() {
  fill(50, 50, 50);
  ellipse(mouseX, mouseY, brushSize, brushSize);
}

void mouseDragged() {
  fill(50, 50, 50);
  ellipse(mouseX, mouseY, brushSize, brushSize);
}
