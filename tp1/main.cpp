#include "2d.h"
#include "3d.h"
#include "keeper.h"
#include "check.h"
#include <conio.h>
#include <fstream>
#include <iostream>
using namespace std;

void menu() {
    cout << "--- Меню ---" << endl;
    cout << "1. Добавить данные из файла" << endl;
    cout << "2. Вывести содержимое контейнера на экран" << endl;
    cout << "3. Вывести данные о конкретном элементе на экран и его рисунок" << endl;
    cout << "4. Добавить новый элемент в начало" << endl;
    cout << "5. Добавить новый элемент в конец" << endl;
    cout << "6. Редактировать элемент по индексу" << endl;
    cout << "7. Удалить элемент с начала" << endl;
    cout << "8. Удалить элемент с конца" << endl;
    cout << "9. Удалить конкретный элемент" << endl;
    cout << "0. Cохранить данные в файл" << endl;
    cout << "x. Выход" << endl;
 }

int main() {
	setlocale(LC_ALL, "Russian");
    menu();
    Keeper keeper;
    char c;
    int n;
    while (1) {
        switch (c = _getch())
        {
        case '1':
            try {
                keeper.load_from_file("file.txt");
            }
            catch (const runtime_error& e) {
                cerr << "Ошибка при загрузке файла: " << e.what() << endl;
            }
            break;
        case '2':
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 2\n" << endl;
            keeper.print_keeper();
            break;
        case '3':
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 3\n" << endl;
            cout << "Введите номер элемента: ";
            n = check();
            keeper.print_element(n);
            break;
        case '4':
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 4\n" << endl;
            ++keeper;
            break;
        case '5':
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 5\n" << endl;
            keeper++;
            break;
        case '6':
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 6\n" << endl;
            cout << "Введите номер элемента: ";
            n = check();
            keeper.edit_element(n);
            break;
        case '7':
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 7\n" << endl;
            --keeper;
            break;
        case '8':
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 8\n" << endl;
            keeper--;
            break;
        case '9':
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 9\n" << endl;
            cout << "Введите номер элемента: ";
            n = check();
            keeper.delete_element(n);
            break;
        case '0': {
            try {
                keeper.save_to_file("file.txt");
            }
            catch (const runtime_error& e) {
                cerr << "Ошибка при сохранении файла: " << e.what() << endl;
            }
            break;
        case 'x':
            return 0;
        }
        default:
            break;
        }
    }
};