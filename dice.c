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
  time_t t;
  while ( choice!='4') {
  printf("-------Menu-------\n");
  printf("1) Choose dice\n");
  printf("2) Roll dice, update new table \n");
  printf("3) Roll dice, update old table\n");
  printf("4) Exit\n");
  scanf("%d", &choice);
  switch(choice){
  case 4:
    printf("\nYOU SELECTED OPTION 4\n");
    return 0;
  case 2:
    printf("\nYOU SELECTED OPTION 2\n");
    printf("\nHow many dice? ");
    scanf("%d", &n);
    if ( n > 10 ) {
      return 0;
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
