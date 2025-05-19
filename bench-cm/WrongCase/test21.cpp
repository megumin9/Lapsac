//https://github.com/vcmi/vcmi/commit/e9e311f1428c22c6a1420e3f50813d5552c42da7

// Violation of Anti-Reflexivity

bool compare_21(const CGPathNode * lhs, const CGPathNode * rhs)
{
    if (rhs->turns > lhs->turns)
        return false;
    if (rhs->turns == lhs->turns && rhs->moveRemains < lhs->moveRemains)
        return false;

    return true;
}