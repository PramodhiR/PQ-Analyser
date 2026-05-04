#ifndef WAVEFORM_H
#define WAVEFORM_H

typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
} WaveformSample;
// RMS
double compute_rms(WaveformSample *samples, int n, char phase);
// PEAK TO PEAK
double compute_peak_to_peak(WaveformSample *samples, int n, char phase);





#endif