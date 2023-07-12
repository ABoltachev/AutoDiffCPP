#ifndef LIBAUTODIFF_NODES_HANDLER_TPP
#define LIBAUTODIFF_NODES_HANDLER_TPP

namespace AutoDiff {
    namespace Core {
        template<typename NodeImpl>
        void NodesHandler<NodeImpl>::registerNode(NodeImpl *node_ptr) {
            if (m_nodes_type == Node::Type::NODE) {
                m_nodes_type = node_ptr->getNodeType();
            } else if (node_ptr->getNodeType() != m_nodes_type) {
                throw IncorrectNodeType();
            }
            if (node_ptr->name().empty()) {
                switch (m_nodes_type) {
                    case Node::Type::VARIABLE:
                        node_ptr->name() = "Variable";
                        break;
                    default:
                        throw IncorrectNodeType();
                }
            }
            if (m_available_id == std::numeric_limits<uint32_t>::max()) {
                throw std::invalid_argument("Available Nodes ID limit reached");
            }
            node_ptr->name() += "/" + std::to_string(m_available_id++);

            m_nodes_dict[node_ptr->name()] = node_ptr;
        }

        template<typename NodeImpl>
        NodeImpl* NodesHandler<NodeImpl>::getNode(
            const std::string &node_name
        ) const {
            if (
                auto it = m_nodes_dict.find(node_name); it != m_nodes_dict.end()
            ) {
                return *it;
            } else {
                return nullptr;
            }
        }
    }
}

#endif // LIBAUTODIFF_NODES_HANDLER_TPP
