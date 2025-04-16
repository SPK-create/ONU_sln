#include <iostream>
using namespace std;

class Point // C++
{
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}; // Конструктор
    Point operator +(int& v) {
        return Point(x + v, y + v);
    }; // Перегрузка оператора +: возвращает сумму точки и целого числа v
    Point operator +(Point& p) {
        return Point(x + p.x, y + p.y);
    }; // Перегрузка оператора +: возвращает сумму двух точек
    int getX() {
        return x;
    } // Вернуть x координату
    int getY() {
        return y;
    } // Вернуть y координату
};

int main() {
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    Point x(a, b), y(c, d);
    cout << x.getX() << " " << x.getY() << " " << y.getX() << " " << y.getY() << endl;
    cout << ((x + y)+n).getX() << " " << ((x + y)+n).getY();
    return 0;
}
