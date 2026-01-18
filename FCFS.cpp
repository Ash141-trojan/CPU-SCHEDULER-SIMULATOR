#include<iostream>
using namespace std;

auto findwaitingtime(int n, int burst_time[], int waiting_time[]){
    waiting_time[0] = 0;
    unsigned long long Total = 0;
    for (int i = 0; i < n - 1 ; i++){ // calculating waiting time for next process 
        waiting_time[i + 1] = burst_time[i]+waiting_time[i];
        Total += waiting_time[i];
    }
    return (Total + waiting_time[n-1]);
}

void turnaroundtime(int n ,int waiting_time[], int burst_time[] , int turnaround[]){
    for (int i = 0; i < n; i++){
        turnaround[i] = waiting_time[i]+burst_time[i];
    }
}

void averagewaitingtime(int processes[], int n , int burst_time[]){
    int averagetime , turnaround[n], waiting_time[n];

    auto totalWaitTime = findwaitingtime(n , burst_time, waiting_time);

    turnaroundtime(n ,waiting_time, burst_time,turnaround);

    cout<<"Processes  "<< "Burst time  "
    <<" waiting time  "<<" turnaround time \n ";

    for (int i = 0; i < n; i++){
        cout << processes[i] << "\t\t"
             << burst_time[i] << "\t\t"
             << waiting_time[i] << "\t\t"
             << turnaround[i] << endl;
    }
    // cout<<"\n debug : Total wait time "<<totalWaitTime<<endl;
    cout<<"\n Average waiting time : " << (double(totalWaitTime) / n) << endl;
}

int main(){

    int processes[]= {1,2,3};
    int n = sizeof processes / sizeof processes[0];

    int burst_time[]={10,5,8};

    averagewaitingtime(processes,n, burst_time);
 return 0;
}

