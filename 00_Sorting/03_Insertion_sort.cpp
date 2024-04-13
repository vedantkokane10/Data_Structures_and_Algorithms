#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[6] = {1, 3, 6, 4, 7, 2};
    int n = 6;
    
    // Insertion Sort
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]) {                    // j > 0 because if j = 0, arr[j-1] would be out of bounds
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }

    for(auto x : arr) {
        cout << x << " ";
    }

    return 0;
}

// Worst / Avg ==> O(n^2)
// Best ==> O(n)
