// Problem: Contains Duplicate (LeetCode 217)
//
// Approach 1: Brute force (two nested loops)
//   Time: O(n^2)   Space: O(1)
// Approach 2: Hash set (one pass)
//   Time: O(n)     Space: O(n)
// Hash set is faster because looking up a number takes O(1) on average.
//Approach 1: Brute Force.
#include <iostream>
using namespace std;
const int MAX_SIZE = 100; // Logic: Single place to control the maximum array size
int main() {
    int n;
    // Logic: Take the size of the array from the user
    cout << "Enter array size (1 to " << MAX_SIZE << "): ";
    cin >> n;
    // Logic: Validate input before touching the array
    if (cin.fail() || n < 1 || n > MAX_SIZE) {
        cout << "Invalid size! Size must be between 1 and " << MAX_SIZE << endl;
        return 1;
    }
    int arr[MAX_SIZE];
    // Logic: Read all n elements into the array
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Logic: Fix one element at index i and compare it with every element after it
    for (int i = 0; i < n; i++) {
        // Logic: Start j from i + 1 so an element is never compared with itself
        for (int j = i + 1; j < n; j++) {
            // Logic: If two elements are equal, a duplicate exists
            if (arr[i] == arr[j]) {
                cout << "true (duplicate found: " << arr[i] << ")" << endl;
                return 0; // Logic: Stop immediately after the first duplicate
            }
        }
    }
    // Logic: Both loops finished without a match, so all elements are distinct
    cout << "false (no duplicates)" << endl;
    return 0;
}
//Approach 2:Hash Set.
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
    int n;
    // Logic: Take the size of the array from the user
    cout << "Enter array size: ";
    cin >> n;
    // Logic: Validate input. Size must be a positive number
    if (cin.fail() || n < 1) {
        cout << "Invalid size! Size must be at least 1" << endl;
        return 1;
    }
    vector<int> arr(n); // Logic: vector has no fixed limit, so no overflow risk
    // Logic: Read all n elements into the vector
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_set<int> seen; // Logic: Stores every element we have visited so far
    for (int i = 0; i < n; i++) {
        // Logic: If the element is already in the set, it appeared before, so it is a duplicate
        if (seen.count(arr[i])) {
            cout << "true (duplicate found: " << arr[i] << ")" << endl;
            return 0; // Logic: Stop immediately after the first duplicate
        }
        // Logic: Otherwise, remember this element for future checks
        seen.insert(arr[i]);
    }
    // Logic: No element repeated, so all elements are distinct
    cout << "false (no duplicates)" << endl;
    return 0;
}
