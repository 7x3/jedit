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
        h,
        error
    };

Commands resolveOption(std::string input) {
    if( input == "q" ) return q;
    if( input == "i" ) return i;
    if( input == "p" ) return p;
    if( input == "h" ) return h;

    return error;
}

void giveHelp() {
    printf("Commands:\ni: Insert text into the document\np: Prints the contents of the document including what you have typed\nq: Saves and quits\nh: Shows this help screen\n");
}

void printFileToScreen(string del = "\n") {
    file_contents_appended = file_contents_original + text_to_write;
    printf("%s", file_contents_appended.c_str());
}


int typing() {
    string current_line;
    bool discard_line = true;

    while(true) {
        getline(cin, current_line);
        if(current_line == ".") {
            break;
        }
        if(discard_line == true) {
            current_line = "";
        } else {
            text_to_write.append(current_line.append("\n"));
        }
        discard_line = false;
    }

    return 1;
}

void loop() {
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
                printFileToScreen();
                break;
            case h:
                giveHelp();
                break;
            default:
                printf("Error: %s is not a command\n", current_command.c_str());
                break;
        }
    }
}

int main(int argc, char *argv[]) {

    if(argv[1] == NULL) {
        cout << "Error: No file given" << endl;
        exit(0);
    }

    file_read.open(argv[1]);
    file.open(argv[1], std::ios_base::app | std::ios_base::in);
    string line;
    if (file_read.is_open()) {
        while ( getline (file_read, line, '\n') ) {
            file_contents.append(line + "\n");
        }
    }
    file_contents_original = file_contents;

    loop();

    if(file.is_open()) {
        //file.write(file_contents.data(), file_contents.size());
        if(file_contents_original != "" && text_to_write == "") {
         file << endl;      
        }
        file << text_to_write;
    } else {
        cout << "Error writing file" << endl;
    }

    file.close();
    return 0;
}