


int sum2(int yi[], int start, int end) {
  int yisum = 0;
  for (int j = start; j <= end; j++) {
    yisum = yisum + yi[j];
  }
  return yisum;
}

int sum(int s[], int start2, int end2) {
  int xiyi = 0;
  for (int i = start2; i <= end2; i++) {
    xiyi = xiyi + s[i];
  }
  return xiyi;
}
void read_sensor_values()
{
  for (int sensorCount = 0; sensorCount < NUM_SENSORS;  sensorCount++) {
    { s1Value = map(analogRead (s1), 0, 1023, 0, 1000);
      if ( s1Value > threshold) {
        analogWrite(s1Led, 255);
      }
      else {
        analogWrite(s1Led, 0);
      }
    }

    { s2Value = map(analogRead (s2), 0, 1023, 0, 1000);
      if ( s2Value > threshold) {
        analogWrite(s2Led, 255);
      }
      else {
        analogWrite(s2Led, 0);
      }
    }
    { s3Value = map(analogRead (s3), 0, 1023, 0, 1000);
      if ( s3Value > threshold) {
        analogWrite(s3Led, 255);
      }
      else {
        analogWrite(s3Led, 0);
      }
    }

    yi[sensorCount] = map(analogRead(sensors[sensorCount]), 0, 1023, 0, 1000); // black line white surface
    //  yi[sensorCount] = digitalRead(sensors[sensorCount]); // white line black surface
    if (yi[sensorCount] > threshold) {
      analogWrite(leds[sensorCount], 255);
    }
    else {
      analogWrite(leds[sensorCount], 0);
    }
    xi[sensorCount] = map(sensors[sensorCount], 54, 62, 0, (NUM_SENSORS - 1));

    s[sensorCount] = yi[sensorCount] * xi[sensorCount];

    //  Serial.print(s[sensorCount]);
    //  Serial.print('\t');
  }
  //Serial.println();
  // delay(1);
  {

    xiyi = sum(s, 0, (NUM_SENSORS - 1));
    yisum = sum2(yi, 0, (NUM_SENSORS - 1));
    position = (xiyi / yisum) * 1000;

    // Serial.println(position);
    //Serial.print('\t');
    //Serial.print(yisum);
    //Serial.print('\t');
  }
  // Serial.println();
  // delay(1);
  return position;
}


