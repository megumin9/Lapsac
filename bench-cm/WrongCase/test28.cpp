//https://github.com/libgeos/geos/commit/009a1c2143514dc4a75efc190117466d7d66a866

// Violation of Anti-Symmetry 

bool compare_28(const SweepLineEvent *f, const SweepLineEvent *s) 
{
  if (f->xValue < s->xValue) return true;
  if (f->eventType < s->eventType) return true;
  return false;
}