#include <iomanip>
#include <sstream>
#include <student.hpp>

using nlohmann::json;
using namespace std;

unsigned Student::MND = 15;
unsigned Student::MGD = 8;
unsigned Student::MDD = 15;
unsigned Student::MAD = 6;

void from_json(const json& j, Student& s) {
  j.at("name").get_to(s.Name);
  Student::MND = (s.Name.size() + 2 > Student::MND)
                               ? s.Name.size() + 2
                               : Student::MND;
  if (j.at("group").is_string()) {
    j.at("group").get_to(s.Group);
  } else {
    int group = 0;
    j.at("group").get_to(group);
    s.Group = to_string(group);
  }
  Student::MGD = (s.Group.size() + 2 > Student::MGD)
                                ? s.Group.size() + 2
                                : Student::MGD;
  if (j.at("avg").is_number()) {
    double number;
    j.at("avg").get_to(number);
    stringstream ss;
    ss << std::fixed << std::setprecision(2) << number;
    s.Avg = ss.str();
  } else {
    j.at("avg").get_to(s.Avg);
  }
  Student::MAD = (s.Avg.size() + 2 > Student::MAD)
                              ? s.Avg.size() + 2
                              : Student::MAD;

  if (j.at("debt").is_string()) {
    j.at("debt").get_to(s.Debt);
  } else if (j.at("debt").is_null()) {
    s.Debt = "null";
  } else {
    vector<string> debts;
    j.at("debt").get_to(debts);
    s.Debt = to_string(debts.size()) + " items";
  }
  Student::MDD = (s.Debt.size() + 2 > Student::MDD)
                               ? s.Debt.size() + 2
                               : Student::MDD;
}

bool operator==(const Student& lhs, const Student& rhs) {
  if (lhs.Name != rhs.Name) return false;
  if (lhs.Group != rhs.Group) return false;
  if (lhs.Avg != rhs.Avg) return false;
  if (lhs.Debt != rhs.Debt) return false;
  return true;
}
