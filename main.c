#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"
#include "io.h"

int main() {

    int n;

    WaveformSample *samples = load_csv("power_quality_log.csv", &n);

    if (!samples) return 1;

    printf("Loaded %d samples\n", n);

    // Print first row (test)
    printf("First row:\n");
    printf("Time: %.4f\n", samples[0].timestamp);
    printf("Phase A: %.2f\n", samples[0].phase_A_voltage);

    free(samples);
    return 0;
}