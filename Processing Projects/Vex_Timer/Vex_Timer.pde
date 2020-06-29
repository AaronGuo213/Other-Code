final int W = 1440, H = 900;
int minutes = 0;
int seconds = 0;
int tsec = 0;
int greenTime, yellowTime;
enum mode {
  driver,
  auton,
  skills;
}
mode currentMode = mode.auton;
boolean paused = true;
boolean spacePressed = false, newPress = true;
Button[] buttons = new Button[5];
final int buttonWidth = 200, buttonHeight = 100;
final int btnTxtSize = 50;

void setup() {
  
  size(1440, 900);
  background(0, 255, 0);
  frameRate(10);
  rectMode(CENTER);
  textAlign(CENTER, CENTER);
  fill(0);
  startMode();
  
  buttons[0] = new Button(W/4 * 1, H/4 * 2, buttonWidth, buttonHeight, "Start", null, 0, 0, 0);
  buttons[1] = new Button(W/4 * 3, H/4 * 2, buttonWidth, buttonHeight, "Reset", null, 0, 0, 0);
  buttons[2] = new Button(W/4 * 1, H/4 * 3, buttonWidth, buttonHeight, "Auton", mode.auton, 0, 0, 0);
  buttons[3] = new Button(W/4 * 2, H/4 * 3, buttonWidth, buttonHeight, "Driver", mode.driver, 0, 0, 0);
  buttons[4] = new Button(W/4 * 3, H/4 * 3, buttonWidth, buttonHeight, "Skills", mode.skills, 0, 0, 0);
  
}

void draw() {
  
  if(!spacePressed) {
    newPress = true;
  }
  else if(newPress) {
    newPress = false;
    buttons[0].clicked();
  }
  showTime();
  if(!paused)
    updateTimer();
  for(int i = 0; i < buttons.length; i++)
    buttons[i].show();
  
}

void startMode() {
  
  switch(currentMode) {
    
    case driver:
      minutes = 1;
      seconds = 45;
      tsec = 0;
      break;
      
    case auton:
      minutes = 0;
      seconds = 15;
      tsec = 0;
      break;
      
    case skills:
      minutes = 1;
      seconds = 0;
      tsec = 0;
      break;
    
  }
  
}

void updateTimer() {
  
  if(tsec == 0) {
    if(seconds == 0) {
      if(minutes != 0) {
        minutes --;
        seconds = 59;
        tsec = 9;
      }
    }
    else {
      seconds --;
      tsec = 9;
    }
  }
  else {
    tsec --;
  }
  
}

void showTime() {
  
  switch(currentMode) {
    
    case driver:
      greenTime = 30;
      yellowTime = 15;
      break;
      
    case auton:
      greenTime = 5;
      yellowTime = 3;
      break;
      
    case skills:
      greenTime = 15;
      yellowTime = 5;
      break;
    
  }
  
  if(seconds >= greenTime || minutes > 0)
    background(0, 255, 0);
    
  else if(seconds >= yellowTime)
    background(255, 255, 0);
    
  else
    background(255, 0, 0);
  
  String time = minutes + ":" + (seconds < 10 ? "0" : "") + seconds + "." + tsec;
  if(minutes + seconds + tsec == 0)
    time = "STOP";
  fill(0);
  textSize(100);
  text(time, W/2, 100);
  
}

void changeMode(mode newMode) {
  
  currentMode = newMode;
  startMode();
  paused = true;
  
}

class Button {
  
  int x, y;
  int w, h;
  int r, g, b;
  String txt;
  mode m;
  
  public Button(int theX, int theY, int theWidth, int theHeight, String theText, mode theMode, int red, int green, int blue) {
    x = theX;
    y = theY;
    w = theWidth;
    h = theHeight;
    r = red;
    g = green;
    b = blue;
    txt = theText;
    m = theMode;
  }
  
  public void show() {
    fill(r, g, b);
    rect(x, y, w, h);
    fill(255);
    textSize(btnTxtSize);
    text(txt, x, y);
  }
  
  public mode clicked() {
    if(m != null)
      return m;
    else if(txt.equals("Start")) {
      paused = false;
      txt = "Stop";
    }
    else if(txt.equals("Stop")) {
      paused = true;
      txt = "Start";
    }
    else if(txt.equals("Reset")) {
      changeMode(currentMode);
      buttons[0].txt = "Start";
    }
    return currentMode;
  }
  
}

void mouseClicked() {
  
  mode start = currentMode;
  for(int i = 0; i < buttons.length; i++) {
    if(abs(mouseX - buttons[i].x) <= buttons[i].w/2 && abs(mouseY - buttons[i].y) <= buttons[i].h/2)
      currentMode = buttons[i].clicked();
  }
  if(start != currentMode)
    changeMode(currentMode);
  
}

void keyPressed() {
  
  if(key == ' ')
    spacePressed = true;
  
}

void keyReleased() {
  
  if(key == ' ')
    spacePressed = false;
  
}
