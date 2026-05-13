#include <sstream>
#include <string>
#include <vector>

namespace mergesort_module {

static void merge(std::vector<int>& values, std::vector<int>& buffer, size_t left, size_t middle, size_t right, long long& comparisons) {
    size_t i = left;
    size_t j = middle + 1;
    size_t k = left;

    while (i <= middle && j <= right) {
        ++comparisons;
        if (values[i] <= values[j]) {
            buffer[k++] = values[i++];
        } else {
            buffer[k++] = values[j++];
        }
    }

    while (i <= middle) {
        buffer[k++] = values[i++];
    }

    while (j <= right) {
        buffer[k++] = values[j++];
    }

    for (size_t index = left; index <= right; ++index) {
        values[index] = buffer[index];
    }
}

static void mergeSortRecursive(std::vector<int>& values, std::vector<int>& buffer, size_t left, size_t right, long long& comparisons) {
    if (left >= right) {
        return;
    }

    const size_t middle = left + (right - left) / 2;
    mergeSortRecursive(values, buffer, left, middle, comparisons);
    mergeSortRecursive(values, buffer, middle + 1, right, comparisons);
    merge(values, buffer, left, middle, right, comparisons);
}

std::vector<int> mergeSort(std::vector<int> values, long long& comparisons, size_t& extraBytes) {
    comparisons = 0;
    extraBytes = values.size() * sizeof(int);

    if (values.empty()) {
        return values;
    }

    std::vector<int> buffer(values.size());
    mergeSortRecursive(values, buffer, 0, values.size() - 1, comparisons);
    return values;
}

std::string buildMergeSortComplexity() {
    std::ostringstream out;
    out << "Merge Sort\n";
    out << "Time complexity: Best O(n log n), Average O(n log n), Worst O(n log n)\n";
    out << "Space complexity: O(n)\n";
    return out.str();
}

} // namespace mergesort_module
