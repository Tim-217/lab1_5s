#include "keeper.h"
#include "check.h"
#include <windows.h>

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {}
Keeper::Keeper(Element* h, Element* t, int c) : head(h), tail(t), count(c) {}
Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {}
Keeper::~Keeper() { delete_all(); }

Element* Keeper::get_head() {
    return this->head;
}
Element* Keeper::get_tail() {
    return this->tail;
}
int Keeper::get_count() {
    return count;
}

void Keeper::delete_all() {
    while (head != 0) {
        Element* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
        count--;
        if (count == 0) {
            tail = nullptr;
        }
    }
    cout << "��������� ������." << endl;
}
Keeper& Keeper::delete_element(int n) {
    if (n < 1 || n > count) {
        cout << "�������� � ����� �������� �� ����������." << endl;
        return *this;
    }
    if (n == 1) {
        this->operator--(0);
        return *this;
    }
    Element* temp = head;
    for (int i = 1; i < n - 1; i++) {
        temp = temp->next;
    }
    Element* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == tail) {
        tail = temp;
    }
    delete toDelete->data;
    delete toDelete;
    count--;
    cout << "�� ������� ���� �������." << endl;
    return *this;
}

Keeper& Keeper::edit_element(int n) {
    if (n < 1 || n > count) {
        cout << "�������� � ����� �������� �� ����������." << endl;
        return *this;
    }
    Element* tmp = head;
    for (int i = 1; i < n; i++) {
        tmp = tmp->next;
    }
    if (tmp->data) {
        tmp->data->edit_inf();
    }
    else {
        cout << "������ � ������� �������� ���." << endl;
    }
    return *this;
}

void Keeper::add_to_head(Figur* tmp) {
    Element* new_el = new Element;
    new_el->data = tmp;
    new_el->next = head;
    if (head == nullptr) {
        tail = new_el;
    }
    head = new_el;
    count++;
}
void Keeper::add_to_tail(Figur* tmp) {
    Element* new_el = new Element;
    new_el->data = tmp;
    new_el->next = nullptr;

    if (head == nullptr) {
        head = tail = new_el;
    }
    else {
        tail->next = new_el;
        tail = new_el;
    }
    count++;
}

Keeper& Keeper::operator++() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "���� ������ �������� ������� ������, ������� 2." << endl;
    cout << "���� ������ �������� �������� ������, ������ 3." << endl;
    int i = 0;
    int f = 0;
    i = check();
    if (i == 2) {
        string type;
        float a, b, c, S;
        cout << "�������, ��� �� ������ ������� ������ ��� ���� �����: ����, ������������� � ������������� �����������" << endl;
        cout << "������� ��� ������: ";
        getline(cin, type);
        if (type == "����") {
            cout << "������� ������: ";
            a = check();
            b = 0;
            c = 0;
            S = 3.14 * a * a;
            if (a == 0)
                f = 1;
        }
        else if (type == "�������������") {
            cout << "������� ������: ";
            a = check();
            cout << "������� �����: ";
            b = check();
            c = 0;
            S = a * b;
            if (a == 0 && b == 0)
                f = 1;
        }
        else if (type == "������������� �����������") {
            cout << "������� ����� 1: ";
            a = check();
            cout << "������� ����� 2: ";
            b = check();
            cout << "������� ����������: ";
            c = check();
            S = a * b / 2;
            if (a == 0 && b == 0 && c == 0)
                f = 1;
        }
        else {
            cout << "������ ���� �� ����������." << endl;
            f = 1;
        }
        if (f == 0)
        {
            figur2d* figur2 = new figur2d(type, a, b, c, S);
            add_to_head(figur2);
            cout << "����� ������� ������� �������� � ������ ������" << endl;
        }
        else
            cout << "������ �� ���������. ���������� ��������� �������� ��� ���." << endl;
        
    }
    else if (i == 3) {
        string type;
        float a, b, c, h, V;
        cout << "�������, ��� �� ������ ������� ������ ��� ���� �������� �����: ���, ��������������� � ������������� ��������" << endl;
        cout << "������� ��� ������: ";
        getline(cin, type);
        if (type == "���") {
            cout << "������� ������: ";
            a = check();
            b = 0;
            c = 0;
            h = 0;
            V = 3.14 * a * a * a * 4 / 3;
            if (a == 0)
                f = 1;
        }
        else if (type == "��������������") {
            cout << "������� ������: ";
            a = check();
            cout << "������� �����: ";
            b = check();
            cout << "������� ������: ";
            c = check();
            h = 0;
            V = a * b * c;
            if (a == 0 && b == 0 && c == 0)
                f = 1;
        }
        else if (type == "������������� ��������") {
            cout << "������� ����� 1: ";
            a = check();
            cout << "������� ����� 2: ";
            b = check();
            cout << "������� ����������: ";
            c = check();
            cout << "������� ������: ";
            h = check();
            V = (a * b) * h / 6;
            if (a == 0 && b == 0 && c == 0 && h == 0)
                f = 1;
        }
        else {
            cout << "������ ���� �� ����������." << endl;
            f = 1;
        }
        if (f == 0)
        {
            figur3d* figur3 = new figur3d(type, a, b, c, h, V);
            add_to_head(figur3);
            cout << "����� ������� ������� �������� � ������ ������" << endl;
        }
        else
            cout << "������ �� ���������. ���������� ��������� �������� ��� ���." << endl;        
    }
    else {
        cout << "������� ���������� ��������." << endl;
    }         
    return *this;
}
Keeper& operator++(Keeper& K, int) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "���� ������ �������� ������� ������, ������� 2." << endl;
    cout << "���� ������ �������� �������� ������, ������ 3." << endl;
    int i = 0;
    int f = 0;
    i = check();
    if (i == 2) {
        string type;
        float a, b, c, S;
        cout << "�������, ��� �� ������ ������� ������ ��� ���� �����: ����, ������������� � ������������� �����������" << endl;
        cout << "������� ��� ������: ";
        getline(cin, type);
        if (type == "����") {
            cout << "������� ������: ";
            a = check();
            b = 0;
            c = 0;
            S = 3.14 * a * a;
            if (a == 0)
                f = 1;
        }
        else if (type == "�������������") {
            cout << "������� ������: ";
            a = check();
            cout << "������� �����: ";
            b = check();
            c = 0;
            S = a * b;
            if (a == 0 && b == 0)
                f = 1;
        }
        else if (type == "������������� �����������") {
            cout << "������� ����� 1: ";
            a = check();
            cout << "������� ����� 2: ";
            b = check();
            cout << "������� ����������: ";
            c = check();
            S = a * b / 2;
            if (a == 0 && b == 0 && c == 0)
                f = 1;
        }
        else {
            cout << "������ ���� �� ����������." << endl;
            f = 1;
        }
        if (f == 0)
        {
            figur2d* figur2 = new figur2d(type, a, b, c, S);
            K.add_to_tail(figur2);
            cout << "����� ������� ������� �������� � ����� ������" << endl;
        }
        else
            cout << "������ �� ���������. ���������� ��������� �������� ��� ���." << endl;        
    }
    else if (i == 3) {
        string type;
        float a, b, c, h, V;
        cout << "�������, ��� �� ������ ������� ������ ��� ���� �������� �����: ���, ��������������� � ������������� ��������" << endl;
        cout << "������� ��� ������: ";
        getline(cin, type);
        if (type == "���") {
            cout << "������� ������: ";
            a = check();
            b = 0;
            c = 0;
            h = 0;
            V = 3.14 * a * a * a * 4 / 3;
            if (a == 0)
                f = 1;
        }
        else if (type == "��������������") {
            cout << "������� ������: ";
            a = check();
            cout << "������� �����: ";
            b = check();
            cout << "������� ������: ";
            c = check();
            h = 0;
            V = a * b * c;
            if (a == 0 && b == 0 && c == 0)
                f = 1;
        }
        else if (type == "������������� ��������") {
            cout << "������� ����� 1: ";
            a = check();
            cout << "������� ����� 2: ";
            b = check();
            cout << "������� ����������: ";
            c = check();
            cout << "������� ������: ";
            h = check();
            V = (a * b) * h / 6;
            if (a == 0 && b == 0 && c == 0 && h == 0)
                f = 1;
        }
        else {
            cout << "������ ���� �� ����������." << endl;
            f = 1;
        }
        if (f == 0)
        {
            figur3d* figur3 = new figur3d(type, a, b, c, h, V);
            K.add_to_tail(figur3);
            cout << "����� ������� ������� �������� � ����� ������" << endl;
        }
        else
            cout << " ������ �� ���������. ���������� ��������� �������� ��� ���." << endl;        
    }
    else {
        cout << "������� ���������� ��������." << endl;
    }
    return K;
}

Keeper& operator--(Keeper& K) {
    if (K.count == 0) {
        cout << "��������� ����. ������� �������� ���-������." << endl;
        return K;
    }
    Element* tmp = K.head;
    K.head = K.head->next;
    delete tmp->data;
    delete tmp;
    K.count--;
    if (K.count == 0) {
        K.tail = nullptr;
    }
    cout << "�� ������� ���� ������� � ������." << endl;
    return K;
}
Keeper& Keeper::operator--(int) {
    if (this->count == 0) {
        cout << "��������� ����. ������� �������� ���-������." << endl;
        return *this;
    }
    if (this->count == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
    }
    else {
        Element* temp = this->head;
        while (temp->next != this->tail) {
            temp = temp->next;
        }
        delete this->tail->data;
        delete this->tail;
        this->tail = temp;
        this->tail->next = nullptr;
    }
    this->count--;
    cout << "�� ������� ���� ������� � �����." << endl;
    return *this;
}

void Keeper::print_element(int n) {
    if (n < 1 || n > count) {
        cout << "�������� � ����� �������� �� ����������." << endl;
        return;
    }
    Element* tmp = head;
    for (int i = 1; i < n; i++) {
        tmp = tmp->next;
    }
    if (tmp->data) {
        tmp->data->print();
        tmp->data->draw();
    }
    else 
        cout << "������ � ������� �������� ���." << endl;
}
void Keeper::print_keeper() {
    Element* temp = head;
    if (count == 0) {
        cout << "��������� ����." << endl;
        return;
    }
    int i = 0;
    while (temp != 0) {
        cout << i + 1 << " - ";
        if (temp->data) {
            temp->data->print();
        }
        else {
            cout << "��������� ����.";
        }
        cout << " " << endl;;
        temp = temp->next;
        i++;
    }
}
void Keeper::load_from_file(const string& filename) {
    ifstream in(filename);
    int c = 0;
    if (!in) {
        cerr << "������ �������� ����� ��� ��������!" << endl;
        return;
    }
    string marker;
    while (getline(in, marker)) {
        if (!marker.empty() && marker.back() == '\r') {
            marker.pop_back();
        }
        Figur* mover = nullptr;
        if (marker == "2d") {
            mover = new figur2d();
        }
        else if (marker == "3d") {
            mover = new figur3d();
        }
        else {
            continue;
        }
        if (mover) {
            mover->load_from_file(in);
            c += 1;
            this->add_to_tail(mover);
        }
    }
    in.close();
    cout << "� ��������� ��������� " << c << " ��������." << endl;
}
void Keeper::save_to_file(const string& filename) {
    ofstream out(filename);
    Element* current = head;
    while (current != nullptr) {
        current->data->save_to_file(out);
        current = current->next;
    }
    out.close();
    cout << "������ ���������." << endl;
}

