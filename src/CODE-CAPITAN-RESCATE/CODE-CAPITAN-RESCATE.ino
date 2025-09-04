#include <AFMotor.h>

#include <SoftwareSerial.h>

double Dato;
AF_DCMotor motorshield_dc_2(2);
AF_DCMotor motorshield_dc_3(3);
SoftwareSerial bt_serial(9,10);

void setup()
{
  	pinMode(2, OUTPUT);

	Serial.begin(9600);
	Serial.flush();
	while(Serial.available()>0)Serial.read();

bt_serial.begin(9600);

	motorshield_dc_2.setSpeed(255);
	motorshield_dc_3.setSpeed(255);

}


void loop()
{

  	if ((bt_serial.available()>0)) {
  		Dato = bt_serial.read();
  		if ((Dato == 65)) {
  			motorshield_dc_2.run(FORWARD);
  			motorshield_dc_3.run(FORWARD);
  		}
  		else if ((Dato == 82)) {
  			motorshield_dc_2.run(BACKWARD);
  			motorshield_dc_3.run(BACKWARD);
  		}
  		else if ((Dato == 73)) {
  			motorshield_dc_2.run(FORWARD);
  			motorshield_dc_3.run(BACKWARD);
  		}
  		else if ((Dato == 68)) {
  			motorshield_dc_2.run(BACKWARD);
  			motorshield_dc_3.run(FORWARD);
  		}
  		else if ((Dato == 83)) {
  			motorshield_dc_2.run(RELEASE);
  			motorshield_dc_3.run(RELEASE);
  		}
  		else if ((Dato == 75)) {
  			digitalWrite(2,HIGH);
  		}
  		else if ((Dato == 76)) {
  			digitalWrite(2,LOW);
  		}

  	}

}