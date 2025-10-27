#include <iostream>
#include <chrono>
#include <fstream>  
#include <string>   
#include <vector>   
#include <list>     
#include <set>
#include <algorithm> 
#include <iomanip>  
#include <iterator> 
using namespace std;
using namespace chrono;

int main() {
    vector<string> my_vector;
    list<string> my_list;
    set<string> my_set;
    string line;
    
    long long read_vector_time, read_list_time, read_set_time;
    long long sort_vector_time, sort_list_time;
    long long insert_vector_time, insert_list_time, insert_set_time;
    long long delete_vector_time, delete_list_time, delete_set_time;

    ifstream infile("codes.txt");
    if (!infile.is_open()) {
        cerr << "Error: Could not open codes.txt" << endl;
        return 1;
    }

    //race 1 reading
    auto start = high_resolution_clock::now();
    while (getline(infile, line)) {
        my_vector.push_back(line);
    }
    auto end = high_resolution_clock::now();
    read_vector_time = duration_cast<microseconds>(end - start).count();

    // reset file stream to beginning
    infile.clear();
    infile.seekg(0, ios::beg);

    // time List Read
    start = high_resolution_clock::now();
    while (getline(infile, line)) {
        my_list.push_back(line);
    }
    end = high_resolution_clock::now();
    read_list_time = duration_cast<microseconds>(end - start).count();

    // reset file stream to beginning
    infile.clear();

    start = high_resolution_clock::now();
    while (getline(infile, line)) {
        my_set.insert(line);
    }
    end = high_resolution_clock::now();
    read_set_time = duration_cast<microseconds>(end - start).count();

    infile.close();
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/