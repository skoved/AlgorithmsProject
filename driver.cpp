#include "kmp.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


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
	
	return 0;
}
