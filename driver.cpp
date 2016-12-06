#include "kmp.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

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

	kmp(pattern, lines);
    bruteForce(pattern, lines);
	
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
                if(text.size() <= j+offset){
                    text = text + input[i+next];
                    next++;
                }
            }
        }
    }
}
                
