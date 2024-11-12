#include <iostream>
#include <algorithm>
using namespace std;

struct Process { int id, bt, pt, wt, tat; };

bool comparePT(Process a, Process b) { return a.pt > b.pt; }
bool compareID(Process a, Process b) { return a.id < b.id; }

void calculateTimes(Process ps[], int n) {
    ps[0].wt = 0;
    for (int i = 1; i < n; i++)
        ps[i].wt = ps[i - 1].wt + ps[i - 1].bt;
    for (int i = 0; i < n; i++)
        ps[i].tat = ps[i].bt + ps[i].wt;
}

void display(Process ps[], int n) {
    int totalTAT = 0, totalWT = 0;
    cout << "ID\tPT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << ps[i].id << "\t" << ps[i].pt << "\t" << ps[i].bt << "\t" << ps[i].wt << "\t" << ps[i].tat << endl;
        totalTAT += ps[i].tat;
        totalWT += ps[i].wt;
    }
    cout << "AVG TAT = " << (float)totalTAT / n << "\nAVG WT = " << (float)totalWT / n << endl;
}

int main() {
    int n;
    cout << "Number of processes: ";
    cin >> n;
    Process ps[n];
    for (int i = 0; i < n; i++) {
        ps[i].id = i + 1;
        cout << "PT for process " << ps[i].id << ": ";
        cin >> ps[i].pt;
        cout << "BT for process " << ps[i].id << ": ";
        cin >> ps[i].bt;
    }
    sort(ps, ps + n, comparePT);
    calculateTimes(ps, n);
    sort(ps, ps + n, compareID);
    display(ps, n);
    return 0;
}