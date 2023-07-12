#include <libautodiff/core/graph/session.hpp>

namespace AutoDiff {
    namespace Core {
        Session *Session::m_instance = nullptr;

        Session* Session::openSession(const std::string &name) {
            if (m_instance == nullptr) {
                m_instance = new Session(name);
            }

            return m_instance;
        }

        bool Session::isOpen() {
            return m_instance != nullptr;
        }

        void Session::registerNode(Node *node) {
            if (!isOpen()) {
                openSession();
            }
            switch (node->getNodeType()) {
                case Node::Type::VARIABLE:
                    m_instance->m_variables_handler.registerNode(
                        dynamic_cast<Variable*>(node)
                    );
                    break;
                default:
                    throw IncorrectNodeType();
            }
        }

        void Session::closeSession() {
            delete m_instance;
        }

        Session::~Session() {
            m_instance = nullptr;
        }
    }
}
