#include "keeper.h"
#include "check.h"
#include <windows.h>

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) { cout << "������ ����������� ��� ���������� ��� ������ Keeper\n"; }
Keeper::Keeper(Element* h, Element* t, int c) : head(h), tail(t), count(c) { cout << "������ ����������� � ����������� ��� ������ Keeper\n"; }
Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "������ ����������� ����������� ��� ������ Keeper\n";
}
Keeper::~Keeper() {
    cout << "������ ���������� ��� ������ Keeper\n";
    delete_all();
}

Element* Keeper::get_head() {
    return this->head;
}
Element* Keeper::get_tail() {
    return this->tail;
}
int Keeper::get_count() {
    return count;
}

void Keeper::delete_head() {
    if (head) {
        Element* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
        count--;
        if (count == 0) {
            tail = nullptr;
        }
    }
}
void Keeper::delete_all() {
    while (head != 0)
        delete_head();
}
Keeper& Keeper::delete_element(int n) {
    if (n < 1 || n > count) {
        cout << "������������ ������ ��������" << endl;
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

    return *this;
}

Keeper& Keeper::edit_element(int n) {
    if (n < 1 || n > count) {
        cout << "������������ ������ ��������" << endl;
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
        cout << "������ ���" << endl;
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

    int add_choice = -1;
    while (add_choice != 0) {
        add_choice = check();
        if (add_choice == 1) {
            string type;
            float a,b,c, S;

            cout << "������� ��� ������\n(�������, ��� �� ������ ������� ������ ��� ���� ������� �����: ����, ������������� � ������������� �����������): ";
            getline(cin, type);
            if (type == "����") {
                cout << "������� ������: " << endl;
                a = check();
                b = 0;
                c = 0;
                S = 3.14 * a * a;
            }
            else if (type == "�������������") {
                cout << "������� ������: " << endl;
                a = check();
                cout << "������� �����: " << endl;
                b = check();
                c = 0;
                S = a * b;
            }
            else if (type == "������������� �����������") {               
                cout << "������� ����� 1: " << endl;
                a = check();
                cout << "������� ����� 2: " << endl;
                b = check();
                cout << "������� ����������: " << endl;
                c = check();  
                S = 1 / 2 * a * b;
            }
            else {
                cout << "������ ���� �� ����������." << endl;
            }
            figur2d* figur2 = new figur2d(type, a, b, c, S);
            add_to_head(figur2);
        }
        else if (add_choice == 2) {
            string type;
            float a, b, c, h, V;
            cout << "������� ��� ������\n(�������, ��� �� ������ ������� ������ ��� ���� ������� �����: ���, �������������� � ������������� ��������): ";
            getline(cin, type);
            if (type == "���") {
                cout << "������� ������: " << endl;
                a = check();
                b = 0;
                c = 0;
                h = 0;
                V = 3.14 * a * a * a * 4 / 3;
            }
            else if (type == "��������������") {
                cout << "������� ������: " << endl;
                a = check();
                cout << "������� �����: " << endl;
                b = check();
                cout << "������� ������: " << endl;
                c = check();
                h = 0;
                V = a * b * c;
            }
            else if (type == "������������� ��������") {
                cout << "������� ����� 1: " << endl;
                a = check();
                cout << "������� ����� 2: " << endl;
                b = check();
                cout << "������� ����������: " << endl;
                c = check();
                cout << "������� ������: " << endl;
                h = check();
                V = (a * b) * h / 6;
            }
            else {
                cout << "������ ���� �� ����������." << endl;
            }
            figur3d* figur3 = new figur3d(type, a, b, c, h, V);
            add_to_head(figur3);
        }
        else if (add_choice == 0) {
            break;
        }
        else {
            cout << "������� ���������� ��������" << endl;
            continue;
        }
    }
    return *this;
}
Keeper& operator++(Keeper& K, int) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int add_choice = -1;
    while (add_choice != 0) {
        add_choice = check();
        if (add_choice == 1) {
            string type;
            float a, b, c, S;

            cout << "������� ��� ������\n(�������, ��� �� ������ ������� ������ ��� ���� ������� �����: ����, ������������� � ������������� �����������): ";
            getline(cin, type);
            if (type == "����") {
                cout << "������� ������: " << endl;
                a = check();
                b = 0;
                c = 0;
                S = 3.14 * a * a;
            }
            else if (type == "�������������") {
                cout << "������� ������: " << endl;
                a = check();
                cout << "������� �����: " << endl;
                b = check();
                c = 0;
                S = a * b;
            }
            else if (type == "������������� �����������") {
                cout << "������� ����� 1: " << endl;
                a = check();
                cout << "������� ����� 2: " << endl;
                b = check();
                cout << "������� ����������: " << endl;
                c = check();
                S = 1 / 2 * a * b;
            }
            else {
                cout << "������ ���� �� ����������." << endl;
            }
            figur2d* figur2 = new figur2d(type, a, b, c, S);
            K.add_to_tail(figur2);
        }
        else if (add_choice == 2) {
            string type;
            float a, b, c, h, V;
            cout << "������� ��� ������\n(�������, ��� �� ������ ������� ������ ��� ���� ������� �����: ���, �������������� � ������������� ��������): ";
            getline(cin, type);
            if (type == "���") {
                cout << "������� ������: " << endl;
                a = check();
                b = 0;
                c = 0;
                h = 0;
                V = 3.14 * a * a * a * 4 / 3;
            }
            else if (type == "��������������") {
                cout << "������� ������: " << endl;
                a = check();
                cout << "������� �����: " << endl;
                b = check();
                cout << "������� ������: " << endl;
                c = check();
                h = 0;
                V = a * b * c;
            }
            else if (type == "������������� ��������") {
                cout << "������� ����� 1: " << endl;
                a = check();
                cout << "������� ����� 2: " << endl;
                b = check();
                cout << "������� ����������: " << endl;
                c = check();
                cout << "������� ������: " << endl;
                h = check();
                V = (a * b) * h / 6;
            }
            else {
                cout << "������ ���� �� ����������." << endl;
            }
            figur3d* figur3 = new figur3d(type, a, b, c, h, V);
            K.add_to_tail(figur3);
        }
        else if (add_choice == 0) {
            break;
        }
        else {
            cout << "������� ���������� ��������" << endl;
            continue;
        }
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
    return *this;
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
