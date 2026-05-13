#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

namespace bubblesort_module {

std::vector<int> bubbleSort(std::vector<int> values, long long& comparisons, long long& swaps) {
    comparisons = 0;
    swaps = 0;

    const size_t size = values.size();
    for (size_t outer = 0; outer < size; ++outer) {
        bool changed = false;
        for (size_t inner = 0; inner + 1 < size - outer; ++inner) {
            ++comparisons;
            if (values[inner] > values[inner + 1]) {
                std::swap(values[inner], values[inner + 1]);
                ++swaps;
                changed = true;
            }
        }
        if (!changed) {
            break;
        }
    }

    return values;
}

std::string buildBubbleSortComplexity() {
    std::ostringstream out;
    out << "Bubble Sort\n";
    out << "Time complexity: Best O(n), Average O(n^2), Worst O(n^2)\n";
    out << "Space complexity: O(1)\n";
    return out.str();
}

} // namespace bubblesort_module
