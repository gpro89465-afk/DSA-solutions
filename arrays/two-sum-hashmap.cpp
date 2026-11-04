// Problem: Two Sum (LeetCode 1)
// Approach: Hash map (one pass, store seen numbers with their index)
// Time: O(n)   Space: O(n)

#include <iostream>
#include <unordered_map>
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
    // Logic: Hash map stores each number we have seen so far.
    // Key = the number, Value = its index in the array
    unordered_map<int, int> seen;
    // Logic: Single pass over the array
    for (int i = 0; i < n; i++) {
        // Logic: The number that must have appeared earlier
        // for arr[i] to complete the target sum
        int need = target - arr[i];
        // Logic: If "need" is already in the map, we found our pair.
        // Lookup in a hash map is O(1), so this replaces the inner loop
        if (seen.find(need) != seen.end()) {
            cout << "Pair found: " << need << " + " << arr[i] << endl;
            cout << "Indices: " << seen[need] << " " << i << endl;
            return 0; // Logic: Stop immediately after the first valid pair
        }
        // Logic: Store the current number AFTER checking, so an element
        // is never paired with itself
        seen[arr[i]] = i;
    }
    // Logic: If the loop finishes without returning, no pair adds up to the target
    cout << "No pair found" << endl;
    return 0;
}
