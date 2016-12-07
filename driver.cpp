#include "kmp.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bruteForce(string pattern, vector<string> input);

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

void bruteForce(string pattern, vector<string> input){//brute force algorithm for finding a subsequence
    ofstream output;
    output.open("output2.txt", ios::trunc);
    for(int i = 0; i < input.size(); i++){
        string text = input[i];//gets the next line of input
        for(int j = 0; j < text.size(); j++){
            int next = 1;
            for(int offset = 0; pattern[offset] == text[j+offset]; offset++){
                if(offset == pattern.size()-1){
                    output<<"Line "<< i+1 <<", Position "<< j+1 <<endl;
                    break;
                }
            }
        }
    }
}
                
