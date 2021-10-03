#include "getFees.h"
#include <stdio.h>

float getConferenceFees() {
   float fees;
   printf("Enter any conference/seminar fees: ");
   scanf("%f", &fees);
   return fees;
}

float getHotelExpenses(int numOfDays, float *hotelAllowance, float *hotelExcess, float *hotelSaved) {    // make sure to assign these vars in main!
   const float COMPANY_COVERED = 90.00;
   
   tryAgain: ;
   
   float fees;
   printf("Enter total amount of hotel expenses spent: ");
   scanf("%f", &fees);
   
   if(fees < 0) {
      printf("Expenses cannot be a negative number!\n");
      goto tryAgain;
   }
   
   *hotelAllowance = COMPANY_COVERED * numOfDays;
   
   if(fees > *hotelAllowance)
      *hotelExcess = fees - *hotelAllowance;
   else if(fees < *hotelAllowance)
      *hotelSaved = *hotelAllowance - fees;
   
   return fees;
}