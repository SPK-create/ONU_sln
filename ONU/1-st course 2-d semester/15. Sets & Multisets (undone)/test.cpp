#include <iostream>
#include<set>
using namespace std;
class Point {
public:
	int x, y;
	Point(int x = 0, int y = 0) {
		this->x = x; this->y = y;
	}
	bool operator< (const Point a)const {
		return x + y < a.x + a.y;
	}

};

set<Point> s;
set<Point>::iterator iter;
int main(void) {
	s.insert(Point(3, 0)); s.insert(Point(3, 5));
	s.insert(Point(2, 8)); s.insert(Point(6, 1));
	s.insert(Point(6, 8)); s.insert(Point(2, 1));
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << (*iter).x << (*iter).y << endl;
	return 0;

}
