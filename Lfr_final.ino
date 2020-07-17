#include <Arduino.h>

#define PWMA 2
#define AIN2 3
#define AIN1 4
#define STBY 5
#define BIN1 6
#define BIN2 7
#define PWMB 8

#define threshold 400

const int s2 = A10;
const int s2Led = 32;
int s2Value = 0;
const int s1 = A9;
const int s1Led = 31;
int s1Value = 0;
const int s3 = A11;
const int s3Led = 33;
int s3Value = 0;


float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;


#define NUM_SENSORS 9
int sensors[] = {A0, A1, A2, A3, A4, A5, A6, A7, A8};
int leds[] = {22, 23, 24, 25, 26, 27, 28, 29, 30};
int yi[NUM_SENSORS] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // sensorValues
int s[NUM_SENSORS];
int xi[NUM_SENSORS]; // number of sensors in an array
float xiyi = 0;
float yisum = 0;
float position = 0;

void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);
void Brake(void);
void Left(void);
void Right(void);
void conditions(void);
void sonar(void);


void setup()
{
  pinMode(PWMA, OUTPUT); //PWM Pin 1
  pinMode(PWMB, OUTPUT); //PWM Pin 2
  pinMode(AIN1, OUTPUT); //Left Motor Pin 1
  pinMode(AIN2, OUTPUT); //Left Motor Pin 2
  pinMode(BIN2, OUTPUT); //Right Motor Pin 1
  pinMode(BIN1, OUTPUT); //Right Motor Pin 2
  pinMode(STBY, OUTPUT); //Right Motor Pin 2


  Serial.begin(9600); //Enable Serial Communications
}


void loop() {
 loops();
}
