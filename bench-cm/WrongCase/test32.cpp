// https://github.com/marbl/canu/commit/24ac48bf16693de683c15f14410b363b396fca1d

// Violation of Anti-Symmetry 

bool compare_32(Olap_Info_t const &a, Olap_Info_t const &b) {
    if (a.b_iid < b.b_iid)      return(true);
    if (a.b_iid > b.b_iid)      return(false);

    if (a.a_iid < b.a_iid)      return(true);
    if (a.a_iid > b.a_iid)      return(false);

    //  It is possible, but unlikely, to have two overlaps to the same pair of reads,
    //  if we overlap a5'-b3' and a3'-b5'.  I think.

    return(a.innie != b.innie);
}