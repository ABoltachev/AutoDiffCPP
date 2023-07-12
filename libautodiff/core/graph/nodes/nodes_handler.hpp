#ifndef LIBAUTODIFF_NODES_HANDLER_H
#define LIBAUTODIFF_NODES_HANDLER_H

#include <limits>
#include <map>
#include <string>

#include <libautodiff/common/exceptions.hpp>
#include <libautodiff/common/macros.hpp>
#include <libautodiff/core/graph/nodes/node.hpp>

namespace AutoDiff {
    namespace Core {
        template<typename NodeImpl>
        class NodesHandler {
        private:
            std::map<std::string, NodeImpl*> m_nodes_dict {};
            uint32_t m_available_id = 0;
            Node::Type m_nodes_type = Node::Type::NODE;
        public:
            NodesHandler(const NodesHandler&) = delete;

            NodesHandler(NodesHandler&&) = delete;

            void registerNode(NodeImpl *node_ptr);

            NodeImpl* getNode(const std::string &node_name) const;
        };
    }
}

#include <libautodiff/core/graph/nodes/nodes_handler.tpp>

#endif // LIBAUTODIFF_NODES_HANDLER_H
