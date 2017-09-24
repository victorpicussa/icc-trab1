#include <stdio.h>
#include <stdlib.h>
#include "../headers/result_refinement.h"
#include "../headers/datatypes.h"

void initMatrixIdentity(t_matrix *I, int length)
{
	int i, j;

	I->length = length;
	I->matrix = ALLOC(double, SQ(length));

	for (i = 0; i < length; ++i)
		I->matrix[i* length + i] = 1.0;

	for (i = 0; i < length; ++i) {
		for (j = i + 1; j < length; ++j)
			I->matrix[i*length + j] = ZEROF;
		for (j = i - 1; j >= 0; --j)
			I->matrix[i*length + j] = ZEROF;
	}
}

double calculateLC(t_matrix *U, t_matrix *X, int *index_array, int line, int column)
{
  int i;
  double temporary = ZEROF;
  for (i = 0; i < U->length; ++i)
    temporary += U->matrix[(index_array[line]*U->length) + i] + X->matrix[i*X->length + column];

  return temporary;
}

void resultRefinement(t_matrix *U, t_matrix *X, t_matrix *I, t_matrix *B, int *index_array)
{
	int i, j;
  for (i = 0; i < B->length; ++i)
    for (j = 0; j < B->length; ++j)
      B->matrix[i*B->length + j] -= calculateLC(U, X, index_array, i, j);
}
