#include <stdio.h>
#include "my_mat.h"

#define RED 1
#define BLUE 2

void scan_matrix(int matrix[MAT_SIZE][MAT_SIZE])
{
     for (int i = 0; i < MAT_SIZE; i++) {
          for (int j = 0; j < MAT_SIZE; j++) {
               printf("%d,%d: ", i, j);
               scanf("%d", &matrix[i][j]);
          }
     }
}

void route_exists(int matrix[MAT_SIZE][MAT_SIZE]) 
{
     int cons[MAT_SIZE] = {0};

     int i, j;
     scanf("%d%d", &i, &j);

     cons[i] = RED;
     cons[j] = BLUE;

     for (int k = 0; k < MAT_SIZE; k++) {
          if (matrix[k][i] != 0) {
               cons[k] += RED;
               if (cons[k] == 3) {
                    printf("True");
                    return;
               }
          }
          if (matrix[j][k] != 0) {
               cons[k] += BLUE;
               if (cons[k] == 3) {
                    printf("True");
                    return;
               }
          }
     }
     printf("False");
}
