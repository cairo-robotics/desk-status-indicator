// set up button variables
const int btnPin = 4; // button is connected to pin 4
int btnState = 0;
int lastBtnState = 0;
int btnCounter = 0;

// set up LED pin numbers
const int led1Pin = 13;
const int led2Pin = 12;
const int led3Pin = 8;

void setup() {
  // put your setup code here, to run once:
  // tell where buttons and LEDs are connected
  pinMode(btnPin, INPUT);

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  // see if button is pushed or not
  btnState = digitalRead(btnPin);
  if (btnState != lastBtnState) {
    if (btnState == HIGH) {
      // we pushed the button down
      // count the number of times the button has been pushed
      btnCounter++;
      //Serial.println("button is pressed down");
      //Serial.print("button counter: ");
      //Serial.println(btnCounter);
    } else {
      // we let go of the button
      //Serial.println("button is let go");
    }
    // delay a bit to avoid bouncing
    delay(50);
  }
  lastBtnState = btnState;

  // rotates between different indicator lights
  if (btnCounter % 4 == 1) {
    // LED1 on
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  }
  if (btnCounter % 4 == 2) {
    // LED2 on
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
  }
  if (btnCounter % 4 == 3) {
    // LED3 on
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
  }
  if (btnCounter % 4 == 0) {
    // all LEDs off
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  }
}
