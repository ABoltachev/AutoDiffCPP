#ifndef LIBAUTODIFF_SESSION_H
#define LIBAUTODIFF_SESSION_H

#include <string>
#include <map>

#include <libautodiff/common/macros.hpp>

#include <libautodiff/core/graph/nodes/node.hpp>
#include <libautodiff/core/graph/nodes/nodes_handler.hpp>
#include <libautodiff/core/graph/nodes/variable.hpp>

namespace AutoDiff {
    namespace Core {
        class LIBAUTODIFF_API Session {
        private:
            std::string m_name;

            static Session *m_instance;

            NodesHandler<Variable> m_variables_handler;

            Session(const std::string &name="Default session");
        public:
            Session(const Session&) = delete;
            void operator=(const Session&) = delete;

            static Session* openSession(const std::string &name="Default session");

            static bool isOpen();

            static void registerNode(Node *node);

            static void closeSession();

            ~Session();
        };
    }
}

#endif // LIBAUTODIFF_SESSION_H
