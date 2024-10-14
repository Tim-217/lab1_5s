#pragma once
#include "figur.h"
class figur3d : public Figur {
private:
	string type;
	float a, b, c, h;
	float V;
public:
	figur3d();
	figur3d(const string& t, const float& a1, const float& b1, const float& c1, const float& h1, const float& V1);
	figur3d(const figur3d& tmp);
	~figur3d();

	void set_type3d(string t);
	void set_sizes3d(float a1, float b1, float c1, float h1);
	void set_V(float S1);

	string get_type3d();
	float* get_sizes3d();
	float get_V();

	void draw() override;
	void print() override;
	int edit_inf() override;
	void load_from_file(istream&) override;
	void save_to_file(ostream&) override;
};