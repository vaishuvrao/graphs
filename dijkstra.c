#include<stdio.h>
#define HIGHVALUE 999
#define MAX 10
 
void dij(int Adj_Matrix[MAX][MAX],int v,int starting_n)
{

    int visited[MAX],count,min_distance,nextnode,i,j;
	int cos_Matrix[MAX][MAX],distance[MAX],previous[MAX];
	

	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			if(Adj_Matrix[i][j]==0) //Check if the value at that point is 0
				cos_Matrix[i][j] = HIGHVALUE; //So that no other value can replace this
			else
				cos_Matrix[i][j] = Adj_Matrix[i][j];
	
	
	for(i=0;i<v;i++)
	{
		distance[i] = cos_Matrix[starting_n][i];
		previous[i] = starting_n;
		visited[i]=0;
	}
	
	distance[starting_n]=0;
	visited[starting_n]=1;
	count=1;
	
	while(count<v-1)
	{
		min_distance=HIGHVALUE;
		
		//nextnode is the node at minimum distance
		for(i=0;i<v;i++)
			if(distance[i] < min_distance && !visited[i])
			{
				min_distance=distance[i];
				nextnode=i;
			}
			
			//Check for a better path		
			visited[nextnode] = 1;
			for(i=0;i<v;i++)
				if(!visited[i])
					if(min_distance + cos_Matrix[nextnode][i] < distance[i])
					{
						distance[i] = min_distance + cos_Matrix[nextnode][i];
						previous[i] = nextnode;
					}
		count++;
	}
 
	//print the path and distance of each node
	for(i=0;i<v;i++)
		if(i!=starting_n)
		{
			printf("\nDistance of node %d = %d ",i,distance[i]);
			printf("\nPath = %d",i);
			
			j=i;
			do
			{
				j = previous[j];
				printf(" <-% d ",j);
			}while(j != starting_n);
	}

printf("\n");
 	
}
 
int main()
{
	int Adj_Matrix[MAX][MAX],i,j,v,u;
	printf("Enter the Total Number of Vertices: ");
	scanf("%d",&v);
	printf("\nEnter the Adjacency matrix by each Row:\n");
	
	for(i=0;i<v;i++) //Loop to get the values from user and store
		for(j=0;j<v;j++)
			scanf("%d",&Adj_Matrix[i][j]);
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	dij(Adj_Matrix,v,u);
	
	return 0;
}
 
