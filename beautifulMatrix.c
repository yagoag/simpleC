/* Create and print a square matrix in which each
   new line until the middle of the matrix, you
   have a square of a digit incremented by one,
   starting and ending when the line and column
   number is the same. It's actually quite confusing,
   so here are some examples;
   This is what the matriz should look like for
   a size of 5:
             1 1 1 1 1
             1 2 2 2 1
             1 2 3 2 1
             1 2 2 2 1
             1 1 1 1 1
   and for a size of 8:
          1 1 1 1 1 1 1 1
          1 2 2 2 2 2 2 1
          1 2 3 3 3 3 2 1
          1 2 3 4 4 3 2 1
          1 2 3 4 4 3 2 1
          1 2 3 3 3 3 2 1
          1 2 2 2 2 2 2 1
          1 1 1 1 1 1 1 1

   Author: Yago Arroyo
   Date:   Oct 3rd, 2013
*/

#include <stdio.h>

// Function prototype
void beautifulMatrix(int, int**);

int main() {
   // Declaration of local variables
   int sz, **M;

   // Determination of the size of the matrix to be created
   printf("Type in the size of the matrix you want to create: ");
   scanf("%d", &sz);

   // Create and print the matrix
   beautifulMatrix(sz, M);

   return 0;
}

/* Function:  beautifulMatrix
   Objective: Create and print a square matrix in which each
              new line until the middle of the matrix, you
              have a square of a digit incremented by one,
              starting and ending when the line and column
              number is the same. It's actually quite confusing,
              so here are some examples;
              This is what the matriz should look like for
              a size of 5:
                         1 1 1 1 1
                         1 2 2 2 1
                         1 2 3 2 1
                         1 2 2 2 1
                         1 1 1 1 1
              and for a size of 8:
                      1 1 1 1 1 1 1 1
                      1 2 2 2 2 2 2 1
                      1 2 3 3 3 3 2 1
                      1 2 3 4 4 3 2 1
                      1 2 3 4 4 3 2 1
                      1 2 3 3 3 3 2 1
                      1 2 2 2 2 2 2 1
                      1 1 1 1 1 1 1 1

   Parametres:
    - sz (value):  size of the matrix to be created
    - M (pointer): pointer of pointers to the matrix
   Return: none
*/
void beautifulMatrix(int sz, int **M) {
   // Local variables
   int i, j, k;

   // Allocation of memory for the matrix's lines
   M = (int*) calloc(sz, sizeof(int));
   if (M == NULL) {
      printf("Error while allocating memory.\n");
      return;
   }

   // Allocation of memory for the matrix's columns
   for (i = 0; i < sz; i++) {
      M[i] = (int*) calloc(sz, sizeof(int));
      if (M[i] == NULL) {
      printf("Error while allocating memory.\n");
      return;
      }
   }

   // Inicialization of the matrix
   for (i = 0; i < sz; i++)
      for (j = 0; j < sz; j++)
         M[i][j] = 0;

   // Creation of the desired matrix
   for (k = 0; k < sz; k++)
      for (i = k; i < sz; i++)
         for (j = k; j < sz; j++)
            if (i < (sz + 1)/2)
               if (j < (sz + 1)/2)
                  M[i][j]++;
               else
                  M[i][j] = M[i][sz-j-1];
            else
               M[i][j] = M[sz-i-1][sz-j-1];

   // Print the matrix
   for (i = 0; i < sz; i++) {
      for (j = 0; j < sz; j++)
         printf("%d\t", M[i][j]);
      printf("\n");
   }

   // Free the allocated memory for the matrix
   for (i = 0; i < sz; i++)
      free(M[i]);
   free(M);

   return;
}
