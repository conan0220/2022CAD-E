#include "Text.h"
#include <string>

/*
 * Description: identify whether char is number
 * Parameters: ch(char)
 * ch -> target
 */
bool isNumber(char ch)
{
	return 48 <= static_cast<int>(ch) && static_cast<int>(ch) <= 57;
}

/*
 * Description: check if string contains target
 * Parameters: str(string), target(string)
 * str -> the string
 * target -> the string we try to find
 */
bool isTargetInString(std::string str, std::string target)
{
	return str.find(target) != std::string::npos;
}

/*
 * Description: load file and return text(vector<string>)
 * Parameters: filePath(string)
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

/*
 * Description: return doubles in string
 * Parameters: str(string)
 * str -> target
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

/*
 * Description: get data in text and return data(vector<double>)
 * Parameters: text(string), start(int)
 * 	text -> use loadFile() to get text
 * 	start -> where start to get data depending on line number
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