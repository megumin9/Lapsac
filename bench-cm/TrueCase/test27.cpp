// https://github.com/cmus/cmus/commit/baee7e24be179483663c19aebed53337635ba45f

int compare_27(const struct album *a, const struct album *b)
{
	int cmp = (*a->name != '<') - (*b->name != '<');

	if (cmp)
		return cmp;

	cmp = a->date - b->date;
	if (cmp)
		return cmp;

	return strcmp(a->collkey_name, b->collkey_name);
}