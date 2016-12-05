#include "kmp.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int* createTable(string pattern){//create backtracking table
    return nullptr;
}

void kmp(string pattern, vector<string> input){
//find and output all instances of the pattern
	int* table = createTable(pattern);
	int i = 0, j = 0;
	ofstream output;
	output.open("output.txt", ios::trunc);
	for(int q = 0; q < input.size(); q++){
		while(i < input.at(q).size() && j < pattern.size()){
			if(input.at(q)[i] == pattern[j]){
				i++;
				j++;
			}
			else{
				if(j!=0){
					j = table[j -1];
				}
				else{
					i++;
				}
			}
		}
		if(j == pattern.size()){
			output << "Line " << q << ", Position " << i - j << "\n";
		}
		i = 0; j = 0;
	}
	return;
}
