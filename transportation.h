#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

float miles();

float parkingFees(int days, float *parkingAllowance, float *parkingExcess, float *parkingSaved);

float taxiFees(float *taxiAllowance, float *taxiExcess, float *taxiSaved);

#endif