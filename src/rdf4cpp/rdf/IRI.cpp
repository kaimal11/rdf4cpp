#include "IRI.hpp"

namespace rdf4cpp::rdf {

IRI::IRI(Node::NodeBackendHandle handle) : Node(handle) {}
IRI::IRI() : Node(NodeBackendHandle{{}, storage::node::identifier::RDFNodeType::IRI, {}}) {}
IRI::IRI(std::string_view iri, Node::NodeStorage &node_storage)
    : Node(NodeBackendHandle{node_storage.find_or_make_id(storage::node::view::IRIBackendView{.identifier = iri}),
                             storage::node::identifier::RDFNodeType::IRI,
                             node_storage.id()}) {}

IRI::operator std::string() const { return handle_.iri_backend().n_string(); }

bool IRI::is_literal() const { return false; }
bool IRI::is_variable() const { return false; }
bool IRI::is_blank_node() const { return false; }
bool IRI::is_iri() const { return true; }


IRI IRI::default_graph(NodeStorage &node_storage) {
    return IRI("", node_storage);
}
std::ostream &operator<<(std::ostream &os, const IRI &iri) {
    os << (std::string) iri;
    return os;
}
const std::basic_string_view<char> IRI::identifier() const {
    return handle_.iri_backend().identifier;
}

}  // namespace rdf4cpp::rdf