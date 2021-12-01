#include <stdio.h>
#include "my_mat.h"

/* Populates matrix with user input. */ 
void scan_matrix(int matrix[MAT_SIZE][MAT_SIZE],
     int dist_matrix[MAT_SIZE][MAT_SIZE])
{
     for (size_t i = 0; i < MAT_SIZE; i++) {
          for (size_t j = 0; j < MAT_SIZE; j++) {
               int weight;
               scanf("%d", &weight);
               matrix[i][j] = weight;

               /* Add the weight of the edge to dist_matrix, or
                * mark that there is no edge. */
               if (weight > 0) {
                    dist_matrix[i][j] = weight;
               } else {
                    dist_matrix[i][j] = -1;
               }
          }
     }
}

/* Prints "True" if there is a route between i,j (nodes in the
 * graph), or "False" otherwise. */
void route_exists(int matrix[MAT_SIZE][MAT_SIZE]) 
{
     /* Nodes to check. */
     int i, j;
     scanf("%d%d", &i, &j);

     /* Special case for i = j, since the algorithm I implemented
      * below doesn't handle it. */
     if (i == j) {
          if (matrix[i][j] == 0) {
               printf("False\n");
          } else {
               printf("True\n");
          }

          return;
     }

     /* Array of all nodes (excluding i and j). */
     int nodes[MAT_SIZE - 2];

     /* Populate it. */
     int index = 0;
     for (size_t p = 0; p < MAT_SIZE; p++) {
          if (p != i && p != j) {
               nodes[index] = p;
               index++;
          }
     }

     /* Array of source nodes - nodes for which we know a route to i
      * exists (initially only i). -1 marks a "null" node. */
     int source_nodes[MAT_SIZE] = {i, -1, -1, -1, -1, -1, -1, -1, -1, -1};
     size_t source_index = 0; /* Current node under consideration. */
     size_t max_source_index = source_index; /* Last "real" (!= -1) node. */

     /* Same as the source array, but for routes to j. */
     int target_nodes[MAT_SIZE] = {j, -1, -1, -1, -1, -1, -1, -1, -1, -1};
     size_t target_index = 0;
     size_t max_target_index = target_index;

     /* Continue looping until we run out of nodes to consider. */
     while (!(source_nodes[source_index] == -1
              && target_nodes[target_index] == -1)
            && !(source_index >= MAT_SIZE
                 || target_index >= MAT_SIZE)) {
          int curr_source = source_nodes[source_index];
          int curr_target = target_nodes[target_index];

          /* Loop over all non-source/target nodes. */
          for (size_t n = 0; n < MAT_SIZE - 2; n++) {
               /* If this node is connected to the current source
                * node, add it to the source_nodes array. */ 
               if (curr_source != 1) {
                    if (matrix[curr_source][nodes[n]] > 0) {
                         max_source_index++;
                         source_nodes[max_source_index] = nodes[n];
                    }
               }

               /* Same as above for the current target node. */
               if (curr_target != 1) {
                    if (matrix[curr_target][nodes[n]] > 0) {
                         max_target_index++;
                         target_nodes[max_target_index] = nodes[n];
                    }
               }
          }

          /* Loop over all target nodes. */
          for (size_t t = 0; t < max_target_index + 1; t++) {
               /* If this target node is equal to the current source
                * node, a route exists between i and j. */
               if (curr_source == target_nodes[t]) {
                    printf("True\n");
                    return;
               }
          }

          /* Make sure the indices don't advance for no reason. */
          if (curr_source != -1) {
               source_index++;    
          }

          if (curr_target != -1) {
               target_index++;
          }
     }

     /* If the loop above finished, no route was found between i and j. */
     printf("False\n");
}

/* Prints the weight of the shortest route between i,j (nodes in the
 * graph), or "-1" if there is no route. */
void shortest_route(int dist_matrix[MAT_SIZE][MAT_SIZE]) 
{
     /* Nodes to check. */
     int i, j;
     scanf("%d%d", &i, &j);

     /* Almost exact copy of the Floyd-Warshall algorithm; only
      * difference being two special cases which arise from treating
      * the distance -1 as infinity. */
     for (size_t n = 0; n < MAT_SIZE; n++) {
          for (size_t m = 0; m < MAT_SIZE; m++) {
               for (size_t l = 0; l < MAT_SIZE; l++) {
                    int dist_sum = dist_matrix[m][n] + dist_matrix[n][l];

                    /* Special case, no (m, l) edge. */
                    if (dist_matrix[m][l] == -1) {
                         if (dist_matrix[m][n] == -1
                             || dist_matrix[n][l] == -1) {
                              continue;
                         } else { /* If the other edges exits, their
                                   * sum must be smaller. */
                              dist_matrix[m][l] = dist_sum;
                         }
                         /* Special case, (m, l) is an edge but one of
                          * (m, n), (n, l) aren't. In this case, just
                          * keep the original value. */
                    } else if (dist_matrix[m][n] == -1
                               || dist_matrix[n][l] == -1) {
                         continue;
                    } else if (dist_matrix[m][l] > dist_sum) {
                         dist_matrix[m][l] = dist_sum;
                    }
               }
          }
     }

     /* Print the distance calculated for (i, j). */
     printf("%d\n", dist_matrix[i][j]);
}
