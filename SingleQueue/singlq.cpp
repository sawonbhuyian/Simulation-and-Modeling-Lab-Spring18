#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max 100000
int  rnd_arrival[max],rnd_service[max],arrival[max],service[max],arrival_time[max],service_begins[max];
int wait_in_queue[max],service_ends[max],spends_in_system[max],idle_time[max];
int main()
{

    freopen("sinput.txt","r",stdin);
    //freopen("spoutput.txt","w",stdout);
    int noc,nor,x=0,service_time_total=0,wait_in_queue_total=0,spends_in_system_total=0,idle_time_total=0;

    printf("Enter number of customer: ");
    scanf("%d",&noc);
    printf("Input %d random digits for Arrival times and Service times\n",nor);
    arrival_time[0]=0;
    service_ends[0]=0;
    for(int i=1;i<=noc;++i){
      //  printf("Enter 2 random digits for customer %d : ",i);
        scanf("%d %d",&rnd_arrival[i],&rnd_service[i]);

        if(rnd_arrival[i]>=1 && rnd_arrival[i]<=125) arrival[i]=1;
        else if(rnd_arrival[i]>=126 && rnd_arrival[i]<=250) arrival[i]=2;
        else if(rnd_arrival[i]>=251 && rnd_arrival[i]<=375) arrival[i]=3;
        else if(rnd_arrival[i]>=376 && rnd_arrival[i]<=500) arrival[i]=4;
        else if(rnd_arrival[i]>=501 && rnd_arrival[i]<=625) arrival[i]=5;
        else if(rnd_arrival[i]>=626 && rnd_arrival[i]<=750) arrival[i]=6;
        else if(rnd_arrival[i]>=751 && rnd_arrival[i]<=875) arrival[i]=7;
        else if(rnd_arrival[i]>=876 && rnd_arrival[i]<=999) arrival[i]=8;
        else arrival[i]=0;


        if(rnd_service[i]>=1 && rnd_service[i]<=10) service[i]=1;
        else if(rnd_service[i]>=11 && rnd_service[i]<=30) service[i]=2;
        else if(rnd_service[i]>=31 && rnd_service[i]<=60) service[i]=3;
        else if(rnd_service[i]>=61 && rnd_service[i]<=85) service[i]=4;
        else if(rnd_service[i]>=86 && rnd_service[i]<=95) service[i]=5;
        else if(rnd_service[i]>=96 && rnd_service[i]<=99) service[i]=6;
        else service[i]=0;

        arrival_time[i]=arrival_time[i-1]+arrival[i];


        if(x<arrival_time[i]){
            x=arrival_time[i];
        }
        else{

        }
        service_begins[i]=x;
        x+=service[i];

        wait_in_queue[i]=service_begins[i]-arrival_time[i];
        service_ends[i]=service[i]+service_begins[i];
        spends_in_system[i]=service_ends[i]-arrival_time[i];
        idle_time[i]=service_begins[i]-service_ends[i-1];

        service_time_total+=service[i];
        wait_in_queue_total+=wait_in_queue[i];
        spends_in_system_total+=spends_in_system[i];
        idle_time_total+=idle_time[i];


    }


    printf("Customer \t Random Digits \t Times between arrival\n");
    for(int i=1;i<=noc;++i){
        printf("%5d\t\t %9d \t   %9d\n",i+1,rnd_arrival[i],arrival[i]);
    }
    printf("\n\n");
    printf("Customer \t Random Digits \t Service Time\n");
    for(int i=1;i<=noc;++i){
        printf("%5d \t\t%9d\t %7d\n",i+1,rnd_service[i],service[i]);
    }



    printf("    A       B       C        D        E        F        G         H        I\n");
    printf("Customer  Last   Arrival  Service  Service  Wait in  Service  Spends in  Idle\n");
    printf("         Arrival   Time     Time    Begins   Queue     Ends     System   Time\n");
    printf("-----------------------------------------------------------------------------\n");
    for(int i=1;i<=noc;++i){
        printf("%5d%7d%9d%9d%9d%9d%9d%10d%9d\n",i,arrival[i],arrival_time[i],service[i],service_begins[i],wait_in_queue[i],service_ends[i],spends_in_system[i],idle_time[i]);
    }
    printf("\t\t\t    ---\t\t      ---\t\t---\t  ---\n");
    printf("\t\t\t    %d\t\t      %d\t\t%d\t  %d\n", service_time_total, wait_in_queue_total,spends_in_system_total,idle_time_total);




}
