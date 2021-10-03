
int getTotalDays(){
  int days;
  bool isValid = false;
  while(!isValid) {
  printf("Enter the total number of days spent on the trip\n");
  scanf("%d", &days);
  isValid = true;
  if(!(days > 1)) {
    isValid = false;
  }
  }
  return days;
}

int getTimeOfDepature() {
  char time[4];
  int timeInt = 0;
  bool isNotValidTime = false;
  while(!isNotValidTime) {
  printf("Enter the time of depature to the trip in military time example 9:00am = 0900\n");
  scanf("%c", &time);

   if(strlen(time) != 4) {
     isNotValidTime = true;
     continue;
   }
   if(time[0] == '0') {
     for(int i = 1; i < 4; i++) {
       int digit = atoi(time[i]);
       if(digit > 9 || digit < 0) {
         isNotValidTime = true;
       }
       if(i == 2 && digit > 5) {
         isNotValidTime = true;
       }
     }
   }
   if(time[0] != '0') {
     if(atoi(time) > 2400 || atoi(time) < 0) {
       isNotValidTime = true;
     }
     for(int i = 0; i < 4; i++) {
       int digit = atoi(time[i]);
       if(i == 0 && (digit > 2 || digit < 0)) {
         isNotValidTime = true;
       }
       if(i == 1 && (digit > 9 || digit < 0)) {
         isNotValidTime = true;
       }
       if(i == 2 && digit > 5) {
         isNotValidTime = true;
       }
     }
   }
   if(isNotValidTime == true) {
     isNotValidTime = false;
   }
   if(isNotValidTime == false) {
     break;
   }
  }
  if(time[0] == '0'){
    int x = 100;
    for(int i = 1; i < 4; i++) {
      timeInt += atoi(time[i]) * x;
      x = x / 10;
    }
    return timeInt;
  }
  if(time[0] != '0') {
    timeInt = atoi(time);
  }
  return timeInt;
}

int getTimeOfArrival() {
  char time[4];
  int timeInt = 0;
  bool isNotValidTime = false;
  while(!isNotValidTime) {
  printf("Enter the time of arravile to home in military time example 9:00am = 0900\n");
  scanf("%c", &time);

   if(strlen(time) != 4) {
     isNotValidTime = true;
     continue;
   }
   if(time[0] == '0') {
     for(int i = 1; i < 4; i++) {
       int digit = atoi(time[i]);
       if(digit > 9 || digit < 0) {
         isNotValidTime = true;
       }
       if(i == 2 && digit > 5) {
         isNotValidTime = true;
       }
     }
   }
   if(time[0] != '0') {
     if(atoi(time) > 2400 || atoi(time) < 0) {
       isNotValidTime = true;
     }
     for(int i = 0; i < 4; i++) {
       int digit = atoi(time[i]);
       if(i == 0 && (digit > 2 || digit < 0)) {
         isNotValidTime = true;
       }
       if(i == 1 && (digit > 9 || digit < 0)) {
         isNotValidTime = true;
       }
       if(i == 2 && digit > 5) {
         isNotValidTime = true;
       }
     }
   }
   if(isNotValidTime == true) {
     isNotValidTime = false;
   }
   if(isNotValidTime == false) {
     break;
   }
  }
  if(time[0] == '0'){
    int x = 100;
    for(int i = 1; i < 4; i++) {
      timeInt += atoi(time[i]) * x;
      x = x / 10;
    }
    return timeInt;
  }
  if(time[0] != '0') {
    timeInt = atoi(time);
  }
  return timeInt;
}

double getAirFare() {
  double fare;
  bool isValid = false;
  while(!isValid) {
  printf("Enter the amount of your air fair\n");
  scanf("%lf", &fare);
  isValid = true;
  if(fare < 0) {
    isValid = false;
  }
  }
  return fare;
}

double getRentals() {
  double fare;
  bool isValid = false;
  while(!isValid) {
  printf("Enter the amount of your car rentals\n");
  scanf("%lf", &fare);
  isValid = true;
  if(fare < 0) {
    isValid = false;
  }
  }
  return fare;
}