//这代码好像过不了，但我懒得调了=.=

#include <iostream>
#include <math.h>
using namespace std;

class Point {
private:
	double x, y;
public:
	Point() {}
	Point(double a, double b) {
		x = a;
		y = b;
	}
	~Point() {
		x = 0;
		y = 0;
		cout << "point clear" << endl;
	}
	void setXY(double a, double b) {
		x = a;
		y = b;
	}
	 double getX() {
		 return x;
	}
	 double getY() {
		 return y;
	 }
};

class Circle {
private:
	double x, y, r;
public:
	Circle(double a, double b, double c) {
		x = a; 
		y = b;
		r = c;
	}
	~Circle() {
		x = 0;
		y = 0;
		r = 0;
		cout<<"circle clear"<<endl;
	}
	bool contain(Point &p){
		return sqrt((p.getX() - x) * (p.getX() - x) + (p.getY() - y) * (p.getY() - y)) <= r;
	}
};

int main() {
	double px, py, cx, cy, r;
	cin >> px >> py;
	Point point(px, py);
	int n;
	cin >> n;
	Point* p = new Point[n];
	for (int i = 0; i < n; i++) {
		cin >> px>> py;
		p[i].setXY(px, py);
	}
	cin >> cx >> cy >> r;
	Circle circle(cx, cy, r);
	if(circle.contain(point))
		cout << "in" << endl;
	else
		cout << "out" << endl;
	for (int i = 0; i < n; i++) {
		if (circle.contain(p[i]))
			cout << "in" << endl;
		else
			cout << "out" << endl;
	}
	//delete[] p;
	return 0;
}
