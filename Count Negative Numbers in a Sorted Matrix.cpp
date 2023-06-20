#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        int r = 0;
        int c = n - 1;

        while (r < m) {
            while (c >= 0 && grid[r][c] < 0) {
                --c;
            }

            count += n - c - 1; // Elements from the end will be counted
            ++r;
        }

        return count;
    }
};

int main() {
    vector<vector<int>> grid = {{4, 3, 2, -1},
                                {3, 2, 1, -1},
                                {1, 1, -1, -2},
                                {-1, -1, -2, -3}};

    Solution obj;
    int result = obj.countNegatives(grid);

    cout << "Number of negative numbers: " << result << endl;

    return 0;
}
