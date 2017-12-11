#include "Altino.h"
#include <stdio.h>

int main()
{
	SensorData sdata;
	Open(szPort);
	Sendbuf[21] = 10;
	int ir1, ir2, ir3, ir4, ir5;
	int backward_speed = -400;
	int forward_speed = 400;

	while (1)
	{
		sdata = Sensor(1);

		ir1 = sdata.IRSensor[0];
		ir2 = sdata.IRSensor[1];
		ir3 = sdata.IRSensor[2];
		ir4 = sdata.IRSensor[3];
		ir5 = sdata.IRSensor[4];

		Go(500, 500);
		if (ir5>250 || ir1>50)
		{
			Go(backward_speed, backward_speed);
			Steering(1);
			delay(750);
			Go(forward_speed, forward_speed);
			Steering(3);
			delay(750);
		}
		else {
			Go(forward_speed, forward_speed);
			Steering(2);
		}

		/*if(ir1<100)
		{
		Go(0,0);
		delay(500);
		Go(-500,-500);
		delay(500);


		Steering(1);
		Go(300,500);
		delay(600);
		}
		else
		{
		Steering(2);
		Go(600,600);
		}*/


		/*if(ir1>200 && ir2>200 && ir3>200&&ir5>200) {
		Go(backward_speed,backward_speed);
		Steering(1);
		delay(750);
		Go(forward_speed, forward_speed);
		Steering(3);
		delay(750);
		}
		else if(ir1>200 && ir2>200) {
		Go(backward_speed,backward_speed);
		Steering(1);
		delay(750);
		Go(forward_speed, forward_speed);
		Steering(3);
		delay(750);
		}

		else if(ir1>200) {
		Go(backward_speed,backward_speed);
		Steering(1);
		delay(750);
		Go(forward_speed, forward_speed);
		Steering(3);
		delay(750);
		}
		else if(ir2>200 && ir3>200) {
		Go(backward_speed,backward_speed);
		Steering(3);
		delay(750);
		Go(forward_speed, forward_speed);
		Steering(1);
		delay(750);
		}
		else if(ir3>200) {
		Go(backward_speed,backward_speed);
		Steering(3);
		delay(750);
		Go(forward_speed, forward_speed);
		Steering(1);
		delay(750);
		}
		else {
		Go(forward_speed, forward_speed);
		Steering(2);
		}0*/
	}


	Close();
	return 0;


}
