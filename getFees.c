#include "getFees.h"
#include <stdio.h>

float getConferenceFees() {
   float fees;
   printf("Enter any conference/seminar fees: ");
   scanf("%f", &fees);
   return fees;
}

float getHotelExpenses(int numOfDays) {
   const float COMPANY_COVERED = 90.00 * numOfDays;
   float fees;
   printf("Enter hotel fees: ");
   scanf("%f", &fees);
   fees = fees * numOfDays;
   if(fees <= COMPANY_COVERED) {
      printf("The company has covered your hotel fees.\n");
      fees = 0;
   }
   else {
      printf("The company has covered $90/night of your hotel fees.\n");
   }
   return fees;
}