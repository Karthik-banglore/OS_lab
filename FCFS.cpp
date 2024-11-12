#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: "; cin >> n;
    int bt[n], wt = 0, tat = 0, total_wt = 0, total_tat = 0;

    cout << "Enter burst times:\n";
    for (int i = 0; i < n; i++) cin >> bt[i];

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << "\t" << bt[i] << "\t\t" << wt << "\t\t" << (tat = wt + bt[i]) << endl;
        total_wt += wt;
        total_tat += tat;
        wt += bt[i];
    }

    cout << "\nAverage Waiting Time: " << (float)total_wt / n;
    cout << "\nAverage Turnaround Time: " << (float)total_tat / n << endl;

    return 0;
}