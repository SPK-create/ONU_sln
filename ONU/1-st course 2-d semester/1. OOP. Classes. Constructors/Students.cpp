#include <iostream>
using namespace std;


class Student {
private:
    string name, surname, birth_date;
    float average_mark;


public:
    Student() : name("N"), surname("N"), birth_date("N"), average_mark(0) {}


    Student(string name, string surname, string date, float mark) {
        this->name = name;
        this->surname = surname;
        birth_date = date;
        average_mark = mark;
    }


    void print() {
        cout << name << " " << surname << " " << birth_date << " " << average_mark;
        cout << endl;
    }


    /*void renew_inforrmation(){
        cout << "Fill the new information" << endl;
        cin >> name >> surname >> birth_date >> average_mark;
        cout << endl;
        setName(name);
        setSurname(surname);
        setBirth_date(birth_date);
        setAverage_mark(average_mark);
        cout << "Information of this student would be:" << endl;
        cout << name << " " << surname << " " << birth_date << " " << average_mark << endl;
    }*/


    string getName() {
        return name;
    }
    string getSurname() {
        return surname;
    }
    string getBirth_date() {
        return birth_date;
    }
    float getAverage_mark() {
        return average_mark;
    }


    void setName(string name) {
        this->name = name;
    }
    void setSurname(string surname) {
        this->surname = surname;
    }
    void setBirth_date(string date) {
        birth_date = date;
    }
    void setAverage_mark(float mark) {
        average_mark = mark;
    }
};


int main() {
    Student s1, s2("Gregor", "Jolit", "20.03.2000", 78.9), s3("Mathew", "Henesy", "01.01.2001", 50.3);
    cout << "Student 1: "; s1.print();
    cout << "Student 2: "; s2.print();
    cout << "Student 3: "; s3.print();
    //s1.renew_inforrmation();
    string name, surname, date;
    float mark;
    cout << "Fill the information for 1-st student:";
    cin >> name >> surname >> date >> mark;
    s1.setName(name);
    s1.setSurname(surname);
    s1.setBirth_date(date);
    s1.setAverage_mark(mark);
    cout << "Actual information is:" << endl;
    cout << "Student 1: "; s1.print();
    cout << "Student 2: "; s2.print();
    cout << "Student 3: "; s3.print();
    return 0;
}
