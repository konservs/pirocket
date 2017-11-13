#include <iostream>
#include <pigpio.h>
#include <thread>

#define ALTITUDE_THRESHOLD 10
#define GPIO_PARACHUTE 1

/*
TO BUILD
gcc -o pirocket pirocket.cpp -lpigpio -lrt

TO RUN
sudo ./pirocket
*/

int maxAltitude;
bool parachuteEjected;
unsigned int i2c_altimeter_handle;

/**
 * Send signal to eject parachute
 */
int ejectParachute(){
    gpioWrite(GPIO_PARACHUTE, 1);
}

/**
 * Altitude received.
 */
int receivedAltitude(int currentAltitude) {
    if((currentAltitude < maxAltitude)&&((maxAltitude - currentAltitude) > ALTITUDE_THRESHOLD)&&(!parachuteEjected)){
        ejectParachute();
    }
}

/**
 * Entry point - init threads, start sensors poll
 */
int main(int argc, char *argv[]) {
    parachuteEjected = 0;
    if (gpioInitialise() < 0) return 1;

    gpioSetMode(GPIO_PARACHUTE, PI_OUTPUT);
    i2c_altimeter_handle = i2cOpen(0,0x01,0);
    //Start the threads

    gpioTerminate();
    return 0;
}
