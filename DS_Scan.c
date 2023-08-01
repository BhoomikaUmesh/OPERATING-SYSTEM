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
    // logic for scan disk scheduling 
    /*logic for sorting the request array*/
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(rq[j]>rq[j+1])
            {
                int temp;
                temp = rq[j];
                rq[j]= rq[j+1];
                rq[j+1]=temp;
            }
        }
    }
    int index;
    for(i=0;i<n;i++)
    {
        if(initial<rq[i])
        {
            index = i;
            break;
        }
    }
    // if movement is towards high value
    if(move ==1)
    {
        printf("Sequence of request access");
        for(i=index;i<n;i++)
        {
            printf("%d",rq[i]);
            totalheadmoment = totalheadmoment+abs(rq[i]-initial);
            initial = rq[i];
        }
        //last movement for max size 
        totalheadmoment = totalheadmoment + abs(size - rq[i-1]);
        initial = size -1;
        for(i=index-1;i>=0;i--)
        {
            printf("%d", rq[i]);
            totalheadmoment = totalheadmoment+abs(rq[i]-initial);
            initial = rq[i];
        }
    }
    // if movement is towards low value
    else
    {
        printf("Sequence of request access:\n");
        for(i=index -1;i>=0;i--)
        {
            totalheadmoment = totalheadmoment+abs(rq[i]-initial);
            initial = rq[i];
        }
        // last movement for min size
        totalheadmoment = totalheadmoment+abs(rq[i+1]-0);
        initial = 0;
        for(i= index;i<n;i++)
        {
            printf("%d", rq[i]);
            totalheadmoment = totalheadmoment+abs(rq[i]-initial);
            initial = rq[i];
        }
    }
    printf("\nTotal head moment is %d", totalheadmoment);
    return 0;
}