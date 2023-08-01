#include<stdio.h>
int main()
{
    int i,j,n,a[50],no,k,avail,fault=0,frame[10];
    printf("\n Enter the numbar of pages:\n");
    scanf("%d",&n);
    printf("\n Enter the page number:\n");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    printf("\n Enter the numbar of frames:\n");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    frame[i]=-1;
    j=0;
    printf("\t Input \t page frames\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t",a[i]);
        avail=0;
        for(k=0;k<no;k++)
        if(frame[k]==a[i])
        avail=1;
        if(avail==0)
        {
            frame[j]=a[i];
            fault++;
            for(k=0;k<no;k++)
            printf("%d\t",frame[k]);
            j=(j+1)%no;

        }
        printf("\n");
    }
    printf("Page fault is %d",fault);
    return 0;
}

/*output:

 Enter the numbar of pages:
7

 Enter the page number:
1 3 0 3 5 6 3

 Enter the numbar of frames:
3
Input              page frames
1               1       -1      -1
3               1       3       -1
0               1       3       0
3
5               5       3       0
6               5       6       0
3               5       6       3
Page fault is 6*/