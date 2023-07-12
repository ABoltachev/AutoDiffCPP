#ifndef LIBAUTODIFF_NODE_H
#define LIBAUTODIFF_NODE_H

#include <string>
#include <vector>

#include <libautodiff/common/macros.hpp>
#include <libautodiff/common/exceptions.hpp>

#include <libautodiff/core/graph/data.hpp>

namespace AutoDiff {
    namespace Core {
        class LIBAUTODIFF_API Node {
        protected:
            DataType m_data = 0;
            DataType m_gradient = 1;
            std::string m_name;

            const DataType& data() const;

            const DataType& gradient() const;

            template<typename... Inputs>
            DataType forward_impl(Inputs... inputs);

            template<typename... Gradients>
            DataType backward_impl(Gradients... gradients);

            explicit Node(const std::string &name="");

            explicit Node(
                const DataType &data,
                const std::string &name=""
            );

            explicit Node(
                const Node &node,
                const std::string &name=""
            );
        public:
            enum class Type {
                NODE,
                VARIABLE
            };

            std::string& name();

            const std::string& name() const;

            virtual Type getNodeType() const = 0;

            template<typename... Inputs>
            DataType forward(Inputs... inputs);

            template<typename... Gradients>
            DataType backward(Gradients... gradients);
        };
    }
}

#endif // LIBAUTODIFF_NODE_H
