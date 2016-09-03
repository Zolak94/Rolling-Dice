/* Copyright 2016 <Pythonovci> */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choosing_dice(int *dice_sides) {
  int dice_choice;
  printf("\nYOU SELECTED OPTION 1\n");
  printf("-------Dice-------\n");
  printf("1) 4-sides\n");
  printf("2) 6-sides \n");
  printf("3) 8-sides\n");
  printf("4) 10-sides\n");
  printf("5) 12-sides\n");
  printf("6) 20-sides\n");
  scanf("%d", &dice_choice);
  if (dice_choice > 6 || dice_choice < 1) {
    printf("\nInvalid choice!\n\n");
  }
  else {
  switch (dice_choice) {
    case 1:
      printf("\nYOU SELECTED 4-SIDED DICE\n");
      *dice_sides = 4;
      break;
    case 2:
      printf("\nYOU SELECTED 6-SIDED DICE\n");
      *dice_sides = 6;
      break;
    case 3:
      printf("\nYOU SELECTED 8-SIDED DICE\n");
      *dice_sides = 8;
      break;
    case 4:
      printf("\nYOU SELECTED 10-SIDED DICE\n");
      *dice_sides = 10;
      break;
    case 5:
      printf("\nYOU SELECTED 12-SIDED DICE\n");
      *dice_sides = 12;
      break;
    case 6:
      printf("\nYOU SELECTED 20-SIDED DICE\n");
      *dice_sides = 20;
      break;
      }
    return *dice_sides;
    }
  }

void printing_table(int dice_sides, int *x) {
  int i;
  for ( i = 0; i < dice_sides; i++ ) {
  printf("%d: %d\n", (i + 1), x[i]);
    }
  }

void rolling_dice(int *x, int dice_sides) {
  int number_of_dice, dice_roll;
  int random_number = 0;
  time_t t;
  int i, j;
  printf("\nHow many dice? ");
  scanf("%d", &number_of_dice);
  if ( number_of_dice > 10 ) {
    printf("\nYou entered invalid number of dice!\n\n");
  }
  else {
  printf("How many rolls? ");
  scanf("%d", &dice_roll);
  srand((unsigned) time(&t));
  for ( i = 0; i < number_of_dice; i++ ) {
    for ( j = 0; j < dice_roll; j++ ) {
      random_number = rand()%dice_sides+1;
      x[random_number-1]++;
      }
    }
  printing_table(dice_sides, x);
  }
}

int reseting_dice(int *dice_sides, int *x) {
  int i;
  for (i = 0; i < *dice_sides; i++) {
    x[i] = 0;
  }
  return *dice_sides;
}

int menu(int *choice) {
  printf("-------Menu-------\n");
  printf("1) Choose dice\n");
  printf("2) Roll dice, update new table \n");
  printf("3) Roll dice, update old table\n");
  printf("4) Exit\n");
  scanf("%d", &*choice);
  return *choice;
  }

int main() {
  int i, j, choice;
  int dice_sides = 6;
  int x[5];
  char answer;
  time_t t;
  while (choice != '4') {
  menu(&choice);
  switch (choice) {
  case 1:
    choosing_dice(&dice_sides);
    break;
  case 2:
    printf("\nYOU SELECTED OPTION 2\n");
    reseting_dice(&dice_sides,x);
    printf("\nYou are rolling %d sided dice\n", dice_sides);
    rolling_dice(x, dice_sides);
    printf("Do you want to roll dice again ? [Y/N]");
    while (scanf(" %c", &answer) == 1 && answer == 'Y' || answer == 'y') {
      reseting_dice(&dice_sides,x);
      printf("\nYou are rolling %d sided dice\n", dice_sides);
      rolling_dice(x, dice_sides);
      printf("Do you want to roll dice again? [Y/N]");
    }
    break;
  case 3:
    printf("\nYOU SELECTED OPTION 3\n");
    rolling_dice(x, dice_sides);
    printf("\nDo you want to roll dice again ? [Y/N]\n");
    while (scanf(" %c", &answer) == 1 && answer == 'Y' || answer == 'y') {
      rolling_dice(x, dice_sides);
      printf("\nDo you want to roll dice again? [Y/N]\n");
    }
    break;
  case 4:
    printf("\nYOU SELECTED OPTION 4\n\n");
    return 0;
    }
  }
}
