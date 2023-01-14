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
 * Extracts numeric values from a string and returns them as a vector.
 *
 * @param input The string to extract values from.
 * @return A vector containing all extracted numeric values.
 */

std::vector<double> extractNumeric(const std::string& input) 
{
  std::vector<double> values;
  std::regex pattern("(-?\\d+\\.?\\d*)");
  std::smatch matches;

  // 查找字串中所有符合的值
  std::string::const_iterator search_start(input.cbegin());
  while (std::regex_search(search_start, input.cend(), matches, pattern)) 
  {
    // 將匹配到的結果轉換為 double 並存入 vector
    values.push_back(std::stod(matches[1].str()));
    // 設定下一次搜尋的位置
    search_start = matches.suffix().first;
  }

  return values;
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
		temp = extractNumeric(text[i]);
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