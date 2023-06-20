#include <iostream>
#include <map>

using namespace std;

class SnapshotArray {
public:
    map<int, map<int, int>> snaps;
    int snapId = 0;

    SnapshotArray(int length) {
        for (int i = 0; i < length; i++) {
            map<int, int> mp;
            mp[0] = 0;
            snaps[i] = mp;
        }
    }

    void set(int index, int val) {
        snaps[index][snapId] = val;
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {
        auto it = snaps[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

int main() {
    SnapshotArray* obj = new SnapshotArray(5);
    obj->set(0, 1);
    obj->set(1, 2);
    obj->set(2, 3);
    int snap1 = obj->snap();
    obj->set(0, 4);
    int snap2 = obj->snap();
    int val1 = obj->get(0, snap1);
    int val2 = obj->get(0, snap2);
    int val3 = obj->get(2, snap2);

    cout << "Value of index 0 at snapshot " << snap1 << ": " << val1 << endl;
    cout << "Value of index 0 at snapshot " << snap2 << ": " << val2 << endl;
    cout << "Value of index 2 at snapshot " << snap2 << ": " << val3 << endl;

    delete obj;
    return 0;
}
