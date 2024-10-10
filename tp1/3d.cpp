#include "3d.h"
#include "check.h"
#include <windows.h>
#include <conio.h>

figur3d::figur3d() :type(""), a(0), b(0), c(0), h(0), V(0) { cout << "Вызван конструктор без параметров для класса figur2d\n"; };
figur3d::figur3d(const string& t, const float& a1, const float& b1, const float& c1, const float& h1, const float& V1) :type(t), a(a1), b(b1), c(c1), h(h1), V(V1) {
	cout << "Вызван конструктор с параметрами для класса figur2d\n";
}
figur3d::figur3d(const figur3d& tmp) : type(tmp.type), a(tmp.a), b(tmp.b), c(tmp.c), h(tmp.h), V(tmp.V) {
	cout << "Вызван конструктор копирования для класса figur2d\n";
}
figur3d::~figur3d() { cout << "Вызван деструктор  для класса figur2d\n"; }

void figur3d::set_type3d(string t) {
	this->type = t;
}

void figur3d::set_sizes3d(float a1, float b1, float c1, float h1) {
	float v;
	if (a1 > 0 && b1 == 0 && c1 == 0 && h1 == 0) {
		v = 3.14 * a1 * a1 * a1 * 4 / 3;
		this->set_V(v);
		this->a = a1;
		this->b = b1;
		this->c = c1;
		this->h = h1;
	}
	else if (a1 > 0 && b1 > 0 && c1 > 0 && h1 == 0) {
		v = a1 * b1 * c1;
		this->set_V(v);
		this->a = a1;
		this->b = b1;
		this->c = c1;
		this->h = h1;
	}
	else if (a1 > 0 && b1 > 0 && c1 > 0 && h1 > 0) {
		v = (a1 * b1) * h1 / 6;
		this->set_V(v);
		float d = 0.001;
		float c2 = sqrt(b1 * b1 + a1 * a1);
		if (abs(c2 - c1) < d) {
			cout << "Всё верно" << endl;
			this->a = a1;
			this->b = b1;
			this->c = c1;
			this->h = h1;
		}
		else
		{
			cout << "Обнаружена ошибка. Параметр одной из сторон был исправлен: cторона с (гипотенуза) теперь равна:" << c2 << endl;
			this->a = a1;
			this->b = b1;
			this->c = c2;
			this->h = h1;
		}
	}
	else {
		cout << "Провертье введённые параметры." << endl;
	}
}
void figur3d::set_V(float V1) {
	this->V = V1;
}

string figur3d::get_type3d() {
	return this->type;
}
float* figur3d::get_sizes3d() {
	float* a1 = new float[4];
	a1[0] = this->a;
	a1[1] = this->b;
	a1[2] = this->c;
	a1[3] = this->h;
	return a1;

}
float figur3d::get_V() {
	return this->V;
}

void figur3d::draw() {

	HWND handle = FindWindowA("ConsoleWindowClass", NULL);
	HDC hdc = GetDC(handle);
	//создаём контур
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(100, 0, 200)); //сплошная линия, толщиной 10 пикселей
	SelectObject(hdc, hPen);// указываем перо 
	//заливка
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBrush);
	if (this->type == "Шар") {
		float r = this->a;
		Ellipse(hdc, 700, 100, 700 + 2 * r, 100 + 2 * r);		
	}
	else if (this->type == "Параллелепипед") {
		Rectangle(hdc, 700, 100, 700 + b, 100 + a);
	}
	else if (this->type == "Прямоугольная пирамида") {
		MoveToEx(hdc, 700, 100, NULL);
		LineTo(hdc, 700, 100 + h);
		LineTo(hdc, 700 + b, 100 + h);
		LineTo(hdc, 700, 100);
	}
}
void figur3d::print() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Тип: " << this->type << endl;
	float* p = new float[4];
	p = this->get_sizes3d();
	if (this->type == "Шар")
		cout << "Радиус: " << p[0] << endl;
	if (this->type == "Параллелепипед") {
		cout << "Ширина: " << p[0] << endl;
		cout << "Длина: " << p[1] << endl;
		cout << "Высота: " << p[2] << endl;
	}
	if (this->type == "Прямоугольная пирамида") {
		cout << "Катет 1: " << p[0] << endl;
		cout << "Катет 2: " << p[1] << endl;
		cout << "Гипотенуза: " << p[2] << endl;
		cout << "Высота: " << p[4] << endl;
	}
	cout << "Объём: " << this->V << endl;
	this->draw();
}
int figur3d::edit_inf() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string type1;
	float a1, b1, c1, h1;

	cout << "Выберите информацию для изменения:" << endl;
	cout << "1. Тип и размеры" << endl;
	cout << "2. Размеры" << endl;
	cout << "0. Выход" << endl;
	char c;
	while(1){
		switch (c = _getch()) {
		case '1':
			cout << "Введите новый тип (помните, что вы можете создать только три типа объёмных фигур: шар, прараллелепипед и прямоугольную пирамиду): ";
			getline(cin, type1);
			if (type1 == "Шар") {
				set_type3d(type1);
				cout << "Введите радиус: " << endl;
				a1 = check();
				set_sizes3d(a1, 0, 0, 0);
				cout << "Данные успешно изменены" << endl;
			}
			else if (type1 == "Параллелепипед") {
				set_type3d(type1);
				cout << "Введите ширину: " << endl;
				a1 = check();
				cout << "Введите длину: " << endl;
				b1 = check();
				cout << "Введите высоту: " << endl;
				c1 = check();
				set_sizes3d(a1, b1, c1, 0);
				cout << "Данные успешно изменены" << endl;
			}
			else if (type1 == "Прямоугольная пирамида") {
				set_type3d(type1);
				cout << "Введите катет 1: " << endl;
				a1 = check();
				cout << "Введите катет 2: " << endl;
				b1 = check();
				cout << "Введите гипотенузу: " << endl;
				c1 = check();
				cout << "Введите высоту: " << endl;
				h1 = check();
				set_sizes3d(a1, b1, c1, h1);
				cout << "Данные успешно изменены" << endl;
			}
			else {
				cout << "Такого типа не существует." << endl;
			}
			break;
		case '2':
			if (this->type == "Шар") {
				cout << "Введите радиус: " << endl;
				a1 = check();
				set_sizes3d(a1, 0, 0, 0);
				cout << "Данные успешно изменены" << endl;
			}
			else if (this->type == "Параллелепипед") {
				cout << "Введите ширину: " << endl;
				a1 = check();
				cout << "Введите длину: " << endl;
				b1 = check();
				cout << "Введите высоту: " << endl;
				c1 = check();
				set_sizes3d(a1, b1, c1, 0);
				cout << "Данные успешно изменены" << endl;
			}
			else if (this->type == "Прямоугольная пирамида") {
				cout << "Введите катет 1: " << endl;
				a1 = check();
				cout << "Введите катет 2: " << endl;
				b1 = check();
				cout << "Введите гипотенузу: " << endl;
				c1 = check();
				cout << "Введите высоту: " << endl;
				h1 = check();
				set_sizes3d(a1, b1, c1, h1);
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