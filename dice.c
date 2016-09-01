#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  int i,j,n,m,k,z,x1,x2,x3,x4,x5,x6;
  x1=0;
  x2=0;
  x3=0;
  x4=0;
  x5=0;
  x6=0;
  z=0;
  int choice;
  time_t t;
  printf("-------Menu-------\n");
  printf("1) Choose dice\n");
  printf("2) Roll dice, update new table \n");
  printf("3) Roll dice, update old table\n");
  printf("4) Exit\n");
  scanf("%d", &choice);
  if (choice==4)
   {
      return 0;
    }
  if (choice==2)
   {
      printf("You chose program 2!\n");
  printf("How many dice? ");
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
        x1++;
      }
      if ( z == 2 ) {
        x2++;
      }
      if ( z == 3 ) {
        x3++;
      }
      if ( z == 4 ) {
        x4++;
      }
      if ( z == 5 ) {
        x5++;
      }
      if ( z == 6 ) {
        x6++;}
      }
    }
    printf ("1:%d\n",x1);
    printf ("2:%d\n",x2);
    printf ("3:%d\n",x3);
    printf ("4:%d\n",x4);
    printf ("5:%d\n",x5);
    printf ("6:%d\n",x6);
  }
  return main();
}
