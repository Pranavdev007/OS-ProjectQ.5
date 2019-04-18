#include<stdio.h>
#include<conio.h>
 
void main()
{
	system("COLOR 4E");
    int b[50];
    int pro[50];
    int w[50];
    int turn[50];
    int i;
    int j;
    int n;
    int all=0;
    int index;
    int flag;
    float average_w,average_t;
    printf("*********************************************************************************************WELCOME TO MY PROJECT************************************************************************************************\n");
    printf("__________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("                                                                                              NAME :- VISHAL KUMAR\n");
    printf("                                                                                             ROLL NO. :- 67\n");
    printf("                                                                                             REG. NO. :- 11704868\n");
    printf("                                                                                             SUBJECT :- OPERATING SYSTEM\n");
    printf("                                                                                             COURSE CODE :- CSE-316\n");
    printf("                                                                                                                                                                     ALLOTED BY :- ROBIN PRAKASH MATHUR\n");

	printf("___________________________________________________________________________________________________________________________________________________________________________________________________________________\n\n\n");
	
	printf("Enter the number of process:\n");
    scanf("%d",&n);
    printf("\nEnter burst time:\n");
    for(i=0;i<n;i++)
    {
        printf("process%d : ",i+1);
        scanf("%d",&b[i]);
        pro[i]=i+1;           
    }
    for(i=0;i<n;i++)
    {
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(b[j]<b[index])
                index=j;
        }
 
        flag=b[i];
        b[i]=b[index];
        b[index]=flag;
 
        flag=pro[i];
        pro[i]=pro[index];
        pro[index]=flag;
    }
    w[0]=0;          
    for(i=1;i<n;i++)
    {
        w[i]=0;
        for(j=0;j<i;j++)
            w[i]+=b[j];
 
        all+=w[i];
    }
    average_w=(float)all/n;      
    all=0;
    printf("\nProcesses    Burst_Time    Waiting_Time\t\tTurnaround_Time");
    for(i=0;i<n;i++)
    {
        turn[i]=b[i]+w[i];     
        all+=turn[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",pro[i],b[i],w[i],turn[i]);
    }
 
    average_t=(float)all/n;     
    printf("\n\nAverage Waiting Time=%f",average_w);
    printf("\nAverage Turnaround Time=%f\n",average_t);
}
