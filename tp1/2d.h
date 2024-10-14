#pragma once
#include "figur.h"
class figur2d : public Figur {
private:
	string type;
	float a, b, c;
	float S;
public:
	figur2d();
	figur2d(const string& t, const float& a1, const float& b1, const float& c1, const float& S1);
	figur2d(const figur2d& tmp);
	~figur2d();

	void set_type2d(string t);
	void set_sizes2d(float a1, float b1, float c1);
	void set_S(float S1);

	string get_type2d();
	float* get_sizes2d();
	float get_S();

	void draw() override;
	void print() override;
	int edit_inf() override;
	void load_from_file(istream&) override;
	void save_to_file(ostream&) override;
};