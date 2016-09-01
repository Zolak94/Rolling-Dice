#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  int i,j,n,m,k,z;
  z=0;
  int x[5];
  for ( i = 0; i < 6; i++ ){
    x[i]=0;
  }
  int choice;
  int dice_choice;
  time_t t;
  while ( choice!='4') {
  printf("-------Menu-------\n");
  printf("1) Choose dice\n");
  printf("2) Roll dice, update new table \n");
  printf("3) Roll dice, update old table\n");
  printf("4) Exit\n");
  scanf("%d", &choice);
  switch(choice){
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
    switch(dice_choice){
      case 1:
      printf("\nYOU SELECTED 4-SIDED DICE\n");
      printf("\nHow many dice? ");
      scanf("%d", &n);
      if ( n > 10 ) {
        printf("\nYou entered invalid number of dice!\n\n");
        return main();
      }
      printf("How many rolls? ");
      scanf("%d", &m);
      srand((unsigned) time(&t));
      for ( i = 0; i < 4; i++ ){
        x[i]=0;
      }
      for ( i = 0; i < m; i++ ) {
        for ( j = 0; j < n; j++ ) {
          z = rand()%4+1;
          if ( z == 1 ) {
            x[0]++;
          }
          if ( z == 2 ) {
            x[1]++;
          }
          if ( z == 3 ) {
            x[2]++;
          }
          if ( z == 4 ) {
            x[3]++;
          }
        }
        for ( i = 0; i < 4; i++ ) {
        printf ("%d: %d\n", ( i + 1 ), x[i] );
        }
        break;
      }
    }
    break;
  case 4:
    printf("\nYOU SELECTED OPTION 4\n");
    return 0;
  case 2:
    printf("\nYOU SELECTED OPTION 2\n");
    printf("\nHow many dice? ");
    scanf("%d", &n);
    if ( n > 10 ) {
      printf("\nYou entered invalid number of dice!\n\n");
      return main();
    }
    printf("How many rolls? ");
    scanf("%d", &m);
    srand((unsigned) time(&t));
    for ( i = 0; i < 6; i++ ){
      x[i]=0;
    }
    for ( i = 0; i < m; i++ ) {
      for ( j = 0; j < n; j++ ) {
        z = rand()%6+1;
        if ( z == 1 ) {
          x[0]++;
        }
        if ( z == 2 ) {
          x[1]++;
        }
        if ( z == 3 ) {
          x[2]++;
        }
        if ( z == 4 ) {
          x[3]++;
        }
        if ( z == 5 ) {
          x[4]++;
        }
        if ( z == 6 ) {
          x[5]++;}
        }
      }
      for ( i = 0; i < 6; i++ ) {
      printf ("%d: %d\n", ( i + 1 ), x[i] );
      }
      break;
      case 3:
      printf("\nYOU SELECTED OPTION 3\n");
      printf("\nHow many dice? ");
      scanf("%d", &n);
      if ( n > 10 ) {
        printf("\nYou entered invalid number of dice!\n\n");
        return main();
      }
      printf("How many rolls? ");
      scanf("%d", &m);
      srand((unsigned) time(&t));
      for ( i = 0; i < m; i++ ) {
        for ( j = 0; j < n; j++ ) {
          z = rand()%6+1;
          if ( z == 1 ) {
            x[0]++;
          }
          if ( z == 2 ) {
            x[1]++;
          }
          if ( z == 3 ) {
            x[2]++;
          }
          if ( z == 4 ) {
            x[3]++;
          }
          if ( z == 5 ) {
            x[4]++;
          }
          if ( z == 6 ) {
            x[5]++;}
          }
        }
        for ( i = 0; i < 6; i++ ) {
        printf ("%d: %d\n", ( i + 1 ), x[i] );
        }
        break;

      }
    return main();
  }
}
