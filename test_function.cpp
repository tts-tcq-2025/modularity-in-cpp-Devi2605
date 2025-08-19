// #include <iostream>
// #include <assert.h>
// #include "ColorCoder.h"
// #include "test_functions.h"

// void testNumberToPair(int pairNumber,
//     TelCoColorCoder::MajorColor expectedMajor,
//     TelCoColorCoder::MinorColor expectedMinor)
// {
//     TelCoColorCoder::ColorPair colorPair =
//         TelCoColorCoder::GetColorFromPairNumber(pairNumber);
//     std::cout << "Got pair " << colorPair.ToString() << std::endl;
//     assert(colorPair.getMajor() == expectedMajor);
//     assert(colorPair.getMinor() == expectedMinor);
// }

// void testPairToNumber(
//     TelCoColorCoder::MajorColor major,
//     TelCoColorCoder::MinorColor minor,
//     int expectedPairNumber)
// {
//     int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
//     std::cout << "Got pair number " << pairNumber << std::endl;
//     assert(pairNumber == expectedPairNumber);
// }
#include "gtest/gtest.h"
#include "ColorCoder.h"

using namespace TelCoColorCoder;

TEST(ColorCoderTests, NumberToPair) {
    ColorPair colorPair = GetColorFromPairNumber(4);
    EXPECT_EQ(colorPair.getMajor(), WHITE);
    EXPECT_EQ(colorPair.getMinor(), BROWN);
}

TEST(ColorCoderTests, PairToNumber) {
    int pairNumber = GetPairNumberFromColor(BLACK, ORANGE);
    EXPECT_EQ(pairNumber, 12);
}

TEST(ColorCoderTests, ManualTableSize) {
    auto table = BuildColorReferenceTable();
    EXPECT_EQ(table.size(), numberOfMajorColors * numberOfMinorColors);
}

TEST(ColorCoderTests, ManualOutputInjection) {
    std::vector<std::string> output;
    auto mockPrinter = [&](const std::string& line){ output.push_back(line); };
    PrintColorReferenceManual(mockPrinter);

    EXPECT_GT(output.size(), 1); // must have header + entries
    EXPECT_TRUE(output[1].find("1 -> White Blue") != std::string::npos);
}

