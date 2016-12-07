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
    return table;
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
    output.close();
}

void kmp(string pattern, vector<string> input){
//find and output all instances of the pattern
	int* table = createTable(pattern);
	int i = 0, j = 0;
	ofstream output;
	output.open("output.txt", ios::trunc);
	
	for(int q = 0; q < input.size(); q++){
		while(i < input.at(q).size()){
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
			if(j == pattern.size()){
				output << "Line " << q + 1 << ", Position " << (i - j) + 1 << "\n";
			}
		}
		i = 0; j = 0;
	}
    delete [] table;
	output.close();
	return;
}
