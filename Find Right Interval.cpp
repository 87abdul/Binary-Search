#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size());
        map<int, int> m;
        for (int i = 0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;
        for (int i = 0; i < intervals.size(); i++) 
            ans[i] = m.lower_bound(intervals[i][1]) != end(m) ? m.lower_bound(intervals[i][1])->second : -1;
        return ans;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {5, 6}, {7, 8}};
    
    Solution obj;
    vector<int> result = obj.findRightInterval(intervals);

    cout << "Right Intervals: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
