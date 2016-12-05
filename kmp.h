#ifndef KMP_H
#define KMP_H
#include <string>
#include <vector>

int* createTable(std::string pattern);
void kmp(int* table, std::string pattern, vector<std::string> input);


#endif
