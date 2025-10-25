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
double timeVectorInsert(vector<string>& codesVector);
double timeListInsert(list<string>& codesList);
double timeSetInsert(set<string>& codesSet);

const int W = 10;
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

    // insert to vector
    double vectorInsertTime = timeVectorInsert(codesVector);
    // insert to list
    double listInsertTime = timeListInsert(codesList);
    // insert to set
    double setInsertTime = timeSetInsert(codesSet);

    // print results to console
    cout << right << setw(W) << "Operation" << setw(W) << "Vector" << setw(W) << "List" << setw(W) << "Set" << endl;
    cout << right << setw(W) << "Read" << setw(W) << vectorReadTime << setw(W) << listReadTime << setw(W) << setReadTime << endl;
    cout << right << setw(W) << "Sort" << setw(W) << vectorSortTime << setw(W) << listSortTime << setw(W) << setSortTime << endl;
    cout << right << setw(W) << "Insert" << setw(W) << vectorInsertTime << setw(W) << listInsertTime << setw(W) << setInsertTime << endl;
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

double timeVectorInsert(vector<string>& codesVector) {
    auto start = high_resolution_clock::now();
    auto it = codesVector.begin(); 
    int middleElement = codesVector.size()/2; 
    codesVector.insert(it + middleElement, "TESTCODE");
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeListInsert(list<string>& codesList) {
    auto start = high_resolution_clock::now();
    //codesList.insert((codesList.begin() + codesList.end()) / 2, "TESTCODE");
    auto it = codesList.begin(); 
    int middleElement = codesList.size()/2; 
    advance(it, middleElement); 
    codesList.insert(it, "TESTCODE");  
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeSetInsert(set<string>& codesSet) {
    auto start = high_resolution_clock::now();
    codesSet.insert("TESTCODE");
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}