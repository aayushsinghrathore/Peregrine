#include "codegen.hpp"

namespace js {

void Codegen::matchArg(std::vector<ast::AstNodePtr> matchItem,
                       std::vector<ast::AstNodePtr> caseItem) {
    ast::AstNodePtr item;
    bool hasMatched = false;

    for (size_t i = 0; i < matchItem.size(); ++i) {
        item = matchItem[i];

        if (i >= caseItem.size()) {
            break;
        }

        if (caseItem[i]->type() != ast::KAstNoLiteral) {
            if (hasMatched) {
                write("&&");
            } else {
                hasMatched = true;
            }

            write("(");
            item->accept(*this);
            write("===");
            caseItem[i]->accept(*this);
            write(")");
        }
    }
}

} // namespace js