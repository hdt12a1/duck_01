#include <iostream>
#include <memory>

int main() {
    // Create a shared pointer to an integer
    std::shared_ptr<int> sharedInt = std::make_shared<int>(42);

    // Create a weak pointer from the shared pointer
    std::weak_ptr<int> weakInt = sharedInt;

    // Use the weak pointer to access the integer
    if (auto lockedInt = weakInt.lock()) {
        // 'lockedInt' is a shared_ptr pointing to the integer
        std::cout << "Weak pointer locked. Value: " << *lockedInt << std::endl;
    } else {
        // The object has been deleted
        std::cout << "Weak pointer is expired." << std::endl;
    }

    // Reset the shared pointer, making the object eligible for destruction
    sharedInt.reset();

    // Attempt to access the integer using the weak pointer again
    if (std::shared_ptr<int> lockedInt = weakInt.lock()) {
        std::cout << "Weak pointer locked. Value: " << *lockedInt << std::endl;
    } else {
        std::cout << "Weak pointer is expired." << std::endl;
    }

    return 0;
}
