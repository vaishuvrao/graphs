#include<stdio.h>

struct graph_node
{
	unsigned distance[30];
	unsigned temp[20];
}ret[30];

int main()
{
	int cost_matrix[30][30],n,i,j,k,count=0;
	printf("==========This is a c program for bellman ford============\n");
	printf("\nENTER THE NO OF NODES OF THE MATRIX\n");
	scanf("%d",&n);
	printf("\nENTER THE COST MATRIX\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)	
		{
		scanf("%d",&cost_matrix[i][j]);
		cost_matrix[i][i]=0;
		ret[i].distance[j]=cost_matrix[i][j];
		ret[i].temp[j]=j;
		}
	}
	do
	{
		count=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if(ret[i].distance[j]>cost_matrix[i][k]+ret[k].distance[j])
					{
						ret[i].distance[j]=ret[i].distance[k]+ret[k].distance[j];
						ret[i].temp[j]=k;
						count++;
					}
	}while(count!=0);
	for(i=0;i<n;i++)
	{
		printf("\n\nTHE ROUTE %d FOR THE NODES\n",i+1);
		for(j=0;j<n;j++)
		{
			printf("\t\n From Node %d through %d distance %d",j+1,ret[i].temp[j]+1,ret[i].distance[j]);
}
}
printf("\nTHE END\n");
}

