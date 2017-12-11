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

		if(sdata.IRSensor[0] > 300 && sdata.IRSensor[1] > 300 && sdata.IRSensor[2]>300)
{
Go(-350,-350);
Steering(3);
}
else if(sdata.IRSensor[0]>300 && sdata.IRSensor[1]>300)
{
Go(-350,-350);
Steering(3);
}
else if(sdata.IRSensor[1]>300 && sdata.IRSensor[2]>300)
{
Go(-350,-350);
Steering(3);
}
else if(sdata.IRSensor[0]>300)
{
Go(-350,-350);
Steering(3);
}
else if(sdata.IRSensor[1]>300)
{
Go(-350,-350);
Steering(3);
}
else if(sdata.IRSensor[2]>300)
{Go(-350,-350);
Steering(3);
}
else
{
Go(350,350);
Steering(2);
}

if(ir4>500&&ir5>500)
        {
            Go(0,0);
            break;
        }



		/*Steering(2);
        Go(330,330);
        delay(1000);
        Go(0,0);

        if(ir1>20&&ir5<70&&ir3<3)
        {
            Go(-330,-330);
            delay(1000);
            Go(330,330);
            Steering(3);
            delay(1000);
            Steering(2);
        }
        else if(ir1>70&&ir2>70&&ir5<100&&ir3<3)
        {
            Go(-330,-470);
            Steering(1);
            delay(1000);
            Go(330,330);
            Steering(3);
            delay(1000);
            Steering(2);
        }
        else if(ir1<5&&ir5>70&&ir3<3)
        {
            Go(-330,-470);
            Steering(3);
            delay(1000);
            Go(330,330);
            Steering(1);
            delay(1000);
            Steering(2);
        }
        else if(ir1>50&&ir5>100&&ir3<3)
        {
            Go(-330,-470);
            Steering(1);
            delay(1000);
            Go(330,330);
            Steering(3);
            delay(1000);
            Steering(2);
        }
        else if(ir1<3&&ir5<70&&ir3<3)
        {
        Go(-330,-470);
            Steering(3);
            delay(1200);
            Go(330,330);
            Steering(1);
            delay(1000);
            Steering(2);




        }
        else if(ir3>10)
        {
            Go(-370,-450);
            Steering(1);
            delay(1000);
            Go(330,330);
            Steering(3);
            delay(1000);
            Steering(2);
        }
        */

       /* if(ir5>100)
        {
            Go(350,350);
            Steering(3);
            delay(700);

        }

        else if(ir5<100)
        {
            Go(350,350);
            Steering(1);
            delay(700);
        }

        else if(ir1>600||ir2>600||ir3>600)
        {
            Go(-350,-350);
            Steering(2);
            delay(1000);

        }

        if(ir4>500&&ir5>500)
        {
            Go(0,0);
            break;
        }
        */


        printf("IR1 : %3d, IR2 : %3d, IR3 : %3d\n", sdata.IRSensor[0], sdata.IRSensor[1],sdata.IRSensor[2]);
        printf("IR5 : %3d,            IR4 : %3d\n", sdata.IRSensor[4], sdata.IRSensor[3]);
        printf("          IR6 : %3d\n",sdata.IRSensor[5]);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        delay(10);
	}



	Close();
	return 0;


}
