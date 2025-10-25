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
    auto start = high_resolution_clock::now();
    ifstream fin("codes.txt");
    string code; 
    // collects file data with vector>
    
    vector<string> codesVector;
    while (fin >> code) {
        codesVector.push_back(code); 
    }
    fin.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "duartion: " << duration.count(); 
    
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/