#include <iostream>
// TODO: create utils class for this function
inline std::size_t CalculatePadding(const std::size_t baseAddress, const std::size_t alignment) {
    std::cout << "calculate padding!" << std::endl;
    const std::size_t multiplier = (baseAddress / alignment) + 1;
    const std::size_t alignedAddress = multiplier * alignment;
    const std::size_t padding = alignedAddress - baseAddress;
    return padding;
}
