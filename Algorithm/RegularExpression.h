#pragma once

#include <iostream>
#include <regex>
#include <string>

using namespace std;

std::string regexReplace(const std::string& input, const std::string& pattern,
	const std::string& replacement) {
	std::regex regexPattern(pattern);  // 
		return std::regex_replace(input, regexPattern, replacement);  // 
}

void Express()
{
	string input = "이름2_AO";
	
	std::string pattern = R"(^(.*?)_)";
	std::string replacement = "T_$1_";

	string result = regexReplace(input, pattern, replacement);

	cout << "변경된 파일 이름 : " << result << endl;
}