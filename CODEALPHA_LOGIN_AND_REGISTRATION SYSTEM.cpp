#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// Function to check if username already exists
bool userExists(const string &username) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

// Registration function
void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Error: Username already exists. Please choose another.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Login function
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    bool success = false;

    while (file >> u >> p) {
        if (u == username && p == password) {
            success = true;
            break;
        }
    }
    file.close();

    if (success) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Error: Invalid username or password.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
