#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point {
	double x, y;
public:
	Point();
	Point(double x_value, double y_value);
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point p);
};

Point::Point(){}

Point::Point(double x_value, double y_value) {
	x = x_value;
	y = y_value;
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

void Point::setX(double x_value) {
	x = x_value;
}

void Point::setY(double y_value) {
	y = y_value;
}

double Point::distanceToAnotherPoint(Point p) {
	return sqrt((pow(x - p.getX(), 2)) + (pow(y - p.getY(), 2)));
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		double x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point p1(x1,y1);
		Point p2(x2, y2);
		cout << "Distance of Point(" << fixed << setprecision(2) << p1.getX() << "," << p1.getY() << ") to Point(" << p2.getX() << "," << p2.getY() << ") is " << p1.distanceToAnotherPoint(p2) << endl;
	}
	return 0;
}


/*
下面是一个平面上的点的类定义，请在类外实现它的所有方法，并生成点测试它。


输入
测试数据的组数 t
第一组测试数据点p1的x坐标   第一组测试数据点p1的y坐标  第一组测试数据点p2的x坐标   第一组测试数据点p2的y坐标
..........
输出
输出p1到p2的距离
在C++中，输出指定精度的参考代码如下：

#include <iostream>
#include <iomanip> //必须包含这个头文件
using namespace std;
void main( )
{ double a =3.141596;
  cout<<fixed<<setprecision(3)<<a<<endl;  //输出小数点后3位
}


样例输入
2
1 2 3 4
-1 0.5 -2 5
样例输出
Distance of Point(1.00,2.00) to Point(3.00,4.00) is 2.83
Distance of Point(-1.00,0.50) to Point(-2.00,5.00) is 4.61
*/