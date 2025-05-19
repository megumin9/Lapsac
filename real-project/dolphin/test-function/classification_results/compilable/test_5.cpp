#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using u16 = uint16_t;
using u32 = uint32_t;

struct AssemblerSettings {};
class DSPDisassembler {
public:
    explicit DSPDisassembler(const AssemblerSettings&) {}
    void DisassembleOpcode(const std::vector<u16>&, u16*, std::string&) const {}
};
struct DSPOPCTemplate { int size; };
const DSPOPCTemplate* FindOpInfoByOpcode(u16);

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool Compare(const std::vector<u16>& code1, const std::vector<u16>& code2) {
  if (code1.size() != code2.size())
    std::cout << "Size difference! 1=" << code1.size() << " 2=" << code2.size() << "\n";
  u32 count_equal = 0;
  const u16 min_size = static_cast<u16>(std::min(code1.size(), code2.size()));

  AssemblerSettings settings;
  DSPDisassembler disassembler(settings);
  for (u16 i = 0; i < min_size; i++) {
    if (code1[i] == code2[i]) {
      count_equal++;
    } else {
      std::string line1, line2;
      u16 pc = i;
      disassembler.DisassembleOpcode(code1, &pc, line1);
      pc = i;
      disassembler.DisassembleOpcode(code2, &pc, line2);
      std::cout << "!! " 
                << std::hex << std::setw(4) << std::setfill('0') << i 
                << " : " 
                << std::setw(4) << std::setfill('0') << code1[i]
                << " vs " 
                << std::setw(4) << std::setfill('0') << code2[i]
                << " - " << line1 << "  vs  " << line2 << "\n";
      std::cout << std::setfill(' ') << std::dec;

      if (i >= 1 && code1[i - 1] == code2[i - 1]) {
        const DSPOPCTemplate* opc = FindOpInfoByOpcode(code1[i - 1]);
        if (opc != nullptr && opc->size == 2) {
          line1.clear();
          line2.clear();
          pc = i - 1;
          disassembler.DisassembleOpcode(code1, &pc, line1);
          pc = i - 1;
          disassembler.DisassembleOpcode(code2, &pc, line2);
          std::cout << "   (or " 
                    << std::hex << std::setw(4) << std::setfill('0') << (i - 1)
                    << " : "
                    << std::setw(4) << std::setfill('0') << code1[i - 1]
                    << " "
                    << std::setw(4) << std::setfill('0') << code1[i]
                    << " vs "
                    << std::setw(4) << std::setfill('0') << code2[i - 1]
                    << " "
                    << std::setw(4) << std::setfill('0') << code2[i]
                    << " - " << line1 << "  vs  " << line2 << ")\n";
          std::cout << std::setfill(' ') << std::dec;
        }
      }
    }
  }
  if (code2.size() != code1.size()) {
    std::cout << "Extra code words:\n";
    const std::vector<u16>& longest = code1.size() > code2.size() ? code1 : code2;
    for (u16 i = min_size; i < longest.size(); i++) {
      u16 pc = i;
      std::string line;
      disassembler.DisassembleOpcode(longest, &pc, line);
      std::cout << "!! " 
                << std::hex << std::setw(4) << std::setfill('0') << i 
                << " : " 
                << std::setw(4) << std::setfill('0') << longest[i] 
                << " - " << line << "\n";
      std::cout << std::setfill(' ') << std::dec;
    }
  }
  std::cout << "Equal instruction words: " << count_equal << " / " << min_size << "\n";
  return code1.size() == code2.size() && code1.size() == count_equal;
}

void test1(const std::vector<u16>& a, const std::vector<u16>& b, const std::vector<u16>& c) {
  NewTest();
  if (!Compare(a, b) && !Compare(b, c) && Compare(a, c))
    ConsistencyChecker();
}

void test2(const std::vector<u16>& a, const std::vector<u16>& b, const std::vector<u16>& c) {
  NewTest();
  if (Compare(a, b) && Compare(b, c) && Compare(c, a))
    TransiveChecker();
}

void test3_1(const std::vector<u16>& a, const std::vector<u16>& b) {
  NewTest();
  if (Compare(a, b) && Compare(b, a))
    SymmetryChecker();
}

void test4(const std::vector<u16>& a) {
  NewTest();
  if (Compare(a, a))
    ReflexivityChecker();
}