#include <algorithm>
#include <array>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace arrays_module {

// ============================================================================
// ARRAY OPERATIONS - Clean implementation for array traversal, insertion,
// deletion, searching, and basic operations
// ============================================================================

/**
 * Array Traversal: Visit each element sequentially
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
std::string traverseArray(const std::vector<std::vector<std::string>>& tasks) {
    std::ostringstream out;
    out << "ARRAY TRAVERSAL OPERATION\n";
    out << "========================\n";
    out << "Visiting each element in the array sequentially...\n\n";

    if (tasks.empty()) {
        out << "Array is empty. No elements to traverse.\n";
        return out.str();
    }

    out << "Forward Traversal (Index-based):\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        out << "[" << i << "] " << tasks[i][0] << " (" << tasks[i][1] << ")\n";
    }

    out << "\nReverse Traversal:\n";
    for (int i = static_cast<int>(tasks.size()) - 1; i >= 0; --i) {
        out << "[" << i << "] " << tasks[i][0] << " (" << tasks[i][1] << ")\n";
    }

    out << "\nTraversal Summary:\n";
    out << "- Total elements visited: " << tasks.size() << "\n";
    out << "- Time complexity: O(n) where n = " << tasks.size() << "\n";
    out << "- Space complexity: O(1) - no extra space needed\n";

    return out.str();
}

/**
 * Array Insertion: Add element at specific position
 * Time Complexity: O(n) - worst case requires shifting elements
 * Space Complexity: O(n) for new array with additional element
 */
std::string insertElement(std::vector<std::vector<std::string>>& tasks,
                          const std::vector<std::string>& newTask,
                          size_t position) {
    std::ostringstream out;
    out << "ARRAY INSERTION OPERATION\n";
    out << "=========================\n";

    if (position > tasks.size()) {
        out << "ERROR: Invalid insertion position (" << position << "). ";
        out << "Array size: " << tasks.size() << "\n";
        return out.str();
    }

    out << "Inserting task: \"" << newTask[0] << "\" at position " << position << "\n";

    // Insert element
    tasks.insert(tasks.begin() + position, newTask);

    out << "\nInsertion successful!\n";
    out << "New array size: " << tasks.size() << "\n";
    out << "Time complexity: O(n) - requires shifting " << (tasks.size() - position - 1);
    out << " elements\n";
    out << "Space complexity: O(n) - new array created\n";
    out << "\nArray after insertion:\n";

    for (size_t i = 0; i < tasks.size(); ++i) {
        if (i == position) {
            out << ">>> [" << i << "] " << tasks[i][0] << " (NEW)\n";
        } else {
            out << "    [" << i << "] " << tasks[i][0] << "\n";
        }
    }

    return out.str();
}

/**
 * Array Deletion: Remove element at specific position
 * Time Complexity: O(n) - requires shifting elements
 * Space Complexity: O(n) for new array
 */
std::string deleteElement(std::vector<std::vector<std::string>>& tasks,
                          const std::string& taskName) {
    std::ostringstream out;
    out << "ARRAY DELETION OPERATION\n";
    out << "========================\n";
    out << "Deleting task: \"" << taskName << "\"\n\n";

    auto it = std::find_if(tasks.begin(), tasks.end(),
                           [&taskName](const auto& task) { return task[0] == taskName; });

    if (it == tasks.end()) {
        out << "ERROR: Task not found in array.\n";
        out << "Deletion failed.\n";
        return out.str();
    }

    size_t deletionIndex = std::distance(tasks.begin(), it);
    tasks.erase(it);

    out << "Deletion successful!\n";
    out << "Deleted from index: " << deletionIndex << "\n";
    out << "Previous array size: " << (tasks.size() + 1) << "\n";
    out << "New array size: " << tasks.size() << "\n";
    out << "Time complexity: O(n) - requires shifting remaining elements\n";
    out << "Space complexity: O(n) - new array created\n";

    if (!tasks.empty()) {
        out << "\nArray after deletion:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            out << "[" << i << "] " << tasks[i][0] << "\n";
        }
    } else {
        out << "\nArray is now empty.\n";
    }

    return out.str();
}

/**
 * Array Searching: Find element by criteria
 * Time Complexity: O(n) - linear search
 * Space Complexity: O(1)
 */
std::string searchArray(const std::vector<std::vector<std::string>>& tasks,
                        const std::string& searchTerm) {
    std::ostringstream out;
    out << "ARRAY SEARCH OPERATION\n";
    out << "======================\n";
    out << "Searching for: \"" << searchTerm << "\"\n\n";

    std::vector<size_t> foundIndices;

    // Linear search through array
    for (size_t i = 0; i < tasks.size(); ++i) {
        // Search in task name
        if (tasks[i][0].find(searchTerm) != std::string::npos) {
            foundIndices.push_back(i);
        }
        // Search in subject
        else if (tasks[i][1].find(searchTerm) != std::string::npos) {
            foundIndices.push_back(i);
        }
    }

    out << "Search Results:\n";
    if (foundIndices.empty()) {
        out << "No matches found. " << tasks.size() << " elements scanned.\n";
        out << "Time complexity: O(n) - all elements checked\n";
    } else {
        out << "Found " << foundIndices.size() << " match(es):\n\n";
        for (size_t idx : foundIndices) {
            out << "[" << idx << "] " << tasks[idx][0] << " | Subject: "
                << tasks[idx][1] << " | Hours: " << tasks[idx][2]
                << " | Priority: " << tasks[idx][3] << "\n";
        }
        out << "\nTime complexity: O(n) - searched all elements\n";
    }

    out << "Space complexity: O(1) - only storing indices\n";
    return out.str();
}

/**
 * Array Access: Direct element retrieval by index
 * Time Complexity: O(1) - constant time random access
 * Space Complexity: O(1)
 */
std::string accessElement(const std::vector<std::vector<std::string>>& tasks,
                          size_t index) {
    std::ostringstream out;
    out << "ARRAY ACCESS OPERATION\n";
    out << "======================\n";
    out << "Accessing element at index: " << index << "\n\n";

    if (index >= tasks.size()) {
        out << "ERROR: Index out of bounds. Array size: " << tasks.size() << "\n";
        out << "Time complexity: O(1) - access attempt\n";
        return out.str();
    }

    const auto& task = tasks[index];
    out << "Element found!\n";
    out << "Task: " << task[0] << "\n";
    out << "Subject: " << task[1] << "\n";
    out << "Hours: " << task[2] << "\n";
    out << "Priority: " << task[3] << "\n";
    out << "\nTime complexity: O(1) - direct memory access\n";
    out << "Space complexity: O(1) - no extra space needed\n";

    return out.str();
}

/**
 * Generate comprehensive array report with all operations
 * Main function called by backend
 */
std::string generateArrayReport(const std::vector<std::vector<std::string>>& tasks) {
    std::ostringstream out;
    const std::array<std::string, 7> weekdays = {
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
    };

    out << "╔════════════════════════════════════════════════════════════════╗\n";
    out << "║              ARRAYS MODULE - COMPREHENSIVE REPORT             ║\n";
    out << "╚════════════════════════════════════════════════════════════════╝\n\n";

    out << "ARRAY FUNDAMENTALS\n";
    out << "──────────────────\n";
    out << "• Fixed-size contiguous memory allocation\n";
    out << "• O(1) random access using index\n";
    out << "• Used for: weekday slots, subject lists, task durations\n";
    out << "• Current array size: " << tasks.size() << " elements\n";
    out << "• Approximate memory: " << (tasks.size() * 96) << " bytes\n\n";

    if (tasks.empty()) {
        out << "STATUS: Empty array\n";
        out << "No study tasks were provided.\n";
        out << "Time complexity: O(1)\n";
        out << "Space complexity: O(1)\n";
        return out.str();
    }

    // Create a copy for manipulation during operations
    std::vector<std::vector<std::string>> workingTasks = tasks;

    // Sort by priority (descending) then hours (ascending)
    std::stable_sort(workingTasks.begin(), workingTasks.end(),
                     [](const auto& left, const auto& right) {
                         const int leftPriority = std::stoi(left[3]);
                         const int rightPriority = std::stoi(right[3]);
                         if (leftPriority != rightPriority) {
                             return leftPriority > rightPriority;
                         }
                         const int leftHours = std::stoi(left[2]);
                         const int rightHours = std::stoi(right[2]);
                         return leftHours < rightHours;
                     });

    // Weekly Schedule Table
    out << "WEEKLY SCHEDULE (Sorted by Priority)\n";
    out << "────────────────────────────────────\n";
    out << std::left << std::setw(14) << "Day"
        << std::setw(22) << "Subject"
        << std::setw(26) << "Task"
        << std::setw(10) << "Hours"
        << std::setw(10) << "Priority" << '\n';
    out << std::string(82, '─') << '\n';

    for (size_t index = 0; index < workingTasks.size(); ++index) {
        const auto& task = workingTasks[index];
        const std::string& day = task.size() > 4 && !task[4].empty()
                                     ? task[4]
                                     : weekdays[index % weekdays.size()];
        out << std::left << std::setw(14) << day
            << std::setw(22) << task[1]
            << std::setw(26) << task[0]
            << std::setw(10) << task[2]
            << std::setw(10) << task[3] << '\n';
    }

    // Array-based study sequence
    out << "\n\nARRAY-BASED STUDY SEQUENCE\n";
    out << "──────────────────────────\n";
    for (size_t index = 0; index < weekdays.size(); ++index) {
        out << "├─ " << weekdays[index] << " slot ready for study planning\n";
    }

    // Performance Summary
    out << "\n\nPERFORMANCE ANALYSIS\n";
    out << "────────────────────\n";
    out << "Array Operations Time Complexity:\n";
    out << "  • Traversal:  O(n) for visiting all " << tasks.size() << " elements\n";
    out << "  • Access:     O(1) for direct index lookup\n";
    out << "  • Insertion:  O(n) worst case (element shifting required)\n";
    out << "  • Deletion:   O(n) worst case (element shifting required)\n";
    out << "  • Searching:  O(n) linear search through array\n";
    out << "  • Sorting:    O(n log n) for priority-based ordering\n\n";

    out << "Memory Usage:\n";
    out << "  • Space complexity: O(n) for storing " << tasks.size() << " tasks\n";
    out << "  • Approximate bytes: " << (tasks.size() * 96 + weekdays.size() * sizeof(std::string))
        << " bytes\n";

    return out.str();
}

} // namespace arrays_module
