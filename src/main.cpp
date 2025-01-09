#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <unordered_set>

using namespace std;

// List of commands
struct Commands {
    static constexpr const char* echo = "echo";
    static constexpr const char* exit = "exit";
    static constexpr const char* type = "type";
};

struct CommandPrefixes {
  static constexpr const char* echo = "echo ";
  static constexpr const char* exit = "exit 0";
  static constexpr const char* type = "type ";
};

unordered_set<string> CommandsSet {
  "echo",
  "exit",
  "type",
};

void handleInput(string input) {
  // Get first word
  string cmd;

  stringstream ss(input);
  ss >> cmd;

  // C++ doesn't support string switch statements, use if else
  if (cmd == Commands::echo) {
    string echo = input.substr(strlen(CommandPrefixes::echo));
    cout << echo << endl;
  }
  else if (cmd == Commands::type) {
    string type = input.substr(strlen(CommandPrefixes::type));

    // Verify type exists
    if (CommandsSet.find(type) != CommandsSet.end()) {
      cout << type << " is a shell builtin" << endl;
    }
    else {
      cout << type << ": not found" << endl;
    }
  }
  else {
    cout << input << ": command not found" << endl;
  }

  // Else, print invalid command
  cout << "$ ";
} 

int main() {
  cout << "$ ";
  string input;
  
  // REPL (Read-Evaluate-Print-Loop)
  while (getline(cin, input) && input.find(CommandPrefixes::exit) != 0) {
    // Flush after every std::cout / std:cerr
    cout << std::unitbuf;
    cerr << std::unitbuf;

    handleInput(input);
  }
}
