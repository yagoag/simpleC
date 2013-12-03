/* Program which converts a tempereture from an scale
   to another.
   Temperature scales available: Kelvin, degrees
   Celcius and degrees Fahrenheit.

   Author: Yago Arroyo
   Date:   03/12/2013
*/

#include <stdio.h>

int main() {
  float initTemp, // initial temperature
        convTemp; // converted temperature
  int initType,   // type of the temperature to be converted
      convType,   // type of the temperature to convert to
      option;     // menu option

newConv:
  printf("Type of the temperature to be converted, following the codes:\n  1. Degrees Celcius\n  2. Degrees Fahrenheit\n  3. Kelvin\n\n");
  scanf("%d", &initType);
  system("clear || cls");

  printf("Type of the temperature to convert to, following the codes:\n  1. Degrees Celcius\n  2. Degrees Fahrenheit\n  3. Kelvin\n\n");
  scanf("%d", &convType);
  system("clear || cls");

convertion:
  printf("Type in the temperature to be converted: ");
  scanf("%f", &initTemp);
  system("clear || cls");

  switch (initType) {
         case 1:
              if (convType == 2) {
                 convTemp = (initTemp * 1.8 + 32);
                 printf("%f degrees Celcius correspond to %f degrees Fahrenheit.", initTemp, convTemp);
              }
              if (convType == 3) {
                 convTemp = (initTemp + 273.15);
                 printf("%f degrees Celcius correspond to %f Kelvin.", initTemp, convTemp);
              }
              break;
         case 2:
              if (convType == 1) {
                 convTemp = ((initTemp - 32) / 1.8);
                 printf("%f degrees Fahrenheit correspond to %f degrees Celcius.", initTemp, convTemp);
              }
              if (convType == 3) {
                 convTemp = ((initTemp - 32) / 1.8 + 237.15);
                 printf("%f degrees Fahrenheit correspond to %f Kelvin.", initTemp, convTemp);
              }
              break;
         case 3:
              if (convType == 1) {
                 convTemp = (initTemp - 273.15);
                 printf("%f Kelvin correspond to %f degrees Celcius.", initTemp, convTemp);
              }
              if (convType == 2) {
                 convTemp = ((initTemp - 273.15) * 1.8 + 32);
                 printf("%f Kelvin correspond to %f degrees Fahrenheit.", initTemp, convTemp);
              }
              break;
         default:
              printf("You didn't choose a valid option for one or more temperature scales.\n\n");
              goto newConv;
  }

  printf("\n\nSelect and option:\n1. To make a new convertion using the same temperature scales\n2. To make a new convertion using different scales\n3. To exit programa\n\n");
Menu:
  scanf("%d", &option);
  switch (option) {
         case 1:
              goto convertion;
              break;
         case 2:
              goto newConv;
              break;
         case 3:
              return 0;
         default:
              goto Menu;
  }
}
