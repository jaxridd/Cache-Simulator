#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <iomanip>
#include <algorithm>

class SimpleCache {
public:
    SimpleCache(int numBlocks, int associativity);
    void access(int address);
    void displayResults();
    
private:
    int numBlocks;
    int associativity;
    int hits, misses;
    std::unordered_map<int, std::list<int>> cache;

    int getSetIndex(int address);
    void displayCacheContent(int address, int setIndex, bool isHit);
};

SimpleCache::SimpleCache(int numBlocks, int associativity)
    : numBlocks(numBlocks), associativity(associativity), hits(0), misses(0) {
    int numSets = (associativity == -1) ? 1 : numBlocks / associativity;
    for (int i = 0; i < numSets; i++) {
        cache[i] = std::list<int>();
    }
}

int SimpleCache::getSetIndex(int address) {
    if (associativity == -1) {
        return 0;
    }
    return address % (numBlocks / associativity);
}

void SimpleCache::access(int address) {
    int setIndex = getSetIndex(address);
    auto& set = cache[setIndex];
    bool isHit = false;

    typename std::list<int>::iterator it = std::find(set.begin(), set.end(), address);
    if (it != set.end()) {
        isHit = true;
        hits++;
        set.erase(it);
    } else {
        misses++;
        if (set.size() == associativity) {
            set.pop_back();
        }
    }
    set.push_front(address);
    displayCacheContent(address, setIndex, isHit);
}

void SimpleCache::displayCacheContent(int address, int setIndex, bool isHit) {
    std::cout << "Address " << address << ": " << (isHit ? "Hit" : "Miss") << " | Cache Set " << setIndex << " | Content: ";
    for (int block : cache[setIndex]) {
        std::cout << "Mem[" << block << "] ";
    }
    std::cout << std::endl;
}

void SimpleCache::displayResults() {
    double missRate = (double) misses / (hits + misses) * 100;
    std::cout << "Cache Miss Rate: " << std::fixed << std::setprecision(2) << missRate << "%" << std::endl;
}

int main() {
    int numBlocks, associativity;
    
    std::cout << "Enter number of cache blocks: ";
    std::cin >> numBlocks;
    std::cout << "Enter associativity (1 for direct-mapped, 2 for 2-way, 4 for 4-way, -1 for fully associative): ";
    std::cin >> associativity;

    SimpleCache cache(numBlocks, associativity);

    std::cout << "Enter sequence of block addresses (enter -1 to end):" << std::endl;
    while (true) {
        int address;
        std::cin >> address;
        if (address == -1) break;
        cache.access(address);
    }

    cache.displayResults();
    return 0;
}





