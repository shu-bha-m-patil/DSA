#include <iostream>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <utility>  // For std::forward

template <typename T>
class SimpleVector {
private:
    T* data;              // Pointer to the dynamic array
    size_t capacity_;     // Capacity of the vector
    size_t size_;         // Number of elements in the vector

    void reallocate(size_t new_capacity) {
        // Allocate a new array with the new capacity
        T* new_data = new T[new_capacity];

        // Copy the existing elements into the new array
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = std::move(data[i]);  // Move elements (or copy for simpler types)
        }

        // Deallocate the old array
        delete[] data;

        // Update the data pointer and capacity
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    // Default constructor
    SimpleVector() : data(nullptr), capacity_(0), size_(0) {}

    // Destructor
    ~SimpleVector() {
        delete[] data;
    }

    // Returns the number of elements in the vector
    size_t size() const {
        return size_;
    }

    // Returns the capacity of the vector
    size_t capacity() const {
        return capacity_;
    }

    // Access an element at a specific index (with bounds checking)
    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Push back a new element to the vector (copy version)
    void push_back(const T& value) {
        if (size_ == capacity_) {
            // If full, increase capacity (usually double the capacity)
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        data[size_] = value;  // Add new element
        ++size_;
    }

    // Push back a new element to the vector (move version)
    void push_back(T&& value) {
        if (size_ == capacity_) {
            // If full, increase capacity (usually double the capacity)
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        data[size_] = std::move(value);  // Move new element
        ++size_;
    }

    // Emplace back a new element to the vector (in-place construction)
    template <typename... Args>
    void emplace_back(Args&&... args) {
        if (size_ == capacity_) {
            // If full, increase capacity (usually double the capacity)
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        // Construct the element in-place at the end of the vector using perfect forwarding
        new(&data[size_]) T(std::forward<Args>(args)...);  // Direct construction
        ++size_;
    }

    // Pop the last element from the vector
    void pop_back() {
        if (size_ == 0) {
            throw std::underflow_error("Vector is empty");
        }
        --size_;
    }

    // Clear the vector (destroy all elements)
    void clear() {
        size_ = 0;
    }

    // Reserve capacity to avoid multiple reallocations
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity_) {
            reallocate(new_capacity);
        }
    }
};

int main() {
    SimpleVector<int> vec;

    // Using push_back
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // Using emplace_back for in-place construction
    vec.emplace_back(40);  // Directly constructs '40' at the end

    // Accessing elements
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Demonstrating emplace_back with more complex types
    SimpleVector<std::pair<int, std::string>> pairVec;
    pairVec.emplace_back(1, "One");   // Construct in-place (no move or copy)
    pairVec.emplace_back(2, "Two");

    for (size_t i = 0; i < pairVec.size(); ++i) {
        std::cout << pairVec[i].first << ": " << pairVec[i].second << std::endl;
    }

    return 0;
}
