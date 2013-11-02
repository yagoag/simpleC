/* Program which verifies if the sum of values of the main
   diagonal (trace) and minor diagonal are the same and, if
   so, prints their value.
   This algorithm works for matrixes of integer values
   only, but can be easily changed to work with real
   numbers with float or double variables.

   Author: Yago Arroyo
   Date:   01/11/2013
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int trace(int**, int);             // Sum of the elements of the main diagonal
int sumMinorDiagonal(int**, int);  // Sum of the elements of the minor diagonal

int main() {
    // Declaration of local variables
    int sz, **m, i, j, sumMain, sumMinor;

    // Read the size of the matrix
    printf("Type in the size of the matrix to calculate: ");
    scanf("%d", &sz);

    // Allocate memory for the matrix
    m = (int *) calloc (sz, sizeof(int));
    for (i = 0; i < sz; i++)
        m[i] = (int *) calloc (sz, sizeof(int));

    // And read its elements
    printf("Type in the elements of the matrix, separate by spaces or change of line:\n");
    for (i = 0; i < sz; i++)
        for (j = 0; j < sz; j++)
            scanf("%d", &m[i][j]);

    // Calculate the sum of both diagonal's elements
    sumMain = trace(m, sz);
    sumMinor = sumMinorDiagonal(m, sz);

    // Verifies if the sum of their elements is the same
    printf("The sum of the elements of the main and minor diagonals are ");
    if (sumMain == sumMinor)
        printf("equal to %d.\n", sumMain);
    else
        printf("different.\n");

    return 0;
}

/* Function:  trace
   Objective: Calculates the trace of a square matrix (sum
              of the elements of its main diagonal)

   Parametres:
    - m (pointer): pointer to the matrix
    - sz (value):  size of the matrix

   Return: value of the trace
*/
int trace(int **m, int sz) {
    // Declaration of local variables
    int i, sum;

    // Determination of the sum
    sum = 0;
    for (i = 0; i < sz; i++)
        sum += m[i][i];

    return sum;
}

/* Function:  sumMinorDiagonal
   Objective: Calculates the sum of the elements of the
              minor diagonal of a square matrix

   Parametres:
    - m (pointer): pointer to the matrix
    - sz (value):  size of the matrix

   Return: value of the sum of the minor diagonal's
           elements
*/
int sumMinorDiagonal(int **m, int sz) {
    // Declaration of local variables
    int i, sum;

    // Determination of the sum
    sum = 0;
    for (i = 0; i < sz; i++)
        sum += m[i][sz - i - 1];

    return sum;
}
