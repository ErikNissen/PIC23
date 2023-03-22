

#ifndef PIC23_GLOBALS_HPP
#define PIC23_GLOBALS_HPP

#include <string>

const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);

std::string lower(const std::string &str);

std::string upper(const std::string &str);

#endif //PIC23_GLOBALS_HPP
