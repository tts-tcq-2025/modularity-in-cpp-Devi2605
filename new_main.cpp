#include <iostream>
#include "test_functions.h"

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    testNumberToPair(1, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(2, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    std::cout << "All tests passed!\n";
    return 0;
}


