/*
Input:
Consists of several tests, each containing two lines. Each line consists of lowercase characters, with the first line 
in the pair being a and the second line being b. The maximum length of each line is 1000 characters.

Output:
For each test, output the string x. If there are several such strings, output the smallest one in alphabetical order.
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string word1, word2;

	while (getline(cin, word1) && getline(cin, word2)) {
		map <char, int> map1, map2;

		for (int i = 0; i < word1.size(); i++) {
			map1[word1[i]]++;
		}
		for (int i = 0; i < word2.size(); i++) {
			map2[word2[i]]++;
		}

		for (auto e : map1) {
			char k = e.first;
			if (map2.find(k) != map2.end()) {
				int min1 = min(map1[k], map2[k]);
				for (int i = 0; i < min1; i++) {
					cout << k;
				}
			}
		}
		cout << endl;
	}
	return 0;
}