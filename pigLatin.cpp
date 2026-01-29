#include <iostream>

void PigLatin(const char *sWord) {
    if (*sWord == '\0') return;

    std::cout << sWord + 1;
    std::cout << sWord[0];
    std::cout << "ay" << "\n";
}
int main() {

    std::cout << "PigLatin of fox = ";
    PigLatin("fox");
    std::cout << "PigLatin of dog = ";
    PigLatin("dog");

    return 0;
}