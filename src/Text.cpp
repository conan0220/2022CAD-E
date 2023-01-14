/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-10 18:32:35
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-12-08 19:22:15
 * @FilePath: \2022CAD-E\src\Text.cpp
 * @Description: This library deals with text.
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#include "Text.h"
#include <string>
#include <regex>

namespace text
{

/**
 * For example "-1.4" -> true, ".34" -> true, "abc" -> false, "-3.33-" -> false, "3.3.3" -> false, "." -> false.
 * @param str std::string type.
 * @return Is numeric or not?
 */
bool isNumeric(const std::string& str)
{
	if (std::count(str.begin(), str.end(),'.') > 1 || (str.size() == 1 && str == "."))
		return false;
	else
    	return std::regex_match(str, std::regex("[(-|+)|][0-9|.]+"));
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
	// std::vector<double> datas;
	// std::string data_str;
	// for (const char& ch : str)
	// {	// ab.7-7.3
	// 	data_str += ch;
	// 	if (data_str.size() == 1 && !isNumeric(data_str) && data_str[0] != '.')
	// 	{
	// 		data_str.pop_back();
	// 	}
	// 	else if (data_str.size() > 1 && !isNumeric(data_str))
	// 	{
	// 		data_str.pop_back();
	// 		datas.push_back(std::stod(data_str));
	// 		data_str.clear();
	// 	}
	// }

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
			if (std::isdigit(str[i]))
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
			if (std::isdigit(str[i]))
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

/**
 * Write text to the file.
 * @param text A text.
 * @param filePath File path.
 * @return None
 */
void writeFile(const std::vector<std::string>& text, std::string filePath)
{
	std::ofstream ofs;

	ofs.open(filePath);

	for (const std::string& str : text)
	{
		ofs << str << std::endl;
	}

	ofs.close();
}

}	// namespace text