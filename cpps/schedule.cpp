#include<bits/stdc++.h>
using namespace std;
void sjfnp(int n, int a[],int b[])
{
    int temp,tt=0,min,d,i,j;
    float awt=0,stat=0,swt=0;
    int e[n],tat[n],wt[n];
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(b[i]>b[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
 
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    min=a[0];
    for(i=0; i<n; i++)
    {
        if(min>a[i])
        {
            min=a[i];
            d=i;
        }
    }
    tt=min;
    e[d]=tt+b[d];
    tt=e[d];
 
    for(i=0; i<n; i++)
    {
        if(a[i]!=min)
        {
            e[i]=b[i]+tt;
            tt=e[i];
        }
    }
    for(i=0; i<n; i++)
    {
 
        tat[i]=e[i]-a[i];
        stat=stat+tat[i];
        wt[i]=tat[i]-b[i];
        swt=swt+wt[i];
    }
    awt=swt/n;
 
    cout<<"SJF Non Preemptive Average Waiting Time: ="<<awt<<endl;
    cout<<endl;
    cout<<endl;
 
}
void fcfs(int n, int a[],int bt[])
{
    int ct=0;
    float ans=0;
    for(int i=0; i<n; i++)
    {
        ct+=bt[i];
        ans+=ct-bt[i]-a[i];
    }
    cout<<"FCFS Average Waiting Time: "<<ans/n<<endl;
     cout<<endl;
    cout<<endl;
 
}
void sjfp(int p,int a[],int cbt[])
{
    int  i, j, sum=0, min, index;
    float awt=0, atat=0;
    int proc[p];
    int  *wt = new int[p];
  int  *gc = new int[p];
    int *tat = new int[p];
  int *tmp = new int[p];
 for(i=0; i<p; i++)
  {
     tmp[i]=cbt[i];
  }
  sort(cbt, cbt+p);
 
  for(j=0; j<=p; j++)
  {
    min=100;
    for(i=0; i<p; i++)
    {
      if(min>tmp[i]&&tmp[i]!=-1)
      {
       min=tmp[i];
       index=i;
      }
   }
 
    gc[j]=sum;
    wt[j]=sum;
    sum+=tmp[index];
    tat[j]=sum;
    tmp[index]=-1;
 
    if(j==p)
     break;
    proc[j]=index+1;
  }
 
  sum=0;
 for(j=0; j<=p; j++)
  {
    if(gc[j]<10)
     sum+=gc[j];
  }
 
    atat=(sum*1.0)/p;
 
    for(i=0; i<p; i++)
    {
     awt=awt+wt[i];
    }
 awt=(awt*1.0)/p;
 cout<<"SJF Preemptive Average Waiting Time: "<<awt<<endl;
 cout<<endl;
 cout<<endl;
}
void roundrobin(int n, int at[],int bt[])
{
    int i,time,remain,temps=0,time_quantum;
	int wt=0,tat=0;
	remain=n;
	int rt[n];
	for(i=0;i<n;i++)
	{
		rt[i]=bt[i];
	}
 
	cout<<"Enter the value of time QUANTUM:"<<endl;
	cin>>time_quantum;
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=time_quantum && rt[i]>0)
		{
			time += rt[i];
 
			rt[i]=0;
			temps=1;
		}
 
		else if(rt[i]>0)
		{
			rt[i] -= time_quantum;
 
			time += time_quantum;
 
		}
 
		if(rt[i]==0 && temps==1)
		{
			remain--;
			wt += time-at[i]-bt[i];
			tat += time-at[i];
			temps=0;
		}
 
		if(i ==n-1)
			i=0;
		else if(at[i+1] <= time)
			i++;
		else
			i=0;
	}
	cout<<"Round Robin Average waiting time "<<wt*1.0/n<<endl;
}
int main()
{
    cout<<"Enter the number of process: ";
    int n,ch;
    cin>>n;
    int a[n],b[n];
    cout<<"Enter Arival Time & Burst Time:\n";
    for(int i=0; i<n; i++)
    {
        cout<<"a["<<i+1<<"] : ";
        cin>>a[i];
        cout<<"b["<<i+1<<"] : ";
        cin>>b[i];
        cout<<endl;
    }
    do
    {
 
        cout<<"---------------------------------\n";
        cout<<"|\tCPU Scheduling MENU      |"<<endl;
        cout<<"|\t 1.FCFS                  |"<<endl;
        cout<<"|\t 2.SJF NonPreemptive     |"<<endl;
        cout<<"|\t 3.SJF Preemptive        |"<<endl;
        cout<<"|\t 4.Round Robin           |"<<endl;
        cout<<"|\t 5.All                   |"<<endl;
        cout<<"|\t 6.Exist                 |"<<endl;
        cout<<"---------------------------------\n";
 
        cout<<" Enter Your Choice 1 to 6 From The Menu : "<<endl;
        cin>>ch;
 
        switch(ch)
        {
        case 1:
            fcfs(n,a,b);
            break;
        case 2:
            sjfnp(n,a,b);
            break;
        case 3:
            sjfp(n,a,b);
            break;
        case 4:
            roundrobin(n,a,b);
            break;
        case 5:
            fcfs(n,a,b);
            sjfp(n,a,b);
            sjfnp(n,a,b);
            roundrobin(n,a,b);
            break;
        case 6:
            exit(0);
        default:
            cout<<"Oops ! You Enter Wrong number ! Tray Again"<<endl;
            break;
        }
    }
    while(ch!=7);
 
 
}
