/* Copyright 2016 <Pythonovci> */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct memory {
  int dice[20];
};
struct memory history[5];

int choosing_dice(int *dice_sides) {
  int dice_choice;
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
      printf("\nYOU SELECTED 4-SIDED DICE\n\n");
      *dice_sides = 4;
      break;
    case 2:
      printf("\nYOU SELECTED 6-SIDED DICE\n\n");
      *dice_sides = 6;
      break;
    case 3:
      printf("\nYOU SELECTED 8-SIDED DICE\n\n");
      *dice_sides = 8;
      break;
    case 4:
      printf("\nYOU SELECTED 10-SIDED DICE\n\n");
      *dice_sides = 10;
      break;
    case 5:
      printf("\nYOU SELECTED 12-SIDED DICE\n\n");
      *dice_sides = 12;
      break;
    case 6:
      printf("\nYOU SELECTED 20-SIDED DICE\n\n");
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

int unos_history_dice(int *x, struct memory history[], int *k,
  int dice_sides) {
  int i = 0;
    if ( *k > 4){
      for( i = 0; i < dice_sides; i++){
        for ( (*k) = 1 ; (*k) < 5; (*k)++ ){
          history[*k-1].dice[i] = history[*k].dice[i];
        }
      }
      i = 0;
      *k = 4;
      for( i = 0; i < dice_sides; i++){
      history[*k].dice[i] = x[i];}
    }
  else {
    for( i = 0; i < dice_sides; i++){
    history[*k].dice[i] = x[i];
      }
    }
    return *k;
  }


void rolling_dice(int *x, int dice_sides, int *k) {
  int number_of_dice, dice_roll;
  int random_number = 0;
  time_t t;
  int i, j;
  printf("\nHow many dice? ");
  scanf("%d", &number_of_dice);
  if ( number_of_dice > 10 ) {
    printf("\nYou entered invalid number of dice!\n");
    return rolling_dice(x, dice_sides,k);
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
  unos_history_dice(x,history,k,dice_sides);
  (*k)++;
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
  printf("4) History\n");
  printf("5) Exit\n");
  scanf("%d", &*choice);
  return *choice;
  }

void rolling_again (int *x, int dice_sides, int *k) {
  char answer;
  printf("\nDo you want to roll dice again ? [Y/N]\n");
  while (scanf(" %c", &answer) == 1 && answer == 'Y' || answer == 'y') {
  rolling_dice(x, dice_sides,k);
  reseting_dice(&dice_sides,x);
  printf("\nDo you want to roll dice again? [Y/N]\n");
  }

}

void rolling_again2 (int *x, int dice_sides, int *k) {
  char answer;
  printf("\nDo you want to roll dice again ? [Y/N]\n");
  while (scanf(" %c", &answer) == 1 && answer == 'Y' || answer == 'y') {
  rolling_dice(x, dice_sides,k);
  printf("\nDo you want to roll dice again? [Y/N]\n");
  }
}

void error_no_table(int *x, int dice_sides) {
  int i;
  for(i = 0; i < dice_sides; i++) {
    if (x[i] > 20) {
      printf("\nError: No table to update!\n");
      reseting_dice(&dice_sides, x);
    }
    if (x[i] < 0) {
      printf("\nError: Current table is empty!\nUpdating new table!\n");
      reseting_dice(&dice_sides, x);
    }
  }
}

void history_ispis(struct memory history[], int *dice_sides) {
  int j,k;
  for(j = 0; j < 5; j++) {
    for (k = 0; k < *dice_sides; k++ ) {
    printf("%d: %d\n", (k+1), history[j].dice[k]);
  }
  printf("\n");
}
}

int main() {
  int choice;
  int dice_sides = 6, k = 0, l = 0;
  int x[6];
  char unwantedCharacters[40];
  unwantedCharacters[0] = 0;
  time_t t;
  while (choice != '4') {
  menu(&choice);
  fgets(unwantedCharacters, 40, stdin);
  if (isalpha(unwantedCharacters[0]) == 0)  {
  switch (choice) {
  case 1:
    printf("\nYOU SELECTED OPTION 1\n");
    choosing_dice(&dice_sides);
    break;
  case 2:
    printf("\nYOU SELECTED OPTION 2\n");
    reseting_dice(&dice_sides, x);
    printf("\nYou are rolling %d sided dice\n", dice_sides);
    rolling_dice(x, dice_sides, &k);
    reseting_dice(&dice_sides, x);
    rolling_again(x, dice_sides, &k);
    break;
  case 3:
    printf("\nYOU SELECTED OPTION 3\n");
    error_no_table(x, dice_sides);
    printf("\nYou are rolling %d sided dice\n", dice_sides);
    rolling_dice(x, dice_sides, &l);
    rolling_again2(x, dice_sides, &l);
    break;
  case 4:
    printf("\nYOU SELECTED OPTION 4\n\n");
    choosing_dice(&dice_sides);
    history_ispis(history, &dice_sides);
    break;
  case 5:
    printf("\nYOU SELECTED OPTION 5\n\n");
    return 0;
  default:
    printf("\nWRONG INPUT\n\n");
    return 0;
     }
   }
  else {
    printf("\nERROR WRONG INPUT!\n\n");
  }
 }
}
