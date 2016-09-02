/* Copyright 2016 <Pythonovci> */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rolling_dice(int dice_side, int dice_roll, int random_number, int *number_on_dice, int dice_sides) {
  time_t t;
  int i, j;
  printf("\nHow many dice? ");
  scanf("%d", &dice_side);
  if ( dice_side > 10 ) {
    printf("\nYou entered invalid number of dice!\n\n");
  }
  printf("How many rolls? ");
  scanf("%d", &dice_roll);
  srand((unsigned) time(&t));
  for ( i = 0; i < dice_roll; i++ ) {
    number_on_dice[i] = 0;
  }
  for ( i = 0; i < dice_side; i++ ) {
    for ( j = 0; j < dice_roll; j++ ) {
      random_number = rand()%dice_sides+1;
      number_on_dice[random_number-1]++;
    }
    for ( i = 0; i < dice_sides; i++ ) {
    printf("%d: %d\n", (i + 1), number_on_dice[i]);
    }
  }
}

int main() {
  int dice_sides;
  dice_sides = 6;
  int i, j, dice_side, dice_roll, random_number;
  random_number = 0;
  char answer;
  int number_on_dice[dice_sides];
  int choice;
  int dice_choice;
  time_t t;
  while (choice != '4') {
  printf("-------Menu-------\n");
  printf("1) Choose dice\n");
  printf("2) Roll dice, update new table \n");
  printf("3) Roll dice, update old table\n");
  printf("4) Exit\n");
  scanf("%d", &choice);
  switch (choice) {
  case 1:
    printf("\nYOU SELECTED OPTION 1\n");
    printf("-------Dice-------\n");
    printf("1) 4-sides\n");
    printf("2) 6-sides \n");
    printf("3) 8-sides\n");
    printf("4) 10-sides\n");
    printf("5) 12-sides\n");
    printf("6) 20-sides\n");
    scanf("%d", &dice_choice);
    switch (dice_choice) {
      case 1:
        printf("\nYOU SELECTED 4-SIDED DICE\n");
        dice_sides = 4;
        break;
      case 2:
        printf("\nYOU SELECTED 6-SIDED DICE\n");
        dice_sides = 6;
        break;
      case 3:
        printf("\nYOU SELECTED 8-SIDED DICE\n");
        dice_sides = 8;
        break;
      case 4:
        printf("\nYOU SELECTED 8-SIDED DICE\n");
        dice_sides = 10;
        break;
      case 5:
        printf("\nYOU SELECTED 8-SIDED DICE\n");
        dice_sides = 12;
        break;
      case 6:
        printf("\nYOU SELECTED 8-SIDED DICE\n");
        dice_sides = 20;
        break;
      }
      break;
  case 2:
    printf("\nYOU SELECTED OPTION 2\n");
    for ( i = 0; i < dice_sides; i++ ) {
      number_on_dice[i] = 0;
    }
    printf("\nYou are rolling %d sided dice\n", dice_sides);
    rolling_dice(dice_side, dice_roll, random_number, number_on_dice, dice_sides);
    printf("Do you want to roll dice again ? [Y/N]");
    while (scanf(" %c", &answer) == 1 && answer == 'Y' || answer == 'y') {
      for ( i = 0; i < dice_sides; i++ ) {
        number_on_dice[i] = 0;
      }
      printf("\nYou are rolling %d sided dice\n", dice_sides);
      rolling_dice(dice_side, dice_roll, random_number, number_on_dice, dice_sides);
      printf("Do you want to roll dice again? [Y/N]");
    }
    break;
  case 3:
    printf("\nYOU SELECTED OPTION 3\n");
    rolling_dice(dice_side, dice_roll, random_number, number_on_dice, dice_sides);
    printf("\nDo you want to roll dice again ? [Y/N]\n");
    while (scanf(" %c", &answer) == 1 && answer == 'Y' || answer == 'y') {
      rolling_dice(dice_side, dice_roll, random_number, number_on_dice, dice_sides);
      printf("\nDo you want to roll dice again? [Y/N]\n");
    }
    break;
  case 4:
    printf("\nYOU SELECTED OPTION 4\n\n");
    return 0;
      }
  }
}
