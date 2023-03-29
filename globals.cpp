

#include "globals.hpp"

std::string lower(const std::string &str){
	std::string tmp;

	for(const auto &c : str){
		tmp += static_cast<char>(std::tolower(c));
	}
	return tmp;
}

std::string upper(const std::string &str){
	std::string tmp;

	for(const auto &c : str){
		tmp += static_cast<char>(std::toupper(c));
	}
	return tmp;
}

std::string strip(std::string &str){
	while (str[str.length() - 1] == ' ' ){
		str = str.substr(0, str.length() - 1);
	}
	while (str[0] == ' ' ){
		str = str.substr(1, str.length() - 1);
	}

	return str;
}

size_t randomNumber(size_t min, size_t max){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(static_cast<double>(min),
												static_cast<double>(max));

	return round(dist(mt));
}