#include <exception>
#include <parser.hpp>

int main(int argc, char** argv) {
  if (argc != 2) {
    throw std::runtime_error{"filename incorrect"};
  }
  auto filepath = std::string{argv[1]};
  std::vector<Student> students = parse(filepath);
  Tablic(students);
}
