#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

string decryptText(const string& text, int key) {
    string decrypted = text;
    for (char& ch : decrypted) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base - key + 26) % 26 + base;
        }
    }
    return decrypted;
}

bool containsVirusSignature(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Error: Unable to open the file." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.find("This is a hidden virus file.") != string::npos) {
            file.close();
            return true; 
        }
    }

    file.close();
    return false; 
}

void cleanFile(const string& filePath, int key) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Error: Unable to open the file." << endl;
        return;
    }

    string encryptedContent;
    getline(file, encryptedContent); 
    file.close();

    string decryptedContent = decryptText(encryptedContent, key);

    if (decryptedContent == "This is a hidden virus file.") {
        ofstream outFile(filePath);
        if (outFile.is_open()) {
            outFile << "File cleaned successfully." << endl;
            outFile.close();
            cout << "The file has been cleaned: " << filePath << endl;
        } else {
            cout << "Error: Unable to clean the file." << endl;
        }
    } else {
        cout << "The file does not appear to be infected." << endl;
    }
}

int main() {
    string fileName;
    int decryptionKey = 5; 

    cout << "========================\n";
    cout << "     ANTIVIRUS TOOL     \n";
    cout << "========================\n";

    cout << "Enter the name of the .docx file to scan: ";
    cin >> fileName;

    regex docxPattern(".*\\.docx$");
    if (!regex_match(fileName, docxPattern)) {
        cout << "Error: The file must have a .docx extension." << endl;
        return 1;
    }

    if (containsVirusSignature(fileName)) {
        cout << "Virus detected in the file: " << fileName << endl;
        cout << "Attempting to clean the file..." << endl;
        cleanFile(fileName, decryptionKey);
    } else {
        cout << "No virus detected in the file: " << fileName << endl;
    }

    return 0;
}
