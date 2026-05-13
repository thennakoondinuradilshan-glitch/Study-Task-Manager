#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace linkedlist_module {

struct Node {
    std::string task;
    std::string subject;
    std::string hours;
    std::string priority;
    Node* next;

    Node(const std::string& taskName,
         const std::string& subjectName,
         const std::string& hourValue,
         const std::string& priorityValue)
        : task(taskName), subject(subjectName), hours(hourValue), priority(priorityValue), next(nullptr) {}
};

std::string buildLinkedListReport(const std::vector<std::vector<std::string>>& tasks, const std::string& deleteTaskName) {
    std::ostringstream out;
    out << "LINKED LIST MODULE REPORT\n";
    out << "-------------------------\n";
    out << "Linked lists are used for dynamic task insertion and deletion.\n\n";

    if (tasks.empty()) {
        out << "No nodes were created.\n";
        out << "Time complexity: O(1)\n";
        out << "Space complexity: O(1)\n";
        return out.str();
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    for (const auto& task : tasks) {
        Node* node = new Node(task[0], task[1], task[2], task[3]);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    if (!deleteTaskName.empty()) {
        Node* previous = nullptr;
        Node* current = head;
        while (current) {
            if (current->task == deleteTaskName) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                if (current == tail) {
                    tail = previous;
                }
                delete current;
                break;
            }
            previous = current;
            current = current->next;
        }
    }

    out << std::left << std::setw(24) << "Task"
        << std::setw(18) << "Subject"
        << std::setw(10) << "Hours"
        << std::setw(10) << "Priority" << '\n';
    out << std::string(62, '-') << '\n';

    size_t nodeCount = 0;
    for (Node* current = head; current; current = current->next) {
        out << std::left << std::setw(24) << current->task
            << std::setw(18) << current->subject
            << std::setw(10) << current->hours
            << std::setw(10) << current->priority << '\n';
        ++nodeCount;
    }

    out << '\n';
    out << "Linked list traversal: head -> next -> next -> null\n";
    out << "Insertion complexity: O(1) at tail in this implementation.\n";
    out << "Deletion complexity: O(n) because the list may need to be searched.\n";
    out << "Space complexity: O(n) for nodes created from the task list.\n";
    out << "Approximate memory usage: about " << (nodeCount * 80) << " bytes for the node chain.\n";

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return out.str();
}

} // namespace linkedlist_module
