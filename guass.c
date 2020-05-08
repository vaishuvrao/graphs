#include<stdio.h>
int main()
{
int i,j,k,n;
double a[40][40],c,x[40],sum=0.0;
printf("\nenter the order of the matrix\n");
scanf("%d",&n);
printf("\nenter the elements of the matrix\n");
for(i=1;i<=n;i++)
	{
		for(j=1;j<=n+1;j++)
		{
		printf("a[%d][%d]:",i,j);
		scanf("%lf",&a[i][j]);
	}
}
for(j=1;j<=n;j++)
{ 
for(i=1;i<=n;i++)
{
if(i>j)
{
c=a[i][j]/a[j][j];
for(k=1;k<=n+1;k++)
{
a[i][k]=a[i][k]-(c*a[j][k]);
}
}
}
}
printf("\n upper trianngualr matrix is as follows\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=(n+1);j++)

printf("%lf\t",a[i][j]);
printf("\n");
}


x[n]=a[n][n+1]/a[n][n];
for(i=n-1;i>=1;i--)
{
x[i]=a[i][n+1];
for(j=i+1;j<=n;j++)
{

x[i]=x[i]-a[i][j]*x[j];
}
x[i]=x[i]/a[i][i];
}
printf("\n the solution is:\n");
for(i=1;i<=n;i++)
{
printf("\n%lf\n",x[i]);
}
return 0;
}
