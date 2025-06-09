#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	multiset <pair<double, int>> s;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		s.insert({ (double)num, i });
	}

	int curridx = n + 1;
	vector<pair<int, int>> averages;

	while (s.size() > 1) {
		auto it1 = s.begin();
		auto it2 = next(it1);
		double v1 = it1->first;
		int idx1 = it1->second;
		double v2 = it2->first;
		int idx2 = it2->second;

		s.erase(it1);
		s.erase(s.begin());
		double avg = (v1 + v2) / 2.0;
		s.insert({ avg, curridx });
		averages.push_back({ idx1, idx2 });
		curridx++;
	}
	for (auto avg : averages) {
		cout << avg.first << " " << avg.second << endl;
	}

	return 0;
}