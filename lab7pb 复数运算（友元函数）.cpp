#include <iostream>
using namespace std;

class Complex {
public:
	Complex() {};
	Complex(double r, double i) {
		real = r;
		imag = i;
	}
	friend Complex addCom(Complex &c1, Complex &c2);
	friend Complex minusCom(Complex& c1, Complex& c2);
	friend void outCom(Complex c);

private:
	double real;
	double imag;
};

Complex addCom(Complex& c1, Complex& c2) {
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.imag = c1.imag + c2.imag;
	return temp;
}

Complex minusCom(Complex& c1, Complex& c2) {
	Complex temp;
	temp.real = c1.real - c2.real;
	temp.imag = c1.imag - c2.imag;
	return temp;
}

void outCom(Complex c) {
	cout << '(' << c.real << ',' << c.imag << ')' << endl;
}

int main() {
	double r, i;
	int t;
	char sign;
	cin >> r >> i >> t;
	Complex c1(r, i);
	while (t--) {
		cin >> sign >> r >> i;
		Complex c2(r, i);
		if (sign == '+') {
			outCom(addCom(c1, c2));
			c1 = addCom(c1, c2);
		}
		if (sign == '-') {
			outCom(minusCom(c1, c2));
			c1 = minusCom(c1, c2);
		}
	}
	return 0;
}

/*
题目描述
复数类的声明如下：

要求如下：
1.     实现复数类和友元函数addCom和outCom。


2.   参考addCom函数为复数类增加一个友元函数minusCom，用于实现两个复数的减法
3.     在main函数中，通过友元函数，实现复数的加减法和复数的输出。


输入
第1行：第1个复数的实部和虚部
第2行：需进行运算的次数，注意：是连续运算。具体结果可参考样例
  第3行开始，每行输入运算类型，以及参与运算的复数的实部与虚部。“+”表示复数相加，“-”表示复数相减。

输出
 每行输出复数运算后的结果，复数输出格式为“(实部,虚部)”。

样例输入
10 10
3
+ 20 10
- 15 5
+ 5 25
样例输出
(30,20)
(15,15)
(20,40)
*/