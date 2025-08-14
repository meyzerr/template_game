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
    int loc_id;
    item() {
        name = "none";
        type = "none";
        value = 0;
        id = 0;
        loc_id = 0;
    }
    item(string pname, string ptype, double pvalue) {
        name = pname;
        type = ptype;
        value = pvalue;
        id = 0;
        loc_id = 0;
    }
    void iname() {
        cout << "==========================================" << endl;
        cout << "|          ВВОД НАЗВАНИЯ ПРЕДМЕТА       |" << endl;
        cout << "==========================================" << endl;
        cout << "Введите название предмета: ";
        getline(cin, name);
    }
    void itype() {
        cout << "==========================================" << endl;
        cout << "|           ВВОД ТИПА ПРЕДМЕТА          |" << endl;
        cout << "==========================================" << endl;
        cout << "Введите тип предмета: ";
        getline(cin, type);
    }
    void ivalue() {
        while (true) {
            cout << "==========================================" << endl;
            cout << "|          ВВОД СТОИМОСТИ ПРЕДМЕТА      |" << endl;
            cout << "==========================================" << endl;
            cout << "Введите стоимость предмета: ";
            cin >> value;
            cin.ignore();

            if (value > 0) {
                break;
            }
            cout << "==========================================" << endl;
            cout << "| ОШИБКА: Некорректная стоимость!        |" << endl;
            cout << "| Введите положительное значение.        |" << endl;
            cout << "==========================================" << endl;
        }
    }

    void input() {
        iname();
        itype();
        ivalue();
    }
    void output() {
        cout << "==========================================" << endl;
        cout << "|          ИНФОРМАЦИЯ О ПРЕДМЕТЕ       |" << endl;
        cout << "==========================================" << endl;
        cout << "| Название: " << name << endl;
        cout << "| Тип: " << type << endl;
        cout << "| Стоимость: " << value << endl;
        cout << "| ID: " << id << endl;
        cout << "| Локация: " << loc_id << endl;
        cout << "==========================================" << endl;
    }
    friend ostream& operator<<(ostream& os, const item& item) {
        os << item.name << endl;
        os << item.type << endl;
        os << item.value << endl;
        os << item.id << endl;
        os << item.loc_id << endl;
        return os;
    }

    friend istream& operator>>(istream& is, item& item) {
        getline(is, item.name);
        getline(is, item.type);
        is >> item.value;
        is >> item.id;
        is >> item.loc_id;
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
    int loc_id;
    character() {
        name = "none";
        level = 1;
        id = rand() % (10000000 - 1) + 1;
        loc_id = 0;
    }
    character(string pname) {
        name = pname;
        level = 1;
        id = rand() % (10000000 - 1) + 1;
        loc_id = 0;
    }
    void iname() {
        cout << "==========================================" << endl;
        cout << "|          СОЗДАНИЕ ПЕРСОНАЖА          |" << endl;
        cout << "==========================================" << endl;
        cout << "Введите имя персонажа: ";
        getline(cin, name);
    }
    void output_info() {
        cout << "==========================================" << endl;
        cout << "|        ХАРАКТЕРИСТИКИ ПЕРСОНАЖА      |" << endl;
        cout << "==========================================" << endl;
        cout << "| Имя: " << name << endl;
        cout << "| Уровень: " << level << endl;
        cout << "| ID: " << id << endl;
        cout << "| Локация: " << loc_id << endl;
        cout << "==========================================" << endl;
    }
    void adding_item() {
        item newItem;
        newItem.input();
        equipment.push_back(newItem);
        newItem.id = id;
    }
    void output_items() {
        if (equipment.size() == 0) {
            cout << "==========================================" << endl;
            cout << "|          ИНВЕНТАРЬ ПУСТ               |" << endl;
            cout << "==========================================" << endl;
        }
        else {
            cout << "==========================================" << endl;
            cout << "|          ИНВЕНТАРЬ ПЕРСОНАЖА         |" << endl;
            cout << "==========================================" << endl;
            cout << "| Всего предметов: " << equipment.size() << endl;
            cout << "==========================================" << endl;

            for (int i = 0; i < equipment.size(); i++) {
                cout << "| Предмет №" << i + 1 << endl;
                cout << "| Название: " << equipment[i].name << endl;
                cout << "| Тип: " << equipment[i].type << endl;
                cout << "| Стоимость: " << equipment[i].value << endl;
                cout << "==========================================" << endl;
            }
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

class location {
public:
    int id;
    string name;
    int  number_of_items;
    int number_of_characters;
    vector<string> locationNames;
    location() {
        id = rand() % (10000000 - 1) + 1;
        name = "none";
        number_of_items = 0;
        number_of_characters = 0;
        locationNames = {
            "Деревня Гадюкино",
            "Город Задрищенск",
            "Темный лес Сопливое болото",
            "Горы Спящий алкоголик",
            "Подземелье Офис налоговой",
            "Поляна Пьяных ежиков",
            "Река Кисельные берега",
            "Озеро Слез программиста",
            "Пещеры Совкового быта",
            "Пустыня Wi-Fi не ловит",
            "Остров Невезения",
            "Долина Разбитых надежд",
            "Холмы Кривых зеркал",
            "Болото Вечной отладки",
            "Вулкан Горячих клавиш",
            "Каньон Бесконечных спринтов",
            "Кладбище Мертвых дедлайнов",
            "Лабиринт Кривого кода",
            "Склеп Старого манагера",
            "Руины Легаси системы"
        };
    }
    location(string pname, int pname_of_items, int pname_of_characters) {
        id = rand() % (10000000 - 1) + 1;
        name = pname;
        number_of_items = pname_of_items;
        number_of_characters = pname_of_characters;
        locationNames = {
            "Деревня Гадюкино",
            "Город Задрищенск",
            "Темный лес Сопливое болото",
            "Горы Спящий алкоголик",
            "Подземелье Офис налоговой",
            "Поляна Пьяных ежиков",
            "Река Кисельные берега",
            "Озеро Слез программиста",
            "Пещеры Совкового быта",
            "Пустыня Wi-Fi не ловит",
            "Остров Невезения",
            "Долина Разбитых надежд",
            "Холмы Кривых зеркал",
            "Болото Вечной отладки",
            "Вулкан Горячих клавиш",
            "Каньон Бесконечных спринтов",
            "Кладбище Мертвых дедлайнов",
            "Лабиринт Кривого кода",
            "Склеп Старого манагера",
            "Руины Легаси системы"
        };
    }
    friend ostream& operator<<(ostream& os, const location& loc) {
        os << loc.name << endl;
        os << loc.id << endl;
        os << loc.number_of_items << endl;
        os << loc.number_of_characters << endl;
        return os;
    }
    friend istream& operator>>(istream& is, location& loc) {
        getline(is, loc.name);
        is >> loc.id;
        is >> loc.number_of_items;
        is >> loc.number_of_characters;
        is.ignore();
        return is;
    }
};

class gameworld {
public:
    vector<character> characters;
    vector<item> items;
    vector<location>locations;
    character prototype_character;
    item prototype_item;
    location prototype_location;
    gameworld() {
        prototype_character.iname();
        characters.push_back(prototype_character);
    }
    void add_locations() {
        int answer = 0;
        cout << "==========================================" << endl;
        cout << "|        СОЗДАНИЕ ИГРОВЫХ ЛОКАЦИЙ      |" << endl;
        cout << "==========================================" << endl;
        while (true) {
            cout << "Введите количество локаций (3-20): ";
            cin >> answer;
            if (answer >= 3 && answer <= 20) {
                break;
            }
            cout << "==========================================" << endl;
            cout << "| ОШИБКА: Некорректное количество!      |" << endl;
            cout << "| Допустимый диапазон: от 3 до 20.      |" << endl;
            cout << "==========================================" << endl;
        }
        locations.clear();
        for (int i = 0; i < answer; i++) {
            int random_name = rand() % prototype_location.locationNames.size();
            location new_loc(prototype_location.locationNames[random_name], 0, 0);
            locations.push_back(new_loc);
            prototype_location.locationNames.erase(prototype_location.locationNames.begin() + random_name);
        }
        cout << "==========================================" << endl;
        cout << "|        СОЗДАННЫЕ ЛОКАЦИИ             |" << endl;
        cout << "==========================================" << endl;
        for (int i = 0; i < locations.size(); i++) {
            cout << "| " << i + 1 << ". " << locations[i].name << endl;
            cout << "| ID: " << locations[i].id << endl;
            cout << "==========================================" << endl;
        }
        while (true) {
            cout << "Введите ID локации для старта: ";
            cin >> answer;
            bool found = false;
            for (int i = 0; i < locations.size(); i++) {
                if (locations[i].id == answer) {
                    prototype_character.loc_id = locations[i].id;
                    found = true;
                    break;
                }
            }
            if (found) break;
            cout << "==========================================" << endl;
            cout << "| ОШИБКА: Локация с таким ID не найдена!|" << endl;
            cout << "==========================================" << endl;
        }
        cout << "==========================================" << endl;
        cout << "| СТАРТОВАЯ ЛОКАЦИЯ УСПЕШНО ВЫБРАНА!    |" << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void adding_character() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|        ДОБАВЛЕНИЕ НОВОГО ПЕРСОНАЖА     |" << endl;
        cout << "==========================================" << endl;
        prototype_character.iname();
        characters.push_back(prototype_character);
        cout << "==========================================" << endl;
        cout << "Персонаж '" << prototype_character.name << "' успешно создан!" << endl;
        cout << "ID персонажа: " << prototype_character.id << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void adding_item() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|         ДОБАВЛЕНИЕ НОВОГО ПРЕДМЕТА     |" << endl;
        cout << "==========================================" << endl;
        if (characters.size() == 0) {
            cout << "Нет доступных персонажей!" << endl;
            cout << "Сначала создайте персонажа." << endl;
            cout << "==========================================" << endl;
            Sleep(2000);
        }
        else {
            cout << "Список персонажей: ";
            for (size_t i = 0; i < characters.size(); i++) {
                cout << i + 1 << ". " << characters[i].name << " (ID: " << characters[i].id << ")\n";
            }
        }
        cout << "Выберите персонажа (0 для отмены): ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0) return;
        if (choice < 1 || choice > static_cast<int>(characters.size())) {
            cout << "Ошибка: неверный выбор персонажа!";
            Sleep(1500);
            return;
        }
        system("cls");
        character& selected_character = characters[choice - 1];
        prototype_item.input();
        prototype_item.id = selected_character.id;
        prototype_item.loc_id = selected_character.loc_id;
        selected_character.equipment.push_back(prototype_item);
        items.push_back(prototype_item);

        cout << "\n==========================================" << endl;
        cout << "Предмет '" << prototype_item.name << "' успешно добавлен!" << endl;
        cout << "Владелец: " << selected_character.name << endl;
        cout << "Локация: " << prototype_item.loc_id << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void search_character() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|          ПОИСК ПЕРСОНАЖА               |" << endl;
        cout << "==========================================" << endl;
        if (characters.size() == 0) {
            cout << "Нет персонажей для поиска!" << endl;
            cout << "==========================================" << endl;
            Sleep(1500);
            return;
        }

        string query;
        cout << "\nВведите имя персонажа (или 0 для отмены): ";
        getline(cin, query);

        if (query == "0") return;

        bool found = false;
        for (const auto& ch : characters) {
            if (ch.name == query) {
                system("cls");
                cout << "==========================================" << endl;
                cout << "НАЙДЕН ПЕРСОНАЖ:" << endl;
                cout << "==========================================" << endl;
                ch.output_info();
                cout << "\nИНВЕНТАРЬ:" << endl;
                ch.output_items();
                cout << "==========================================" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Персонаж '" << query << "' не найден!";
            Sleep(1500);
        }
        else {
            cout << "Нажмите Enter для продолжения...";
            cin.get();
        }
    }
    void search_item() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|          ПОИСК ПРЕДМЕТА               |" << endl;
        cout << "==========================================" << endl;
        string query;
        cout << "\nВведите название предмета (или 2 для отмены): ";
        getline(cin, query);
        if (query == "2") return;
        bool found = false;
        for (int i = 0; i < items.size(); i++) {
            if (items[i].name == query) {
                cout << "\n==========================================" << endl;
                cout << "НАЙДЕН ПРЕДМЕТ:" << endl;
                cout << "==========================================" << endl;
                items[i].output();
                for (int j = 0; j < characters.size(); j++) {
                    if (characters[j].id == items[i].id) {
                        cout << "\nВЛАДЕЛЕЦ: " << characters[j].name << " (ID: " << characters[j].id << ")";
                        break;
                    }
                }
                cout << "\n==========================================" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\nПредмет '" << query << "' не найден!";
            Sleep(1500);
        }
        else {
            cout << "\nНажмите Enter для продолжения...";
            cin.get();
        }
    }

    void output_world_info() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|       ПОЛНАЯ ИНФОРМАЦИЯ О МИРЕ        |" << endl;
        cout << "==========================================" << endl;
        cout << "\n=== ЛОКАЦИИ (" << locations.size() << ") ===" << endl;
        if (locations.size() == 0) {
            cout << "Локации не созданы!\n";
        }
        else {
            for (int i = 0; i < locations.size(); i++) {
                cout << i + 1 << ". " << locations[i].name << endl;
                cout << "   ID: " << locations[i].id << endl;
                cout << "   Персонажей: " << locations[i].number_of_characters << endl;
                cout << "   Предметов: " << locations[i].number_of_items << endl;
                if (i != locations.size() - 1) cout << "--------------------------------" << endl;
            }
        }
        cout << "\n=== ПЕРСОНАЖИ (" << characters.size() << ") ===" << endl;
        if (characters.size() == 0) {
            cout << "Персонажи не созданы!\n";
        }
        else {
            for (int i = 0; i < characters.size(); i++) {
                cout << i + 1 << ". " << characters[i].name << " (уровень " << characters[i].level << ")" << endl;
                cout << "   ID: " << characters[i].id << endl;
                cout << "   Локация: " << characters[i].loc_id << endl;
                cout << "   Предметов: " << characters[i].equipment.size() << endl;
                if (i != characters.size() - 1) cout << "--------------------------------" << endl;
            }
        }
        cout << "\nНажмите Enter для продолжения...";
        cin.ignore();
        cin.get();
    }
    void save_characters(string filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|        СОХРАНЕНИЕ ПЕРСОНАЖЕЙ          |" << endl;
        cout << "==========================================" << endl;
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "\nОшибка: не удалось создать файл!";
            Sleep(1500);
            return;
        }
        file << characters.size() << endl;
        for (int i = 0; i < characters.size(); i++) {
            file << characters[i];
        }
        file.close();
        cout << "\nУспешно сохранено персонажей: " << characters.size() << endl;
        cout << "Файл: " << filename << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void save_items(const string& filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|         СОХРАНЕНИЕ ПРЕДМЕТОВ          |" << endl;
        cout << "==========================================" << endl;
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "ОШИБКА: Не удалось открыть файл для записи!" << endl;
            cout << "==========================================" << endl;
            Sleep(2000);
            return;
        }
        file << items.size() << endl;
        for (const auto& it : items) {
            file << it;
        }
        file.close();
        cout << "\nУСПЕШНО СОХРАНЕНО:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Файл:          " << filename << endl;
        cout << "Всего предметов: " << items.size() << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void load_characters(string filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|        ЗАГРУЗКА ПЕРСОНАЖЕЙ            |" << endl;
        cout << "==========================================" << endl;
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "\nОшибка: файл не найден!";
            Sleep(1500);
            return;
        }
        int characterCount;
        file >> characterCount;
        file.ignore();
        characters.clear();
        for (int i = 0; i < characterCount; i++) {
            character ch;
            file >> ch;
            characters.push_back(ch);
        }
        file.close();
        cout << "\nУспешно загружено персонажей: " << characterCount << endl;
        cout << "Файл: " << filename << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void load_items(const string& filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|          ЗАГРУЗКА ПРЕДМЕТОВ           |" << endl;
        cout << "==========================================" << endl;
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "ОШИБКА: Файл " << filename << " не найден!" << endl;
            cout << "==========================================" << endl;
            Sleep(2000);
            return;
        }
        int count;
        file >> count;
        file.ignore();
        items.clear();
        for (int i = 0; i < count; i++) {
            item it;
            file >> it;
            items.push_back(it);
        }
        file.close();
        cout << "УСПЕШНО ЗАГРУЖЕНО:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Файл:          " << filename << endl;
        cout << "Всего предметов: " << items.size() << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void move_character() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|       ПЕРЕМЕЩЕНИЕ ПЕРСОНАЖА           |" << endl;
        cout << "==========================================" << endl;
        if (characters.empty()) {
            cout << "Нет персонажей!\n";
            cout << "==========================================" << endl;
            Sleep(1500);
            return;
        }
        cout << "\nДоступные локации:\n";
        for (size_t i = 0; i < locations.size(); i++) {
            cout << i + 1 << ". " << locations[i].name << " (ID: " << locations[i].id << ")\n";
        }
        int loc_choice;
        cout << "Выберите локацию: ";
        cin >> loc_choice;
        cin.ignore();
        if (loc_choice < 1 || loc_choice > static_cast<int>(locations.size())) {
            cout << "Неверный выбор локации!\n";
            Sleep(1000);
            return;
        }
        characters[loc_choice - 1].loc_id = locations[loc_choice - 1].id;
        cout << "Персонаж перемещен в " << locations[loc_choice - 1].name << "!\n";
        cout << "==========================================" << endl;
        Sleep(1500);
    }
    void show_stats() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|            СТАТИСТИКА МИРА            |" << endl;
        cout << "==========================================" << endl;
        cout << "Всего персонажей: " << characters.size() << endl;
        cout << "Всего предметов: " << items.size() << endl;
        cout << "Всего локаций: " << locations.size() << endl;
        if (!locations.size() == 0) {
            cout << "Персонажей по локациям: ";
            for (const auto& loc : locations) {
                int count = count_if(characters.begin(), characters.end(),
                    [&](const character& ch) { return ch.loc_id == loc.id; });
                cout << loc.name << ": " << count << " персонажей\n";
            }
        }
        cout << "==========================================" << endl;
        cout << "Нажмите Enter для продолжения...";
        cin.ignore();
        cin.get();
    }
    void save_locations(const string& filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|         СОХРАНЕНИЕ ЛОКАЦИЙ            |" << endl;
        cout << "==========================================" << endl;
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "\nОШИБКА: Не удалось открыть файл для записи!" << endl;
            cout << "==========================================" << endl;
            Sleep(2000);
            return;
        }
        file << locations.size() << endl;
        for (const auto& loc : locations) {
            file << loc;
        }
        file.close();
        cout << "\nУСПЕШНО СОХРАНЕНО:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Файл:          " << filename << endl;
        cout << "Всего локаций: " << locations.size() << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void load_locations(const string& filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|          ЗАГРУЗКА ЛОКАЦИЙ             |" << endl;
        cout << "==========================================" << endl;
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "\nОШИБКА: Файл " << filename << " не найден!" << endl;
            cout << "==========================================" << endl;
            Sleep(2000);
            return;
        }
        int count;
        file >> count;
        file.ignore();
        locations.clear();
        for (int i = 0; i < count; i++) {
            location loc;
            file >> loc;
            locations.push_back(loc);
        }
        file.close();
        cout << "\nУСПЕШНО ЗАГРУЖЕНО:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Файл:          " << filename << endl;
        cout << "Всего локаций: " << locations.size() << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void save_game() {
        save_characters("characters.txt");
        save_items("items.txt");
        save_locations("locations.txt");
        system("cls");
        cout << "==========================================" << endl;
        cout << "|         ИГРА УСПЕШНО СОХРАНЕНА        |" << endl;
        cout << "==========================================" << endl;
        cout << "Все данные сохранены в файлы:" << endl;
        cout << "- characters.txt" << endl;
        cout << "- items.txt" << endl;
        cout << "- locations.txt" << endl;
        cout << "==========================================" << endl;
        Sleep(2500);
    }
    void load_game() {
        load_characters("characters.txt");
        load_items("items.txt");
        load_locations("locations.txt");
        system("cls");
        cout << "==========================================" << endl;
        cout << "|        ИГРА УСПЕШНО ЗАГРУЖЕНА         |" << endl;
        cout << "==========================================" << endl;
        cout << "Загружено:" << endl;
        cout << "- Персонажей: " << characters.size() << endl;
        cout << "- Предметов: " << items.size() << endl;
        cout << "- Локаций: " << locations.size() << endl;
        cout << "==========================================" << endl;
        Sleep(2500);
    }
};
void demo(gameworld& prototype) {
    while (true) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|           ГЛАВНОЕ МЕНЮ               |" << endl;
        cout << "==========================================" << endl;
        cout << "1. Управление персонажами" << endl;
        cout << "2. Управление предметами" << endl;
        cout << "3. Просмотр мира" << endl;
        cout << "4. Сохранить игру" << endl;
        cout << "5. Загрузить игру" << endl;
        cout << "6. Выход" << endl;
        cout << "==========================================" << endl;
        cout << "Выберите действие: ";
        int answer;
        cin >> answer;
        cin.ignore();
        if (answer == 1) {
            system("cls");
            cout << "==========================================" << endl;
            cout << "|       УПРАВЛЕНИЕ ПЕРСОНАЖАМИ        |" << endl;
            cout << "==========================================" << endl;
            cout << "1. Добавить персонажа" << endl;
            cout << "2. Поиск персонажа" << endl;
            cout << "3. Переместить персонажа" << endl;
            cout << "4. Назад" << endl;
            cout << "==========================================" << endl;
            cout << "Выберите действие: ";
            int char_choice;
            cin >> char_choice;
            cin.ignore();
            if (char_choice == 1) {
                prototype.adding_character();
            }
            else if (char_choice == 2) {
                prototype.search_character();
            }
            else if (char_choice == 3) {
                prototype.move_character();
            }
            else if (char_choice != 4) {
                cout << "Неверный выбор!" << endl;
                Sleep(1000);
            }
        }
        else if (answer == 2) {
            system("cls");
            cout << "==========================================" << endl;
            cout << "|        УПРАВЛЕНИЕ ПРЕДМЕТАМИ         |" << endl;
            cout << "==========================================" << endl;
            cout << "1. Добавить предмет" << endl;
            cout << "2. Поиск предмета" << endl;
            cout << "3. Назад" << endl;
            cout << "==========================================" << endl;
            cout << "Выберите действие: ";
            int item_choice;
            cin >> item_choice;
            cin.ignore();
            if (item_choice == 1) {
                prototype.adding_item();
            }
            else if (item_choice == 2) {
                prototype.search_item();
            }
            else if (item_choice != 3) {
                cout << "Неверный выбор!" << endl;
                Sleep(1000);
            }
        }
        else if (answer == 3) {
            system("cls");
            cout << "==========================================" << endl;
            cout << "|          ПРОСМОТР МИРА               |" << endl;
            cout << "==========================================" << endl;
            cout << "1. Полная информация" << endl;
            cout << "2. Статистика" << endl;
            cout << "3. Назад" << endl;
            cout << "==========================================" << endl;
            cout << "Выберите действие: ";
            int view_choice;
            cin >> view_choice;
            cin.ignore();
            if (view_choice == 1) {
                prototype.output_world_info();
            }
            else if (view_choice == 2) {
                prototype.show_stats();
            }
            else if (view_choice != 3) {
                cout << "Неверный выбор!" << endl;
                Sleep(1000);
            }
        }
        else if (answer == 4) {
            prototype.save_game();
        }
        else if (answer == 5) {
            prototype.load_game();
        }
        else if (answer == 6) {
            cout << "Выход из программы." << endl;
            Sleep(1000);
            return;
        }
        else {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            Sleep(1000);
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