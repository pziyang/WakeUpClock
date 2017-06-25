#include "Clock.h"
#include "led-matrix.h"

#include "unistd.h"

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

int main(int argc, char **argv) {

    // Set defaults for canvas
    RGBMatrix::Options defaults;
    defaults.hardware_mapping = "adafruit-hat";
    defaults.chain_length = 1;

    rgb_matrix::RuntimeOptions runtime_defaults;
    runtime_defaults.drop_privileges = 1;

    Canvas *canvas = rgb_matrix::CreateMatrixFromOptions(defaults, runtime_defaults);

    if (canvas == NULL) {
        PrintMatrixFlags(stderr, defaults, runtime_defaults);
        return false;
    }

    //create LedClock class
    LedClock ledclock(canvas);

    //begin execution
    ledclock.Start();

    //prevent exit
    while(1)
    {
        sleep(10);
    }

    // Animation finished. Shut down the RGB matrix.
    delete canvas;

    return 0;
}
