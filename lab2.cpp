
#include <iostream>
#include "BOOK.h";
#include "lab2.h"
using namespace std;

int main()
{
    BOOK b;
    cout << b << endl;
    int choise = 0;
    char new_name_temp[100];
    char* new_name = NULL;
    int count = 0;
    char ch = 1;
    int num;
    int nums;
    int n;
    int k;
    int j;
    while (choise != 14) {
        cout << "choose the action" << endl;
        cout << "1 - open book" << endl;
        cout << "2 - close book" << endl;
        cout << "3 - rename book" << endl;
        cout << "4 - open n sheet" << endl;
        cout << "5 - close n sheet" << endl;
        cout << "6 - rename n  sheet" << endl;
        cout << "7 - open n k cell from j sheet" << endl;
        cout << "8 - close n k cell from j sheet" << endl;
        cout << "9 - rename n k cell from j sheet" << endl;
        cout << "10 - put value in the n k cell from j sheet" << endl;
        cout << "11 - get value from the n k cell from j sheet" << endl;
        cout << "12 - save book to the disk" << endl;
        cout << "13 - get book from the disk" << endl;
        cout << "14 - exit this part of menu" << endl;
        cin >> choise;
        switch (choise) {
        case 1:
            b.open();
            cout << b << endl;
            break;
        case 2:
            b.close();
            cout << b << endl;
            break;
        case 3:
            cout << "enter the name of the book without spaces:" << endl;
            name_enterer(ch, new_name_temp, count, new_name);
            b.change_name(count, new_name);
            cout << b << endl;
            break;
        case 4:
            cout << "enter the number of the sheet" << endl;
            cin >> nums;
            if (nums <0 || nums > b.get_content_length()) {
                nums = 0;
            }
            b.get_content()[nums].open();
            cout << b << endl;
            break;
        case 5:
            cout << "enter the number of the sheet" << endl;
            cin >> nums;
            if (nums <0 || nums > b.get_content_length()) {
                nums = 0;
            }
            b.get_content()[nums].close();
            cout << b << endl;
            break;
        case 6:
            cout << "enter the number of the sheet" << endl;
            cin >> num;
            if (num <0 || num > b.get_content_length()) {
                num = 0;
            }
            cout << "enter the name of the sheet without spaces:" << endl;
            name_to_zero(new_name_temp, new_name, count, ch);
            name_enterer(ch, new_name_temp, count, new_name);
            b.get_content()[num].change_name(count, new_name);
            cout << b << endl;
            break;
        case 7:
            cell_selector(j, n, k, b);
            b.get_content()[j][n][k].open();
            cout << b << endl;
            break;
        case 8:
            cell_selector(j, n, k, b);
            b.get_content()[j][n][k].close();
            cout << b << endl;
            break;
        case 9:
            cell_selector(j, n, k, b);
            name_to_zero(new_name_temp, new_name, count, ch);
            name_enterer(ch, new_name_temp, count, new_name);
            b.get_content()[j][n][k].change_name(count, new_name);
            cout << b << endl;
            break;
        case 10:
            cell_selector(j, n, k, b);
            name_to_zero(new_name_temp, new_name, count, ch);
            name_enterer(ch, new_name_temp, count, new_name);
            b.get_content()[j][n][k].put_value(count, new_name);
            cout << b << endl;
            break;
        case 11:
            cell_selector(j, n, k, b);
            name_to_zero(new_name_temp, new_name, count, ch);
            name_enterer(ch, new_name_temp, count, new_name);
            b.get_content()[j][n][k].get_value();
            cout << b << endl;
            break;

        case 12:
            b.save_to_the_disk();
            break;

        case 13:
            b.get_from_the_disk();
            break;
        }
    }
}

void cell_selector(int& j, int& n, int& k, BOOK& b)
{
    cout << "enter the j" << endl;
    cin >> j;
    cout << "enter the n" << endl;
    cin >> n;
    cout << "enter the k" << endl;
    cin >> k;
    if (j <0 || j > b.get_content_length()) {
        j = 0;
    }
    if (n <0 || n > b.get_content()[j].get_content_length()) {
        n = 0;
    }
    if (k <0 || k > b.get_content()[j][n].get_content_length()) {
        k = 0;
    }
}

void name_to_zero(char  new_name_temp[100], char*& new_name, int& count, char& ch)
{
    //free(new_name_temp);
    new_name = NULL;
    count = 0;
    ch = 1;
}

void name_enterer(char& ch, char  new_name_temp[100], int& count, char*& new_name)
{
    while (ch != '/') {
        cout << "enter the symbol('/' to finish)" << endl;
        cin >> ch;
        if (ch != '/') {
            new_name_temp[count] = ch;
            ++count;
        }
    }
    new_name = new char[count];
    for (int i = 0; i < count; i++) {
        new_name[i] = new_name_temp[i];
    }
}
