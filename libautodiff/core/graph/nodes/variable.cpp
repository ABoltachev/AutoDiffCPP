#include <libautodiff/core/graph/nodes/variable.hpp>

#include <libautodiff/core/graph/session.hpp>

namespace AutoDiff {
    namespace Core {
        Variable::Variable(const std::string &name) : Node(name) {}

        Variable::Variable(
            const DataType &data, const std::string &name
        ) : Node(data, name) {
            Session::registerNode(this);
        }

        Variable::Variable(
            const Variable &var, const std::string &name
        ) : Node(var, name) {
            Session::registerNode(this);
        }

        template<>
        DataType Variable::forward_impl<const DataType&>(
            const DataType &input
        ) {
            return input;
        }

        template<>
        DataType Variable::backward_impl<const DataType&>(
            const DataType &gradient
        ) {
            return gradient;
        }

        Node::Type Variable::getNodeType() const {
            return Node::Type::VARIABLE;
        }
    }
}
