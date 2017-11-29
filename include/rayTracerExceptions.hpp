#include <string>
#include <sstream>
#include <exception>

class FileOpeningError : public std::runtime_error
{
    std::string mFile;
public:
    FileOpeningError(const std::string& file): mFile(file){};

    virtual const char* what() const
    {
        sstream buffer;
        buffer << "Impossible to open file " << mFile;
        return buffer.str.c_str();
    }
}

class ParsingError : public std::runtime_error
{
    virtual const char* what() const
    {
        return "Error while parsing file.";
    }
}
