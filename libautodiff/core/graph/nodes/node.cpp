#include <libautodiff/core/graph/nodes/node.hpp>

namespace AutoDiff {
    namespace Core {
        Node::Node(const std::string &name) : m_name(name) {
            ; // TODO: Not implemented
        }

        Node::Node(
            const DataType &data, const std::string &name
        ) : m_data(data), m_name(name) {
            ; // TODO: Not implemented
        }

        Node::Node(
            const Node &node,
            const std::string &name
        ) : m_data(node.m_data), m_gradient(node.m_gradient), m_name(name) {
            ; // TODO: not implemented
        }

        const DataType& Node::data() const {
            return m_data;
        }

        const DataType& Node::gradient() const {
            return m_gradient;
        }

        std::string& Node::name() {
            return m_name;
        }

        const std::string& Node::name() const {
            return m_name;
        }

        template<typename... Inputs>
        DataType Node::forward_impl([[maybe_unused]] Inputs... inputs) {
            throw NotImplemented();
        }

        template<typename... Gradients>
        DataType Node::backward_impl([[maybe_unused]] Gradients... gradients) {
            throw NotImplemented();
        }

        template<typename... Inputs>
        DataType Node::forward(Inputs... inputs) {
            m_data = forward_impl(inputs...);
            return m_data;
        }

        template<typename... Gradients>
        DataType Node::backward(Gradients... gradients) {
            m_gradient = backward_impl(gradients...);
            return m_gradient;
        }
    }
}
