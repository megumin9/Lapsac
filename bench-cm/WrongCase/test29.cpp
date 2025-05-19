//https://github.com/cms-sw/cmssw/commit/759b084b2152815337e39d74311fc41668936d31

// Violation of Anti-Reflexivity

bool compare_29(const SiPixelCluster& one, const SiPixelCluster& other) {
    if (one.geographicalId() < other.geographicalId()) {
        return true;
    } else if (one.geographicalId() > other.geographicalId()) {
        return false;
    } else if (one.minPixelRow() < other.minPixelRow()) {
        return true;
    } else if (one.minPixelRow() > other.minPixelRow()) {
        return false;
    } else if (one.minPixelCol() <= other.minPixelCol()) {
        return true;
    } else {
        return false;
    }
}