#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using namespace std;
enum class State { kEmpty, kObstacle };
string CellString(State state);
// Overload operator<< to use CellString
std::ostream& operator<<(std::ostream& os,State state) {
    os << std::setw(4) << CellString(state);
    return os ;
}


vector<State> ParseLine(string line) {
  istringstream sline(line);
  vector<State> row;
  int n;
  char c;
  while (sline >> n >> c && c == ',') {

    switch (n) {
    case 0:
      row.push_back(State::kEmpty);
      break;
    case 1:
      row.push_back(State::kObstacle);
      break;
    }
  }
  return row;
}
vector<vector<State>> ReadBoardFile(string path) {
  vector<vector<State>> board{};
  ifstream myfile(path);

  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
    return board;
  } else {
    cerr << "Error: Could not open file " << path << endl;
    return {};
  }
}
string CellString(State state) {
  switch (state) {
  case State::kEmpty:
    return " 0  ";
    break;
  case State::kObstacle:
    return " ⛰  ";
    break;
  default:
    return "? ";
  }
}

void PrintBoard(const vector<vector<State>> &board) {
  for (const auto &row : board) {
    for (const auto& cell : row) {
      cout << cell;
    }
    cout << "\n";
  }
}

int main() {
  auto board = ReadBoardFile("board.txt");
  PrintBoard(board);
}
