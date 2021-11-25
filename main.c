#include <stdio.h>
#include "my_mat.h"

int main() 
{
     int matrix[MAT_SIZE][MAT_SIZE];

     char choice = ' ';
     while (choice != 'D') {
          scanf("%c", &choice);
          switch (choice) {
          case 'A':
               scan_matrix(matrix);
               break;
          case 'B':
               route_exists(matrix);
               break;
          }
     }
     return 0;
}
