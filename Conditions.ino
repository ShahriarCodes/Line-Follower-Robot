
#define threshold 400

int d = 150;

  void conditions() {

    if (s2Value > threshold) {

      if (s1Value > threshold && s3Value <= threshold) {
        Left();
        delay(d);
      }

      else if (s1Value <= threshold && s3Value > threshold) {
        Right();
        delay(d) ;
      }
      else if (s1Value <= threshold && s3Value <= threshold) {
        motor_control();
      }
      else if (s1Value > threshold && s3Value > threshold) {
        motor_control();
      }
    }

    else if (s2Value <= threshold) {
      if (s1Value > threshold && s3Value <= threshold) {
        Left();
        delay(d) ;
      }
      else if (s1Value <= threshold && s3Value > threshold) {
        Right();
        delay(d) ;
      }
      else if (s1Value <= threshold && s3Value <= threshold) {
        motor_control();
      }
      else if (s1Value > threshold && s3Value > threshold) {
        motor_control();
      }

    }
  }


