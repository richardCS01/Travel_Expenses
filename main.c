#include "getFees.h"
#include "information.h"
#include "meals.h"
#include "transportation.h"

#include <stdio.h>

int main() {
   int myTotalDays, myTimeOfDeparture, myTimeOfArrival;
   double myAirFare, myRentals;   // info from information.c
   float myVehicleExpenses, myParkingFees, myTaxiFees;    // info from transportation.c
   float myConferenceFees, myHotelExpenses;     // info from getFees.c
   float myMealFees;    // info from meals.c
   
   // pulling data from information.c
   myTotalDays = getTotalDays();
   myTimeOfDeparture = getTimeOfDeparture();
   myTimeOfArrival = getTimeOfArrival();
   myAirFare = getAirFare();
   myRentals = getRentals();
   
   // pulling data from transportation.c
   myVehicleExpenses = miles();
   float parkingAllowance, parkingExcess, parkingSaved;
   myParkingFees = parkingFees(myTotalDays, &parkingAllowance, &parkingExcess, &parkingSaved);
   // printf("parkingAllowance = %.2f\nparkingExcess = %.2f\nparkingSaved = %.2f\n", parkingAllowance, parkingExcess, parkingSaved);
   float taxiAllowance, taxiExcess, taxiSaved;
   myTaxiFees = taxiFees(&taxiAllowance, &taxiExcess, &taxiSaved);
   
   // pulling data from getFees.c
   myConferenceFees = getConferenceFees();
   float hotelAllowance, hotelExcess, hotelSaved;
   myHotelExpenses = getHotelExpenses(myTotalDays, &hotelAllowance, &hotelExcess, &hotelSaved);
   // printf("hotelAllowance = %.2f\nhotelExcess = %.2f\nhotelSaved = %.2f\n", hotelAllowance, hotelExcess, hotelSaved);
   
   // pulling data from meals.c
   float mealAllowance, mealExcess, mealSaved;
   myMealFees = mealFees(myTimeOfArrival, myTimeOfDeparture, &mealAllowance, &mealExcess, &mealSaved);
   
   float totalExpenses = myAirFare + myRentals + myVehicleExpenses + myParkingFees + myTaxiFees + myConferenceFees + myHotelExpenses + myMealFees;
   float allowableExpenses = parkingAllowance + taxiAllowance + hotelAllowance + mealAllowance;
   float totalExcess = parkingExcess + taxiExcess + hotelExcess + mealExcess;
   float totalSaved = parkingSaved + taxiSaved + mealSaved + hotelSaved;
   
   printf("\nTotal expenses: $%.2f\n", totalExpenses);
   printf("Total allowable expenses: $%.2f\n", allowableExpenses);
   printf("Total excess: $%.2f\n", totalExcess);
   printf("Total saved: $%.2f\n", totalSaved);
   
   return 0;
}
