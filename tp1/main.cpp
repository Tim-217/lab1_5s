#include "2d.h"
#include "3d.h"
#include "keeper.h"
#include "check.h"
#include <conio.h>
#include <fstream>
#include <iostream>
using namespace std;

void menu() {
    cout << "--- ���� ---" << endl;
    cout << "1. �������� ������ �� �����" << endl;
    cout << "2. ������� ���������� ���������� �� �����" << endl;
    cout << "3. ������� ������ � ���������� �������� �� ����� � ��� �������" << endl;
    cout << "4. �������� ����� ������� � ������" << endl;
    cout << "5. �������� ����� ������� � �����" << endl;
    cout << "6. ������������� ������� �� �������" << endl;
    cout << "7. ������� ������� � ������" << endl;
    cout << "8. ������� ������� � �����" << endl;
    cout << "9. ������� ���������� �������" << endl;
    cout << "0. C�������� ������ � ����" << endl;
    cout << "x. �����" << endl;
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
                cerr << "������ ��� �������� �����: " << e.what() << endl;
            }
            break;
        case '2':
            system("cls");
            menu();
            cout << "\n�� ������� �������� 2\n" << endl;
            keeper.print_keeper();
            break;
        case '3':
            system("cls");
            menu();
            cout << "\n�� ������� �������� 3\n" << endl;
            cout << "������� ����� ��������: ";
            n = check();
            keeper.print_element(n);
            break;
        case '4':
            system("cls");
            menu();
            cout << "\n�� ������� �������� 4\n" << endl;
            ++keeper;
            break;
        case '5':
            system("cls");
            menu();
            cout << "\n�� ������� �������� 5\n" << endl;
            keeper++;
            break;
        case '6':
            system("cls");
            menu();
            cout << "\n�� ������� �������� 6\n" << endl;
            cout << "������� ����� ��������: ";
            n = check();
            keeper.edit_element(n);
            break;
        case '7':
            system("cls");
            menu();
            cout << "\n�� ������� �������� 7\n" << endl;
            --keeper;
            break;
        case '8':
            system("cls");
            menu();
            cout << "\n�� ������� �������� 8\n" << endl;
            keeper--;
            break;
        case '9':
            system("cls");
            menu();
            cout << "\n�� ������� �������� 9\n" << endl;
            cout << "������� ����� ��������: ";
            n = check();
            keeper.delete_element(n);
            break;
        case '0': {
            try {
                keeper.save_to_file("file.txt");
            }
            catch (const runtime_error& e) {
                cerr << "������ ��� ���������� �����: " << e.what() << endl;
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