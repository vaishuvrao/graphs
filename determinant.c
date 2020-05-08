#include<stdio.h>
int main()
{
	int mat[5][5], determinant, sum;
	int row,column,k,n;
	printf("\n======THIS IS A C PROGRAM TO CALCULATE DETERMINANT==========\n");
	printf("\nENTER THE ORDER OF MATRIX 5 OR BELOW 5\n\n");
	scanf("%d",&n);
	printf("\nENTER THE MATRIX PLEASE\n\n");
	for(row=0;row<n;row++){ /*code to enter row*/
		for(column=0;column<n;column++) { /*code to enter column*/
			scanf("%d",&mat[row][column]);
				  }
			}
/* since solving huge matrix requires some way to solve them with upper triangular matrix. small matrices like 2x2 or 3x3 could be solved directly uding the formula*/


for(row=0;row<n;row++) {
	for(column=0;column<n;column++) {
		if(column>row){
			
			sum=mat[column][row]/mat[row][row];
			for(k=0;k<n;k++)
			{
			mat[column][k]-=sum* mat[row][k];
}
}
}
}
determinant=1;
for(row=0;row<n;row++)
determinant*=mat[row][row];
printf("\n===================DETERMINANT MATRIX===================\n");
printf("%d\t",determinant);
printf("\n");
return 0;
}
