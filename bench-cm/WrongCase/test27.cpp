// https://github.com/cmus/cmus/commit/baee7e24be179483663c19aebed53337635ba45f

// Violation of Transitivity

int compare_27(const struct album *a, const struct album *b)
{
	int cmp = (*a->name != '<') - (*b->name != '<');

	if (cmp)
		return cmp;

	if (a->date != b->date && !a->is_compilation && !b->is_compilation)
		return a->date - b->date;

	return strcmp(a->collkey_name, b->collkey_name);
}