#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> v1(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v1[i] = num;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }
    vector<int> v2;
    for (int i = 0; i < n; i++) {
        if (s.find(v1[i]) == s.end()) {
            v2.push_back(v1[i]);

        }
    }
    cout << v2.size() << endl;
    for (int v : v2) {
        cout << v << " ";
    }

    return 0;
}