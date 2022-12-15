#include <stdio.h>  
#include<ctype.h>
#include<math.h> 
void readMatrix(int array[10][10], int rows, int colums);  
void printMatrix(int array[10][10], int rows, int colums);  
void matrixAddSub(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul);  
void matrixScalarMultiply(int array[10][10], int scalar, int rows, int colums);  
void matrixMultiply(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA, int columsB);  
void cofactor(float[][25],float);
float determinant(float[][25],float);
void transpose(float[][25],float[][25],float);
int main(void)
{  
    int i, j, k;
    int matrixA[10][10];
    int matrixB[10][10];  
    int rowA, colA;  
    int rowB, colB;  
    int operation; 
    char again = 'Y';  
    int scalar = 0;  
    int add = 1;  
    int sub = -1;  
    while (again == 'Y')
	{  
        printf("\nOperation Menu\n");  
        printf("\t1. to Add\n");  
        printf("\t2. to Subtract\n");  
        printf("\t3. to Scalar Multiply\n");  
        printf("\t4. to Multiply two matrices\n"); 
		printf("\t5. to Inverse\n");
        printf("Enter your choice: ");  
        scanf(" %d", &operation);  
        switch (operation)
		{   
            case 1:
			    printf("\nEnter the #rows and #cols for matrix A: ");  
                scanf("%d%d", &rowA, &colA);  
                printf("Enter the #rows and #cols for matrix B: ");  
                scanf("%d%d", &rowB, &colB);  
                while ((rowA != rowB) && (colA != colB))
		    	{  
                    printf("\nMatrices must be the same size\n");  
                    printf("\nEnter the #rows and #cols for matrix A: ");  
                    scanf("%d%d", &rowA, &colA);  
                    printf("Enter the #rows and #cols for matrix B: ");  
                    scanf("%d%d", &rowB, &colB);  
                }  
                printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA);
                readMatrix(matrixA, rowA, colA);  
                printf("\n\t\tMatrix A\n\n");  
                printMatrix(matrixA, rowA, colA);  
                printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); 
                readMatrix(matrixB, rowB, colB);  
                printf("\n\t\tMatrix B\n\n");  
                printMatrix(matrixB, rowB, colB);  
                printf("\nThe Sum of matrixA + matrixB is : \n");  
                matrixAddSub(matrixA, matrixB, rowA, colA, add);  
                break; 
			 
            case 2:
			    printf("\nEnter the #rows and #cols for matrix A: ");  
                scanf("%d%d", &rowA, &colA);  
                printf("Enter the #rows and #cols for matrix B: ");  
                scanf("%d%d", &rowB, &colB);  
                while ((rowA != rowB) && (colA != colB))
				{  
                    printf("\nMatrices must be the same size\n");  
                    printf("\nEnter the #rows and #cols for matrix A: ");  
                    scanf("%d%d", &rowA, &colA);  
  
                    printf("Enter the #rows and #cols for matrix B: ");  
                    scanf("%d%d", &rowB, &colB);  
                }    
                printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); 
                readMatrix(matrixA, rowA, colA);  
                printf("\n\t\tMatrix A\n\n");  
                printMatrix(matrixA, rowA, colA);    
                printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB);
                readMatrix(matrixB, rowB, colB);
                printf("\n\t\tMatrix B\n\n");  
                printMatrix(matrixB, rowB, colB);   
                printf("\nThe difference between matrixA - matrixB is : \n");  
                matrixAddSub(matrixA, matrixB, rowA, colA, sub);  
                break;  
  
            case 3:   
                printf("\nEnter the scalar: ");  
                scanf("%d", &scalar);  
                printf("\nThe scalar is: %d ", scalar);    
                printf("\nEnter the #rows and #cols for matrix A: ");  
                scanf("%d%d", &rowA, &colA);    
                printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA);  
                readMatrix(matrixA, rowA, colA);  
                printf("\n\t\tMatrix A\n\n");  
                printMatrix(matrixA, rowA, colA);    
                printf("\nThe scalar multiplication between matrixA * %d is: \n", scalar);  
                matrixScalarMultiply(matrixA, scalar, rowA, colA);  
                break;  
  
            case 4:  
                printf("\nEnter the #rows and #cols for matrix A: ");  
                scanf("%d%d", &rowA, &colA);  
                printf("Enter the #rows and #cols for matrix B: ");  
                scanf("%d%d", &rowB, &colB);  
                while (colA != rowB)  
                {  
                    printf("\n\nError! column of first matrix not equal to row of second.\n\n");  
                    printf("\nEnter the #rows and #cols for matrix A: ");  
                    scanf("%d%d", &rowA, &colA);  
                    printf("Enter the #rows and #cols for matrix B: ");  
                    scanf("%d%d", &rowB, &colB);  
                }   
                printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA);
                readMatrix(matrixA, rowA, colA);  
                printf("\n\t\tMatrix A\n\n");  
                printMatrix(matrixA, rowA, colA);  
                printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); 
                readMatrix(matrixB, rowB, colB);  
                printf("\n\t\tMatrix B\n\n");  
                printMatrix(matrixB, rowB, colB);    
                matrixMultiply(matrixA, matrixB, rowA, colA, colB);  
                break;  
            
            case 5:
        	    float a[25][25], k, d;
                int i, j;
                printf("Enter the order of the Matrix : ");
                scanf("%f", &k);
                printf("Enter the elements of the Matrix : \n", k, k);
                for (i = 0;i < k; i++)
                {
                    for (j = 0;j < k; j++)
                    {
                        scanf("%f", &a[i][j]);
                    }
                }
                d = determinant(a, k);
                if (d == 0)
                printf("\nInverse of Entered Matrix is not possible\n");
                else
                cofactor(a, k);
                break;
  
            default:  
            printf("\nIncorrect option! Please choose a number 1-4.");  
            break;  
        }   
        printf("\n\nDo you want to calculate again? Y/N\n");  
        scanf(" %c", &again);  
        again = toupper(again);  
    }  
printf("\n\nGoodbye!\n\n");  
return 0;  
}  
   
void readMatrix(int array[10][10], int rows, int colums){  
    int i, j;  
    for (i = 0; i < rows; i++){  
        printf("\t%d entries for row %d: ", colums, i + 1);  
        for (j = 0; j < colums; j++){  
            scanf("%d", &array[i][j]);  
        }  
    }  
  
    return;  
}  
  
void printMatrix(int array[10][10], int rows, int colums){  
    int i, j;    
    for (i = 0; i < rows; i++) {  
        for (j = 0; j < colums; j++){  
            printf("\t%d", array[i][j]);  
        }  
        printf("\n");  
    }  
}  
  
  
void matrixAddSub(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul){  
    int i, j;  
    int sumM[10][10];  
    int scaM[10][10];  
    for (i = 0; i < rows; i++){  
        for (j = 0; j < colums; j++){  
            scaM[i][j] = mul * arraytwo[i][j];  
            }  
        }  
  
  
    for (i = 0; i < rows; i++){  
        for (j = 0; j < colums; j++){  
            sumM[i][j] = arrayone[i][j] + scaM[i][j];  
            printf("\t%d", sumM[i][j]);  
        }  
        printf("\n");  
    }  
}  
  
void matrixScalarMultiply(int array[10][10], int scalar, int rows, int colums){  
    int i, j;  
    int scaM[10][10];  
    for (i = 0; i < rows; i++){  
        for (j = 0; j < colums; j++){  
            scaM[i][j] = scalar * array[i][j];  
            printf("%d\t", scaM[i][j]);  
        }  
        printf("\n");  
    }  
}  
  
void matrixMultiply(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA,int columsB){  
    int i, j, k;  
    int mulM[10][10];  
    for (i = 0; i<rowsA; ++i)  
        for (j = 0; j<columsB; ++j)  
        {  
            mulM[i][j] = 0;  
        }  
    for (i = 0; i<rowsA; ++i)  
        for (j = 0; j<columsB; ++j)  
            for (k = 0; k<columsA; ++k)  
            {  
                mulM[i][j] += arrayone[i][k] * arraytwo[k][j];  
            }  
    printf("\nOutput Matrix:\n");  
    for (i = 0; i<rowsA; ++i)  
        for (j = 0; j<columsB; ++j)  
        {  
            printf("\t%d ", mulM[i][j]);  
            if (j == columsB - 1)  
                printf("\n\n");  
        }  
}

float determinant(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
 
    return (det);
}
 
void cofactor(float num[25][25], float f)
{
 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f);
}
 
void transpose(float num[25][25], float fac[25][25], float r)
{
  int i, j;
  float b[25][25], inverse[25][25], d;
 
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
   printf("\n\n\nThe inverse of matrix is : \n");
 
   for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         printf("\t%f", inverse[i][j]);
        }
    printf("\n");
     }
}
