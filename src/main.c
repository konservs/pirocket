/*
*/

#include <stdio.h>
#include <stdlib.h>
#include "altimeter.hpp"

int main(int argc, char **argv)
{
	printf("----------------------------------\n");
	printf("BMP085 test\n");
	printf("----------------------------------\n");

	Altimeter alt;
	double maxAltitude = -9999;
	printf("Sensor calibrated\n");

	while(1) {
		double altitude = alt.getAltitude();
		if(altitude>maxAltitude){
			maxAltitude = altitude;
		}

		//printf(" - Temperature\t%0.1fC\n", ((double)temperature)/10);
		//printf(" - Pressure\t%0.2fhPa\n", ((double)pressure)/100);
		printf(" - Altitude\t%0.1f m (max %0.1f)\n", altitude, maxAltitude);
		printf("----------------------------------\n");

		if((altitude<maxAltitude)&&((maxAltitude - altitude)>10)){
			//10 meters falling!
			return 0;
		}

		sleep(1);
	}
	return 0;
}
