#include "gtest/gtest.h"
#include "ColorCoder.h"

using namespace TelCoColorCoder;

// ---- Helper functions (previously test_functions.h/.cpp) ----
void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    EXPECT_EQ(colorPair.getMajor(), expectedMajor);
    EXPECT_EQ(colorPair.getMinor(), expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = GetPairNumberFromColor(major, minor);
    EXPECT_EQ(pairNumber, expectedPairNumber);
}

// ---- GoogleTest test cases ----
TEST(ColorCoderTests, NumberToPair) {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
}

TEST(ColorCoderTests, PairToNumber) {
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
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

