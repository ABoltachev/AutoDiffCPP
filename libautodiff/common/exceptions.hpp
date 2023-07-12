#ifndef AUTO_DIFF_EXCEPTIONS_H
#define AUTO_DIFF_EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace AutoDiff {
    class NotImplemented : public std::logic_error {
    public:
        NotImplemented(const std::string &msg="Function not yet implemented");
    };

    class TooManyArguments : public std::logic_error {
    public:
        TooManyArguments(const std::string &msg);
    };

    class IncorrectNodeType : public std::runtime_error {
    public:
        IncorrectNodeType(const std::string &msg="Incorrect node type");
    };
}

#endif // AUTO_DIFF_EXCEPTIONS_H
