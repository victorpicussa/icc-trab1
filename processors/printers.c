#include <stdio.h>
#include "../headers/printers.h"
/**
 * @brief      Imprime a matriz no formato especificado
 *
 * @param      M     Matriz a ser impressa
 */
void printMatrix(t_matrix *M)
{
	int length = M->length;
	printf("Tamanho matrix (NxN): %d\n",length);
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; j++) {
			printf("%.17g " , VALUE(M,i,j));
		};
		printf("\n");
	}
}

void printMatrixL(t_matrix *matrix)
{
  int i;
  printf("Tamanho matrix L (N): %d\n", matrix->lenght);
  for (i = 0; i < matrix->lenght; ++i) {
    printf("%.17g\n", matrix->matrix[i]);
  }
}
