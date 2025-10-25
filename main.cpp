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

double timeVectorRead(vector<string>& codesVector);
double timeListRead(list<string>& codesList);
double timeSetRead(set<string>& codesSet);
int main() {
    ifstream fin("codes.txt");
    string code; 
    
    // collects file data with vector
    vector<string> codesVector;
    double vectorReadTime = timeVectorRead(codesVector);
    // collects file data with list
    list<string> codesList;
    double listReadTime = timeListRead(codesList);
    // collects file data with set
    set<string> codesSet;
    double setReadTime = timeSetRead(codesSet);
    return 0;
}

double timeVectorRead(vector<string>& codesVector) { 
    ifstream fin("codes.txt");
    string code; 
    auto start = high_resolution_clock::now();
    while (fin >> code) {
        codesVector.push_back(code); 
    }
    fin.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeListRead(list<string>& codesList) { 
    ifstream fin("codes.txt");
    string code; 
    auto start = high_resolution_clock::now();
    while (fin >> code) {
        codesList.push_back(code); 
    }
    fin.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeSetRead(set<string>& codesSet) { 
    ifstream fin("codes.txt");
    string code; 
    auto start = high_resolution_clock::now();
    while (fin >> code) {
        codesSet.insert(code); 
    }
    fin.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}
