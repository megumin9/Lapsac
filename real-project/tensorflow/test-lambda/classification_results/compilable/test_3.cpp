#include <vector>
#include <algorithm>
#include <cstdint>

namespace absl {
class Status {
public:
  Status() = default;
  Status(const Status&) = default;
  Status& operator=(const Status&) = default;
};

Status FailedPreconditionError(const char*) {
  return Status();
}
}  // namespace absl

class FieldIndex {
public:
  bool has_field() const;
  bool has_index() const;
  bool has_map_key() const;
  uint32_t field() const;
  uint64_t index() const;
};

class Message {
public:
  int chunk_index() const;
};

class ChunkedField {
public:
  const std::vector<FieldIndex>& field_tag() const;
  const Message& message() const;
};

absl::Status sort_status;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(ChunkedField cf1, ChunkedField cf2) {
  int tag_depth =
      std::min(cf1.field_tag().size(), cf2.field_tag().size());
  for (int depth = 0; depth < tag_depth; ++depth) {
    FieldIndex tag1 = cf1.field_tag()[depth];
    FieldIndex tag2 = cf2.field_tag()[depth];
    if (tag1.has_field() && tag2.has_field()) {
      uint32_t field1 = tag1.field();
      uint32_t field2 = tag2.field();
      if (field1 != field2) return field1 < field2;
    } else if (tag1.has_index() && tag2.has_index()) {
      uint64_t index1 = tag1.index();
      uint64_t index2 = tag2.index();
      if (index1 != index2) return index1 < index2;
    } else if (tag1.has_map_key() && tag2.has_map_key()) {
      return false;
    } else {
      sort_status = absl::FailedPreconditionError("Field tag mismatch");
      return false;
    }
  }
  if (cf1.field_tag().size() == cf2.field_tag().size()) {
    return cf1.message().chunk_index() < cf2.message().chunk_index();
  }
  return cf1.field_tag().size() < cf2.field_tag().size();
}

void test1(ChunkedField a, ChunkedField b, ChunkedField c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) 
    ConsistencyChecker();
}

void test2(ChunkedField a, ChunkedField b, ChunkedField c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) 
    TransiveChecker();
}

void test3_1(ChunkedField a, ChunkedField b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) 
    SymmetryChecker();
}

void test3_2(ChunkedField a, ChunkedField b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) 
    SymmetryChecker();
}

void test4(ChunkedField a) {
  NewTest();
  if (lambda0(a, a)) 
    ReflexivityChecker();
}