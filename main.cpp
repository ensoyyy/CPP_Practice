#include <iostream>

int powerNum(int iBase, int iExponent) {
    if (iExponent == 0){
        return 1;
    }
    else {
        return iBase * powerNum(iBase, iExponent - 1);
    }
}
int main() {

    int iBase = 0 , iExponent = 0;

    std::cout << "Enter Base:" << "\n";
    std::cin >> iBase;
    std::cout << "Enter Exponent:" << "\n";
    std::cin >> iExponent;

    std::cout << "Power (" << iBase << ", " << iExponent << ") = " << powerNum(iBase, iExponent) << "\n";

    return 0;
}