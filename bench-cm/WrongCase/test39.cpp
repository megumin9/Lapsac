// https://github.com/ashkulz/NppFTP/commit/06cd30dff2fe4d04a8ad8045d3394c3c5dab0470

// Violation of Consistency

bool compare_39(const FileObject * fo1, const FileObject * fo2) {
	int res = 0;
	if (fo1->isDir() != fo2->isDir()) {
		res = fo1->isDir()?false:true;
	} else {
		res = lstrcmpiA(fo1->GetPath(), fo2->GetPath());
	}
	return (res < 0);
}