#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> ParseLine(string line) {
    vector<int> result;
    stringstream ss(line);
    int number;

    while (ss >> number) {
        result.push_back(number);
    }

    return result;
}

int main() {
    string input = "1 2 3 4";
    vector<int> nums = ParseLine(input);

    for (int n : nums) {
        cout << n << " ";
    }

    return 0;
}