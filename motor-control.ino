#define enB 9
#define in3 6
#define in4 7
#define button 4
int rotDirection = 0;
int pressed = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(button, INPUT);
  // set the initial rotation direction
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(A0); // read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0, 255); // map the potentiometer value from 0 to 255
  analogWrite(enB, pwmOutput); // send PwM signal to L298N enable pin
  // read button -- debounce
  if(digitalRead(button) == true){
    pressed = !pressed;
  }
  while (digitalRead(button) == true);
  delay(20);
  //if button is pressed, change the rotation direecction
  if(pressed == true & rotDirection == 0){
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    rotDirection = 1;
    delay(20);
  }

  // if the button is pressed, change rotation direction
  if(pressed == false & rotDirection == 1){
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    rotDirection = 1;
    delay(20);
  }
}
