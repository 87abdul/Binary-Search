#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] > target) {
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;

    Solution obj;
    int result = obj.search(nums, target);

    if (result == -1) {
        cout << "Target not found" << endl;
    }
    else {
        cout << "Target found at index " << result << endl;
    }

    return 0;
}

