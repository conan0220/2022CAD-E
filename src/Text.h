#ifndef _TEXT_H_
#define _TEXT_H_

#include <iostream>
#include <fstream>
#include <vector>

namespace text
{
bool isNumeric(const std::string& str);

bool isTargetInString(std::string str, std::string target);

std::vector<std::string> loadFile(std::string filePath = "");
std::vector<double> extractNumeric(const std::string& input);
std::vector<double> getDataFromText(std::vector<std::string> text, int start = 0);

void writeFile(const std::vector<std::string>& text, std::string filePath);

}   // namespace text
#endif /* _TEXT_H_ */