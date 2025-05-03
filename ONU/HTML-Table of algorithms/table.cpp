#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <filesystem>

using namespace std;

void CreateTable(ofstream& myfile, fstream& data);

int main() {

	cout << "Let`s create a table, that compares the work of BubbleSort and SelectionSort algorithms" << endl;
	cout << "Enter the arrays, that you want to sort and compare (each string is new array, use ' ' instead ',', to stop write in next string '-s'):" << endl << endl;
	cout << "Current path: " << std::filesystem::current_path() << endl;

	string line;
	fstream data;
	data.open("./HTML-Table of algorithms/data.txt");
	if (data.is_open()) {
		while (getline(cin, line)) {
			if (line == "-s") {
				break;
			}
			data << line << endl;
			cout << "Succesfully added" << endl;
		}
	}
	data.close();

	ofstream myfile;
	myfile.open("./HTML-Table of algorithms/table.html");
	if (myfile.is_open()) {
		myfile << "<html>" << endl;
		myfile << "<head>" << endl;
		myfile << "<title>Comparison between Bubble & Selection sorts on C++</title>" << endl;
		myfile << "<h1>Comparison between Bubble & Selection sorts on C++</h1>" << endl;
		myfile << "</head>" << endl << endl;

		myfile << "<body>" << endl;
		
		
		CreateTable(myfile, data);
		
	}
	myfile.close();
	data.close();

	return 0;
}

void CreateTable(ofstream& myfile, fstream& data) {
	data.open("./HTML-Table of algorithms/data.txt");
	if (myfile.is_open() && data.is_open()) {

		string line;
		vector<int> v;
		while (getline(data, line)) {
			cout << line << endl;
		}
	}
	data.close();
	return;
}