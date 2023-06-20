#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char result = letters[0];
        int l = 0;
        int h = letters.size() - 1;

        while (l <= h) {
            int mid = (l + h) / 2;
            if (target >= letters[mid]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return l == letters.size() ? result : letters[l];
    }
};

int main() {
    vector<char> letters = {'c', 'f', 'j', 'm'};
    char target = 'g';

    Solution obj;
    char result = obj.nextGreatestLetter(letters, target);

    cout << "Next greatest letter: " << result << endl;

    return 0;
}
