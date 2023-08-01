#include<stdio.h>
#include<stdlib.h>
int main()
{
    int rq[100],i,j,n,totalheadmoment=0,initial, size , move;
    printf("Enter the number of requests\n");
    scanf("%d",&n);
    printf("Enter the request sequence\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }
    printf("Enter the inital head position\n");
    scanf("%d",&initial);
    printf("Enter total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and low 0\n");
    scanf("%d",&move);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            int temp;
            temp = rq[j];
            rq[j]= rq[j+1];
            rq[j+1]=temp;
        }
    }