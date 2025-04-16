#include <iostream>
using namespace std;

class Triangle {
private:
	int x1, y1, x2, y2, x3, y3;
	long double AB, BC, AC;
public:
	Triangle (): x1(0), y1(0), x2(0), y2(0), x3(0), y3(0), AB(0), BC(0), AC(0) {}
	Triangle (int x1, int y1, int x2, int y2, int x3, int y3): x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
		setAB();
		setBC();
		setAC();
	}

	void Out1() {
		cout << AB << " " << BC << " " << AC;
	}
	void Out() {
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
	}
	//Нахождение длин сторон треугольника ABC
	void setAB() {
		AB = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	}
	void setBC() {
		BC = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
	}
	void setAC() {
		AC = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1));
	}

	double perimeter() {
		return (AB + BC + AC);
	}
	double area() {
		double poly_perimeter = double(perimeter() / 2);
		return sqrt(poly_perimeter * (poly_perimeter - AB) * (poly_perimeter - BC) * (poly_perimeter - AC));
	}
	double inscribedRadius() { //r = S/p, p = P/2 - радиус впис.
		double poly_perimeter = double(perimeter() / 2);
		return double(area() / poly_perimeter);
	}
	double describedRadius() { //R = abc/4S - радиус опис. 
		return (AB * BC * AC) / (4 * area());
	}

	bool equilateral() { // - равносторонний треуг. ?
		return AB == BC and AB == AC;
	}
	bool versatile() { // - разносторонний треуг. ?
		if (AB != BC and AB != AC and BC != AC) {
			return 1;
		}
		else { return 0; }
	}
	bool isosceles() { // - равнобедренный треуг. ?
		if ((AB == BC and AB != AC) or (BC == AC and BC != AB) or (AB == AC and AB != BC)) {
			return 1;
		}
		else { return 0; }
	}
	bool rectangular() { // - прямоугольный треуг. ?
		double max_side, side1, side2;
		if (AB > BC and AB > AC) {
			max_side = AB;
			side1 = BC;
			side2 = AC;
		}
		else if (BC > AB and BC > AC) {
			max_side = BC;
			side1 = AB;
			side2 = AC;
		}
		else { max_side = AC; side1 = AB; side2 = BC; }

		if (max_side == sqrt((side1 * side1) + (side2 * side2))) {
			return 1;
		} else { return 0; }
	}
	//Teorema Cos: a^2 = b^2 + c^2 - 2abCosA => CosA = (b^2 + c^2 - a^2)/2ab
	bool acute_angled() {
		long double CosAB = ((BC * BC) + (AC * AC) - (AB * AB)) / (2 * BC * AC); //напротив АВ
		long double CosAC = ((AB * AB) + (BC * BC) - (AC * AC)) / (2 * AB * BC); //напротив АС
		long double CosBC = ((AB * AB) + (AC * AC) - (BC * BC)) / (2 * AB * AC); //напротив ВС
		if (CosAB > 0 and CosAC > 0 and CosBC > 0) {
			return 1;
		}
		else { return 0; }
	}
	bool obtuse() {
		double eps = 1e-9;
		long double CosAB = ((BC * BC) + (AC * AC) - (AB * AB)) / (2 * BC * AC); //напротив АВ
		long double CosAC = ((AB * AB) + (BC * BC) - (AC * AC)) / (2 * AB * BC); //напротив АС
		long double CosBC = ((AB * AB) + (AC * AC) - (BC * BC)) / (2 * AB * AC); //напротив ВС
		if (CosAB < -eps or CosAC < -eps or CosBC < -eps) {
			return 1;
		}
		else { return 0; }
	}
};

int main() {
	Triangle t1(0, 0, 0, 1, 1, 0);
	cout << t1.rectangular();
	
}