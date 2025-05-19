#include <bits/stdc++.h>

struct schema;
struct decorated_key;

namespace dht {
class ring_position {
public:
    explicit ring_position(const decorated_key&);
    bool less_compare(const schema&, const dht::ring_position&) const;
};
} // namespace dht

class sstable {
public:
    const decorated_key& get_first_decorated_key() const;
};

using shared_sstable = std::shared_ptr<sstable>;

extern schema* schema;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const shared_sstable& a, const shared_sstable& b) {
    return dht::ring_position(a->get_first_decorated_key()).less_compare(*schema, dht::ring_position(b->get_first_decorated_key()));
}

void test1(const shared_sstable& a, const shared_sstable& b, const shared_sstable& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const shared_sstable& a, const shared_sstable& b, const shared_sstable& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const shared_sstable& a, const shared_sstable& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const shared_sstable& a, const shared_sstable& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const shared_sstable& a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}