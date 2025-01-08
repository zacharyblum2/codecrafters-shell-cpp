#include <iostream>
#include <string>

using namespace std;

string exitString = "exit 0";

int main() {
  // REPL (Read-Evaluate-Print-Loop)
  while (true) {
    // Flush after every std::cout / std:cerr
    cout << std::unitbuf;
    cerr << std::unitbuf;

    cout << "$ ";

    string input;
    getline(std::cin, input);

    if (input == exitString) {
      return 0;
    }

    cout << input << ": command not found" << endl;
  }
}
