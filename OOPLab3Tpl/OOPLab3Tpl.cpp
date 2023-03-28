// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//
#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include <math.h>
#if !defined(CODING_VS_CODE)
#include <clocale>
#endif
// Ваші файли загловки 
//
#include "Lab3Example.h"
using namespace std;

class Romb {
	double a, d; // side and diagonal side of the romb
	unsigned int color;
public:
	Romb() : a(1.0), d(2.0), color(0) {}
	Romb(double ai) : a(ai), color(0) {}
	Romb(int ic) : a(1.0) { if (ic >= 0) color = ic; else color = 0; }
	Romb(double a, double d, int c) {
		this->a = a;
		this->d = d;
		if (c >= 0) color = c; else color = 0;
	}
	double getA() const
	{
		return a;
	}
	void setA(double a)
	{
		if (a < 0 || a > 1.e+100)
		{
			cout << " Error set  a \n";
			return;
		}
		this->a = a;
	}
	double getD() const
	{
		return d;
	}
	void setD(double d)
	{
		if (d < 0 || d > 1.e+100)
		{
			cout << " Error set  D \n";
			return;
		}
		this->d = d;
	}
	double getColor() const
	{
		return color;
	}
	void setColor(int c)
	{
		if (c < 0 || c > 10000)
		{
			cout << " Error set  color \n";
			return;
		}
		this->color = c;
	}
	double S() {
		return (d * d) / 2;
	}
	double P() {
		return 4 * a;
	}
	void printInfo()
	{
		cout << "\n a= " << a << "\n d= " << d << "\n color = " << color;
		cout << "  S= " << S() << " P = " << P() << endl;
	}

};

int main()
{
    std::cout << " Lab #3  !\n";
//  Код виконання завдань
//  Головне меню завдань
//  Функції та класи можуть знаходитись в інших файлах проекту
	Romb obj;
	obj.printInfo();
	double in_a, in_d; int in_color;
	cout << " Input side, diagonal and color of Romb: "; cin >> in_a >> in_d >> in_color;
	Romb obj1(in_a), obj2(in_d), obj3(in_color), obj4(in_a, in_d, in_color);
	obj1.printInfo();
	obj2.printInfo();
	obj3.printInfo();
	obj4.printInfo();

	cout << "Test:";
	obj.setA(-5);
	obj.printInfo();
	obj.setA(5);
	obj.printInfo();
	obj.setA(2.e100);
	obj.printInfo();

	obj.setD(-5);
	obj.printInfo();
	obj.setD(5);
	obj.printInfo();
	obj.setD(2.e100);
	obj.printInfo();

	obj.setColor(-10);
	obj.printInfo();
	obj.setColor(10);
	obj.printInfo();
	obj.setColor(10001);
	obj.printInfo();
	cout << " End testing \n";
	return 0;
}

