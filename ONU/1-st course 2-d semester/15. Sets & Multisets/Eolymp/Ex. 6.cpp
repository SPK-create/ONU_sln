#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<pair<int, int>> points;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        points.insert({ x, i + 1 });
    }

    auto it = points.begin();
    auto prev_it = it++;

    int min_dist = abs(it->first - prev_it->first);
    int idx1 = prev_it->second;
    int idx2 = it->second;

    while (it != points.end()) {
        int d = abs(it->first - prev_it->first);
        if (d < min_dist) {
            min_dist = d;
            idx1 = prev_it->second;
            idx2 = it->second;
        }
        it++;
        prev_it++;
    }

    cout << min_dist << endl;
    cout << idx1 << " " << idx2 << endl;

    return 0;
}