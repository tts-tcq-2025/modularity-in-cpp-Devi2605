#include <iostream>
#include "ColorCoder.h"

int main() {
    // Print manual using cout (can be replaced with mock printer in tests)
    TelCoColorCoder::PrintColorReferenceManual(
        [](const std::string& line){ std::cout << line << std::endl; });

    return 0;
}
