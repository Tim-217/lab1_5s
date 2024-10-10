#pragma once
#include <iostream>
#include <string>
using namespace std;
class Figur {
public:
	Figur();
	Figur(const int& n);
	Figur(const Figur& n);
	virtual ~Figur();

	virtual void draw() = 0;
	virtual void print() = 0;
	virtual int edit_inf() = 0;

};