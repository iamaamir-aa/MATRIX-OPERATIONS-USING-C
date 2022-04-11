#include <stdio.h>

void scanOneMatrix(int whichOperation);
void scanTwoMatrix(int whichOperation);
void addition(int n, int m, double matrix1[n][m], double matrix2[n][m]);
void subtraction(int n, int m, double matrix1[n][m], double matrix2[n][m]);
void multiplication(int n1, int n2, int m1, int m2, double matrix1[n1][m1], double matrix2[n2][m2]);
void transpose(int n, int m, double matrix[n][m]);
double det(int n, int m, double matrix[n][m]);
void inverse(int n, int m, double matrix[n][m]);
void adjoint(int n, int m, double matrix[n][m]);
void print(int n, int m, double matToDisplay[n][m]);
void swapRow(int x, int y, int n, int m, double matrix[n][m]);

int main()
{
	int inputSelection = 0;

	input:
		printf("ENTER\n");
	printf("1: MATRIX ADDITION\n");
	printf("2: MATRIX SUBTRACTION\n");
	printf("3: MATRIX MULTIPLICATION\n");
	printf("4: MATRIX TRANSPOSE\n");
	printf("5: MATRIX DETERMINANT\n");
	printf("6: MATRIX INVERSE\n");
	printf("7: MATRIX ADJOINT\n");
    printf("Input: ");
	scanf("%d", &inputSelection);

	switch (inputSelection)
	{
		case 1:
			scanTwoMatrix(inputSelection);
			break;
		case 2:
			scanTwoMatrix(inputSelection);
			break;
		case 3:
			scanTwoMatrix(inputSelection);
			break;
		case 4:
			scanOneMatrix(inputSelection);
			break;
		case 5:
			scanOneMatrix(inputSelection);
			break;
		case 6:
			scanOneMatrix(inputSelection);
			break;
		case 7:
			scanOneMatrix(inputSelection);
			break;
		default:
			printf("INVALID SELECTION! TRY AGAIN\n");
			goto input;
			break;
	}

	return 0;
}

//SCANNING ONE MATRIX
void scanOneMatrix(int whichOperation)
{
	int n, m;
	printf("ENTER THE ORDER OF MATRIX (ROWS, COLUMNS): ");
	scanf("%d %d", &n, &m);

	if (n != m && (whichOperation == 5 || whichOperation == 7 || whichOperation == 6))
	{
		printf("NON SQUARE MATRIX!\n");
		return;
	}

	printf("\n||||||||||||||||||||||||||||||||||\n");
	printf("|| ENTER THE ELEMENTS OF MATRIX ||");
	printf("\n||||||||||||||||||||||||||||||||||\n\n");
	//Creating matrix of order input by user
	double matrix[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("A[%d][%d]= ", i, j);
			scanf("%lf", &matrix[i][j]);
		}
	}

	switch (whichOperation)
	{
		case 4:
			transpose(n, m, matrix);
			break;
		case 5:
			{
				double resultDet = 0;
				resultDet = det(n, m, matrix);
				printf("\nDETERMINANT = %.3lf\n", resultDet);
				break;
			}

		case 6:
			inverse(n, m, matrix);
			break;
		case 7:
			adjoint(n, m, matrix);
			break;
		default:
			printf("ERROR!");
			break;
	}

	return;
}

//SCANNING TWO MATRIX
void scanTwoMatrix(int whichOperation)
{
	int n1 = 0, m1 = 0, n2 = 0, m2 = 0;

	printf("ENTER THE ORDER OF FIRST MATRIX (ROWS, COLUMNS): ");
	scanf("%d %d", &n1, &m1);
	printf("ENTER THE ORDER OF SECOND MATRIX (ROWS, COLUMNS): ");
	scanf("%d %d", &n2, &m2);

	// Check if two matrices are of Same Order for ADDITION/SUBTRACTION
	if ((whichOperation == 1 || whichOperation == 2) && (n1 != n2 || m1 != m2))
	{
		printf("INCOMPATIBLE ORDER OF BOTH MATRIX FOR ADDITION/SUBTRACTION!\n");
		return;
	}
	else if (whichOperation == 3 && m1 != n2)
	{
		printf("INCOMPATIBLE ORDER OF BOTH MATRIX FOR MULTIPLICATION!\n");
		return;
	}

	//Creating two matrices of order input by the user
	double matrix1[n1][m1], matrix2[n2][m2];

	printf("\n||||||||||||||||||||||||||||||||||||||||\n");
	printf("|| ENTER THE ELEMENTS OF FIRST MATRIX ||");
	printf("\n||||||||||||||||||||||||||||||||||||||||\n\n");

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			printf("A[%d][%d]= ", i, j);
			scanf("%lf", &matrix1[i][j]);
		}
	}

	printf("\n|||||||||||||||||||||||||||||||||||||||||\n");
	printf("|| ENTER THE ELEMENTS OF SECOND MATRIX ||");
	printf("\n|||||||||||||||||||||||||||||||||||||||||\n\n");

	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			printf("B[%d][%d]= ", i, j);
			scanf("%lf", &matrix2[i][j]);
		}
	}

	switch (whichOperation)
	{
		case 1:
			{
				addition(n1, m1, matrix1, matrix2);
				break;
			}

		case 2:
			{
				subtraction(n1, m1, matrix1, matrix2);
				break;
			}

		case 3:
			{
				multiplication(n1, n2, m1, m2, matrix1, matrix2);
				break;
			}

		default:
			{
				printf("ERROR\n");
				break;
			}
	}

	return 0;
}

void addition(int n, int m, double matrix1[n][m], double matrix2[n][m])
{
	double add[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			add[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	print(n, m, add);
	return;
}

void subtraction(int n, int m, double matrix1[n][m], double matrix2[n][m])
{
	double sub[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sub[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}

	print(n, m, sub);
	return;
}

void multiplication(int n1, int n2, int m1, int m2, double matrix1[n1][m1], double matrix2[n2][m2])
{
	double mul[n1][m2];

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			mul[i][j] = 0;
		}
	}

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			for (int k = 0; k < n2; k++)
			{
				mul[i][j] = mul[i][j] + matrix1[i][k] *matrix2[k][j];
			}
		}
	}

	print(n1, m2, mul);
	return;
}

void transpose(int n, int m, double matrix[n][m])
{
	double transposeMatrix[m][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			transposeMatrix[j][i] = matrix[i][j];
		}
	}

	print(m, n, transposeMatrix);

	return;
}

double det(int n, int m, double matrix[n][m])
{
	double temp_constant = 0;
	double determinant = 1;

	//rearranging matrix for non-zero diagonals
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][i] == 0)
		{
			if (i + 1 < n)
			{
				swapRow(i, i + 1, n, m, matrix);
				determinant *= -1;	// interchanging
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (matrix[i][i] != 0)
			{
				temp_constant = -matrix[j][i] / matrix[i][i];
				for (int k = 0; k < n; k++)
				{
					matrix[j][k] = matrix[j][k] + temp_constant *matrix[i][k];
				}
			}
			else
			{
				if (i + 1 < n)
				{
					swapRow(i, i + 1, n, m, matrix);
					determinant *= -1;	// interchanging
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				determinant = determinant *matrix[i][j];
			}
		}
	}

	return (double) determinant;
}

void inverse(int n, int m, double matrix[n][m])
{
	double matrix_copied[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix_copied[i][j] = matrix[i][j];
		}
	}

	double determinant = det(n, m, matrix_copied);

	if (determinant == 0)
	{
		printf("INVERSE NOT EXIST AS MATRIX IS SINGULAR!\n");
		return;
	}

	double identityMatrix[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				identityMatrix[i][j] = 1;
			}
			else
			{
				identityMatrix[i][j] = 0;
			}
		}
	}

	double temp1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
		    if(matrix[i][i]!=0){
			temp1 = -matrix[j][i] / matrix[i][i];
			for (int k = 0; k < n; k++)
			{
				if (i != j)
				{
					matrix[j][k] = matrix[j][k] + temp1 *matrix[i][k];
					identityMatrix[j][k] = identityMatrix[j][k] + temp1 *identityMatrix[i][k];

				}
			}
		}

		}
	}

	double temp2 = 0;
	for (int i = 0; i < n; i++)
	{
		temp2 = matrix[i][i];
		for (int j = 0; j < n; j++)
		{
			identityMatrix[i][j] = identityMatrix[i][j] / temp2;

		}
	}

	print(n, m, identityMatrix);

	return;
}

void adjoint(int n, int m, double matrix[n][m])
{
	double matrix_copied[n][m];

	//CREATING A COPY OF MATRIX TO FIND THE DETERMINANT
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix_copied[i][j] = matrix[i][j];
		}
	}

	double determinant = det(n, m, matrix_copied);

	if (determinant == 0)
	{
		printf("ADJOINT OF MATRIX IS ZERO");
		return;
	}

	double identityMatrix[n][m];

	//CREATING A IDENTITY MATRIX
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j)
			{
				identityMatrix[i][j] = 1;
			}
			else
			{
				identityMatrix[i][j] = 0;
			}
		}
	}

	double temp1 = 0;

	//PERFORMING ELEMENTARY ROW TRANSFORMATION ON BOTH (INPUT/IDENTITY MATRIX)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][i] != 0)
			{
				temp1 = -matrix[j][i] / matrix[i][i];
				for (int k = 0; k < n; k++)
				{
					if (i != j)
					{
						matrix[j][k] = matrix[j][k] + temp1 *matrix[i][k];
						identityMatrix[j][k] = identityMatrix[j][k] + temp1 *identityMatrix[i][k];

					}
				}
			}
		}
	}

	double temp2 = 0;
	for (int i = 0; i < n; i++)
	{
		temp2 = matrix[i][i];
		for (int j = 0; j < m; j++)
		{
			identityMatrix[i][j] = (identityMatrix[i][j] / temp2) *determinant;

		}
	}

	print(n, m, identityMatrix);

	return;
}

void print(int n, int m, double matToDisplay[n][m])
{
	printf("<---------------YOUR RESULTANT MATRIX IS--------------->\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%lf\t", matToDisplay[i][j]);
		}

		printf("\n");
	}
}

void swapRow(int x, int y, int n, int m, double matrix[n][m])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == x)
			{
				double temp = matrix[x][j];
				matrix[x][j] = matrix[y][j];
				matrix[y][j] = temp;
			}
		}
	}

	return;
}
