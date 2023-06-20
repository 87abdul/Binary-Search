#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        if (mp[key][0].first > timestamp) {
            return "";
        }

        string ans;
        int l = 0, r = mp[key].size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (mp[key][m].first == timestamp) {
                return mp[key][m].second;
            } else if (mp[key][m].first < timestamp) {
                ans = mp[key][m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};

int main() {
    TimeMap* obj = new TimeMap();
    obj->set("key1", "value1", 1);
    obj->set("key1", "value2", 2);
    obj->set("key2", "value3", 3);

    string value1 = obj->get("key1", 1);
    string value2 = obj->get("key1", 3);
    string value3 = obj->get("key2", 4);

    cout << "Value at timestamp 1 for key1: " << value1 << endl;
    cout << "Value at timestamp 3 for key1: " << value2 << endl;
    cout << "Value at timestamp 4 for key2: " << value3 << endl;

    delete obj;
    return 0;
}
