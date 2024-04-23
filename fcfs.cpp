    #include<iostream>
    using namespace std;

    double total(int arr[], int n)
    {
        double total = 0;
        for(int i = 0; i<n; i++)
        {
            total += arr[i];
        }
        return total;
    }

    void process(int arrivalTime[], int burstTime[], int n)
    {
        int completionTime[n], turnAroundTime[n], waitingTime[n], respawnTime[n];
        int averageTat, averageWt, averageRt;
        double totalTat = 0, totalWt = 0, totalRt = 0;

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                completionTime[i] = burstTime[i];
            }
            else
            {
                completionTime[i] = max(arrivalTime[i], completionTime[i-1]) + burstTime[i];
            }

        }

        for(int i = 0; i < n; i++)
        {
            turnAroundTime[i] = completionTime[i] - arrivalTime[i];
            waitingTime[i] = turnAroundTime[i] - burstTime[i];
        }

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                respawnTime[i] = 0;
            }
            else
            {
                respawnTime[i] = max(arrivalTime[i],completionTime[i-1]) - arrivalTime[i];
            }
        }

        cout << "Completion Time\tTurnaround Time\tWaiting Time\tResponse Time" << endl;

        for(int i = 0; i<n; i++)
        {
            cout<<completionTime[i]<<"\t\t"<<turnAroundTime[i]<<"\t\t"<<waitingTime[i]<<"\t\t"<<respawnTime[i]<<endl;
        }

        cout<<endl;

        cout<<"Average Turnaround Time: "<<total(turnAroundTime, n) / n<<endl;
        cout<<"Average Waiting Time: "<<total(waitingTime, n) / n<<endl;
        cout<<"Average Response Time: "<<total(respawnTime, n) / n<<endl;

    }

    int main()
    {
        cout<<"Enter process size: "<<endl;
        int n;
        cin>>n;

        int arrivalTime[n];
        int burstTime[n];

        cout<<"Enter arrival Time: "<<endl;
        for(int i = 0; i < n; i++)
        {
            cin>>arrivalTime[i];
        }
        cout<<"Enter Burst Time: "<<endl;
        for(int i = 0; i < n; i++)
        {
            cin>>burstTime[i];
        }

        process(arrivalTime, burstTime, n);

        return 0;
    }
