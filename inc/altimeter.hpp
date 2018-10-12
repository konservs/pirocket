/*
*/

#ifndef LIB_ALTIMETER_H
#define LIB_ALTIMETER_H

#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <sys/ioctl.h>
#include <math.h>
#include "smbus.h" 

class Altimeter {
public:
	Altimeter();
	double getAltitude();
	double getAltitude(double i, double k);

private:
	// Calibration values - These are stored in the BMP085
	short int ac1;
	short int ac2; 
	short int ac3; 
	unsigned short int ac4;
	unsigned short int ac5;
	unsigned short int ac6;
	short int b1; 
	short int b2;
	short int mb;
	short int mc;
	short int md;
	int b5; 

	int bmp085_i2c_Begin();
	void bmp085_Calibration();
	__s32 bmp085_i2c_Read_Int(int fd, __u8 address);
	void bmp085_i2c_Write_Byte(int fd, __u8 address, __u8 value);
	void bmp085_i2c_Read_Block(int fd, __u8 address, __u8 length, __u8 *values);

	unsigned int bmp085_ReadUT();
	unsigned int bmp085_ReadUP();
	unsigned int bmp085_GetPressure(unsigned int up);
	unsigned int bmp085_GetTemperature(unsigned int ut);
};

#endif /* LIB_ALTIMETER_H */
