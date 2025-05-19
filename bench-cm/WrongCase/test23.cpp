//https://github.com/Ardour/ardour/commit/fd89d52af5ef353e787cdae621f6474c6251b908

// Violation of Anti-Symmetry 

bool compare_23(const PatchPrimaryKey& a, const PatchPrimaryKey& b){
		if (a.msb < b.msb) {
			return true;
		} else if (a.msb == b.msb && a.lsb < b.lsb) {
			return true;
		} else if (a.lsb == b.lsb && a.program_number < b.program_number) {
			return true;
		}

		return false;
	}