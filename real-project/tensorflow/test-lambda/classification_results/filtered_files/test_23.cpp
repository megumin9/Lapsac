#include <vector>
#include <algorithm>

struct Origin {
    const std::vector<int>& elements() const;
};

struct IndexDomain {
    Origin origin() const;
};

struct IndexDomainDevice {
    IndexDomain index_domain;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const IndexDomainDevice& a, const IndexDomainDevice& b) {
  return std::lexicographical_compare(
      a.index_domain.origin().elements().begin(),
      a.index_domain.origin().elements().end(),
      b.index_domain.origin().elements().begin(),
      b.index_domain.origin().elements().end());
}

void test1(const IndexDomainDevice& a, const IndexDomainDevice& b, const IndexDomainDevice& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const IndexDomainDevice& a, const IndexDomainDevice& b, const IndexDomainDevice& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const IndexDomainDevice& a, const IndexDomainDevice& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const IndexDomainDevice& a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}