/**
@file matrix_multiplication.c
@brief Compute matrix multiplication of 4x4 matrix
@author Dennis Porras Barrantes
*/
#include <stdio.h> //Input and output
#include <smmintrin.h> //v4
#include <emmintrin.h> //v3

#define SIZE_M 16
#define ROWS_M 4
#define COLS_M 4
#define MASK 0x0F1

int main(int argc, char const *argv[])
{
	//Matrix1
	float matrix1[ROWS_M][COLS_M];
	
	//Matrix2 transpose
	float matrix2[COLS_M][ROWS_M];

	//Filling matrix
	for (int i = 0; i < ROWS_M; ++i)
	{
		for (int j = 0; j < COLS_M; ++j)
		{
			printf("\nInsertar el valor de M1[%d][%d]:\n", i, j);
			scanf("%f", &matrix1[i][j]);
			printf("\n\nInsertar el valor de M2[%d][%d]:\n", i, j);
			scanf("%f", &matrix2[j][i]); //Filling correctly the transpose changing j and i
		}
	}

	//Matrix printing
	printf("\n\n\nCreated M1:\n");
	for (int i = 0; i < ROWS_M; ++i)
	{
		for (int j = 0; j < COLS_M; ++j)
		{
			printf("%f\t", matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\nCreated M2:\n");
	//Printing transpose correctly
	for (int i = 0; i < ROWS_M; ++i)
	{
		for (int j = 0; j < COLS_M; ++j)
		{
			printf("%f\t", matrix2[j][i]);
		}
		printf("\n");
	}

	//Matrix result
	float matrix_result[ROWS_M][COLS_M];

	for (int i = 0; i < ROWS_M; ++i)
	{
		__m128 * a = (__m128 *)matrix1[i]; //Vector of a row
		for (int j = 0; j < COLS_M; ++j)
		{
			__m128 * b = (__m128 *)matrix2[j]; //Vector of a column
			__m128 result = _mm_dp_ps(*a, *b, MASK); //To compute an element, dot producto is used
			float element = _mm_cvtss_f32(result); //Convert element
			matrix_result[i][j] = element; //Insert in matrix
		}
	}

	//Result printing
	printf("\n\n\nResult M1xM2:\n");
	for (int i = 0; i < ROWS_M; ++i)
	{
		for (int j = 0; j < COLS_M; ++j)
		{
			printf("%f\t", matrix_result[i][j]);
		}
		printf("\n");
	}
	return 0;
}