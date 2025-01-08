#include <iostream>
#include <string>

using namespace std;

string exitCommand = "exit 0";
string echoCommand = "echo";

int main() {
  // REPL (Read-Evaluate-Print-Loop)
  while (true) {
    // Flush after every std::cout / std:cerr
    cout << std::unitbuf;
    cerr << std::unitbuf;

    cout << "$ ";

    string input;
    getline(std::cin, input);

    // Check for exit command.
    if (input == exitCommand) {
      return 0;
    };

    string echoCheck = input.substr(0, 4);

    // Check for echo command.
    if (echoCheck == echoCommand) {
      string echo = input.substr(5, input.length() - echoCommand.length());
      cout << echo << endl;
    }
    else {
      cout << input << ": command not found" << endl;
    }
  }
}
