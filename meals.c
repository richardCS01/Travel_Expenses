#include "meals.h"

float mealFees(int arrivalTime, int departureTime, float *mealAllowance, float *mealExcess, float *mealSaved)
{
    const int BREAKFAST_ALLOWANCE = 9;
    const int LUNCH_ALLOWANCE = 12;
    const int DINNER_ALLOWANCE = 16;
    float mealTotal, mealCost1, mealCost2, mealAllow1, mealAllow2;
    int increment = 0;


    do{
        //Determine Departure Meal
        if(departureTime == 2400)
        {
            departureTime = 0;
        }

        if(departureTime < 700 && departureTime >= 0)
        {
            printf("\nThe company allows for Breakfast, with an allowance of $9.00: \n");
            printf("Enter Meal Total: ");
            scanf("%f", &mealCost1);

            printf("You entered: $%.2f\n", mealCost1);  

            mealAllow1 = BREAKFAST_ALLOWANCE;
                

        }
        else if(departureTime >= 700 && departureTime < 1200)
        {

            printf("\nThe company allows for Lunch, with an allowance of $12.00: \n");
            printf("Enter Meal Total: ");
            scanf("%f", &mealCost1);

            printf("You entered: $%.2f\n", mealCost1);  

            mealAllow1 = LUNCH_ALLOWANCE;
                
        }
        else if(departureTime >= 1200 && departureTime < 1800)
        {

            printf("\nThe company allows for Dinner, with an allowance of $16.00: \n");
            printf("Enter Meal Total: ");
            scanf("%f", &mealCost1);

            printf("You entered: $%.2f\n", mealCost1);  

            mealAllow1 = DINNER_ALLOWANCE;
                
        }

        //Determine Arrival Meal
        if(arrivalTime > 800 && arrivalTime <= 1300)
        {

            printf("\nThe company allows for Breakfast, with an allowance of $9.00: \n");
            printf("Enter Meal Total: ");
            scanf("%ff", &mealCost2);

            printf("You entered: $%.2f\n", mealCost2);  

            mealAllow2 = BREAKFAST_ALLOWANCE;
            }
            else if(arrivalTime > 1300 && arrivalTime <= 1900)
            {

            printf("\nThe company allows for Lunch, with an allowance of $12.00: \n");
            printf("Enter Meal Total: ");
            scanf("%f", &mealCost2);

            printf("You entered: $%.2f\n", mealCost2);  

            mealAllow2 = LUNCH_ALLOWANCE;
            }
            else if(arrivalTime > 1900 && arrivalTime <= 2400)
            {

            printf("\nThe company allows for Dinner, with an allowance of $16.00: \n");
            printf("Enter Meal Total: ");
            scanf("%f", &mealCost2);

            printf("You entered: $%.2f\n", mealCost2);  

            mealAllow2 = DINNER_ALLOWANCE;
            }
    increment++;
    }
    while(increment < 1);


        //FINAL CALCULATIONS
        *mealAllowance = mealAllow1 + mealAllow2;
        mealTotal = mealCost1 + mealCost2;
        
        if(*mealAllowance < mealTotal)
            *mealExcess = mealTotal - *mealAllowance;
        else if(*mealAllowance > mealTotal)
            *mealSaved = *mealAllowance - mealTotal;

    return mealTotal;
}