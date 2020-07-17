#define setpoint 4000

float Kp = .3, Ki = 0, Kd = 1; // kp .05, kd 0 // .3, 1

void calculate_pid()
{

  error = position - setpoint;
  //Serial.println(error);
  //delay(50);
  P = error;
  I = I + previous_I;
  D = error - previous_error;

  PID_value = (Kp * P) + (Ki * I) + (Kd * D);

  previous_I = I;
  previous_error = error;
}
