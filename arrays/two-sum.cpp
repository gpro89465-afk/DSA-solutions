// Problem: Two Sum (LeetCode 1)
// Approach: Brute force (two nested loops)
// Time: O(n^2)   Space: O(1)

#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Logic: Single place to control the maximum array size

int main() {
    int n, target;

    // Logic: Take the size of the array from the user
    cout << "Enter array size (1 to " << MAX_SIZE << "): ";
    cin >> n;

    // Logic: Validate input. If cin failed (e.g. user typed a letter)
    // or n is outside the valid range, stop before touching the array
    if (cin.fail() || n < 1 || n > MAX_SIZE) {
        cout << "Invalid size! Size must be between 1 and " << MAX_SIZE << endl;
        return 1; // Logic: Non-zero return means the program ended with an error
    }

    int arr[MAX_SIZE]; // Fixed-size array, now safe because n is validated

    // Logic: Read all n elements into the array
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Logic: Read the target sum we want to find
    cout << "Enter target: ";
    cin >> target;

    // Logic: Brute force approach. Fix one element at index i,
    // then check it against every element after it.
    for (int i = 0; i < n; i++) {

        // Logic: Start j from i + 1 so that we never pair an element
        // with itself and never check the same pair twice
        for (int j = i + 1; j < n; j++) {

            // Logic: If the two elements add up to the target, we found our answer
            if (arr[i] + arr[j] == target) {
                cout << "Pair found: " << arr[i] << " + " << arr[j] << endl;
                cout << "Indices: " << i << " " << j << endl;
                return 0; // Logic: Stop immediately after the first valid pair
            }
        }
    }

    // Logic: If both loops finish without returning, no pair adds up to the target
    cout << "No pair found" << endl;
    return 0;
}
