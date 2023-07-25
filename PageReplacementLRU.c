#include<stdio.h>
#include<limits.h>
int checkHit(int incommingPage, int queue[], int occupied){
    for(int i=0;i<occupied;i++){
        if(incommingPage==queue[i])
        return 1;
    }
    return 0;
}
void printFrame(int queue[],int occupied)
{
    for(int i=0;i<occupied;i++)
    printf("%d\t\t",queue[i]);
}
int main()
{
    int n=sizeof(incommingStream)/sizeof(incommingSrteam[0]);
    int frames=3;
    int queue[n];
    int distance[n];
    int occupied=0;
    int pagefault=0;
    printf("Page\tFrame1\tFrame2\tFrame3\n");
    for(int i=0;i<n;i++)
    {
        printf("%d:\t\t",incommingStream[i]);
        //What if currently in Frame 7
        //next item appears alos 7
        if(checkHit(incommingStream[i],queue,occupied)){
            printFrame(queue,occupied);
        }
        //filling when frames are empty
        else if(occupied<frames){
            queue[occupied]=incommingStream[i];
            pageFault++;
            occupied++;
            
        }
    }

}