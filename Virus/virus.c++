#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

string encryptText(const string& text, int key) {
    string encrypted = text;
    for (char& ch : encrypted) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + key) % 26 + base;
        }
    }
    return encrypted;
}

void createVirus(const string& nyogokuru.docx, int key) {
    string content = "This is a hidden virus file.";

    string encryptedContent = encryptText(content, key);

    ofstream file(nyogokuru.docx);
    if (file.is_open()) {
        file << encryptedContent << endl;
        file.close();
        cout << "Simulated virus created: " << nyogokuru<< endl;
    } else {
        cout << "Failed to create the file." << endl;
    }
}

bool isDocxFile(const string& nyogokuru) {
    regex docxPattern(".*\\.docx$");
    return regex_match(nyogokuru, docxPattern);
}

int main() {
    const string password = "1234"; 
    string inputPassword;

    cout << "========================\n";
    cout << "     LOGIN REQUIRED     \n";
    cout << "========================\n";

    cout << "Enter the password: ";
    cin >> inputPassword;

    if (inputPassword != password) {
        cout << "Incorrect password. Access denied." << endl;
        return 1;
    }

    cout << "\nLogin successful! Welcome to the program.\n";

    string fileName;
    cout << "\nEnter the name of the .docx file you want to process: ";
    cin >> fileName;

    if (!isDocxFile(fileName)) {
        cout << "Error: The file must have a .docx extension." << endl;
        return 1;
    }

    int key = 5;
    createVirus(fileName, key);

    cout << "\nProcess completed. Goodbye!" << endl;
    return 0;
}
