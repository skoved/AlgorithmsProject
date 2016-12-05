#include "kmp.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
    //read input and setup for kmp
	ifstream infile(argv[1]);
	vector<string> lines;
	string line;
	while(getline(infile, line)){
		lines.push_back(line);
	}
	
	return 0;
}
