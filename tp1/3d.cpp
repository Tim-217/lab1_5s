#include "3d.h"
#include <windows.h>
#include <conio.h>

figur3d::figur3d() :type(""), a(0), b(0), c(0), h(0), V(0) { cout << "������ ����������� ��� ���������� ��� ������ figur2d\n"; };
figur3d::figur3d(const string& t, const float& a1, const float& b1, const float& c1, const float& h1, const float& V1) :type(t), a(a1), b(b1), c(c1), h(h1), V(V1) {
	cout << "������ ����������� � ����������� ��� ������ figur2d\n";
}
figur3d::figur3d(const figur3d& tmp) : type(tmp.type), a(tmp.a), b(tmp.b), c(tmp.c), h(tmp.h), V(tmp.V) {
	cout << "������ ����������� ����������� ��� ������ figur2d\n";
}
figur3d::~figur3d() { cout << "������ ����������  ��� ������ figur2d\n"; }

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
		v = (a1 * b1) * h1 / 6;
		this->set_V(v);
		float d = 0.001;
		float c2 = sqrt(b1 * b1 + a1 * a1);
		if (abs(c2 - c1) < d) {
			cout << "�� �����" << endl;
			this->a = a1;
			this->b = b1;
			this->c = c1;
			this->h = h1;
		}
		else
		{
			cout << "���������� ������. �������� ����� �� ������ ��� ���������." << endl;
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
		Ellipse(hdc, 700, 100, 700 + 2 * r, 100 + 2 * r);		
	}
	else if (this->type == "��������������") {
		Rectangle(hdc, 700, 100, 700 + b, 100 + a);
	}
	else if (this->type == "������������� ��������") {
		MoveToEx(hdc, 700, 100, NULL);
		LineTo(hdc, 700, 100 + h);
		LineTo(hdc, 700 + b, 100 + h);
		LineTo(hdc, 700, 100);
	}
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
			cout << "������� ����� ��� (�������, ��� �� ������ ������� ������ ��� ���� �������� �����: ���, ��������������� � ������������� ��������): ";
			getline(cin, type1);
			if (type1 == "���") {
				set_type3d(type1);
				cout << "������� ������: " << endl;
				cin >> a1;
				set_sizes3d(a1, 0, 0, 0);
				cout << "������ ������� ��������" << endl;
			}
			else if (type1 == "��������������") {
				set_type3d(type1);
				cout << "������� ������: " << endl;
				cin >> a1;
				cout << "������� �����: " << endl;
				cin >> b1;
				cout << "������� ������: " << endl;
				cin >> c1;
				set_sizes3d(a1, b1, c1, 0);
				cout << "������ ������� ��������" << endl;
			}
			else if (type1 == "������������� ��������") {
				set_type3d(type1);
				cout << "������� ����� 1: " << endl;
				cin >> a1;
				cout << "������� ����� 2: " << endl;
				cin >> b1;
				cout << "������� ����������: " << endl;
				cin >> c1;
				cout << "������� ������: " << endl;
				cin >> h1;
				set_sizes3d(a1, b1, c1, h1);
				cout << "������ ������� ��������" << endl;
			}
			else {
				cout << "������ ���� �� ����������." << endl;
			}
			break;
		case '2':
			if (this->type == "���") {
				cout << "������� ������: " << endl;
				cin >> a1;
				set_sizes3d(a1, 0, 0, 0);
				cout << "������ ������� ��������" << endl;
			}
			else if (this->type == "��������������") {
				cout << "������� ������: " << endl;
				cin >> a1;
				cout << "������� �����: " << endl;
				cin >> b1;
				cout << "������� ������: " << endl;
				cin >> c1;
				set_sizes3d(a1, b1, c1, 0);
				cout << "������ ������� ��������" << endl;
			}
			else if (this->type == "������������� ��������") {
				cout << "������� ����� 1: " << endl;
				cin >> a1;
				cout << "������� ����� 2: " << endl;
				cin >> b1;
				cout << "������� ����������: " << endl;
				cin >> c1;
				cout << "������� ������: " << endl;
				cin >> h1;
				set_sizes3d(a1, b1, c1, h1);
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