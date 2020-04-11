#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;



int main()
{


	cout<<"--------------------------------------------------> WELCOME TO CPU SCHEDULING SIMULATION <--------------------------------------------------\n"
	    <<"-------------------------------------------------->       MULTILEVEL FEEDBACK QUEUE      <--------------------------------------------------\n\n"
        <<"Press any key to continue...";

    cin.get();

    cout<<("\e[1;1H\e[2J");


	int num;

	 	
	cout<<"Enter number of processes : ";
	cin>>num;
	
	
	int process[num], arrival[num], burst[num], t_around[num], waiting[num], burstNew[num], queueNew[num];
	

	for(int i=0;i<num;i++)
	{	
		process[i] = i+1;
		
		cout<<"\n\nEnter arrival time : ";
		cin>>arrival[i];

		cout<<"Enter Burst time : ";
		cin>>burst[i];

		burstNew[i] = burst[i];
		waiting[i]=0;
		t_around[i]=0;
		queueNew[i] = 0;

	}
	


	int temp;


	for(int i=0;i<num-1;i++)
	for(int j=i+1;j<num;j++)

	if(arrival[i] > arrival[j])
		{
			temp = burst[i];
			burst[i] = burst[j];
			burst[j] = temp;
			temp = burstNew[i];
			burstNew[i] = burstNew[j];
			burstNew[j] = temp;
			temp = arrival[i];
			arrival[i] = arrival[j];
			arrival[j] = temp;
			temp = process[i];
			process[i] = process[j];
			process[j] = temp;
		}
	

	for(int i=0;i<num;i++)
	{
		cout<<"P"<<process[i]<<arrival[i]<<burst[i]
		    <<waiting[i]<<t_around[i]<<queueNew[i];
	}

	cout<<" \n";
	
	
	int queue1[num], queue2[num], q[num];
	int t = arrival[0];
	int qtm1 = 8 , qtm2 = 16 ;
	
	
	for(int i=0;i<num;i++)
	{
		t += qtm1;
		burstNew[i] -= qtm1;
		queue1[i] = burstNew[i];
			
		if(burstNew[i] <= 0)
		{
			queue1[i] = 0;
			waiting[i] = 	t - arrival[i]-burst[i];
			t_around[i] = t-arrival[i];
			queueNew[i] = 1;	
		}		
	}
	
	
	for(int i=0;i<num;i++)
	{
		if(queue1[i]>0)
		{
		
		if(queue1[i] >=  qtm2)
		{
			t += qtm2;
			queue1[i] -= qtm2;
			queue2[i] = queue1[i];
			
			if(queue1[i] <= 0)
			{
				queue2[i] = 0;
				waiting[i] = t - arrival[i]-burst[i];
				t_around[i] = t-arrival[i];
				queueNew[i] = 2;	
			}
		}
		else 
		{
			t += queue1[i];
			queue1[i] = 0;
			queue2[i] = queue1[i];
			waiting[i] = 	t - arrival[i]-burst[i];
			t_around[i] = t-arrival[i];
			queueNew[i] = 2;					
			}	
		}		
	}	
	
	
	
	for(int i=0;i<num;i++)
	{
		if(queue2[i] <= 0)
		{
			burstNew[i] = 0;
			waiting[i] = 	t - arrival[i]-burst[i];
			t_around[i] = t-arrival[i];
			queueNew[i] = 3;	
		}
		
		if(queue2[i]>0)
		{

		t = t + queue2[i];
		queue2[i] =0;
		q[i] = queue2[i];
			
		}			
	}	
	
	double avgWait=0, avgTaround=0;

	cout<<"\n\nPress any key to see simulation summary \n";
    cin.get();
    cout<<("\e[1;1H\e[2J");
    cout<<("\e[1;1H\e[2J");


    cout<<"\n----------------------------------------->  Simulation Summary <---------------------------------------- \n\n";
    
    cout <<  "Process   " << setw(15) << right  << "Arrival time"  << setw(15) << right << "Burst time"  << setw(15) << right << "Waiting time" << setw(20) << right << "Turnaround time"<<endl<<endl;
    int g = 0;
	
	while( g < num ) 
	{
		cout <<  "P"  <<process[g] << setw(18) << right << arrival[g] << setw(15) << right << burst[g]  << setw(15) << right << waiting[g]  << setw(15) << right << t_around[g] <<"\n\n";	
		g++;
	}
	
	cout<<endl<<endl;


	for(int g=0;g<num;g++)
	{
		avgWait = avgWait + waiting[g];
		avgTaround = avgTaround + t_around[g];
	}
	

	cout<<"\t\t\t\tAverage Waiting Time : " 
	    << (avgWait/num) ;
	cout<<"\n\t\t\t\tAverage Turnaround Time : "
	    << (avgTaround/num) ;

}