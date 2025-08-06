#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

const string COMPONENT_ADMIN_KEY = "EED_SDLCadmin";
const string COMPONENT_USER_KEY = "EED_SDLCuser";
const string FILE_PATH = "D:\\Year_2025_2026\\CPPProjectSDLC\\sdlc.csv";

class Component {
public:
    string name;
    float value;
    int quantity;
    string unit;

    Component(string _name, float _value, int _quantity, string _unit)
        : name(_name), value(_value), quantity(_quantity), unit(_unit) {}

    void display_Component() const {
        cout << "\nComponent Name : " << name << endl;
        cout << "Value          : " << value << " " << unit << endl;
        cout << "Quantity       : " << quantity << endl;
        cout << "------------------------------" << endl;
    }
};

vector<Component> components;

void read_components() {
    string searchValue;
    cout << "\nSearch by component name or unit: ";
    cin >> searchValue;

    components.clear();
    ifstream inputFile(FILE_PATH);
    if (!inputFile.is_open()) {
        cerr << "Error opening the file: " << FILE_PATH << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string name, valueStr, quantityStr, unit;

        getline(ss, name, ',');
        getline(ss, valueStr, ',');
        getline(ss, quantityStr, ',');
        getline(ss, unit);

        if (name == searchValue || unit == searchValue) {
            try {
                float value = stof(valueStr);
                int quantity = stoi(quantityStr);
                components.emplace_back(name, value, quantity, unit);
            } catch (...) {
                cerr << "Error converting data in line: " << line << endl;
            }
        }
    }

    inputFile.close();

    if (components.empty()) {
        cout << "No components found for: " << searchValue << endl;
    } else {
        for (const auto& component : components) {
            component.display_Component();
        }
    }
}

void write_component() {
    int numComponents;
    cout << "\nEnter number of components to add: ";
    cin >> numComponents;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ofstream file(FILE_PATH, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file: " << FILE_PATH << endl;
        return;
    }

    for (int i = 0; i < numComponents; i++) {
        string name, unit;
        float value;
        int quantity;

        cout << "\nComponent " << i + 1 << ":" << endl;
        cout << "Enter name     : ";
        getline(cin, name);
        cout << "Enter value    : ";
        cin >> value;
        cout << "Enter quantity : ";
        cin >> quantity;
        cout << "Enter unit     : ";
        cin >> unit;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        file << name << "," << value << "," << quantity << "," << unit << "\n";
    }

    file.close();
    cout << "\nComponent(s) added successfully.\n";
}

void ComponentAdmin() {
    string pin;
    cout << "\nEnter Admin Access Key: ";
    cin >> pin;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (pin == COMPONENT_ADMIN_KEY) {
        int choice;
        cout << "\n1. Add Components\n2. Read Components\nChoose an option: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            write_component();
        } else if (choice == 2) {
            read_components();
        } else {
            cout << "Invalid option.\n";
        }
    } else {
        cout << "Access Denied. Invalid Admin Key.\n";
    }
}

void ComponentUser() {
    string pin;
    cout << "\nEnter User Access Key: ";
    cin >> pin;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (pin == COMPONENT_USER_KEY) {
        read_components();
    } else {
        cout << "Access Denied. Invalid User Key.\n";
    }
}

int main() {
    cout << "==== SDLC Component Management System ====" << endl;

    string role;
    cout << "\nLogin as (admin/user): ";
    cin >> role;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (role == "admin") {
        ComponentAdmin();
    } else if (role == "user") {
        ComponentUser();
    } else {
        cout << "Invalid role entered.\n";
    }

    return 0;
}
