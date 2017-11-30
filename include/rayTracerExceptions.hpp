#include <string>
#include <sstream>
#include <exception>

struct FileOpeningError : public std::runtime_error
{
    explicit FileOpeningError(const std::string& file):
        runtime_error(std::string("Impossible to open file ") + file)
    {}
};

struct ParsingError : public std::runtime_error
{
    ParsingError():
        runtime_error("Error while parsing file.")
    {}
};