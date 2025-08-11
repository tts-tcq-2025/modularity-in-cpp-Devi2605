#include <iostream>
#include "test_functions.h"

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    testNumberToPair(8, TelCoColorCoder::WHITE, TelCoColorCoder::GREEN);
    testNumberToPair(9, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::BROWN, 14);
    testPairToNumber(TelCoColorCoder::GREEN, TelCoColorCoder::YELLOW, 18);

    

    std::cout << "All tests passed!\n";
    return 0;
}


