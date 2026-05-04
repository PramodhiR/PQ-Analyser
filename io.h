#ifndef IO_H
#define IO_H

#include "waveform.h"

WaveformSample* load_csv(const char *filename, int *n);

//Write results
void write_results(const char *filename,
                   double rmsA, double rmsB, double rmsC,
                   double p2pA, double p2pB, double p2pC,
                   double dcA, double dcB, double dcC,
                   int clipA, int clipB, int clipC);
#endif