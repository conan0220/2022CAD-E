#ifndef _TEXT_H_
#define _TEXT_H_

#include <iostream>
#include <fstream>
#include <vector>

bool isNumber(char ch);
bool isTargetInString(std::string str, std::string target);

std::vector<std::string> loadFile(std::string filePath = "");
std::vector<double> getDataFromString(std::string str);
std::vector<double> getDataFromText(std::vector<std::string> text, int start = 0);

#endif /* _TEXT_H_ */