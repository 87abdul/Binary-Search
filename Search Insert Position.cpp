#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = 0;

        if(target > nums[nums.size()-1]){
            return nums.size();  // target element should be placed at the last index of the array
        }

        int l = 0; 
        int h = nums.size()-1;

        while(l <= h){
            int mid = (l + h) / 2;
            if(target == nums[mid]){
                return mid;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }

        return h + 1;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 6;

    Solution obj;
    int result = obj.searchInsert(nums, target);

    cout << "Index to insert target: " << result << endl;

    return 0;
}
