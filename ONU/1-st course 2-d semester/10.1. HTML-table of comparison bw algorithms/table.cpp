#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

struct SortStats {
    string alg;
    int length;
    string state;
    int comp;
    int perm;
};

void generate(int a[], int n, string type) {
    if (type == "random") {
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 100;
        }
    }
    else if (type == "sorted") {
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
    }
    else if (type == "reversed") {
        for (int i = 0; i < n; i++) {
            a[i] = n - i;
        }
    }
}

void bubble(int* a, int n, SortStats& stats) {
    stats.alg = "Bubble Sort";
    stats.length = n;
    int c = 0;
    int p = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            c++;
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                p++;
            }
        }
    }
    stats.comp = c;
    stats.perm = p;
    cout << p << endl;
}

void print(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << "   ";
    }
    cout << endl;
}

void insertion(int* a, int n, SortStats& stats) {
    stats.alg = "Insertion Sort";
    stats.length = n;
    int c = 0;
    int p = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        c++;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
            p++;
        }
        a[j + 1] = key;
        if ((j + 1) != i) {
            c++;
            p++;
        }
    }
    stats.comp = c;
    stats.perm = p;
}

void generate_html(SortStats* results, int n) {
    ofstream file("10.1. HTML-table of comparison bw algorithms\\algorithms.html");
    file << "<html>";
    file << "<table border='1' align=center width='50%' cellspacing='0' cellpadding='6'>";
    file << "<tr>";
    file << "<th>Aglorithm Name</th>";
    file << "<th>Array Length</th>";
    file << "<th>State</th>";
    file << "<th>Comparison Number</th>";
    file << "<th>Permutation Number</th>";
    file << "</tr>";

    for (int i = 0; i < n; i++) {
        file << "<tr>";
        file << "<td>" << results[i].alg << "</td>";
        file << "<td>" << results[i].length << "</td>";
        file << "<td>" << results[i].state << "</td>";
        file << "<td>" << results[i].comp << "</td>";
        file << "<td>" << results[i].perm << "</td>";
        file << "</tr>";
    }

    file << "</table>";
    file << "</html>";
}

int main() {
    const int lengths[] = { 6, 80, 900 };
    const string types[] = { "random", "sorted", "reversed" };
    const int test_num = 2 * 3 * 3;
    SortStats test_results[test_num];
    int res_id = 0;

    for (int l_i = 0; l_i < 3; l_i++) { // array length
        int length = lengths[l_i];
        for (int t_i = 0; t_i < 3; t_i++) { // array type
            string type = types[t_i];
            int* a1 = new int[length];
            int* a2 = new int[length];
            generate(a1, length, type);
            for (int i = 0; i < length; i++) {
                a2[i] = a1[i];
            }

            test_results[res_id].state = type;
            bubble(a1, length, test_results[res_id]);
            res_id++;
            print(a1, length);

            test_results[res_id].state = type;
            insertion(a2, length, test_results[res_id]);
            res_id++;
            print(a2, length);
            delete[] a1;
            delete[] a2;
            cout << endl;
        }
    }

    generate_html(test_results, test_num);
}
