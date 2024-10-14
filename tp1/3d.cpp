#include "3d.h"
#include "check.h"
#include <windows.h>
#include <conio.h>

figur3d::figur3d() :type(""), a(0), b(0), c(0), h(0), V(0) {};
figur3d::figur3d(const string& t, const float& a1, const float& b1, const float& c1, const float& h1, const float& V1) :type(t), a(a1), b(b1), c(c1), h(h1), V(V1) {}
figur3d::figur3d(const figur3d& tmp) : type(tmp.type), a(tmp.a), b(tmp.b), c(tmp.c), h(tmp.h), V(tmp.V) {}
figur3d::~figur3d() {}

void figur3d::set_type3d(string t) {
	this->type = t;
}

void figur3d::set_sizes3d(float a1, float b1, float c1, float h1) {
	float v;
	if (a1 > 0 && b1 == 0 && c1 == 0 && h1 == 0) {
		this->type = "���";
		v = 3.14 * a1 * a1 * a1 * 4 / 3;
		this->set_V(v);
		this->a = a1;
		this->b = b1;
		this->c = c1;
		this->h = h1;
	}
	else if (a1 > 0 && b1 > 0 && c1 > 0 && h1 == 0) {
		this->type = "��������������";
		v = a1 * b1 * c1;
		this->set_V(v);
		this->a = a1;
		this->b = b1;
		this->c = c1;
		this->h = h1;
	}
	else if (a1 > 0 && b1 > 0 && c1 > 0 && h1 > 0) {
		this->type = "������������� ��������";
		v = a1 * b1 * h1 / 6;
		this->set_V(v);
		float d = 0.001;
		float c2 = sqrt(b1 * b1 + a1 * a1);
		if (abs(c2 - c1) < d) {
			this->a = a1;
			this->b = b1;
			this->c = c1;
			this->h = h1;
		}
		else
		{
			cout << "���������� ������. �������� ����� �� ������ ��� ���������: c������ � (����������) ������ �����:" << c2 << endl;
			this->a = a1;
			this->b = b1;
			this->c = c2;
			this->h = h1;
		}
	}
	else {
		cout << "��������� �������� ���������." << endl;
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
	//������ ������
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(100, 0, 200)); //�������� �����, �������� 10 ��������
	SelectObject(hdc, hPen);// ��������� ���� 
	//�������
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBrush);
	if (this->type == "���") {
		float r = this->a;
		Ellipse(hdc, 650, 300, 650 + 2 * r, 300 + 2 * r);
	}
	else if (this->type == "��������������") {
		Rectangle(hdc, 650, 300, 650 + b, 300 + a);
	}
	else if (this->type == "������������� ��������") {
		MoveToEx(hdc, 650, 300, NULL);
		LineTo(hdc, 650, 300 + h);
		LineTo(hdc, 650 + b, 300 + h);
		LineTo(hdc, 650, 300);
	}
}
void figur3d::print() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "���: " << this->type << endl;
	float* p = new float[4];
	p = this->get_sizes3d();
	if (this->type == "���")
		cout << "������: " << p[0] << endl;
	if (this->type == "��������������") {
		cout << "������: " << p[0] << endl;
		cout << "�����: " << p[1] << endl;
		cout << "������: " << p[2] << endl;
	}
	if (this->type == "������������� ��������") {
		cout << "����� 1: " << p[0] << endl;
		cout << "����� 2: " << p[1] << endl;
		cout << "����������: " << p[2] << endl;
		cout << "������: " << p[4] << endl;
	}
	cout << "�����: " << this->V << endl;
}
int figur3d::edit_inf() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string type1;
	float a1, b1, c1, h1;
	cout << "�������� ���������� ��� ���������:" << endl;
	cout << "1. ��� � �������" << endl;
	cout << "2. �������" << endl;
	cout << "0. �����" << endl;
	char c;
	while(1){
		switch (c = _getch()) {
		case '1':
			cout << "�������, ��� �� ������ ������� ������ ��� ���� �������� �����: ���, ��������������� � ������������� ��������" << endl;
			cout << "������� ����� ���: ";
			getline(cin, type1);
			if (type1 == "���") {
				set_type3d(type1);
				cout << "������� ������: ";
				a1 = check();
				set_sizes3d(a1, 0, 0, 0);
				cout << "������ ������� ��������" << endl;
			}
			else if (type1 == "��������������") {
				set_type3d(type1);
				cout << "������� ������: ";
				a1 = check();
				cout << "������� �����: ";
				b1 = check();
				cout << "������� ������: ";
				c1 = check();
				set_sizes3d(a1, b1, c1, 0);
				cout << "������ ������� ��������" << endl;
			}
			else if (type1 == "������������� ��������") {
				set_type3d(type1);
				cout << "������� ����� 1: ";
				a1 = check();
				cout << "������� ����� 2: ";
				b1 = check();
				cout << "������� ����������: ";
				c1 = check();
				cout << "������� ������: ";
				h1 = check();
				set_sizes3d(a1, b1, c1, h1);
				cout << "������ ������� ��������" << endl;
			}
			else {
				cout << "������ ���� �� ����������." << endl;
			}
			break;
		case '2':
			if (this->type == "���") {
				cout << "������� ������: ";
				a1 = check();
				set_sizes3d(a1, 0, 0, 0);
				cout << "������ ������� ��������" << endl;
			}
			else if (this->type == "��������������") {
				cout << "������� ������: ";
				a1 = check();
				cout << "������� �����: ";
				b1 = check();
				cout << "������� ������: ";
				c1 = check();
				set_sizes3d(a1, b1, c1, 0);
				cout << "������ ������� ��������" << endl;
			}
			else if (this->type == "������������� ��������") {
				cout << "������� ����� 1: ";
				a1 = check();
				cout << "������� ����� 2: ";
				b1 = check();
				cout << "������� ����������: ";
				c1 = check();
				cout << "������� ������: ";
				h1 = check();
				set_sizes3d(a1, b1, c1, h1);
				cout << "������ ������� ��������" << endl;
			}
			else {
				cout << "������ ���� �� ����������." << endl;
			}
			break;
		case '0':
			cout << "����� �� ��������������" << endl;
			return 0;
		default:
			cout << "����� ������� �� ����������." << endl;
			break;
		}
	}
	
}
void figur3d::load_from_file(istream& in) {
	in >> a >> b >> c >> h;
	this->set_sizes3d(a, b, c, h);
}
void figur3d::save_to_file(ostream& out) {
	out << "3d\n" << a << ' ' << b << ' ' << c << ' ' << h << '\n';
}