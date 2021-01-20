#ifndef LAB01_PARSER_H
#define LAB01_PARSER_H

#include <iostream>
#include <student.hpp>
#include <vector>

void Tablic(const std::vector<Student>& V,
                      std::ostream& out = std::cout);
std::vector<Student> parse(const std::string& filename);

#endif 
