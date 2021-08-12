using namespace std;

//Access to the files
ofstream file;
ifstream file_read;

//A buffer used to hold the text to be inserted
string text_to_write;

//Holds the text of the file in various states of modification
string file_contents;
string file_contents_original;
string file_contents_appended;

//Sets the character used to show a prompt
string prompt_character = ":";
