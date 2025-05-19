//https://github.com/blender/blender/commit/f320724195e3ec045781d5331955be866c821b4f

//Violation of Anti-Symmetry 

bool compare_14(const NewCollision &a, const NewCollision &b){
	return a.first < b.first || a.second < b.second || a.colldata < b.colldata;
}