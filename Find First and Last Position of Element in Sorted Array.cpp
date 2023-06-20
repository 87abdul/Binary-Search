#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_ele = firstOccurrence(nums, target);
        int last_ele = lastOccurrence(nums, target);
        return {first_ele, last_ele}; 
    }

    int firstOccurrence(vector<int>& nums, int target) {
        int n = nums.size();
        int res = -1;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                res = mid;
                high = mid - 1; // Look for target on the left side
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int n = nums.size();
        int res = -1;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                res = mid;
                low = mid + 1; // Look for target on the right side
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 4, 4, 5};
    int target = 4;

    Solution obj;
    vector<int> result = obj.searchRange(nums, target);

    cout << "First Occurrence: " << result[0] << endl;
    cout << "Last Occurrence: " << result[1] << endl;

    return 0;
}
