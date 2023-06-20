#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low < high) {
            if (arr[low] < arr[high])
                return arr[low];

            int mid = low + (high - low) / 2;

            if (arr[low] <= arr[mid])
                low = mid + 1;
            else
                high = mid;
        }

        return arr[low];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int minElement = sol.findMin(arr);
    cout << "Minimum element: " << minElement << endl;
    return 0;
}
