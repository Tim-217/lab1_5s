#include "figur.h"
Figur::Figur() { cout << "Вызван конструктор класса Figur\n"; };
Figur::Figur(const int& n) { cout << "Вызван конструктор c параметрами класса Figur\n"; }
Figur::Figur(const Figur& n) { cout << "Вызван конструктор копирования класса Figur\n"; };
Figur::~Figur() { cout << "Вызван деструктор класса Figur\n"; };