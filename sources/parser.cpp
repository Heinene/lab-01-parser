#include <fstream>
#include <iomanip>
#include <parser.hpp>
#include <string>

void Tablic(const std::vector<Student>& V, std::ostream& out) {
  out << "| "
      << "name" << std::string(Student::MND - 5, ' ') << "| "
      << "group" << std::string(Student::MGD - 6, ' ') << "| "
      << "avg" << std::string(Student::MAD - 4, ' ') << "| "
      << "debt" << std::string(Student::MDD - 5, ' ') << "|\n";
  out << '|' << std::string(Student::MND, '-') << '|'
      << std::string(Student::MGD, '-') << '|'
      << std::string(Student::MAD, '-') << '|'
      << std::string(Student::MDD, '-') << "|\n";
  for (const Student& s : V) {
    out << "| " << s.Name
        << std::string(Student::MND - s.Name.size() - 1, ' ') << "| "
        << s.Group
        << std::string(Student::MGD - s.Group.size() - 1, ' ')
        << "| " << s.Avg
        << std::string(Student::MAD - s.Avg.size() - 1, ' ') << "| "
        << s.Debt
        << std::string(Student::MDD - s.Debt.size() - 1, ' ')
        << "|\n";
    out << '|' << std::string(Student::MND, '-') << '|'
        << std::string(Student::MGD, '-') << '|'
        << std::string(Student::MAD, '-') << '|'
        << std::string(Student::MDD, '-') << "|\n";
  }
}

std::vector<Student> parse(const std::string& filename) {
  std::ifstream file{filename};
  if (!file) {
    throw std::runtime_error{"unable to open json: " + filename};
  }

  nlohmann::json data;
  file >> data;

  if (!data.at("items").is_array()) {
    throw std::invalid_argument{"item in" + filename + "should be array"};
  }

  if (data.at("items").size() != data.at("_meta").at("count")) {
    throw std::invalid_argument(
        "count from _meta should be equal to items length");
  }

  std::vector<Student> students;
  for (auto const& student : data.at("items")) {
    students.push_back(Student(student));
  }

  return students;
}
