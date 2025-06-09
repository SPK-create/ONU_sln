#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<long> s;
    for (long i = 0; i < n; i++) {
        long num;
        cin >> num;
        s.insert(num);
    }

    long total = 0;
    while (s.size() > 1) {
        long n1 = *s.begin();
        s.erase(s.begin());

        long n2 = *s.begin();
        s.erase(s.begin());

        long sum = n1 + n2;
        s.insert(sum);
        total += sum;
    }
    cout << total;

    return 0;
}