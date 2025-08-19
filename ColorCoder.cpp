
#include "ColorCoder.h"

namespace TelCoColorCoder
{
    const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    ColorPair::ColorPair(MajorColor major, MinorColor minor)
        : majorColor(major), minorColor(minor) {}

    MajorColor ColorPair::getMajor() const { return majorColor; }
    MinorColor ColorPair::getMinor() const { return minorColor; }

    std::string ColorPair::ToString() const {
        return std::string(MajorColorNames[majorColor]) + " " +
               MinorColorNames[minorColor];
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor =
            static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    // ✅ Pure function: builds table
    std::vector<std::string> BuildColorReferenceTable() {
        std::vector<std::string> table;
        for (int pairNumber = 1; pairNumber <= numberOfMajorColors * numberOfMinorColors; pairNumber++) {
            ColorPair colorPair = GetColorFromPairNumber(pairNumber);
            table.push_back(std::to_string(pairNumber) + " -> " + colorPair.ToString());
        }
        return table;
    }

    // ✅ Dependency injected printer
    void PrintColorReferenceManual(
        const std::function<void(const std::string&)>& printer)
    {
        printer("---- 25-Pair Color Code Manual ----");
        for (const auto& entry : BuildColorReferenceTable()) {
            printer(entry);
        }
    }
}
