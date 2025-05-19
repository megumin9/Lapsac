#include <bits/stdc++.h>
using namespace std;

struct decorated_key;
struct schema_type;
struct sstable {
    const decorated_key& get_first_decorated_key() const;
};
namespace dht {
    class ring_position {
    public:
        explicit ring_position(const decorated_key& dk);
        bool less_compare(const schema_type& schema, const ring_position& other) const;
    };
}
using shared_sstable = shared_ptr<sstable>;
extern schema_type* schema;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const shared_sstable& a, const shared_sstable& b) {
    return dht::ring_position(a->get_first_decorated_key()).less_compare(*schema, dht::ring_position(b->get_first_decorated_key()));
}

void test1(const shared_sstable& a, const shared_sstable& b, const shared_sstable& c) {
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c)) 
        ConsistencyChecker();
}

void test2(const shared_sstable& a, const shared_sstable& b, const shared_sstable& c) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a)) 
        TransiveChecker();
}

void test3_1(const shared_sstable& a, const shared_sstable& b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test3_2(const shared_sstable& a, const shared_sstable& b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(const shared_sstable& a) {
    NewTest();
    if (lambda1(a, a)) 
        ReflexivityChecker();
}