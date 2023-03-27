#ifndef PIC23_GLOBALS_HPP
#define PIC23_GLOBALS_HPP

#pragma once

#include <string>
#include <sstream>
#include <array>
#include <cstdlib>

const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);

#ifndef _WIN32
const auto RESET{"\033[0m"};
const auto BLACK{"\033[0;30m"};
const auto RED{"\033[0;31m"};
const auto GREEN{"\033[0;32m"};
const auto YELLOW{"\033[0;33m"};
const auto BLUE{"\033[0;34m"};
const auto MAGENTA{"\033[0;35m"};
const auto CYAN{"\033[0;36m"};
const auto WHITE{"\033[0;37m"};
const auto BOLD{"\033[1m"};
const auto UNDERLINE{"\033[4m"};
const auto INVERSE{"\033[7m"};
#elif defined(_WIN32)
const auto BOLD{""};
const auto RESET{""};
const auto BLACK{""};
const auto RED{""};
const auto GREEN{""};
const auto YELLOW{""};
const auto BLUE{""};
const auto MAGENTA{""};
const auto CYAN{""};
const auto WHITE{""};
#endif



std::string lower(const std::string &str);

std::string upper(const std::string &str);

std::string strip(std::string &str);

#endif //PIC23_GLOBALS_HPP
