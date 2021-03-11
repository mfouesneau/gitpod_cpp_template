#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include "example.hpp"

int main() {
    int A[3] {3, 5, 7};
    //auto a0, a1, a2] = A;
    for (auto val : A){
        std::cout << val << " ";
    }
    std::cout << "\n";

    example::example1();

    xt::xarray<double> arr1
    {{1.0, 2.0, 3.0},
    {2.0, 5.0, 7.0},
    {2.0, 5.0, 7.0}};

    xt::xarray<double> arr2
    {5.0, 6.0, 7.0};

    xt::xarray<double> res = xt::view(arr1, 1) + arr2;

    std::cout << res;
}
