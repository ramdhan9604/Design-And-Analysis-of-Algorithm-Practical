#include <algorithm>
#include <iostream>
using namespace std;

// A structure to represent a job
struct Job {
    char id;    // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is done before or on the deadline
};

// Comparator function for sorting jobs by profit in descending order
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to schedule jobs to maximize profit
void printJobScheduling(Job arr[], int n) {
    // Sort all jobs according to decreasing order of profit
    sort(arr, arr + n, comparison);

    int result[n]; // To store result (Sequence of jobs)
    bool slot[n];  // To keep track of free time slots
    int totalProfit = 0; // Variable to store the total profit

    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            // Free slot found
            if (slot[j] == false) {
                result[j] = i;       // Add this job to result
                slot[j] = true;      // Mark this slot as occupied
                totalProfit += arr[i].profit; // Add profit of this job
                break;
            }
        }
    }

    // Print the scheduled jobs
    cout << "Scheduled jobs: ";
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
    
    // Print the total profit
    cout << "\nTotal Profit: " << totalProfit << endl;
}

// Driver code
int main() {
    Job arr[] = {{ 'a', 2, 6 }, { 'b', 1, 8 }, { 'c', 1, 5 }, { 'd', 2, 10 } };

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is the maximum profit sequence of jobs:\n";

    // Function call
    printJobScheduling(arr, n);
    return 0;
}


// ***************************************************OUTPUT*******************************************
// Following is the maximum profit sequence of jobs:
// Scheduled jobs: b d
// Total Profit: 18
