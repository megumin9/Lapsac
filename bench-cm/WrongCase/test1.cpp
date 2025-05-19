// https://github.com/musescore/MuseScore/commit/cab5fc2412ea231555de13462f9a73274ce76dcc

// Violation of Anti-Reflexivity

bool compare_1(const Accidental* acc1, const Accidental* acc2) {
    return acc1->stackingOrder() <= acc2->stackingOrder();
}