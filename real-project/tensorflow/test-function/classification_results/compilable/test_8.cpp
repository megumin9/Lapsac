#include <tuple>
#include <cstdint>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

struct NodeItem;
struct InputFrame;
struct InputIter;

struct TaggedNode {
    NodeItem* node_item;
    InputFrame* input_frame;
    InputIter* input_iter;
};

struct NodeItem {
    int node_id;
};

struct InputFrame {
    uint64_t frame_id;
};

struct InputIter {
    int64_t iter_num;
};

bool compare(TaggedNode const& lhs, TaggedNode const& rhs) {
    std::tuple<int, uint64_t, int64_t> lhs_prio{lhs.node_item->node_id,
                                              lhs.input_frame->frame_id,
                                              lhs.input_iter->iter_num};
    std::tuple<int, uint64_t, int64_t> rhs_prio{rhs.node_item->node_id,
                                              rhs.input_frame->frame_id,
                                              rhs.input_iter->iter_num};
    return lhs_prio < rhs_prio;
}

void test1(const TaggedNode& a, const TaggedNode& b, const TaggedNode& c) {
    NewTest();
    if (!compare(a,b) && !compare(b,c) && compare(a,c))
        ConsistencyChecker();
}

void test2(const TaggedNode& a, const TaggedNode& b, const TaggedNode& c) {
    NewTest();
    if (compare(a,b) && compare(b,c) && compare(c,a))
        TransiveChecker();
}

void test3_1(const TaggedNode& a, const TaggedNode& b) {
    NewTest();
    if (compare(a,b) && compare(b,a))
        SymmetryChecker();
}

void test3_2(const TaggedNode& a, const TaggedNode& b) {
    NewTest();
    if (compare(a,b) && compare(b,a))
        SymmetryChecker();
}

void test4(const TaggedNode& a) {
    NewTest();
    if (compare(a, a))
        ReflexivityChecker();
}