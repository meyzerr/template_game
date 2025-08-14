#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <ctime>
#include <cmath>
#include <stack>
#include <cctype>
#include <algorithm>
#include <vector> 
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <windows.h>

using namespace std;

class item {
public:
    string name;
    string type;
    double value;

    item() {
        name = "none";
        type = "none";
        value = 0;
    }

    item(string pname, string ptype, double pvalue) {
        name = pname;
        type = ptype;
        value = pvalue;
    }

    void iname() {
        cout << "Введи название для предмета: " << endl;
        getline(cin, name);
    }

    void itype() {
        cout << "Введи тип предмета: " << endl;
        getline(cin, type);
    }

    void ivalue() {
        cout << "Введи стоимость предмета: " << endl;
        cin >> value;
        cin.ignore();
    }

    void input() {
        iname();
        itype();
        ivalue();
    }

    void output() {
        cout << "Название для предмета: " << name << endl;
        cout << "Тип предмета: " << type << endl;
        cout << "Cтоимость предмета: " << value << endl;
    }
};

class character {
public:
    string name;
    int level;
    vector<item> equipment;

    character() {
        name = "none";
        level = 1;
    }

    character(string pname) {
        name = pname;
        level = 1;
    }

    void iname() {
        cout << "Введи имя: " << endl;
        getline(cin, name);
    }

    void output_info() {
        cout << "Имя персонажа: " << name << endl;
        cout << "Уровень персонажа: " << level << endl;
    }

    void adding_item() {
        item newItem;
        newItem.input();
        equipment.push_back(newItem);
    }

    void output_items() {
        for (int i = 0; i < equipment.size(); i++) {
            cout << "Предмет №" << i + 1 << ": ";
            equipment[i].output();
            cout << "==========================================================" << endl;
        }
    }
};

class gameworld {
public:
    vector<character> characters;
    vector<item> items;

    character prototype_character;
    item prototype_item;

    gameworld() {
        characters.push_back(prototype_character);
        prototype_character.iname();
    }

    void adding_character() {
        character newCharacter;
        newCharacter.iname();
        characters.push_back(newCharacter);
    }

    void adding_item() {
        item newItem;
        newItem.input();
        items.push_back(newItem);
    }

    void search_character() {
        string line;
        while (true) {
            cout << "Введи имя персонажа или введи 2 чтобы завершить поиск: " << endl;
            getline(cin, line);
            if (line == "2") break;

            bool found = false;
            for (int i = 0; i < characters.size(); i++) {
                if (characters[i].name == line) {
                    cout << "Персонаж успешно найден!" << endl;
                    characters[i].output_info();
                    characters[i].output_items();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Персонаж не найден!" << endl;
                Sleep(1000);
            }
        }
    }

    void search_item() {
        string line;
        while (true) {
            cout << "Введи название предмета или введи 2 чтобы завершить поиск: " << endl;
            getline(cin, line);
            if (line == "2") break;

            bool found = false;
            for (int i = 0; i < items.size(); i++) {
                if (items[i].name == line) {
                    cout << "Предмет успешно найден!" << endl;
                    items[i].output();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Предмет не найден!" << endl;
                Sleep(1000);
            }
        }
    }

    void output_world_info() {
        cout << "Информация о мире:" << endl;
        cout << "Персонажи:" << endl;
        for (int i = 0; i < characters.size(); i++) {
            characters[i].output_info();
            characters[i].output_items();
            cout << "==========================================================" << endl;
        }

        cout << "Предметы:" << endl;
        for (int i = 0; i < items.size(); i++) {
            items[i].output();
            cout << "==========================================================" << endl;
        }
    }
};

void demo(gameworld& prototype) {
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить персонажа" << endl;
        cout << "2. Добавить предмет" << endl;
        cout << "3. Поиск персонажа" << endl;
        cout << "4. Поиск предмета" << endl;
        cout << "5. Вывод информации о мире" << endl;
        cout << "6. Выход" << endl;
        int answer;
        cin >> answer;
        cin.ignore();
        if (answer == 1) {
            prototype.adding_character();
        }
        else if (answer == 2) {
            prototype.adding_item();
        }
        else if (answer == 3) {
            prototype.search_character();
        }
        else if (answer == 4) {
            prototype.search_item();
        }
        else if (answer == 5) {
            prototype.output_world_info();
        }
        else if (answer == 6) {
            cout << "Выход из программы." << endl;
            break;
        }
        else {
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    system("chcp 1251>nul");
    gameworld world;
    demo(world);
    return 0;
}