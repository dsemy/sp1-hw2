#include <stdio.h>
#include "my_mat.h"

void scan_matrix(int matrix[MAT_ROW][MAT_COL])
{
     for (int i = 0; i < MAT_ROW; i++) {
          for (int j = 0; j < MAT_COL; j++) {
               printf("%d,%d: ", i, j);
               scanf("%d", &matrix[i][j]);
          }
     }
}
