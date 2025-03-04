#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// ANSI codes for Colors and Styles
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string BG_BLACK = "\033[40m";

// Basic necessary Functions
void displayMenu();
void clearScreen();
void printHeader();
void handleWrite();
void handleRead();
void handleAppend();
void pressEnterToContinue();

int main() {
    int choice;
    do {
        clearScreen();
        printHeader();
        displayMenu();

        //Here, the user need to enter the choice base on their needs
        cout << BOLD << "┃ " << CYAN << "Enter your choice: " << RESET;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice) {
            case 1:
                handleWrite();
                break;
            case 2:
                handleRead();
                break;
            case 3:
                handleAppend();
                break;
            case 4:
                clearScreen();
                cout << BOLD << GREEN << "\n  Goodbye! Thanks for using File Handler.\n" << RESET;
                break;
            default:
                cout << RED << "  Invalid choice! Please try again." << RESET;
                pressEnterToContinue();
        }
    } while(choice != 4);

    return 0;
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

//This part is used here for styling the selection menu
void printHeader() {
    cout << BOLD << BLUE 
         << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
         << "┃        " << MAGENTA << "  FILE HANDLER  " << BLUE << "        ┃\n"
         << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" 
         << RESET;
}

void displayMenu() {
    cout << BOLD << YELLOW
         << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
         << "┃          " << CYAN << " MAIN MENU " << YELLOW << "           ┃\n"
         << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
         << "┃ 1. Write to a new file         ┃\n"
         << "┃ 2. Read from a file            ┃\n"
         << "┃ 3. Append to an existing file  ┃\n"
         << "┃ 4. Exit                        ┃\n"
         << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
         << RESET;
}

//This below is the code for writing data into the file - the file will be created and the data will be stored into it
void handleWrite() {
    clearScreen();
    printHeader();
    
    string filename, content;
    cout << BOLD << GREEN << "┏━━━━━━━━━━ WRITE MODE ━━━━━━━━━━┓\n" << RESET;
    cout << BOLD << "┃ Enter filename: " << CYAN;
    getline(cin, filename);
    
    ofstream file(filename);
    if(!file) {
        cout << RED << "┃ Error creating file!" << RESET;
        pressEnterToContinue();
        return;
    }

    cout << BOLD << "┃ Enter content (type 'END' on new line to finish):\n" << RESET;
    cout << GREEN << "┃ " << RESET;
    while(getline(cin, content) && content != "END") {
        file << content << "\n";
        cout << GREEN << "┃ " << RESET;
    }

    file.close();
    cout << BOLD << GREEN << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
    cout << GREEN << "  File written successfully!\n" << RESET;
    pressEnterToContinue();
}

//This below is the code for reading data from the file
void handleRead() {
    clearScreen();
    printHeader();
    
    string filename, line;
    cout << BOLD << GREEN << "┏━━━━━━━━━━ READ MODE ━━━━━━━━━━━┓\n" << RESET;
    cout << BOLD << "┃ Enter filename: " << CYAN;
    getline(cin, filename);
    
    ifstream file(filename);
    if(!file) {
        cout << RED << "┃ Error opening file!" << RESET;
        pressEnterToContinue();
        return;
    }

    cout << BOLD << MAGENTA << "\n┏━━━━━━━━ FILE CONTENT ━━━━━━━━━┓\n";
    while(getline(file, line)) {
        cout << "┃ " << CYAN << line << "\n";
    }
    cout << MAGENTA << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" << RESET;
    file.close();
    pressEnterToContinue();
}

//This below is the code for adding data into a file - also referred to as 'Append' in technical terms
void handleAppend() {
    clearScreen();
    printHeader();
    
    string filename, content;
    cout << BOLD << GREEN << "┏━━━━━━━━━ APPEND MODE ━━━━━━━━━━┓\n" << RESET;
    cout << BOLD << "┃ Enter filename: " << CYAN;
    getline(cin, filename);
    
    ofstream file(filename, ios::app);
    if(!file) {
        cout << RED << "┃ Error opening file!" << RESET;
        pressEnterToContinue();
        return;
    }

    cout << BOLD << "┃ Enter content to append (type 'END' on new line to finish):\n" << RESET;
    cout << GREEN << "┃ " << RESET;
    while(getline(cin, content) && content != "END") {
        file << content << "\n";
        cout << GREEN << "┃ " << RESET;
    }

    file.close();
    cout << BOLD << GREEN << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
    cout << GREEN << "  Content appended successfully!\n" << RESET;
    pressEnterToContinue();
}

void pressEnterToContinue() {
    cout << RESET << BOLD << YELLOW << "\n  Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
