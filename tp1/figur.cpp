#include "figur.h"
Figur::Figur() { cout << "Вызван конструктор без параметров для класса Figur\n"; };
Figur::Figur(const int& n) { cout << "Вызван конструктор с параметром для класса Figur\n"; }
Figur::Figur(const Figur& n) { cout << "Вызван конструктор копирования для класса Figur\n"; };
Figur::~Figur() { cout << "Вызван виртуальный деструктор для класса Figur\n"; };