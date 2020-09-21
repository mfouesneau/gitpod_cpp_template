#include <iostream>

int main() {
    int A[3] {3, 5, 7};
    //auto a0, a1, a2] = A;
    for (auto val : A){
        std::cout << val << " ";
    }
    std::cout << "\n";
}
