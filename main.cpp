#include "Clock.h"
#include "led-matrix.h"

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

int main(int argc, char **argv) {

    // Set some defaults
    RGBMatrix::Options my_defaults;
    my_defaults.hardware_mapping = "adafruit-hat";
    my_defaults.chain_length = 1;

    rgb_matrix::RuntimeOptions runtime_defaults;
    runtime_defaults.drop_privileges = 1;

    RGBMatrix *matrix = rgb_matrix::CreateMatrixFromOptions(my_defaults, runtime_defaults);

    if (matrix == NULL) {
        PrintMatrixFlags(stderr, my_defaults, runtime_defaults);
        return 1;
    }


    //myledclock.Run();

}
