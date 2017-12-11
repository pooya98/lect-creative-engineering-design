#include "Altino.h"
#include <stdio.h>

int main()
{
	int ir1, ir2, ir3, ir4, ir5;
	SensorData sdata;
	Open(szPort);

	int backward_speed = -300;
	int forward_speed = 300;



	while (1)
	{
		sdata = Sensor(1);
		ir1 = sdata.IRSensor[0];
		ir2 = sdata.IRSensor[1];
		ir3 = sdata.IRSensor[2];
		ir4 = sdata.IRSensor[3];
		ir5 = sdata.IRSensor[4];

		if (sdata.IRSensor[0] > 300 && sdata.IRSensor[1] > 300 && sdata.IRSensor[2]>300)
		{
			Go(-350, -350);
			Steering(3);
		}
		else if (sdata.IRSensor[0]>300 && sdata.IRSensor[1]>300)
		{
			Go(-350, -350);
			Steering(3);
		}
		else if (sdata.IRSensor[1]>300 && sdata.IRSensor[2]>300)
		{
			Go(-350, -350);
			Steering(3);
		}
		else if (sdata.IRSensor[0]>300)
		{
			Go(-350, -350);
			Steering(3);
		}
		else if (sdata.IRSensor[1]>300)
		{
			Go(-350, -350);
			Steering(3);
		}
		else if (sdata.IRSensor[2]>300)
		{
			Go(-350, -350);
			Steering(3);
		}
		else
		{
			Go(350, 350);
			Steering(2);
		}

		if (ir4>500 && ir5>500)
		{
			Go(0, 0);
			break;
		}

	}



	Close();
	return 0;


}
