#include "kmp.h"
#include <vector>
#include <string>
using namespace std;

int* createTable(string pattern){//create backtracking table
    if(pattern.length() == 0)   
        return nullptr;
    int* table = new int[pattern.length()];
    int j = 0;
    table[0] = 0;
    for(int i=1; i<pattern.length(); i++){
        while(pattern[i] != pattern[j]){
            if(j == 0){
                break;
            }
            else{
                j = table[j-1];
            }
        }
        table[i] = table[j]+1;
        j++;
    }
    return table;
}

void kmp(int* table, string pattern, vector<string> input){//find and output all instances of the pattern
    return;
}
