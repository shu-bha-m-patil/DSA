#include <iostream>
#include <vector>
#include <algorithm> // For sort, reverse, find, unique, etc.

void demonstrateVectorOperations() {
    std::cout << "=== Complete Vector Operations Demo ===\n";

    // 1. Constructors
    std::cout << "\n--- Constructors ---\n";
    std::vector<int> defaultVec; // Default constructor
    std::vector<int> fillVec(5, 10); // Fill constructor
    std::vector<int> rangeVec(fillVec.begin(), fillVec.end()); // Range constructor
    std::vector<int> copyVec(fillVec); // Copy constructor

    std::cout << "Fill constructor vector: ";
    for (const auto& val : fillVec) std::cout << val << " ";
    std::cout << "\n";

    // 2. Adding and Removing Elements
    std::cout << "\n--- Adding and Removing Elements ---\n";
    std::vector<int> vec;
    vec.push_back(10); // Add at the end
    vec.push_back(20);
    vec.emplace_back(30); // In-place construction
    vec.insert(vec.begin(), 5); // Insert at the beginning
    vec.insert(vec.begin() + 1, 2, 15); // Insert multiple elements
    vec.pop_back(); // Remove the last element
    vec.erase(vec.begin() + 1); // Remove second element
    vec.erase(vec.begin(), vec.begin() + 2); // Remove a range

    std::cout << "After adding and removing elements: ";
    for (const auto& val : vec) std::cout << val << " ";
    std::cout << "\n";

    // 3. Accessing Elements
    std::cout << "\n--- Accessing Elements ---\n";
    vec = {10, 20, 30, 40, 50};
    std::cout << "  First element: " << vec.front() << "\n";
    std::cout << "  Last element: " << vec.back() << "\n";
    std::cout << "  Element at index 2: " << vec.at(2) << "\n";

    // 4. Size and Capacity
    std::cout << "\n--- Size and Capacity ---\n";
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n";

    vec.reserve(10);
    std::cout << "After reserving capacity for 10 elements, Capacity: " << vec.capacity() << "\n";

    vec.shrink_to_fit();
    std::cout << "After shrinking, Capacity: " << vec.capacity() << "\n";

    // 5. Iterators
    std::cout << "\n--- Iterators ---\n";
    std::cout << "Using iterators to traverse: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "Using reverse iterators: ";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << "\n";

    // 6. Algorithms
    std::cout << "\n--- Algorithms ---\n";
    std::vector<int> algoVec = {5, 2, 9, 1, 5, 6, 9, 1};
    
    // Sort
    std::sort(algoVec.begin(), algoVec.end());
    std::cout << "Sorted vector: ";
    for (const auto& val : algoVec) std::cout << val << " ";
    std::cout << "\n";

    // Reverse
    std::reverse(algoVec.begin(), algoVec.end());
    std::cout << "Reversed vector: ";
    for (const auto& val : algoVec) std::cout << val << " ";
    std::cout << "\n";

    // Find
    auto it = std::find(algoVec.begin(), algoVec.end(), 5);
    if (it != algoVec.end()) {
        std::cout << "Element 5 found at position: " << std::distance(algoVec.begin(), it) << "\n";
    } else {
        std::cout << "Element 5 not found\n";
    }

    // Unique
    algoVec.erase(std::unique(algoVec.begin(), algoVec.end()), algoVec.end());
    std::cout << "After removing consecutive duplicates: ";
    for (const auto& val : algoVec) std::cout << val << " ";
    std::cout << "\n";

    // Clear
    algoVec.clear();
    std::cout << "After clearing, size: " << algoVec.size() << "\n";

    // 7. Miscellaneous Functions
    std::cout << "\n--- Miscellaneous Functions ---\n";
    vec = {1, 2, 3, 4, 5};
    std::cout << "Original vector: ";
    for (const auto& val : vec) std::cout << val << " ";
    std::cout << "\n";

    // Swap
    std::vector<int> otherVec = {10, 20, 30};
    vec.swap(otherVec);
    std::cout << "After swap, vec: ";
    for (const auto& val : vec) std::cout << val << " ";
    std::cout << "\n";

    // Data
    int* dataPtr = otherVec.data();
    std::cout << "Accessing elements using data pointer: ";
    for (size_t i = 0; i < otherVec.size(); ++i) {
        std::cout << *(dataPtr + i) << " ";
    }
    std::cout << "\n";
}

int main() {
    demonstrateVectorOperations();
    return 0;
}
