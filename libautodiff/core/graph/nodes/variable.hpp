#ifndef LIBAUTODIFF_VARIABLE_H
#define LIBAUTODIFF_VARIABLE_H

#include <string>

#include <libautodiff/common/macros.hpp>

#include <libautodiff/core/graph/data.hpp>
#include <libautodiff/core/graph/nodes/node.hpp>
#include <libautodiff/core/graph/nodes/nodes_handler.hpp>

namespace AutoDiff {
    namespace Core {
        class LIBAUTODIFF_API Variable : public Node {
        protected:
            explicit Variable(
                const std::string &name=""
            );

            template<typename Input>
            DataType forward_impl(Input input);

            template<typename Gradient>
            DataType backward_impl(Gradient gradient);
        public:
            Variable(
                const DataType &data,
                const std::string &name=""
            );

            Variable(
                const Variable &var,
                const std::string &name=""
            );

            Node::Type getNodeType() const final;

            friend void NodesHandler<Variable>::registerNode(Variable*);
        };
    }
}

#endif // LIBAUTODIFF_VARIABLE_H
