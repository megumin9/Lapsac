//https://github.com/blender/blender/commit/f320724195e3ec045781d5331955be866c821b4f

bool compare_14 (const NewCollision &a, const NewCollision &b){
	if (a.first == b.first) {
		if (a.second == b.second) {
			return a.colldata < b.colldata;
		}
		return a.second < b.second;
	}
	return a.first < b.first;
}

