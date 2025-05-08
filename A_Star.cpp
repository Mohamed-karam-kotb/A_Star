#include "A_Star.hpp"
namespace A_Star_Algorithm {

// string CellString(State state);
//  Overload operator<< to use CellString
/*
std::ostream& operator<<(std::ostream& os,State state) {
    os << std::setw(4) << CellString(state);
    return os ;
}
*/

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
  } else {
    cerr << "Error: Could not open file " << path << endl;
  }
  return board;
}
bool Compare(const vector<int> &node1, const vector<int> &node2) {
  return node1[2] + node1[3] > node2[2] + node2[3];
}
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}
int Heuristic(const int &x1, const int &y1, const int &x2, const int &y2){
  return abs(x2 - x1) + abs(y2 - y1);

}

bool IsValidCoord(int x, int y, vector<vector<State>> &grid,
                  bool verbose = false) {
  bool res = true;
  if (x < 0 || x >= grid.size()) {
    if (verbose)
      cout << "x coord is invalid" << endl;
    res = false;
  }
  if (y < 0 || y >= grid[0].size()) {
    if (verbose)
      cout << "y coord is invalid" << endl;
    res = false;
  }
  return res;
}
bool CheckValidCell(int x, int y, vector<vector<State>> &grid) {
  if (!IsValidCoord(x, y, grid))
    return false;
  if (grid[x][y] == State::kEmpty)
    return true;
  return false;
}
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist,
               vector<vector<State>> &grid) {
  vector<int> node{x, y, g, h};
  openlist.push_back(node);
  grid[x][y] = State::kClosed;
}
void ExpandNeighbors(const vector<int> &currentNode, int goal[2],
                     vector<vector<int>> &openlist,
                     vector<vector<State>> &grid) {
  int x = currentNode[0];
  int y = currentNode[1];
  int g = currentNode[2];

  for (int i = 0; i < 4; i++) {
    int newX = x + delta[i][0];
    int newY = y + delta[i][1];
    if (CheckValidCell(newX, newY, grid)) {
      int h = Heuristic(newX, newY, goal[0], goal[1]);
      AddToOpen(newX, newY, g + 1, h, openlist, grid);
    }
  }
}
vector<vector<State>> Search(vector<vector<State>> grid, int init[2],int goal[2]){
                        
  vector<vector<int>> openlist{};

  // Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);

  // Use AddToOpen to add the starting node to the openlist vector.
  AddToOpen(x, y, g, h, openlist, grid);

  // while openlist vector is non empty {
  while (!openlist.empty()) {
      // Sort the openlist using CellSort, and get the current node.
      CellSort(&openlist);  // pass the address since the function needs a pointer
      vector<int> currentNode = openlist.back();
      openlist.pop_back();

      // Get the x and y values from the current node, and set grid[x][y] to kPath.
      int curX = currentNode[0];
      int curY = currentNode[1];
      grid[curX][curY] = State::kPath;

      // Check if you've reached the goal. If so, return grid.
      if (curX == goal[0] && curY == goal[1]) {
          grid[init[0]][init[1]] = State::kStart;
          grid[goal[0]][goal[1]] = State::kFinish;
          return grid;
      }

      // If we're not done, expand search to current node's neighbors. This step will be completed in a later quiz.
      ExpandNeighbors(currentNode, goal, openlist, grid);
  }

  // We've run out of new nodes to explore and haven't found a path.
  cout << "No path found!\n";
  return vector<vector<State>>{};
}

string CellString(State cell) {
  switch (cell) {
      case State::kObstacle:
          return "x   ";
      case State::kPath:
          return "*   ";
      case State::kStart:
          return "i   ";
      case State::kFinish:
          return "G   ";
      default:
          return "0   ";
  }
}
/* this require operator overloaded because cell is a State type and cout doen't know how to print enum class type 
void PrintBoard(const vector<vector<State>> &board) {
  for (const auto &row : board) {
    for (const auto& cell : row) {
      cout << cell;
    }
    cout << "\n";
  }
}
*/
void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
          cout << CellString(board[i][j]);
      }
      cout << "\n";
  }
}
} // namespace A_Star_Algorithm


