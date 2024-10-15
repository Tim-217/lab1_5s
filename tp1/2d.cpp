#include "2d.h"
#include "check.h"
#include <conio.h>
#include <windows.h>

figur2d::figur2d() :type(""), a(0), b(0), c(0), S(0) { cout << "Вызван конструктор класса figur2d\n"; };
figur2d::figur2d(const string& t, const float& a1, const float& b1, const float& c1, const float& S1) :type(t), a(a1), b(b1), c(c1), S(S1){ 
	cout << "Вызван конструктор c параметрами класса figur2d\n"; }
figur2d::figur2d(const figur2d& tmp) : type(tmp.type), a(tmp.a), b(tmp.b), c(tmp.c), S(tmp.S) { 
	cout << "Вызван конструктор копирования класса figur2d\n"; }
figur2d::~figur2d() { cout << "Вызван деструктор класса figur2d\n"; }

void figur2d::set_type2d(string t) {
	this->type = t;
}

void figur2d::set_sizes2d(float a1, float b1, float c1) {
	float s;
	if (a1 > 0 && b1 == 0 && c1 == 0) { 
		this->type = "Круг";
		s = 3.14 * a1 * a1;
		this->set_S(s);
		this->a = a1;
		this->b = b1;
		this->c = c1;
	}	
	else if (a1 > 0 && b1 > 0 && c1 == 0) {  
		this->type = "Прямоугольник";
		s = a1 * b1;
		this->set_S(s);
		this->a = a1;
		this->b = b1;
		this->c = c1;
	}
	else if (a1 > 0 && b1 > 0 && c1 > 0) { 
		this->type = "Прямоугольный треугольник";
		s = a * b / 2;
		this->set_S(s);
		float d = 0.001;
		float c2 = sqrt(b1 * b1 + a1 * a1);
		if (abs(c2 - c1) < d) {
			this->a = a1;
			this->b = b1;
			this->c = c1;
		}
		else
		{
			cout << "Обнаружена ошибка. Параметр одной из сторон был исправлен: cторона с (гипотенуза) теперь равна:" << c2 << endl;
			this->a = a1;
			this->b = b1;
			this->c = c2;
		}
	}		
	else {
		cout << "Провертье введённые параметры." << endl;
	}
}
void figur2d::set_S(float S1) {
	this->S = S1;
}

string figur2d::get_type2d() {
	return this->type;
}
float* figur2d::get_sizes2d() {
	float* a1 = new float[3];
	a1[0] = this->a;
	a1[1] = this->b;
	a1[2] = this->c;

	return a1;

}
float figur2d::get_S() {
	return this->S;
}

void figur2d::draw() {
	
	HWND handle = FindWindowA("ConsoleWindowClass", NULL);
	HDC hdc = GetDC(handle);
	//создаём контур
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(100, 200, 0)); //сплошная линия, толщиной 10 пикселей
	SelectObject(hdc, hPen);// указываем перо 
	//заливка
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBrush);
	if (this->type == "Круг") {
		float r = this->a;
		Ellipse(hdc, 650, 300, 650 + 2 * r, 300 + 2 * r);
	}
	else if(this->type == "Прямоугольник") {
		Rectangle(hdc, 650, 300, 650 + b, 300 + a);
	}
	else if (this->type == "Прямоугольный треугольник") {
		MoveToEx(hdc, 650, 300, NULL);
		LineTo(hdc, 650, 300 + a);
		LineTo(hdc, 650 + b, 300 + a);
		LineTo(hdc, 650, 300);
	}
}
void figur2d::print() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Тип: " << this->type << endl;
	float* p = new float[3];
	p = this->get_sizes2d();
	if (this->type == "Круг")
		cout << "Радиус: " << p[0] << endl;
	if (this->type == "Прямоугольник") {
		cout << "Ширина: " << p[0] << endl;
		cout << "Длина: " << p[1] << endl;
	}
	if (this->type == "Прямоугольный треугольник") {
		cout << "Катет 1: " << p[0] << endl;
		cout << "Катет 2: " << p[1] << endl;
		cout << "Гипотенуза: " << p[2] << endl;
	}
	cout << "Площадь: " << this->S << endl;
}
int figur2d::edit_inf() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string type1;
	float a1, b1, c1;
	cout << "Выберите информацию для изменения:" << endl;
	cout << "1. Тип и размеры" << endl;
	cout << "2. Размеры" << endl;
	cout << "0. Выход из редактированя" << endl;
	char c;
	while (1) {
		switch (c = _getch()) {
		case '1':
			cout << "Помните, что вы можете создать только три типа фигур: круг, прямоугольник и прямоугольный треугольник" << endl;
			cout << "Введите новый тип: ";
			getline(cin, type1);
			if (type1 == "Круг") {
				set_type2d(type1);
				cout << "Введите радиус: ";
				a1 = check();
				set_sizes2d(a1, 0, 0);
				cout << "Данные успешно изменены" << endl;
			}
			else if (type1 == "Прямоугольник") {
				set_type2d(type1);
				cout << "Введите ширину: ";
				a1 = check();
				cout << "Введите длину: ";
				b1 = check();
				set_sizes2d(a1, b1, 0);
				cout << "Данные успешно изменены" << endl;
			}
			else if (type1 == "Прямоугольный треугольник") {
				set_type2d(type1);
				cout << "Введите катет 1: ";
				a1 = check();
				cout << "Введите катет 2: ";
				b1 = check();
				cout << "Введите гипотенузу: ";
				c1 = check();
				set_sizes2d(a1, b1, c1);
				cout << "Данные успешно изменены" << endl;
			}
			else {
				cout << "Такого типа не существует." << endl;
			}
			break;
		case '2':
			if (this->type == "Круг") {
				cout << "Введите радиус: ";
				a1 = check();
				set_sizes2d(a1, 0, 0);
				cout << "Данные успешно изменены" << endl;
			}
			else if (this->type == "Прямоугольник") {
				cout << "Введите ширину: ";
				a1 = check();
				cout << "Введите длину: ";
				b1 = check();
				set_sizes2d(a1, b1, 0);
				cout << "Данные успешно изменены" << endl;
			}
			else if (this->type == "Прямоугольный треугольник") {
				cout << "Введите катет 1: ";
				a1 = check();
				cout << "Введите катет 2: ";
				b1 = check();
				cout << "Введите гипотенузу: " << endl;
				c1 = check();
				set_sizes2d(a1, b1, c1);
				cout << "Данные успешно изменены" << endl;
			}
			else {
				cout << "Такого типа не существует." << endl;
			}
			break;
		case '0':
			cout << "Выход из редактирования" << endl;
			return 0;
		default:
			cout << "Такой команды не существует." << endl;
			break;
		}
	}
}
void figur2d::load_from_file(istream& in) {
	in >> a >> b >> c;
	this->set_sizes2d(a, b, c);
}
void figur2d::save_to_file(ostream& out)  {
	out << "2d\n" << a << ' ' << b << ' ' << c << '\n';
}