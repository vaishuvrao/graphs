#include<stdio.h>
int main()
{
	float mat[5][5], sum,inverse;
	int row,column,k,n;
	printf("\n======THIS IS A C PROGRAM TO CALCULATE INVERSE OF A MATRIX==========\n");
	printf("\nENTER THE ORDER OF MATRIX 5 OR BELOW 5\n\n");
	scanf("%d",&n);
	printf("\nENTER THE MATRIX PLEASE\n\n");
	for(row=0;row<n;row++){ /*code to enter row*/
		for(column=0;column<n;column++) { /*code to enter column*/
			scanf("%f",&mat[row][column]);
				  }
			}
/* since solving huge matrix requires some way to solve them with upper triangular matrix. small matrices like 2x2 or 3x3 could be solved directly uding the formula*/

for(row=0;row<n;row++) {
	for(column=n;column<2*n;column++) {
	if(row==(column-n))
		mat[row][column]=1.0;
	else
		mat[row][column]=0.0;
}
}
for(row=0;row<n;row++) {
	for(column=0;column<n;column++) {
		if(row!=column){
			
			sum=mat[column][row]/mat[row][row];
			for(k=0;k<2*n;k++)
			{
			mat[column][k]-=sum* mat[row][k];
}
}
}
}

for(row=0; row<n;row++) {
	inverse=mat[row][row];
	for(column=0;column<2*n;column++) {
		mat[row][column]/=inverse;
}
}

printf("\n===================INVERSE MATRIX===================\n");
for(row=0;row<n;row++)
{
for(column=n;column<2*n;column++){

printf("%.2f\t",mat[row][column]);
printf("\t");
}
printf("\n");
}
return 0;
}
