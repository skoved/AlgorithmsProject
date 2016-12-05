#ifndef KMP_H
#define KMP_H
#include <string>

int* createTable(std::string pattern);
void kmp(int* table, std::string pattern, vector<std::string> input);


#endif
