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
    cout << "Контейнер очищен." << endl;
}
Keeper& Keeper::delete_element(int n) {
    if (n < 1 || n > count) {
        cout << "Элемента с таким индексом не существует." << endl;
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
    cout << "Вы удалили один элемент." << endl;
    return *this;
}

Keeper& Keeper::edit_element(int n) {
    if (n < 1 || n > count) {
        cout << "Элемента с таким индексом не существует." << endl;
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
        cout << "Данных у данного элемента нет." << endl;
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
    cout << "Если хотите добавить плоскую фигуру, введите 2." << endl;
    cout << "Если хотите добавить объёмную фигуру, введит 3." << endl;
    int i = 0;
    int f = 0;
    i = check();
    if (i == 2) {
        string type;
        float a, b, c, S;
        cout << "Помните, что вы можете создать только три типа фигур: круг, прямоугольник и прямоугольный треугольник" << endl;
        cout << "Введите тип фигуры: ";
        getline(cin, type);
        if (type == "Круг") {
            cout << "Введите радиус: ";
            a = check();
            b = 0;
            c = 0;
            S = 3.14 * a * a;
            if (a == 0)
                f = 1;
        }
        else if (type == "Прямоугольник") {
            cout << "Введите ширину: ";
            a = check();
            cout << "Введите длину: ";
            b = check();
            c = 0;
            S = a * b;
            if (a == 0 && b == 0)
                f = 1;
        }
        else if (type == "Прямоугольный треугольник") {
            cout << "Введите катет 1: ";
            a = check();
            cout << "Введите катет 2: ";
            b = check();
            cout << "Введите гипотенузу: ";
            c = check();
            S = a * b / 2;
            if (a == 0 && b == 0 && c == 0)
                f = 1;
        }
        else {
            cout << "Такого типа не существует." << endl;
            f = 1;
        }
        if (f == 0)
        {
            figur2d* figur2 = new figur2d(type, a, b, c, S);
            add_to_head(figur2);
            cout << "Новый элемент успешно добавлен в начало списка" << endl;
        }
        else
            cout << "Данные не добавлены. Попробуйте повторить операцию еще раз." << endl;
        
    }
    else if (i == 3) {
        string type;
        float a, b, c, h, V;
        cout << "Помните, что вы можете создать только три типа объёмных фигур: шар, прараллелепипед и прямоугольную пирамиду" << endl;
        cout << "Введите тип фигуры: ";
        getline(cin, type);
        if (type == "Шар") {
            cout << "Введите радиус: ";
            a = check();
            b = 0;
            c = 0;
            h = 0;
            V = 3.14 * a * a * a * 4 / 3;
            if (a == 0)
                f = 1;
        }
        else if (type == "Параллелепипед") {
            cout << "Введите ширину: ";
            a = check();
            cout << "Введите длину: ";
            b = check();
            cout << "Введите высоту: ";
            c = check();
            h = 0;
            V = a * b * c;
            if (a == 0 && b == 0 && c == 0)
                f = 1;
        }
        else if (type == "Прямоугольная пирамида") {
            cout << "Введите катет 1: ";
            a = check();
            cout << "Введите катет 2: ";
            b = check();
            cout << "Введите гипотенузу: ";
            c = check();
            cout << "Введите высоту: ";
            h = check();
            V = (a * b) * h / 6;
            if (a == 0 && b == 0 && c == 0 && h == 0)
                f = 1;
        }
        else {
            cout << "Такого типа не существует." << endl;
            f = 1;
        }
        if (f == 0)
        {
            figur3d* figur3 = new figur3d(type, a, b, c, h, V);
            add_to_head(figur3);
            cout << "Новый элемент успешно добавлен в начало списка" << endl;
        }
        else
            cout << "Данные не добавлены. Попробуйте повторить операцию еще раз." << endl;        
    }
    else {
        cout << "Введите корректное значение." << endl;
    }         
    return *this;
}
Keeper& operator++(Keeper& K, int) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Если хотите добавить плоскую фигуру, введите 2." << endl;
    cout << "Если хотите добавить объёмную фигуру, введит 3." << endl;
    int i = 0;
    int f = 0;
    i = check();
    if (i == 2) {
        string type;
        float a, b, c, S;
        cout << "Помните, что вы можете создать только три типа фигур: круг, прямоугольник и прямоугольный треугольник" << endl;
        cout << "Введите тип фигуры: ";
        getline(cin, type);
        if (type == "Круг") {
            cout << "Введите радиус: ";
            a = check();
            b = 0;
            c = 0;
            S = 3.14 * a * a;
            if (a == 0)
                f = 1;
        }
        else if (type == "Прямоугольник") {
            cout << "Введите ширину: ";
            a = check();
            cout << "Введите длину: ";
            b = check();
            c = 0;
            S = a * b;
            if (a == 0 && b == 0)
                f = 1;
        }
        else if (type == "Прямоугольный треугольник") {
            cout << "Введите катет 1: ";
            a = check();
            cout << "Введите катет 2: ";
            b = check();
            cout << "Введите гипотенузу: ";
            c = check();
            S = a * b / 2;
            if (a == 0 && b == 0 && c == 0)
                f = 1;
        }
        else {
            cout << "Такого типа не существует." << endl;
            f = 1;
        }
        if (f == 0)
        {
            figur2d* figur2 = new figur2d(type, a, b, c, S);
            K.add_to_tail(figur2);
            cout << "Новый элемент успешно добавлен в конец списка" << endl;
        }
        else
            cout << "Данные не добавлены. Попробуйте повторить операцию еще раз." << endl;        
    }
    else if (i == 3) {
        string type;
        float a, b, c, h, V;
        cout << "Помните, что вы можете создать только три типа объёмных фигур: шар, прараллелепипед и прямоугольную пирамиду" << endl;
        cout << "Введите тип фигуры: ";
        getline(cin, type);
        if (type == "Шар") {
            cout << "Введите радиус: ";
            a = check();
            b = 0;
            c = 0;
            h = 0;
            V = 3.14 * a * a * a * 4 / 3;
            if (a == 0)
                f = 1;
        }
        else if (type == "Параллелепипед") {
            cout << "Введите ширину: ";
            a = check();
            cout << "Введите длину: ";
            b = check();
            cout << "Введите высоту: ";
            c = check();
            h = 0;
            V = a * b * c;
            if (a == 0 && b == 0 && c == 0)
                f = 1;
        }
        else if (type == "Прямоугольная пирамида") {
            cout << "Введите катет 1: ";
            a = check();
            cout << "Введите катет 2: ";
            b = check();
            cout << "Введите гипотенузу: ";
            c = check();
            cout << "Введите высоту: ";
            h = check();
            V = (a * b) * h / 6;
            if (a == 0 && b == 0 && c == 0 && h == 0)
                f = 1;
        }
        else {
            cout << "Такого типа не существует." << endl;
            f = 1;
        }
        if (f == 0)
        {
            figur3d* figur3 = new figur3d(type, a, b, c, h, V);
            K.add_to_tail(figur3);
            cout << "Новый элемент успешно добавлен в конец списка" << endl;
        }
        else
            cout << " Данные не добавлены. Попробуйте повторить операцию еще раз." << endl;        
    }
    else {
        cout << "Введите корректное значение." << endl;
    }
    return K;
}

Keeper& operator--(Keeper& K) {
    if (K.count == 0) {
        cout << "Контейнер пуст. Сначала добавьте что-нибудь." << endl;
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
    cout << "Вы удалили один элемент с начала." << endl;
    return K;
}
Keeper& Keeper::operator--(int) {
    if (this->count == 0) {
        cout << "Контейнер пуст. Сначала добавьте что-нибудь." << endl;
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
    cout << "Вы удалили один элемент с конца." << endl;
    return *this;
}

void Keeper::print_element(int n) {
    if (n < 1 || n > count) {
        cout << "Элемента с таким индексом не существует." << endl;
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
        cout << "Данных у данного элемента нет." << endl;
}
void Keeper::print_keeper() {
    Element* temp = head;
    if (count == 0) {
        cout << "Контейнер пуст." << endl;
        return;
    }
    int i = 0;
    while (temp != 0) {
        cout << i + 1 << " - ";
        if (temp->data) {
            temp->data->print();
        }
        else {
            cout << "Контейнер пуст.";
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
        cerr << "Ошибка открытия файла для загрузки!" << endl;
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
    cout << "В контейнер добавлено " << c << " объектов." << endl;
}
void Keeper::save_to_file(const string& filename) {
    ofstream out(filename);
    Element* current = head;
    while (current != nullptr) {
        current->data->save_to_file(out);
        current = current->next;
    }
    out.close();
    cout << "Данные сохранены." << endl;
}

