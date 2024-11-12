#include <iostream>
#include <iomanip>
using namespace std;

int n = 3;
int weights[] = {60, 100, 120};
int profits[] = {10, 20, 30};
int maxWeight = 50;

int main() {
    int currentWeight = maxWeight;
    float totalValue = 0.0;
    int used[10] = {0};  // Array to track if an item has been used

    // Continue filling the knapsack until no space is left
    while (currentWeight > 0) {
        int maxIndex = -1;

        // Find the item with the maximum profit-to-weight ratio
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0 && (maxIndex == -1 || (float)profits[i] / weights[i] > (float)profits[maxIndex] / weights[maxIndex])) {
                maxIndex = i;
            }
        }

        // Mark the selected item as used
        used[maxIndex] = 1;
        currentWeight -= weights[maxIndex];

        // If the item fits completely in the knapsack
        if (currentWeight >= 0) {
            totalValue += profits[maxIndex];
            cout << "Added object " << maxIndex + 1 << " (weight: " << weights[maxIndex] 
                 << ", profit: " << profits[maxIndex] << ") completely in the bag. Space left: " 
                 << currentWeight << "." << endl;
        } else {
            // If only part of the item can be added to the knapsack
            totalValue += (1 + (float)currentWeight / weights[maxIndex]) * profits[maxIndex];
            cout << "Added " << (int)((1 + (float)currentWeight / weights[maxIndex]) * 100) 
                 << "% of object " << maxIndex + 1 << " (weight: " << weights[maxIndex] 
                 << ", profit: " << profits[maxIndex] << ") in the bag." << endl;
            break;
        }
    }

    cout << fixed << setprecision(2) << "Filled the bag with objects worth " << totalValue << "." << endl;
    return 0;
}


// ****************************OUTPUT*****************************
// Added 41% of object 3 (weight: 120, profit: 30) in the bag.
// Filled the bag with objects worth 12.50.
