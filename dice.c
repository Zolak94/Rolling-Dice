#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  int i,j,n,m;
  time_t t;
  printf("How many dice? ");
  scanf("%d", &n);
  if ( n > 11 ) {
    return 0;
  }
  printf("How many rolls? ");
  scanf("%d", &m);
  srand((unsigned) time(&t));
  for ( i = 0; i < m; i++ ) {
    printf("%d: {", i + 1 );
    for ( j = 0; j < n; j++ ) {
      printf("%d", rand()%6+1);
      if ( j < ( n - 1 )) {
        printf(",");
      }
    }
    printf("}\n");
  }
  return 0;
}
