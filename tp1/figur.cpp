#include "figur.h"
Figur::Figur() { cout << "������ ����������� ������ Figur\n"; };
Figur::Figur(const int& n) { cout << "������ ����������� c ����������� ������ Figur\n"; }
Figur::Figur(const Figur& n) { cout << "������ ����������� ����������� ������ Figur\n"; };
Figur::~Figur() { cout << "������ ���������� ������ Figur\n"; };