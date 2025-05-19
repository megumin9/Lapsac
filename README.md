# Lapsac

**Lapsac** is a static analysis tool designed to detect **logic errors in comparators** within C/C++ programs.

## 📦 Project Structure

- **`bench-hm/`** and **`bench-cm/`**  
  These are the two benchmark datasets used in our experiments.

- **`real-project/`**  
  This directory contains ten real-world open-source projects that we analyzed using Lapsac. Our tool successfully detected **19 previously unreported comparator bugs** in these projects.

- **`prompt/`**  
  This folder contains:
  - Prompts used for direct LLM-based comparator analysis
  - Prompts designed for LLM-assisted Property-Based Static Analysis (PBA) code generation

- **`static_analysis/`**  
  The core implementation of our **functional property guided static analysis**.

- **`bin/`**  
  Contains the compiled executable of the Lapsac analysis tool.

## 🚀 Usage

To analyze a file (e.g., `test.cpp`) with our custom checker, use the following command:

```bash
./bin/clang-check -analyze \
  -extra-arg=-Xanalyzer -extra-arg=-analyzer-checker=CompareCheck \
  -extra-arg=-Xclang -extra-arg=-analyzer-config \
  -extra-arg=-Xclang -extra-arg=aggressive-binary-operation-simplification=true \
  -extra-arg=-Xclang -extra-arg=-analyzer-config \
  -extra-arg=-Xclang -extra-arg=prune-path=false \
  -extra-arg=-Xclang -extra-arg=-analyzer-purge=none \
  -extra-arg=-Xanalyzer -extra-arg=-analyzer-config \
  -extra-arg=-Xanalyzer -extra-arg=prune-paths=false,suppress-c++-stdlib=true,suppress-null-return-paths=false,crosscheck-with-z3=true \
  test.cpp
