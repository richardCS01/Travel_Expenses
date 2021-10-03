#include "transportation.h"

float miles()
{
   const float costPerMile = 0.27;
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
         vehicleExpense = milesDriven * costPerMile;
   }
   return vehicleExpense;
}

float parkingFees()
{
   float parkingTotal;

tryAgain:

   printf("How much did you spend on parking during your trip?\n");
   scanf("%f", &parkingTotal);

   if (parkingTotal < 0)
   {
      printf("You have entered an invalid value for the total you spent on parking fees. Please try again.\n");
      goto tryAgain;
   }
   return parkingTotal;
}

float taxiFees(int days, double *total)
{

}