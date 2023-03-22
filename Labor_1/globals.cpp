

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