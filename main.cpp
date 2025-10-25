// COMSC210 | lab 25 | Majd Bohsali
// IDE useD: Visual Studio Code
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <list>
#include <set> 
using namespace std;
using namespace std::chrono;

int main() {
    ifstream fin("codes.txt");
    string code; 
    
    // collects file data with vector
    auto startVector = high_resolution_clock::now();
    vector<string> codesVector;
    while (fin >> code) {
        codesVector.push_back(code); 
    }
    fin.close();
    auto endVector = high_resolution_clock::now();
    auto readVectorDuration = duration_cast<milliseconds>(endVector - startVector);

    // collects file data with list
    auto startList = high_resolution_clock::now();
    list<string> codesList;
    while (fin >> code) {
        codesList.push_back(code); 
    }
    fin.close();
    auto endList = high_resolution_clock::now();
    auto readListDuration = duration_cast<milliseconds>(endList - startList);

    // collects file data with set
    auto startSet = high_resolution_clock::now();
    set<string> codesSet;
    while (fin >> code) {
        codesSet.insert(code); 
    }
    fin.close();
    auto endSet = high_resolution_clock::now();
    auto readSetDuration = duration_cast<milliseconds>(endSet - startSet);
    
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/