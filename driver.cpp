#include "kmp.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv){//read input and setup for kmp
	ifstream infile;
	string pattern = argv[2];
	vector<string> lines;
	string line;
    infile.open(argv[1]);
    if(!infile){
        lines.push_back(argv[1]);
    }
    else{
        while(getline(infile, line)){
            lines.push_back(line);
        }
    }
    //timing for brute force search
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    bruteForce(pattern, lines);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    
    cout<<"Brute Force Search"<<endl;
    cout<<"Pattern: "<<pattern<<endl;
    cout<<"Time: "<<duration<<endl;
    cout<<endl;


    //timing for kmp search
    t1 = high_resolution_clock::now(); 
	kmp(pattern, lines);
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    
    cout<<"KMP Search"<<endl;
    cout<<"Pattern: "<<pattern<<endl;
    cout<<"Time: "<<duration<<endl;
    cout<<endl;
	
	return 0;
}


                
