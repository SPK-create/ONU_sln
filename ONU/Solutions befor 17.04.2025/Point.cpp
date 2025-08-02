#include <iostream>
using namespace std;

class Point // C++
{
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}; // �����������
    Point operator +(int& v) {
        return Point(x + v, y + v);
    }; // ���������� ��������� +: ���������� ����� ����� � ������ ����� v
    Point operator +(Point& p) {
        return Point(x + p.x, y + p.y);
    }; // ���������� ��������� +: ���������� ����� ���� �����
    int getX() {
        return x;
    } // ������� x ����������
    int getY() {
        return y;
    } // ������� y ����������
};

int main() {
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    Point x(a, b), y(c, d);
    cout << x.getX() << " " << x.getY() << " " << y.getX() << " " << y.getY() << endl;
    cout << ((x + y)+n).getX() << " " << ((x + y)+n).getY();
    return 0;
}
