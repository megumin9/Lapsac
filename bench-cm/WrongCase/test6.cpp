//https://github.com/ripose-jp/Memento/commit/24d0f6d92cc75d3b6ad493e6199ae0e7a8129a69

// Violation of Anti-Symmetry 

bool compare_6(const SharedTerm* lhs, const SharedTerm* rhs) 
{
    if (lhs->clozeBody.size() != rhs->clozeBody.size())
    {
        return lhs->clozeBody.size() > rhs->clozeBody.size();
    }
    if (lhs->expression.size() != rhs->expression.size())
    {
        return lhs->expression.size() > rhs->expression.size();
    }
    if (lhs->conjugationExplanation.size() != rhs->conjugationExplanation.size())
    {
        return lhs->conjugationExplanation.empty() || lhs->conjugationExplanation.size() > rhs->conjugationExplanation.size();
    }
    return lhs->score > rhs->score;
}
