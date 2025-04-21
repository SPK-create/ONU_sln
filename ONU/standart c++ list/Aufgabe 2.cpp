#include <iostream>
#include <list>
using namespace std;

class Student {
private:
	string surname;
	int course, grade_mathanal, grade_algebra;
public:
	Student() : surname(""), course(0), grade_mathanal(0), grade_algebra(0) {};
	Student(string surname, int course, int grade1, int grade2) : surname(surname), course(course), grade_mathanal(grade1), grade_algebra(grade2) {};

	string getSurname() {
		return surname;
	}
	int getCourse() {
		return course;
	}
	int getGradeMathanal() {
		return grade_mathanal;
	}
	int getGradeAlgebra() {
		return grade_algebra;
	}
	void setCourse(const int &c) {
		course = c;
	}
};

void printList(list<Student> &mylist);
bool compare_surname(Student &first_student, Student &second_student);
bool compare_course(Student& first_student, Student& second_student);
void nextCourse(list<Student>& mylist);
bool failedMathanal(Student& s);
bool failedAlgebra(Student& s);

int main() {

	list<Student> list_of_students;

	Student s1("Gerakl", 1, 72, 84), s2("Kirsch", 2, 93, 87), s3("Muha", 1, 60, 54), s4("Zevs", 1, 67, 79), s5("Greg", 2, 48, 52);

	list_of_students.push_back(s1);
	list_of_students.push_back(s2);
	list_of_students.push_back(s3);
	list_of_students.push_back(s4);
	list_of_students.push_back(s5);

	printList(list_of_students);

	list_of_students.sort(compare_surname);
	cout << "Sorted list by surname:" << endl;
	printList(list_of_students);

	list_of_students.sort(compare_course);
	cout << "Sorted list by course:" << endl;
	printList(list_of_students);

	nextCourse(list_of_students);
	cout << "New list (with next course for those, who has more than 60 grade of mathanal and algebra):" << endl;
	printList(list_of_students);

	list_of_students.remove_if(failedAlgebra);
	list_of_students.remove_if(failedMathanal);
	cout << "List without excluded students (that have less 60 of mathanal or algebra):" << endl;
	printList(list_of_students);

	return 0;
}

void printList(list<Student> &mylist) {
	for (list<Student>::iterator it = mylist.begin(); it != mylist.end(); it++) {
		cout << it->getSurname() << " " << it->getCourse() << " " << it->getGradeMathanal() << " " << it->getGradeAlgebra() << endl;
	}
	cout << endl;
}

bool compare_surname(Student &first_student, Student &second_student) {
	return first_student.getSurname() < second_student.getSurname();
}

bool compare_course(Student& first_student, Student& second_student) {
	return first_student.getCourse() < second_student.getCourse();
}

void nextCourse(list<Student>& mylist) {
	for (list<Student>::iterator i = mylist.begin(); i != mylist.end(); i++) {
		if ((i->getGradeAlgebra() >= 60) and (i->getGradeMathanal() >= 60)) {
			i->setCourse(i->getCourse() + 1);
		}
	}
}

bool failedMathanal(Student& s) {
	return s.getGradeMathanal() < 60;
}

bool failedAlgebra(Student& s) {
	return s.getGradeAlgebra() < 60;
}