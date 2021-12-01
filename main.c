#include <stdio.h>
#include "my_mat.h"

#define TRUE 1

int main() 
{
     /* Initialize a graph matrix and distance matrix. */
     int matrix[MAT_SIZE][MAT_SIZE];
     int dist_matrix[MAT_SIZE][MAT_SIZE];

     while (TRUE) { /* Loop until 'D' is chosen. */
          switch (getchar()) {
          case 'A':
               scan_matrix(matrix, dist_matrix);
               break;
          case 'B':
               route_exists(matrix);
               break;
          case 'C':
               shortest_route(dist_matrix);
               break;
          case 'D':
               return 0;
          }
     }
}
