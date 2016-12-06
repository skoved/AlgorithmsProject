#include "kmp.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int* createTable(string pattern){//create backtracking table
    if(pattern.size() == 0)   
        return NULL;
    int* table = new int[pattern.size()];
    int j = 0;
    table[0] = 0;
    bool flag = false;
    for(int i=1; i<pattern.size();){
        if(pattern[j] == pattern[i]){
            table[i] = j+1;
            i++;
            j++;
        }
        else{
            if(j != 0)
                j = table[j-1];
            else{
                table[i] = 0;
                i++;
            }
        }
    }
    for(int i=0; i<pattern.size(); i++)
        cout<<table[i]<<" ";
    return table;
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
