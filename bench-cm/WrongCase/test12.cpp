//https://github.com/facebook/hhvm/commit/c399e910f3fbf79acdd310e2f3485e25014901d1

// Violation of Anti-Symmetry 


bool compare_12(const BlockScopePtr &b1, const BlockScopePtr &b2) {
    if (auto d = b1->getStmt()->getRange().compare(b2->getStmt()->getRange())) {
        return d; 
    }
    return b1->getContainingFile()->getName() < b2->getContainingFile()->getName();
}