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
using namespace std;

/*class Romb {
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
void task1() 
{
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
	cin.get();
}*/

/*
Створити тип даних - клас вектор, який має поля x, y та z типу float і змінну стану. У
класі визначити
o конструктор без параметрів(інінціалізує поля в нуль);
o конструктор з одним параметром типу float (інінціалізує поля x, y та z
значенням параметру);
o конструктор з одним параметром вказівник на тип (інінціалізує поля x, y та z
значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити
код помилки);
o деструктор із виведенням інформації про стан вектора;
o визначити функцію, яка присвоює полю x, y або z деяке значення (параметр за
замовчуванням);
Об’єктно – орієнтоване програмування мовою С++ Лазорик В.В.
16
o функцію яка одержує деякий елемент з полів x, y та z;
o конструктор копій та операцію присвоєння; // !!!
o визначити функції друку, додавання, віднімання, векторний добуток які
здійснюють ці арифметичні операції з даними цього класу;
o функцію ділення на ціле типу short(при діленні на 0 змінити стан, а ділення не
виконувати);
o визначити функції порівняння: більше, менше або рівно, які повертають true
або false.
У змінну стани встановлювати код помилки, діленні на 0, при передачі NULL (nulptr) в
конструкторі із вказівником. Передбачити можливість підрахунку числа об'єктів даного типу.
Написати програму тестування всіх можливостей цього класу.
*/
const int OK = 0;
const int BAD_INIT = 1;
const int BAD_DIV = 2;

class Vec2
{
	float  x, y, z;
	int state;
	static int count;
public:
	Vec2() : x(0), y(0) , z(0) {
		state = OK; count++;
	}   // o конструктор без параметрів(інінціалізує поля в нуль);

	Vec2(float iv) : x(iv), y(iv), z(iv) {
		state = OK; count++;
	}	// o конструктор з одним параметром типу float(інінціалізує поля x, y та z значенням параметру);

	Vec2(float ix, float iy, float iz);
	Vec2(float ix, float iy);
	Vec2(float* v) {
		if (v == nullptr) {
			state = BAD_INIT; x = 0; y = 0; z = 0;
		}
		else {
			x = v[0]; y = v[1]; z = v[2];
			state = OK;
		}
		count++;
	}
	~Vec2() {
		count--;
		cout << " state Vec: " << state;
		cout << " Vec delete \n";
	}
	Vec2(const Vec2&);
	Vec2 Add(Vec2& d);
	Vec2 Sub(Vec2& d);
	Vec2 Mul(float d);
	Vec2 Div(float d);
	void Input();   //  !!! Без первантаження операцій    
	void Output();  //  !!! Без первантаження операцій
	bool CompLessAll(Vec2& s);
	static int getCount() {
		if (count <= 0) cout << " Немає об'єктів Vec2 ";
		return count;
	}
	int getState() { return state; }

}; //кінець класу

	int Vec2::count = 0; 
	Vec2::Vec2(float ix, float iy, float iz) {
		x = ix; y = iy; z = iz;
		state = OK;
		count++;
	};
	Vec2::Vec2(const Vec2& s) {
		//if (this == &s) return; //  // the expression is used in the old standard
		x = s.x; y = s.y; z = s.z; state = OK;
		count++;
	};
	// Vec2::Vec2(float* v) {}
	void Vec2::Input() {
		cout << " Input  x y z";
		cin >> x >> y >> z;
	}
	void Vec2::Output() {
		cout << " x =" << x << " y = " << y << " z = " << z << " state  " << state << endl;
	}

	Vec2 Vec2::Add(Vec2& s) {
		Vec2 tmp;
		tmp.x = x + s.x;
		tmp.y = y + s.y;
		tmp.z = z + s.z;
		return tmp;
	}

	Vec2 Vec2::Sub(Vec2& s) {
		Vec2 tmp;
		tmp.x = x - s.x;
		tmp.y = y - s.y;
		tmp.z = z - s.z;
		return tmp;
	}
	Vec2 Vec2::Div(float d) {
		Vec2 tmp;
		if (fabs(d) < 1.e-25) {
			tmp.state = BAD_DIV;
			cout << " Error div \n";
			return *this;
		}
		tmp.x = x / d;
		tmp.y = y / d;
		tmp.z = z / d;
		return tmp;
	}
	Vec2 Vec2::Mul(float d) {
		Vec2 tmp(*this);
		tmp.x = x * d;
		tmp.y = y * d;
		tmp.z = z * d;
		return tmp;
	}

	bool Vec2::CompLessAll(Vec2& s) {

		if (x < s.x && y < s.y && z < s.z) return true;
		return false;
	}

	//Teстування
	void mainExample3()
	{
		setlocale(LC_CTYPE, "ukr");
		cout << "Тестування створенного класу \n";
		cout << "Тестування конструкторiв \n";
		cout << "Testing create class  \n";
		cout << "Testing crot's  \n";
		Vec2 ObjCDef;
		ObjCDef.Output();
		Vec2 ObjP1(10.0);
		ObjP1.Output();
		float  a = 1.0, b = 2.0;
		Vec2  ObjP2(a, b);
		ObjP2.Output();
		Vec2 ObjCopy(ObjP2);
		float* v = nullptr, v2[] = { 1.2, 3.3 };
		Vec2  ObjP3(v2);
		if (ObjP3.getState() != OK) cout << " ObjP3  x= 0  y= 0  \n";
		Vec2  ObjP4(v2);
		if (ObjP4.getState() != OK) cout << " ObjP4 x= 0  y= 0  \n";
		cout << " Кiлькiсть створених об'єктiв Vec2 " << Vec2::getCount() << endl;
		cout << "Тестування введення \n";
		ObjCDef.Input();
		cout << "Тестування функцiй \n";
		ObjCDef = ObjCDef.Add(ObjP2);
		ObjCDef.Output();
		cout << " \n Кiлькiсть створених об'єктiв Vec2 до Sub " << Vec2::getCount() << endl;
		ObjCDef = ObjCDef.Sub(ObjP2);
		cout << " \n Кiлькiсть створених об'єктiв Vec2 пiсля Sub " << Vec2::getCount() << endl;

		cout << "Testing input \n";
		ObjCDef.Input();
		cout << "Testing gunction \n";
		ObjCDef = ObjCDef.Add(ObjP2);
		ObjCDef.Output();
		cout << " \n Counts create objects Vec2 before  Sub " << Vec2::getCount() << endl;
		ObjCDef = ObjCDef.Sub(ObjP2);
		cout << " \n  Counts create objects Vec2 after Sub  " << Vec2::getCount() << endl;


		ObjCDef.Output();
		ObjCDef = ObjCDef.Mul(5);
		ObjCDef.Output();
		ObjCDef = ObjCDef.Div(1.3);
		if (ObjCDef.getState() == BAD_DIV) cout << "BAD_DIV \n";
		ObjCDef.Output();

		ObjCDef = ObjCDef.Div(0.0);
		if (ObjCDef.getState() == BAD_DIV) cout << "BAD_DIV \n";
		ObjCDef.Output();
		cout << "ObjCopy state " << ObjCopy.getState() << endl;
		if (ObjCopy.CompLessAll(ObjCDef))  cout << "ObjCopy less ObjDef  " << endl;


		cout << "Завершення  тестування  \n";

		cout << "Completion of testing  \n";

		return;
	}


int main()
{
	//  Код виконання завдань
	//  Головне меню завдань
	char ch = '5';
	do {
		system("cls");
		std::cout << " Lab #3 \n";
		cout << "Main menu: \n1)Task 1 \n2)Task 2 \n3)Task 3 \n 4) Exit\n\n";
		cout << "Choose the task: ";
		ch = cin.get();

		cin.get();
		/*
		switch (ch) {
		case '1': task1();   break;
		case '2': task2();   break;
		case '3': task2();   break;
		case '4': return 0;
		}*/
		cout << "\nPress any key and enter\n";
		ch = cin.get();
	} while (ch != '3');
	return 0;
	//  Функції та класи можуть знаходитись в інших файлах проекту
}

