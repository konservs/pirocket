#include <iostream>
#include <pigpio.h>

/*
TO BUILD
gcc -o pirocket pirocket.cpp -lpigpio -lrt

TO RUN
sudo ./pirocket
*/

int main(int argc, char *argv[]) {
    if (gpioInitialise() < 0) return 1;

    gpioTerminate();
    return 0;
}
