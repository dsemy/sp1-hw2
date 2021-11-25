#include <stdio.h>
#include "my_mat.h"

int main() 
{
     int matrix[MAT_ROW][MAT_COL];

     char choice = ' ';
     while (choice != 'D') {
          scanf("%c", &choice);
          switch (choice) {
                    case 'A':
                         scan_matrix(matrix);
                         break;
               }
     }
     return 0;
}
