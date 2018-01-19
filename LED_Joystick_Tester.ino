
// This allows calibration and testing of an analog joystick by means of 4 LEDs,
// which will gradually get brighter as the joystick is moved along the
// X and Y axes. This is done by using pulse-width modulation (PWM) to simulate
// analog current control.


// The LEDs are connected to PWM-enabled pins.

int upPin = 5;
int downPin = 6;
int leftPin = 9;
int rightPin = 10;

// The joystick's X-axis and Y-axis outputs are connected to analog input pins.

const int Y_pin = 0; // analog pin connected to X output
const int X_pin = 1; // analog pin connected to Y output

void setup() {

  // The digital pins connected to the LEDs are initialized as outputs.
  pinMode(upPin, OUTPUT);
  pinMode(downPin, OUTPUT);
  pinMode(leftPin, OUTPUT);
  pinMode(rightPin, OUTPUT);

}

void loop() {

  // Each if statement takes the analog input from the joystick pins, which will have
  // a value between 0 - 1024 for each axis. If the joystick has been moved in that
  // direction, converts it to a value between 0 and 255 for the analogWrite
  // function, which uses PWM to fade the LEDs. If the joystick has not moved in
  // that direction, a value of 0 is passed to the output and the next direction
  // is polled.


  // Joystick left?
  if (analogRead(X_pin) < 500)
  {
    analogWrite(leftPin, (512 - analogRead(X_pin) / 2));
  }
  else
  {
    analogWrite(leftPin, 0);
  }
  
  // Joystick right?
  if (analogRead(X_pin) > 535)
  {
    analogWrite(rightPin, ((analogRead(X_pin) - 512) / 2));
  }
  else
  {
    analogWrite(rightPin, 0);
  }
  
  // Joystick down?
  if (analogRead(Y_pin) < 500)
  {
    analogWrite(downPin, ((512 - analogRead(Y_pin)) / 2));
  }
  else
  {
    analogWrite(downPin, 0);
  }
  
  // Joystick up?
  if (analogRead(Y_pin) > 525)
  {
    analogWrite(upPin, ((analogRead(Y_pin) - 512) / 2));
  }
  else
  {
    analogWrite(upPin, 0);
  }
}

