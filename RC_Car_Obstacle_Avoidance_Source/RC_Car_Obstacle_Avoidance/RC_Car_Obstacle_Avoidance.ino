#include <Servo.h>

#define ENA 5
#define IN1 4
#define IN2 7

#define ENB 6
#define IN3 8
#define IN4 12

#define TRIG_PIN 9
#define ECHO_PIN 10
#define SERVO_PIN 3

#define STOP_DISTANCE 20

Servo scanServo;

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return 300;
  return duration * 0.034 / 2;
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

void stopMotors() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  delay(400);
  stopMotors();
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  delay(400);
  stopMotors();
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  scanServo.attach(SERVO_PIN);
  scanServo.write(90);

  stopMotors();
  delay(1000);
}

void loop() {
  long distance = getDistance();

  if (distance > STOP_DISTANCE) {
    moveForward();
  } else {
    stopMotors();
    delay(300);

    scanServo.write(30);
    delay(400);
    long leftDist = getDistance();

    scanServo.write(150);
    delay(400);
    long rightDist = getDistance();

    scanServo.write(90);
    delay(200);

    if (leftDist > rightDist) {
      turnLeft();
    } else {
      turnRight();
    }
  }
}
