#include <iostream>
#include <string>

using namespace std;

string exitCommand = "exit 0";
string echoCommand = "echo ";

int main() {
  cout << "$ ";
  string input;
  
  // REPL (Read-Evaluate-Print-Loop)
  while (getline(cin, input) && input.find(exitCommand) != 0) {
    // Flush after every std::cout / std:cerr
    cout << std::unitbuf;
    cerr << std::unitbuf;

    // TODO: Create helper function for builtins
    if (input.find(echoCommand) == 0) {
      string echo = input.substr(echoCommand.length());
      cout << echo << endl;
    } else {
      cout << input << ": command not found" << endl;
    }

    cout << "$ ";
  }
}
