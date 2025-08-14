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
    int id;

    item() {
        name = "none";
        type = "none";
        value = 0;
        id = 0;
    }

    item(string pname, string ptype, double pvalue) {
        name = pname;
        type = ptype;
        value = pvalue;
        id = 0;
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
        while (true) {
            cout << "Введи стоимость предмета: " << endl;
            cin >> value;
            cin.ignore();
            if (value > 0) {
                break;
            }
            else {
                cout << "Введите корректную стоимость!";
            }
        }
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
        cout << "ID предмета: " << id << endl;
    }
    friend ostream& operator<<(ostream& os, const item& item) {
        os << item.name << endl;
        os << item.type << endl;
        os << item.value << endl;
        os << item.id << endl;
        return os;
    }

    friend istream& operator>>(istream& is, item& item) {
        getline(is, item.name);
        getline(is, item.type);
        is >> item.value;
        is >> item.id;
        is.ignore();
        return is;
    }
};


class character {
public:
    string name;
    int level;
    vector<item> equipment;
    int id;

    character() {
        name = "none";
        level = 1;
        id = rand() % (10000000 - 1) + 1;
    }

    character(string pname) {
        name = pname;
        level = 1;
        id = rand() % (10000000 - 1) + 1;
    }

    void iname() {
        cout << "Введи имя: " << endl;
        getline(cin, name);
    }

    void output_info() {
        cout << "Имя персонажа: " << name << endl;
        cout << "Уровень персонажа: " << level << endl;
        cout << "ID персонажа: " << id << endl;
    }
    void adding_item() {
        item newItem;
        newItem.input();
        equipment.push_back(newItem);
        newItem.id = id;
    }

    void output_items() {
        for (int i = 0; i < equipment.size(); i++) {
            cout << "Предмет №" << i + 1 << ": ";
            equipment[i].output();
            cout << "==========================================================" << endl;
        }
    }
    friend ostream& operator<<(ostream& os, const character& character) {
        os << character.name << endl;
        os << character.level << endl;
        os << character.id << endl;
        os << character.equipment.size() << endl;
        for (int i = 0; i < character.equipment.size(); i++) {
            os << character.equipment[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, character& character) {
        getline(is, character.name);
        is >> character.level;
        is >> character.id;
        is.ignore();

        int equipmentSize;
        is >> equipmentSize;
        is.ignore();

        character.equipment.clear();
        for (int i = 0; i < equipmentSize; i++) {
            item it;
            is >> it;
            character.equipment.push_back(it);
        }
        return is;
    }
};

class gameworld {
public:
    vector<character> characters;
    vector<item> items;
    character prototype_character;
    item prototype_item;

    gameworld() {
        prototype_character.iname();
        characters.push_back(prototype_character);
    }

    void adding_character() {
        character newCharacter;
        newCharacter.iname();
        characters.push_back(newCharacter);
    }

    void adding_item() {
        while (true) {
            cout << "Выберите персонажа для добавления предмета:" << endl;
            for (int i = 0; i < characters.size(); i++) {
                cout << i + 1 << ". " << characters[i].name << endl;
            }
            int choice;
            cin >> choice;
            cin.ignore();
            if (choice < 1 || choice > characters.size()) {
                cout << "Неверный выбор персонажа." << endl;
            }
            else {
                character& selected_character = characters[choice - 1];
                item newItem;
                newItem.input();
                newItem.id = selected_character.id;
                selected_character.equipment.push_back(newItem);
                items.push_back(newItem);
                break;
            }
        }
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
    void save_characters(string filename) {
        ofstream file(filename);
        file << characters.size() << endl;
        for (int i = 0; i < characters.size(); i++) {
            file << characters[i];
        }
        file.close();
        cout << "Данные о персонажах успешно сохранены в файл " << filename << "!" << endl;
    }

    void save_items(string filename) {
        ofstream file(filename);
        file << items.size() << endl;
        for (int i = 0; i < items.size(); i++) {
            file << items[i];
        }
        file.close();
        cout << "Данные о предметах успешно сохранены в файл " << filename << "!" << endl;
    }
    void load_characters(string filename) {
        ifstream file(filename);
        int characterCount;
        file >> characterCount;
        file.ignore();
        characters.clear();
        for (int i = 0; i < characterCount; i++) {
            character none;
            file >> none;
            characters.push_back(none);
        }
        file.close();
        cout << "Данные о персонажах успешно загружены из файла " << filename << "!" << endl;
    }

    void load_items(string filename) {
        ifstream file(filename);
        int itemCount;
        file >> itemCount;
        file.ignore();
        items.clear();
        for (int i = 0; i < itemCount; i++) {
            item none;
            file >> none;
            items.push_back(none);
        }
        file.close();
        cout << "Данные о предметах успешно загружены из файла " << filename << "!" << endl;
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
        cout << "6. Сохранение в файл" << endl;
        cout << "7. Выгрузка из файла" << endl;
        cout << "8. Выход" << endl;
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
            prototype.save_characters("characters.txt");
            prototype.save_items("items.txt");
        }
        else if (answer == 7) {
            prototype.load_characters("characters.txt");
            prototype.load_items("items.txt");
        }
        else if (answer == 8) {
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
    srand(time(NULL));
    gameworld world;
    demo(world);
    return 0;
}