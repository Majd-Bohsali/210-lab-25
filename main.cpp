// COMSC210 | lab 25 | Majd Bohsali
// IDE useD: Visual Studio Code
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <list>
#include <set> 
#include <algorithm>
using namespace std;
using namespace std::chrono;

double timeVectorRead(vector<string>& codesVector);
double timeListRead(list<string>& codesList);
double timeSetRead(set<string>& codesSet);
double timeVectorSort(vector<string>& codesVector);
double timeListSort(list<string>& codesList);
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

    // sorts vector
    double vectorSortTime = timeVectorSort(codesVector);
    // sorts list
    double listSortTime = timeListSort(codesList);
    // sort set
    double setSortTime = -1; // set is already sorted

    // print results to console
    cout << right << setw(10) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    cout << right << setw(10) << "Read" << setw(10) << vectorReadTime << setw(10) << listReadTime << setw(10) << setReadTime << endl;
    cout << right << setw(10) << "Sort" << setw(10) << vectorSortTime << setw(10) << listSortTime << setw(10) << setSortTime << endl;
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

double timeVectorSort(vector<string>& codesVector) {
    auto start = high_resolution_clock::now();
    sort(codesVector.begin(), codesVector.end());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeListSort(list<string>& codesList) {
    auto start = high_resolution_clock::now();
    codesList.sort();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}