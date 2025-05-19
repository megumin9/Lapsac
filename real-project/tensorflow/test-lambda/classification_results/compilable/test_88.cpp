#include <tuple>
#include <vector>

struct HloInstruction;
struct Shape;
struct DeviceInfo;

Shape GetInputShapeForMultiOutputFusion(const HloInstruction&, const DeviceInfo&);
int GetInstrCountOfFusible(const HloInstruction&);
extern DeviceInfo device_info;

struct HloInstruction {
    int unique_id() const;
};

struct Shape {
    int rank() const;
    const std::vector<int>& dimensions() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const HloInstruction* a, const HloInstruction* b) {
    Shape shape_a = GetInputShapeForMultiOutputFusion(*a, device_info);
    Shape shape_b = GetInputShapeForMultiOutputFusion(*b, device_info);
    auto tuple_for_op = [](const Shape& shape, const HloInstruction* op) {
        return std::tuple<int, const std::vector<int>&, int, int>{shape.rank(), shape.dimensions(), GetInstrCountOfFusible(*op), op->unique_id()};
    };
    return tuple_for_op(shape_a, a) < tuple_for_op(shape_b, b);
}

void test1(const HloInstruction* a, const HloInstruction* b, const HloInstruction* c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
        ConsistencyChecker();
    }
}

void test2(const HloInstruction* a, const HloInstruction* b, const HloInstruction* c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
        TransiveChecker();
    }
}

void test3_1(const HloInstruction* a, const HloInstruction* b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) {
        SymmetryChecker();
    }
}

void test4(const HloInstruction* a) {
    NewTest();
    if (lambda0(a, a)) {
        ReflexivityChecker();
    }
}