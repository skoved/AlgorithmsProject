#ifndef KMP_H
#define KMP_H
#include <string>
#include <vector>

int* createTable(std::string pattern);
void kmp(std::string pattern, std::vector<std::string> input);


#endif
