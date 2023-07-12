#include <libautodiff/common/exceptions.hpp>

namespace AutoDiff {
    NotImplemented::NotImplemented(
        const std::string &msg
    ) : std::logic_error(msg) {}

    TooManyArguments::TooManyArguments(
        const std::string &msg
    ) : std::logic_error(msg) {}

    IncorrectNodeType::IncorrectNodeType(
        const std::string &msg
    ) : std::runtime_error(msg) {}
}
