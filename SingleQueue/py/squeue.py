def printf(str, *args):
    print(str % args, end='')  

rnd_arrival=[0]
rnd_service=[0]
arrival=[0]
service=[0]
arrival_time=[0]
service_begins=[0]
wait_in_queue=[0]
service_ends=[0]
spends_in_system=[0]
idle_time=[0]


x=int(0)
service_time_total=int(0)
wait_in_queue_total=int(0)
spends_in_system_total=int(0)
idle_time_total=int(0)


n=input(int())
noc=int(n)


i=int(1)
for j in range (1,noc+1,1):
   
    a=input(int())
    b=input(int())
    rnd_arrival.append(int(a))
    rnd_service.append(int(b))

    if(rnd_arrival[i]>=1 and rnd_arrival[i]<=125): arrival.append(1)
    elif(rnd_arrival[i]>=126 and rnd_arrival[i]<=250): arrival.append(2)
    elif(rnd_arrival[i]>=251 and rnd_arrival[i]<=375): arrival.append(3)
    elif(rnd_arrival[i]>=376 and rnd_arrival[i]<=500): arrival.append(4)
    elif(rnd_arrival[i]>=501 and rnd_arrival[i]<=625): arrival.append(5)
    elif(rnd_arrival[i]>=626 and rnd_arrival[i]<=750): arrival.append(6)
    elif(rnd_arrival[i]>=751 and rnd_arrival[i]<=875): arrival.append(7)
    elif(rnd_arrival[i]>=876 and rnd_arrival[i]<=999): arrival.append(8)
    else : arrival.append(0)


    if(rnd_service[i]>=1 and rnd_service[i]<=10): service.append(1)
    elif(rnd_service[i]>=11 and rnd_service[i]<=30): service.append(2)
    elif(rnd_service[i]>=31 and rnd_service[i]<=60): service.append(3)
    elif(rnd_service[i]>=61 and rnd_service[i]<=85): service.append(4)
    elif(rnd_service[i]>=86 and rnd_service[i]<=95): service.append(5)
    elif(rnd_service[i]>=96 and rnd_service[i]<=99): service.append(6)
    else : service.append(0)

    
    arrival_time.append(arrival_time[i-1]+arrival[i])


    if(x<arrival_time[i]):
        x=arrival_time[i]

    service_begins.append(x)
    x+=service[i]

    wait_in_queue.append(service_begins[i]-arrival_time[i])
    service_ends.append(service[i]+service_begins[i])
    spends_in_system.append(service_ends[i]-arrival_time[i])
    idle_time.append(service_begins[i]-service_ends[i-1])

    service_time_total+=service[i]
    wait_in_queue_total+=wait_in_queue[i]
    spends_in_system_total+=spends_in_system[i]
    idle_time_total+=idle_time[i]
    
    i+=1

printf("    A       B       C        D        E        F        G         H        I\n")
printf("Customer  Last   Arrival  Service  Service  Wait in  Service  Spends in  Idle\n")
printf("         Arrival   Time     Time    Begins   Queue     Ends     System   Time\n")
printf("-----------------------------------------------------------------------------\n")
for i in range (1,noc+1):
    printf("%5d%7d%9d%9d%9d%9d%9d%10d%9d\n",i,arrival[i],arrival_time[i],service[i],service_begins[i],wait_in_queue[i],service_ends[i],spends_in_system[i],idle_time[i])

printf("\t\t\t    ---\t\t      ---\t\t---\t  ---\n")
printf("\t\t\t    %d\t\t      %d\t\t%d\t  %d\n", service_time_total, wait_in_queue_total,spends_in_system_total,idle_time_total)
