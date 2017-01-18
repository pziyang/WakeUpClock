RGBMatrix::Options matrix_options;
rgb_matrix::RuntimeOptions runtime_opt;

// These are the defaults when no command-line flags are given.
matrix_options.rows = 32;
matrix_options.chain_length = 1;
matrix_options.parallel = 1;

RGBMatrix *matrix = CreateMatrixFromOptions(matrix_options, runtime_opt);

LedClock *ledclock = new LedClock(&matrix);
ledclock->Start();   // Start doing things.
// This now runs in the background, you can do other things here,
// e.g. aquiring new data or simply wait. But for waiting, you wouldn't
// need a thread in the first place.
ledclock->Stop();

delete demo;