#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <nlohmann/json.hpp>
#include <string>

struct Student {
  std::string Name;
  std::string Group;
  std::string Avg;
  std::string Debt;

  static unsigned MND;
  static unsigned MGD;
  static unsigned MAD;
  static unsigned MDD;
};

void from_json(const nlohmann::json& j, Student& s);
bool operator==(const Student& lhs, const Student& rhs);

#endif  // INCLUDE_HEADER_HPP_
