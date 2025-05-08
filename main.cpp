#include "A_Star.hpp"
using namespace A_Star_Algorithm;
int main() {
    string boardFile;
    //boardFile="1.board";
    bool emptyFile = false;
    vector<vector<State>> board;
    do {
        cout << "Enter the path to the text file: ";
        cin >> boardFile;
        cout << endl;
        board = ReadBoardFile(boardFile);
        if (board.empty() || board[0].empty())
            emptyFile = true;
        else
            emptyFile = false;
    } while (emptyFile);

    int xInit, yInit, xGoal, yGoal;
    do {
        cout << "Enter the x-coordinate of the starting point: ";
        cin >> xInit;
        cout << endl
             << "Enter the y-coordinate of the starting point: ";
        cin >> yInit;
        cout << endl;
    } while (!IsValidCoord(xInit, yInit, board, true));

    do {
        cout << "Enter the x-coordinate of ending point: ";
        cin >> xGoal;
        cout << endl
             << "Enter the y-coordinate of ending point: ";
        cin >> yGoal;
        cout << endl;
    } while (!IsValidCoord(xGoal, yGoal, board, true));

    int init[2]{xInit, yInit};
    int goal[2]{xGoal, yGoal};

    auto solution = Search(board, init, goal);
    PrintBoard(solution);
    return 0;
}