/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-10 18:32:35
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-12-11 00:29:10
 * @FilePath: /2022CAD-E/src/Text.h
 * @Description: This library deals with text.
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
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