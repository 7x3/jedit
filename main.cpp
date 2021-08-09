#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "globals.h"

using namespace std;



enum Commands {
        q,
        i,
        p,
        error
    };

Commands resolveOption(std::string input) {
    if( input == "q" ) return q;
    if( input == "i" ) return i;
    if( input == "p" ) return p;

    return error;
}


int typing() {
    string current_line;
    while(true) {
        cin >> current_line;
        if(current_line == ".") {
            break;
        }
        file_contents.append("\n" + current_line);
    }
    return 1;
}

string loop() {
    string current_command;
    bool continue_program = true;
    while(continue_program) {
        cout << prompt_character;
        cin >> current_command;
        switch (resolveOption(current_command))
        {
            case q:
            continue_program = false;
                break;
            case i:
                typing();
            case p:
                cout << file_contents << endl;
                break;
        
            default:
                printf("Error: %s is not a command\n", current_command.c_str());
                break;
        }
    }
    return "";
}

int main(int argc, char *argv[]) {
    ofstream file;
    ifstream file_read;

    if(argv[1] == NULL) {
        cout << "Error: No file given" << endl;
        exit(0);
    }

    file_read.open(argv[1]);
    file.open(argv[1], std::ios_base::app | std::ios_base::in);
    string line;
    if (file_read.is_open()) {
        while ( getline (file_read, line) ) {
            file_contents = file_contents + line;
        }
    }

    loop();

    if(file.is_open()) {
        file.write(file_contents.data(), file_contents.size());
    } else {
        cout << "Error writing file" << endl;
    }
    
    file.close();
    return 0;
}