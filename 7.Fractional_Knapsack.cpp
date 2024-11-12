#include <iostream>
#include <iomanip>
using namespace std;

int n = 3;
int weights[10] = {10, 20, 30};
int profits[10] = {60, 100, 120};
int maxCapacity = 50;

int main() {
    int remainingCapacity = maxCapacity;
    float totalValue = 0.0;
    int used[10] = {0};

    while (remainingCapacity > 0) {
        int selectedItem = -1;

        // Find the item with the maximum profit-to-weight ratio
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0 && (selectedItem == -1 || 
                (float)profits[i] / weights[i] > (float)profits[selectedItem] / weights[selectedItem])) {
                selectedItem = i;
            }
        }

        used[selectedItem] = 1;
        remainingCapacity -= weights[selectedItem];
        totalValue += profits[selectedItem];

        if (remainingCapacity >= 0) {
            cout << "Added object " << selectedItem + 1 << " (" << profits[selectedItem] << ", " << weights[selectedItem]
                 << ") completely in the bag. Space left: " << remainingCapacity << "." << endl;
        } else {
            int percentage = (int)((1 + (float)remainingCapacity / weights[selectedItem]) * 100);
            cout << "Added " << percentage << "% of object " << selectedItem + 1 << " (" << profits[selectedItem] 
                 << ", " << weights[selectedItem] << ") in the bag." << endl;

            totalValue -= profits[selectedItem];
            totalValue += (1 + (float)remainingCapacity / weights[selectedItem]) * profits[selectedItem];
            break;
        }
    }

    cout << fixed << setprecision(2) << "Filled the bag of objects worth " << totalValue << "." << endl;
    return 0;
}


// ********************************OUTPUT*************************
// Added object 1 (60, 10) completely in the bag. Space left: 40.
// Added object 2 (100, 20) completely in the bag. Space left: 20.
// Added 66% of object 3 (120, 30) in the bag.
// Filled the bag of objects worth 240.00.
