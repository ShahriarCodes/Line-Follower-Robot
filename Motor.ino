#define PWMA 2
#define AIN2 3
#define AIN1 4
#define STBY 5
#define BIN1 6
#define BIN2 7
#define PWMB 8

#define Lspeed 120
#define Rspeed 120

int initial_motor_speed = 100; // 70,100
int motor_max_speed = 150; //100,150


void motor_control()
{
  // Calculating the effective motor speed:
  int left_motor_speed = initial_motor_speed + PID_value;
  int right_motor_speed = initial_motor_speed - PID_value;

  // The motor speed should not exceed the max PWM value
  left_motor_speed = constrain(left_motor_speed, 0, motor_max_speed);
  right_motor_speed = constrain(right_motor_speed, 0, motor_max_speed);

  //Serial.print(left_motor_speed);
  //Serial.print("  ");
  //Serial.println(right_motor_speed);

  analogWrite(PWMA, left_motor_speed); //Left Motor Speed
  analogWrite(PWMB, right_motor_speed); //Right Motor Speed
  //following lines of code are to make the bot move forward
  /*The pin numbers and high, low values might be different
    depending on your connections */
  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(STBY, HIGH);

}

void Brake() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  digitalWrite(AIN2, LOW);
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(STBY, LOW);
}

void Left() {
  {
    analogWrite(PWMA, 0);
    analogWrite(PWMB, Lspeed);
    digitalWrite(AIN2, LOW);
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(STBY, HIGH);
  }
  delay(80);
  while (true)
  {
    read_sensor_values();
    if ((s2Value) > threshold) break;
    {
      analogWrite(PWMA, 0);
      analogWrite(PWMB, Lspeed);
      digitalWrite(AIN2, LOW);
      digitalWrite(AIN1, HIGH);
      digitalWrite(BIN2, LOW);
      digitalWrite(BIN1, HIGH);
      digitalWrite(STBY, HIGH);
    }
  }

  analogWrite(PWMA, 0);
  analogWrite(PWMB, Lspeed);
  digitalWrite(AIN2, LOW);
  digitalWrite(AIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(STBY, HIGH);

}

void Right() {
  {
    analogWrite(PWMA, Rspeed);
    analogWrite(PWMB, 0);
    digitalWrite(AIN2, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(STBY, HIGH);
  }

  delay(80);
  while (true)
  {
    read_sensor_values();
    if ((s2Value) > threshold) break;
    {
      analogWrite(PWMA, Rspeed);
      analogWrite(PWMB, 0);
      digitalWrite(AIN2, HIGH);
      digitalWrite(AIN1, LOW);
      digitalWrite(BIN2, LOW);
      digitalWrite(BIN1, LOW);
      digitalWrite(STBY, HIGH);
    }
  }
  analogWrite(PWMA, Rspeed);
  analogWrite(PWMB, 0);
  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(STBY, HIGH);

}
