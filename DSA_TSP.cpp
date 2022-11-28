#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
float max_value= 10000.0;
int arr[500];
queue(float cost_array[500][500],int n)					// Classic Queue implementation
{
    long double queue_cost=0.0;
    for(int i=0; i<n-1; i++)
    {
		queue_cost = queue_cost + cost_array[i][i+1];
    }
    queue_cost+=cost_array[n-1][0];
    cout<<queue_cost<<"\n";
}
/*
    start from 1st position in duplicate cost matrix.
    find minimum in that sub array(1D),add it to the cost variable, and make (all the elements of that row and all elements of the column
	to which we are going) as a maximum value.
    Repeat the steps till the complete matrix is having same maximum value.
*/
float matrix(float orig_array[500][500],int n)				// Our Method
{															// Time Complexity
    float cost=0.0,min, cost_array[500][500];
    int pos=0,new_pos=0,count=0;
    for(int i=0; i<n; i++)									// n
    {
    	for(int j=0; j<n; j++)								// n*n
    	{
			if(j==0 || i==j)
    			cost_array[i][j]=max_value;
    		else
				cost_array[i][j]=orig_array[i][j];
		}
	}
    for(int i=0; i<n; i++)									// n
    {	arr[i]=pos;
        count++;
		min=max_value;
		printf("After Processing the above: \n");
	/*	for(int k=0; k<n; k++)								// n*n
        {
        	printf("\n");
			for(int l=0; l<n; l++)							// n*n*n 	// But This is print statement is not the part of the algorithm
        		printf("%f	",cost_array[k][l]);
        	printf("\n");
		}*/
        if(count<n)											// n
        {
        	for(int j=0; j<n ; j++)							// n*n
        	{
	            if(cost_array[pos][j] < min )
	            {
	                min=cost_array[pos][j];
	                new_pos=j;
	            }
        	}
		}
		else												// n
		{
			min = orig_array[pos][0];
			new_pos=0;
		}
        printf("\n\nmin: %f		",min);
        printf("new_pos: %d		",new_pos);
        cost=cost + min;
        printf("cost: %f\n\n",cost);
        for(int j=0; j<n; j++)								// n*n
        {
             cost_array[pos][j]=max_value;
             cost_array[j][new_pos]=max_value;
        }
        pos=new_pos;
    }
    return cost;
}
/*
	float branch_bound(float cost_array[10][10],int n)				// Branch & Bound
	Since, Worst case time complexity of Branch and Bound method can be (n-1)!, It is not an efficient solution.
*/
int main()
{
	int n,choice=1;
	float cost[500][500],res1,res2,ar[500][2];
	while(choice)
	{
		system("CLS");
		printf("\n\n\t\t\t**********************************\n\n");
		printf("\n\n\t\t\t\tDelivery Problem: \n\n");
	    printf("\n\n\t\t\t1. Enter your own addresses \n");
	    printf("\n\t\t\t2. Check the algorithm with random addresses\n");
	    printf("\n\t\t\t3. Exit ");
	    printf("\n\n\t\t\t Enter Choice : ");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\n\n\t\t\tEnter Number of Delivery Addresses: ");
	    	scanf("%d",&n);
			printf("\nEnter The Coordinates of Addresses : \n");
			for(int i=0; i<n; i++)
			{
				printf("\n Delivery address %d: ",i+1);
				scanf("%d%d",&ar[i][0],&ar[i][1]);
			}
		}
	    else if(choice==2)
		{
			printf("\n\n\t\t\tEnter Number of Delivery Addresses: ");
	    	scanf("%d",&n);
			for(int i=0; i<n; i++)
			{
				ar[i][0]=(float)(rand()%360)/(rand()%360);
				ar[i][1]=(float)(rand()%360)/(rand()%360);
			}
		}
		else
		{
			printf("\n\n\t\t\tThank You!!");
			printf("\n\n\t\t\t PROJECT ID: 13");
			printf("\n\n\t\t\tSUBMITTED BY:\n");
			printf("\n\t\t\t\tHIMANSHU KAUSHIK-    18BCE0579");
			printf("\n\t\t\t\tARCHIT NAHTA-        18BCE0584");
			printf("\n\t\t\t\tSRINIVASAN SHARMA-   18BCE0931\n");
			exit(0);
		}
		for(int i =0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cost[i][j]= (float)sqrt(pow((ar[i][0]-ar[j][0]),2)+ pow((ar[i][1]-ar[j][1]),2));     // Cost Matrix
		}
		printf("\n\n\t\t\tCost Matrix is: \n\n");
		for(int i =0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				printf("%f	",cost[i][j]);
			printf("\n");
		}
		res2=matrix(cost,n);
		printf("\n\n\t\t\tDelivery Solution Cost for %d Locations is: ",n);
		printf("\n\n\t\t\tQueue Result is: ");
		queue(cost,n);
	    printf("\n\n\t\t\tOUR RESULT IS : %f\n\n",res2);
	    printf("\n\n\t\t\tOur suggested Path is: \n");
	    for(int i=0; i<n; i++)
	    	printf("%d-->",arr[i]+1);
	    printf("\n\n");
		system("PAUSE");
	}
	return 0;
}
