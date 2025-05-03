#include <iostream>
#include <vector>
using namespace std;

class Word {
private:
	string word;
	long hash;

	long evaluateHash() {
		long sum = 0;

		if (word == "ADAUniversity") {
			return 0;
		}

		for (int i = 0; i < word.size(); i++) {
			sum += long(word[i]);
		}
		return sum;
	}
public:
	Word(string word) : word(word) {
		hash = evaluateHash();
	}

	void setWord(string word) {
		this->word = word;
		hash = evaluateHash(); //Пересчитываем хэш для нового слова
	}

	string getWord() {
		return word;
	}

	long getHash() {
		return hash;
	}
};

void BubleSort(vector<Word>&);

int main() {

	string word;
	vector<Word> array;

	while (cin >> word) {
		Word w(word);
		array.push_back(w);
	}

	BubleSort(array);

	for (int i = 0; i < array.size(); i++) {
		cout << array[i].getWord() << endl;
	}

	return 0;
}

void BubleSort(vector<Word>& v) {
	int size = v.size();
	int true_position = 0;

	if (size == 1) {
		return;
	}

	while (true_position != (size - 1)) {
		true_position = 0;
		for (int i = 0; i < (v.size() - 1); i++) {
			if (v[i].getHash() > v[i + 1].getHash()) {
				Word tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
			}
			else { true_position++; }
		}
	}

	return;
}