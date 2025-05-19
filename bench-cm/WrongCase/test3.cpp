//https://github.com/glandium/firefox/commit/ab87644a3632e75df8b8be180349d34557d2b13f

//Violation of Anti-Reflexivity

int compare_3(const AuthChallenge& lhs, const AuthChallenge& rhs) {
  if (lhs.rank != rhs.rank) {
    return lhs.rank < rhs.rank ? 1 : -1;
  }

  if (lhs.rank != ChallengeRank::Digest) {
    return 0;
  }

  if (lhs.algorithm == 0 || rhs.algorithm == 0) {
    return 0;
  }

  return lhs.algorithm < rhs.algorithm ? 1 : -1;
}