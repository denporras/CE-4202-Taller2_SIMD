/**
@file compare.c
@brief Compare the columns of a matrix and get the max elements.
@author Dennis Porras Barrantes
*/
#include <stdio.h> //Input and output
#include <smmintrin.h> //v4
#include <emmintrin.h> //v3

#define SIZE_M 16
#define ROWS_M 2
#define COLS_M 8

int main(int argc, char const *argv[])
{
	//Matrix
	short matrix[ROWS_M][COLS_M];

	//Filling matrix
	for (int i = 0; i < ROWS_M; ++i)
	{
		for (int j = 0; j < COLS_M; ++j)
		{
			printf("\nInsertar el valor de M[%d][%d]:\n", i, j);
			scanf("%hd", &matrix[i][j]);
		}
	}

	//Matrix printing
	printf("\n\n\nCreated matrix:\n");
	for (int i = 0; i < ROWS_M; ++i)
	{
		for (int j = 0; j < COLS_M; ++j)
		{
			printf("%hd\t", matrix[i][j]);
		}
		printf("\n");
	}


	//Convert the matrix row short pointer to a SSE vector pointer
	__m128i* row1 = (__m128i*)matrix[0];
	__m128i* row2 = (__m128i*)matrix[1];

	//Use instruction that get max value in every row previusly converted
	__m128i result = _mm_max_epu16(*row1, *row2);

	//Vector Printing
	printf("\n\nResult vector:\n");
	int data = _mm_extract_epi16(result,0);
	printf("%d \t", data);
	data = _mm_extract_epi16(result,1);
	printf("%d \t", data);
	data = _mm_extract_epi16(result,2);
	printf("%d \t", data);
	data = _mm_extract_epi16(result,3);
	printf("%d \t", data);
	data = _mm_extract_epi16(result,4);
	printf("%d \t", data);
	data = _mm_extract_epi16(result,5);
	printf("%d \t", data);
	data = _mm_extract_epi16(result,6);
	printf("%d \t", data);
	data = _mm_extract_epi16(result,7);
	printf("%d \t", data);
	printf("\n");

	return 0;
}