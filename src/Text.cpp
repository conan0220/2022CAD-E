/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-10 18:32:35
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-10-17 00:51:09
 * @FilePath: \2022CAD-E\src\Text.cpp
 * @Description: This library deals with text.
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#include "Text.h"
#include <string>

namespace text
{

/**
 * Identify whether ch is number.
 * @param ch
 * @return If ch is number return true, otherwise false.
 */
bool isNumber(char ch)
{
	return 48 <= static_cast<int>(ch) && static_cast<int>(ch) <= 57;
}

/**
 * Check whether str contains target.
 * @param str The string where we find.
 * @param target The string we try to find.
 * @return If target in str return true, otherwise false.
 */
bool isTargetInString(std::string str, std::string target)
{
	return str.find(target) != std::string::npos;
}

/**
 * Load file and return the content.
 * @param filePath Relative file path. For example, "../res/testing-data.txt", "../" means jump to outer folder.
 * @return Return file's content, the type is vector<string>. The size of vector is the whole lines of file.
 */
std::vector<std::string> loadFile(std::string filePath)
{
	std::ifstream file(filePath);
	std::string lineText = "";
	std::vector<std::string> txt;
	while (std::getline(file, lineText))
	{
		txt.push_back(lineText);
	}
	file.close();
	return txt;
}

/**
 * Get data(number) in string.
 * @param str
 * @return Return the data in str which type is vector<double>. The size of vector is the number of data in str.
 */
std::vector<double> getDataFromString(std::string str)
{
	std::vector<double> ans;
	std::string temp = "";
	int i = -1;
	while (++i < str.size())
	{
		if (str[i] == '-')
		{
			temp += '-';
			i++;
		}
		// 小數點前的判斷
		while (true)
		{
			if (isNumber(str[i]))
				temp += str[i];
			else if (str[i] == '.')
			{
				temp += str[i];
				break;
			}
			else
			{
				if (temp == "-")
				{
					temp.clear();
					break;
				}
				else if (!temp.empty())
				{
					// std::cerr << std::endl << temp;
					ans.push_back(std::stof(temp));

					temp.clear();
					break;
				}
				else
					break;
			}
			i++;
		}
		if (temp.empty())
			continue;
		// 小數點後的判斷
		while (true)
		{
			i++;
			if (isNumber(str[i]))
				temp += str[i];
			else
			{
				if (temp == ".")
				{
					temp.clear();
					break;
				}
				ans.push_back(std::stof(temp));
				temp.clear();
				break;
			}
		}
	}
	return ans;
}

/**
 * Get data(number) in Text
 * @param text Text can be a article or other text set. In order to get text, you can use loadFile() import *.txt.
 * @param start which line we start to get data, default value is 0.
 * @return Return data in text which type is vector<double>. The size of vector is the whole line of text minus start.
 */
std::vector<double> getDataFromText(std::vector<std::string> text, int start)
{
	std::vector<double> ans;
	std::vector<double> temp;
	for (int i = start; i < text.size(); i++)
	{
		temp = getDataFromString(text[i]);
		ans.insert(ans.end(), temp.begin(), temp.end());
	}
	return ans;
}

}	// namespace text