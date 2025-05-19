// https://github.com/arvidn/libtorrent/commit/356332a93b95d32a31383c55ed902770e8fdd4ff

// Violation of Anti-Reflexivity

bool compare_20(peer_connection const* lhs, peer_connection const* rhs) {
    bool lhs_connecting = lhs->is_connecting() && !lhs->is_disconnecting();
    bool rhs_connecting = rhs->is_connecting() && !rhs->is_disconnecting();

    if (lhs_connecting > rhs_connecting) return false;
		if (lhs_connecting < rhs_connecting) return true;

    return lhs->connected_time() >= rhs->connected_time();
}