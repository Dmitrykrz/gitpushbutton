#include <Keyboard.h>

const int buttonPin = 2;
bool hasPushed = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !hasPushed) {
    hasPushed = true; // Prevent multiple triggers while holding the button
    Keyboard.print("git push");
    delay(100); 
    Keyboard.press(KEY_RETURN);
    delay(100); 
    Keyboard.releaseAll();  
    delay(1000);
    
  }

  if (digitalRead(buttonPin) == HIGH) {
    hasPushed = false; // Reset when button is released
  }
}




