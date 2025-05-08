#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::abs;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;
using namespace std;
namespace A_Star_Algorithm{
    enum class State { kEmpty, kObstacle, kClosed, kPath, kStart, kFinish };
    const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<State> ParseLine(string line);
    vector<vector<State>> ReadBoardFile(string path);
    bool Compare(const vector<int> &node1, const vector<int> &node2);
    void CellSort(vector<vector<int>> *v);
    int Heuristic(const int &x1, const int &y1, const int &x2, const int &y2);
    bool IsValidCoord(int x, int y, vector<vector<State>> &grid, bool verbose);
    bool CheckValidCell(int x, int y, vector<vector<State>> &grid);
    void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid);
    void ExpandNeighbors(const vector<int> &currentNode, int goal[2], vector<vector<int>> &openlist, vector<vector<State>> &grid);
    vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]);
    string CellString(State cell);
    void PrintBoard(const vector<vector<State>> board);

}
