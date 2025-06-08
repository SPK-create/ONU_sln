#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    set<int> results;
    for (int i = min(a, b); i <= max(a, b); i++)
    {
        for (int j = min(c, d); j <= max(c, d); j++)
        {
            results.insert(i * j);
        }
    }
    cout << results.size() << endl;
}