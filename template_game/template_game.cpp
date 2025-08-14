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
        cout << "|          ���� �������� ��������       |" << endl;
        cout << "==========================================" << endl;
        cout << "������� �������� ��������: ";
        getline(cin, name);
    }
    void itype() {
        cout << "==========================================" << endl;
        cout << "|           ���� ���� ��������          |" << endl;
        cout << "==========================================" << endl;
        cout << "������� ��� ��������: ";
        getline(cin, type);
    }
    void ivalue() {
        while (true) {
            cout << "==========================================" << endl;
            cout << "|          ���� ��������� ��������      |" << endl;
            cout << "==========================================" << endl;
            cout << "������� ��������� ��������: ";
            cin >> value;
            cin.ignore();

            if (value > 0) {
                break;
            }
            cout << "==========================================" << endl;
            cout << "| ������: ������������ ���������!        |" << endl;
            cout << "| ������� ������������� ��������.        |" << endl;
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
        cout << "|          ���������� � ��������       |" << endl;
        cout << "==========================================" << endl;
        cout << "| ��������: " << name << endl;
        cout << "| ���: " << type << endl;
        cout << "| ���������: " << value << endl;
        cout << "| ID: " << id << endl;
        cout << "| �������: " << loc_id << endl;
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
        cout << "|          �������� ���������          |" << endl;
        cout << "==========================================" << endl;
        cout << "������� ��� ���������: ";
        getline(cin, name);
    }
    void output_info() {
        cout << "==========================================" << endl;
        cout << "|        �������������� ���������      |" << endl;
        cout << "==========================================" << endl;
        cout << "| ���: " << name << endl;
        cout << "| �������: " << level << endl;
        cout << "| ID: " << id << endl;
        cout << "| �������: " << loc_id << endl;
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
            cout << "|          ��������� ����               |" << endl;
            cout << "==========================================" << endl;
        }
        else {
            cout << "==========================================" << endl;
            cout << "|          ��������� ���������         |" << endl;
            cout << "==========================================" << endl;
            cout << "| ����� ���������: " << equipment.size() << endl;
            cout << "==========================================" << endl;

            for (int i = 0; i < equipment.size(); i++) {
                cout << "| ������� �" << i + 1 << endl;
                cout << "| ��������: " << equipment[i].name << endl;
                cout << "| ���: " << equipment[i].type << endl;
                cout << "| ���������: " << equipment[i].value << endl;
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
            "������� ��������",
            "����� ����������",
            "������ ��� �������� ������",
            "���� ������ ���������",
            "���������� ���� ���������",
            "������ ������ ������",
            "���� ��������� ������",
            "����� ���� ������������",
            "������ ��������� ����",
            "������� Wi-Fi �� �����",
            "������ ���������",
            "������ �������� ������",
            "����� ������ ������",
            "������ ������ �������",
            "������ ������� ������",
            "������ ����������� ��������",
            "�������� ������� ���������",
            "�������� ������� ����",
            "����� ������� ��������",
            "����� ������ �������"
        };
    }
    location(string pname, int pname_of_items, int pname_of_characters) {
        id = rand() % (10000000 - 1) + 1;
        name = pname;
        number_of_items = pname_of_items;
        number_of_characters = pname_of_characters;
        locationNames = {
            "������� ��������",
            "����� ����������",
            "������ ��� �������� ������",
            "���� ������ ���������",
            "���������� ���� ���������",
            "������ ������ ������",
            "���� ��������� ������",
            "����� ���� ������������",
            "������ ��������� ����",
            "������� Wi-Fi �� �����",
            "������ ���������",
            "������ �������� ������",
            "����� ������ ������",
            "������ ������ �������",
            "������ ������� ������",
            "������ ����������� ��������",
            "�������� ������� ���������",
            "�������� ������� ����",
            "����� ������� ��������",
            "����� ������ �������"
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
        cout << "|        �������� ������� �������      |" << endl;
        cout << "==========================================" << endl;
        while (true) {
            cout << "������� ���������� ������� (3-20): ";
            cin >> answer;
            if (answer >= 3 && answer <= 20) {
                break;
            }
            cout << "==========================================" << endl;
            cout << "| ������: ������������ ����������!      |" << endl;
            cout << "| ���������� ��������: �� 3 �� 20.      |" << endl;
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
        cout << "|        ��������� �������             |" << endl;
        cout << "==========================================" << endl;
        for (int i = 0; i < locations.size(); i++) {
            cout << "| " << i + 1 << ". " << locations[i].name << endl;
            cout << "| ID: " << locations[i].id << endl;
            cout << "==========================================" << endl;
        }
        while (true) {
            cout << "������� ID ������� ��� ������: ";
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
            cout << "| ������: ������� � ����� ID �� �������!|" << endl;
            cout << "==========================================" << endl;
        }
        cout << "==========================================" << endl;
        cout << "| ��������� ������� ������� �������!    |" << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void adding_character() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|        ���������� ������ ���������     |" << endl;
        cout << "==========================================" << endl;
        prototype_character.iname();
        characters.push_back(prototype_character);
        cout << "==========================================" << endl;
        cout << "�������� '" << prototype_character.name << "' ������� ������!" << endl;
        cout << "ID ���������: " << prototype_character.id << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void adding_item() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|         ���������� ������ ��������     |" << endl;
        cout << "==========================================" << endl;
        if (characters.size() == 0) {
            cout << "��� ��������� ����������!" << endl;
            cout << "������� �������� ���������." << endl;
            cout << "==========================================" << endl;
            Sleep(2000);
        }
        else {
            cout << "������ ����������: ";
            for (size_t i = 0; i < characters.size(); i++) {
                cout << i + 1 << ". " << characters[i].name << " (ID: " << characters[i].id << ")\n";
            }
        }
        cout << "�������� ��������� (0 ��� ������): ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 0) return;
        if (choice < 1 || choice > static_cast<int>(characters.size())) {
            cout << "������: �������� ����� ���������!";
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
        cout << "������� '" << prototype_item.name << "' ������� ��������!" << endl;
        cout << "��������: " << selected_character.name << endl;
        cout << "�������: " << prototype_item.loc_id << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void search_character() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|          ����� ���������               |" << endl;
        cout << "==========================================" << endl;
        if (characters.size() == 0) {
            cout << "��� ���������� ��� ������!" << endl;
            cout << "==========================================" << endl;
            Sleep(1500);
            return;
        }

        string query;
        cout << "\n������� ��� ��������� (��� 0 ��� ������): ";
        getline(cin, query);

        if (query == "0") return;

        bool found = false;
        for (const auto& ch : characters) {
            if (ch.name == query) {
                system("cls");
                cout << "==========================================" << endl;
                cout << "������ ��������:" << endl;
                cout << "==========================================" << endl;
                ch.output_info();
                cout << "\n���������:" << endl;
                ch.output_items();
                cout << "==========================================" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "�������� '" << query << "' �� ������!";
            Sleep(1500);
        }
        else {
            cout << "������� Enter ��� �����������...";
            cin.get();
        }
    }
    void search_item() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|          ����� ��������               |" << endl;
        cout << "==========================================" << endl;
        string query;
        cout << "\n������� �������� �������� (��� 2 ��� ������): ";
        getline(cin, query);
        if (query == "2") return;
        bool found = false;
        for (int i = 0; i < items.size(); i++) {
            if (items[i].name == query) {
                cout << "\n==========================================" << endl;
                cout << "������ �������:" << endl;
                cout << "==========================================" << endl;
                items[i].output();
                for (int j = 0; j < characters.size(); j++) {
                    if (characters[j].id == items[i].id) {
                        cout << "\n��������: " << characters[j].name << " (ID: " << characters[j].id << ")";
                        break;
                    }
                }
                cout << "\n==========================================" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\n������� '" << query << "' �� ������!";
            Sleep(1500);
        }
        else {
            cout << "\n������� Enter ��� �����������...";
            cin.get();
        }
    }

    void output_world_info() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|       ������ ���������� � ����        |" << endl;
        cout << "==========================================" << endl;
        cout << "\n=== ������� (" << locations.size() << ") ===" << endl;
        if (locations.size() == 0) {
            cout << "������� �� �������!\n";
        }
        else {
            for (int i = 0; i < locations.size(); i++) {
                cout << i + 1 << ". " << locations[i].name << endl;
                cout << "   ID: " << locations[i].id << endl;
                cout << "   ����������: " << locations[i].number_of_characters << endl;
                cout << "   ���������: " << locations[i].number_of_items << endl;
                if (i != locations.size() - 1) cout << "--------------------------------" << endl;
            }
        }
        cout << "\n=== ��������� (" << characters.size() << ") ===" << endl;
        if (characters.size() == 0) {
            cout << "��������� �� �������!\n";
        }
        else {
            for (int i = 0; i < characters.size(); i++) {
                cout << i + 1 << ". " << characters[i].name << " (������� " << characters[i].level << ")" << endl;
                cout << "   ID: " << characters[i].id << endl;
                cout << "   �������: " << characters[i].loc_id << endl;
                cout << "   ���������: " << characters[i].equipment.size() << endl;
                if (i != characters.size() - 1) cout << "--------------------------------" << endl;
            }
        }
        cout << "\n������� Enter ��� �����������...";
        cin.ignore();
        cin.get();
    }
    void save_characters(string filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|        ���������� ����������          |" << endl;
        cout << "==========================================" << endl;
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "\n������: �� ������� ������� ����!";
            Sleep(1500);
            return;
        }
        file << characters.size() << endl;
        for (int i = 0; i < characters.size(); i++) {
            file << characters[i];
        }
        file.close();
        cout << "\n������� ��������� ����������: " << characters.size() << endl;
        cout << "����: " << filename << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void save_items(const string& filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|         ���������� ���������          |" << endl;
        cout << "==========================================" << endl;
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "������: �� ������� ������� ���� ��� ������!" << endl;
            cout << "==========================================" << endl;
            Sleep(2000);
            return;
        }
        file << items.size() << endl;
        for (const auto& it : items) {
            file << it;
        }
        file.close();
        cout << "\n������� ���������:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "����:          " << filename << endl;
        cout << "����� ���������: " << items.size() << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void load_characters(string filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|        �������� ����������            |" << endl;
        cout << "==========================================" << endl;
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "\n������: ���� �� ������!";
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
        cout << "\n������� ��������� ����������: " << characterCount << endl;
        cout << "����: " << filename << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void load_items(const string& filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|          �������� ���������           |" << endl;
        cout << "==========================================" << endl;
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "������: ���� " << filename << " �� ������!" << endl;
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
        cout << "������� ���������:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "����:          " << filename << endl;
        cout << "����� ���������: " << items.size() << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void move_character() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|       ����������� ���������           |" << endl;
        cout << "==========================================" << endl;
        if (characters.empty()) {
            cout << "��� ����������!\n";
            cout << "==========================================" << endl;
            Sleep(1500);
            return;
        }
        cout << "\n��������� �������:\n";
        for (size_t i = 0; i < locations.size(); i++) {
            cout << i + 1 << ". " << locations[i].name << " (ID: " << locations[i].id << ")\n";
        }
        int loc_choice;
        cout << "�������� �������: ";
        cin >> loc_choice;
        cin.ignore();
        if (loc_choice < 1 || loc_choice > static_cast<int>(locations.size())) {
            cout << "�������� ����� �������!\n";
            Sleep(1000);
            return;
        }
        characters[loc_choice - 1].loc_id = locations[loc_choice - 1].id;
        cout << "�������� ��������� � " << locations[loc_choice - 1].name << "!\n";
        cout << "==========================================" << endl;
        Sleep(1500);
    }
    void show_stats() {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|            ���������� ����            |" << endl;
        cout << "==========================================" << endl;
        cout << "����� ����������: " << characters.size() << endl;
        cout << "����� ���������: " << items.size() << endl;
        cout << "����� �������: " << locations.size() << endl;
        if (!locations.size() == 0) {
            cout << "���������� �� ��������: ";
            for (const auto& loc : locations) {
                int count = count_if(characters.begin(), characters.end(),
                    [&](const character& ch) { return ch.loc_id == loc.id; });
                cout << loc.name << ": " << count << " ����������\n";
            }
        }
        cout << "==========================================" << endl;
        cout << "������� Enter ��� �����������...";
        cin.ignore();
        cin.get();
    }
    void save_locations(const string& filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|         ���������� �������            |" << endl;
        cout << "==========================================" << endl;
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "\n������: �� ������� ������� ���� ��� ������!" << endl;
            cout << "==========================================" << endl;
            Sleep(2000);
            return;
        }
        file << locations.size() << endl;
        for (const auto& loc : locations) {
            file << loc;
        }
        file.close();
        cout << "\n������� ���������:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "����:          " << filename << endl;
        cout << "����� �������: " << locations.size() << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void load_locations(const string& filename) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|          �������� �������             |" << endl;
        cout << "==========================================" << endl;
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "\n������: ���� " << filename << " �� ������!" << endl;
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
        cout << "\n������� ���������:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "����:          " << filename << endl;
        cout << "����� �������: " << locations.size() << endl;
        cout << "==========================================" << endl;
        Sleep(2000);
    }
    void save_game() {
        save_characters("characters.txt");
        save_items("items.txt");
        save_locations("locations.txt");
        system("cls");
        cout << "==========================================" << endl;
        cout << "|         ���� ������� ���������        |" << endl;
        cout << "==========================================" << endl;
        cout << "��� ������ ��������� � �����:" << endl;
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
        cout << "|        ���� ������� ���������         |" << endl;
        cout << "==========================================" << endl;
        cout << "���������:" << endl;
        cout << "- ����������: " << characters.size() << endl;
        cout << "- ���������: " << items.size() << endl;
        cout << "- �������: " << locations.size() << endl;
        cout << "==========================================" << endl;
        Sleep(2500);
    }
};
void demo(gameworld& prototype) {
    while (true) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|           ������� ����               |" << endl;
        cout << "==========================================" << endl;
        cout << "1. ���������� �����������" << endl;
        cout << "2. ���������� ����������" << endl;
        cout << "3. �������� ����" << endl;
        cout << "4. ��������� ����" << endl;
        cout << "5. ��������� ����" << endl;
        cout << "6. �����" << endl;
        cout << "==========================================" << endl;
        cout << "�������� ��������: ";
        int answer;
        cin >> answer;
        cin.ignore();
        if (answer == 1) {
            system("cls");
            cout << "==========================================" << endl;
            cout << "|       ���������� �����������        |" << endl;
            cout << "==========================================" << endl;
            cout << "1. �������� ���������" << endl;
            cout << "2. ����� ���������" << endl;
            cout << "3. ����������� ���������" << endl;
            cout << "4. �����" << endl;
            cout << "==========================================" << endl;
            cout << "�������� ��������: ";
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
                cout << "�������� �����!" << endl;
                Sleep(1000);
            }
        }
        else if (answer == 2) {
            system("cls");
            cout << "==========================================" << endl;
            cout << "|        ���������� ����������         |" << endl;
            cout << "==========================================" << endl;
            cout << "1. �������� �������" << endl;
            cout << "2. ����� ��������" << endl;
            cout << "3. �����" << endl;
            cout << "==========================================" << endl;
            cout << "�������� ��������: ";
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
                cout << "�������� �����!" << endl;
                Sleep(1000);
            }
        }
        else if (answer == 3) {
            system("cls");
            cout << "==========================================" << endl;
            cout << "|          �������� ����               |" << endl;
            cout << "==========================================" << endl;
            cout << "1. ������ ����������" << endl;
            cout << "2. ����������" << endl;
            cout << "3. �����" << endl;
            cout << "==========================================" << endl;
            cout << "�������� ��������: ";
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
                cout << "�������� �����!" << endl;
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
            cout << "����� �� ���������." << endl;
            Sleep(1000);
            return;
        }
        else {
            cout << "�������� �����. ���������� �����." << endl;
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