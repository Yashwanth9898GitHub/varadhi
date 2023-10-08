#include <Servo.h> //for servo motor
const int TRIG_PIN  = 6;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin

const int ECHO_PIN  = 7;  // Arduino pin connected to Ultrasonic Sensor's ECHO pin

const int SERVO_PIN = 9; // Arduino pin connected to Servo Motor's pin

const int DISTANCE_THRESHOLD = 6; // 6 cm u can change as per your requirement

Servo servo; // create servo object to control servo motors

float duration_us, distance_cm; // variables will change:

void setup() 
{ 
  //setup loop for initialization and identification to arduino if it is input to arduino or output from arduino

  Serial.begin (9600);       // initialize serial port

  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode

  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode

  servo.attach(SERVO_PIN);   // attaches the servo on pin 9 to the servo object

  servo.write(0); 

}

void loop() {/*this loop for working how the components works ... based upon some conditions 
   generate 10-microsecond pulse to TRIG pin*/
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(TRIG_PIN, LOW);
  // measure duration of pulse from ECHO pin ultrasonic sensor
  duration_us = pulseIn(ECHO_PIN, HIGH);
  distance_cm = 0.017 * duration_us;//distance caluclating formula
  if(distance_cm < DISTANCE_THRESHOLD)
    servo.write(90); // rotate servo motor to 90 degree
  else
    servo.write(0);  // rotate servo motor 0   degree

  Serial.print("distance: "); // print the value to Serial Monitor
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(3000);
}
