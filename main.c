#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"
#include "io.h"

int main() {

    int n;

    // Load CSV data
    WaveformSample *samples = load_csv("power_quality_log.csv", &n);

    if (!samples) {
        printf("Error loading data\n");
        return 1;
    }

    printf("Loaded %d samples\n\n", n);

    // Show first row (just to confirm data is correct)
    printf("First row:\n");
    printf("Time: %.4f\n", samples[0].timestamp);
    printf("Phase A: %.2f\n\n", samples[0].phase_A_voltage);


    // RMS CALCULATIONS

    double rmsA = compute_rms(samples, n, 'A');
    double rmsB = compute_rms(samples, n, 'B');
    double rmsC = compute_rms(samples, n, 'C');

    printf("RMS Values:\n");
    printf("Phase A: %.2f V\n", rmsA);
    printf("Phase B: %.2f V\n", rmsB);
    printf("Phase C: %.2f V\n\n", rmsC);
// Peak to Peak

    double p2pA = compute_peak_to_peak(samples, n, 'A');
    double p2pB = compute_peak_to_peak(samples, n, 'B');
    double p2pC = compute_peak_to_peak(samples, n, 'C');

    printf("Peak-to-Peak:\n");
    printf("A: %.2f V\n", p2pA);
    printf("B: %.2f V\n", p2pB);
    printf("C: %.2f V\n\n", p2pC);

// DC OFFSET

    double dcA = compute_dc_offset(samples, n, 'A');
    double dcB = compute_dc_offset(samples, n, 'B');
    double dcC = compute_dc_offset(samples, n, 'C');

    printf("DC Offset:\n");
    printf("A: %.5f V\n", dcA);
    printf("B: %.5f V\n", dcB);
    printf("C: %.5f V\n\n", dcC);






    // Free memory
    free(samples);

    return 0;
}