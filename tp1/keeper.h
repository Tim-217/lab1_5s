#pragma once
#include "figur.h"
#include "2d.h"
#include "3d.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Element {
    Element* next;
    Figur* data;
};

class Keeper
{
private:
    Element* head;
    Element* tail;
    int count;

public:
    Keeper();
    Keeper(Element* h, Element* t, int c);
    Keeper(Keeper& other);
    ~Keeper();

    Element* get_head();
    Element* get_tail();
    int get_count();

    void delete_head();
    void delete_all();
    Keeper& delete_element(int n);

    Keeper& edit_element(int n);

    void add_to_head(Figur* mover);
    void add_to_tail(Figur* mover);

    Keeper& operator++();
    friend Keeper& operator++(Keeper& K, int);

    Keeper& operator--(int);
    friend Keeper& operator--(Keeper& K);

    void print_keeper();
};