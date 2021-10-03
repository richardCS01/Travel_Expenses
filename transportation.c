#include "transportation.h"

float miles()
{
   const float COST_PER_MILE = 0.27;
   char input[1];
   int milesDriven;
   float vehicleExpense;

   printf("Did you drive a private vehicle? (Y/N)\n");
   scanf("%s", input);

   tryAgain:

   if (input[0] == 'Y' || input[0] == 'y')
   {
      printf("How many miles did you drive?\n");
      scanf("%d", &milesDriven);

      if (milesDriven < 0)
      {
         printf("You have entered an invalid value for the number of miles driven. Please try again.\n");
         goto tryAgain;
      }
      else
         vehicleExpense = milesDriven * COST_PER_MILE;
   }
   return vehicleExpense;
}

float parkingFees(int days, float *parkingAllowance, float *parkingExcess, float *parkingSaved)
{
   const int PARKING_ALLOWANCE_RATE = 6;
   float parkingTotal;

tryAgain:

   printf("How much did you spend on parking during your trip?\n");
   scanf("%f", &parkingTotal);

   if (parkingTotal < 0)
   {
      printf("You have entered an invalid value for the total you spent on parking fees. Please try again.\n");
      goto tryAgain;
   }

   *parkingAllowance = days * PARKING_ALLOWANCE_RATE;

   if (parkingTotal > *parkingAllowance)
      *parkingExcess = parkingTotal - *parkingAllowance;
   else if (parkingTotal < *parkingAllowance)
      *parkingSaved = *parkingAllowance - parkingTotal;

   return parkingTotal;
}

float taxiFees(float *taxiAllowance, float *taxiExcess, float *taxiSaved)
{
   const int TAXI_ALLOWANCE_RATE = 10;
   char input[1];
   int taxisTaken;
   float taxiTotal;

numOfTaxis:

   printf("How many days did you use a taxi during your trip?\n");
   scanf("%d", &taxisTaken);

   if (taxisTaken < 0)
   {
      printf("You have entered an invalid value for the amount of taxis you have taken. Please try again.\n");
      goto numOfTaxis;
   }

   if (taxisTaken > 0)
   {
   tryAgain:
      printf("How much did you spend in total on taxis?\n");
      scanf("%f", &taxiTotal);

      if (taxiTotal < 0)
      {
         printf("You have entered an invalid value for the total you spent on taxis. Please try again.\n");
         goto tryAgain;
      }

      *taxiAllowance = TAXI_ALLOWANCE_RATE * taxisTaken;

      if (taxiTotal > *taxiAllowance)
         *taxiExcess = taxiTotal - *taxiAllowance;
      else if (taxiTotal < *taxiAllowance)
         *taxiSaved = *taxiAllowance - taxiTotal;
   }

   return taxiTotal;
}