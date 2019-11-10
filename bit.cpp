#include <bit>
#include <bitset>
#include <iostream>

void endian_example()
{
    if(std::endian::native == std::endian::big)
    {
        std::cout << "This machine uses BIG endian" << std::endl;
    }
    else if(std::endian::native == std::endian::little)
    {
        std::cout << "This machine uses little endian" << std::endl;
    }
    else
    {
        std::cout << "This machine endian is unknown" << std::endl;
    }
}

void bit_examples()
{
    endian_example();

    uint16_t number = 0x1D10u; // 0b0001110100010000u;

    std::cout << "Printing bits in number is easy using std::bitset" << std::endl;
    std::cout << number << " as bitstring: " << std::bitset< 16 >( number ) << std::endl;
    std::cout << std::endl;

    std::cout << "Counting bits" << std::endl;
    std::cout << "how many actuall bits we need to represent the number?" << std::endl;
    std::cout << number << " log2p1:       " <<  std::log2p1( number ) << std::endl;
    std::cout << std::endl;

    std::cout << "how many 0, or 1 bits is in the number from left or right" << std::endl;
    std::cout << "To count bits from left use std::countl_zero or std::countl_one" << std::endl;
    std::cout << "Left zeros in:  " << std::bitset< 16 >( number ) << " " << std::countl_zero( number ) << std::endl;
    std::cout << "Left ones in:   " << std::bitset< 16 >( number ) << " " << std::countl_one( number ) << std::endl;

    std::cout << "To count bits from right use std::countr_zero or std::countr_one" << std::endl;
    std::cout << "Right zeros in: " << std::bitset< 16 >( number ) << " " << std::countr_zero( number ) << std::endl;
    std::cout << "Right ones in:  " << std::bitset< 16 >( number ) << " " << std::countr_one( number ) << std::endl;

    std::cout << "how many 1s in total are in number" << std::endl;
    std::cout << "All ones in:    " << std::bitset< 16 >( number ) << " " << std::popcount( number ) << std::endl;
    std::cout << std::endl;

    std::cout << "To do some power operations we can use:" << std::endl;
    std::cout << " - std::ispow2" << std::endl;
    std::cout << " - std::floor2" << std::endl;
    std::cout << " - std::ceil2" << std::endl;

    uint16_t floor = std::floor2( number ); // find nearest integral power of two that is <= than number
    uint16_t ceil = std::ceil2( number );   // find nearest integral power of two that is >= than number

    std::cout << number << " ispow2: " << std::boolalpha << std::ispow2( number ) << std::endl;
    std::cout << number << " floor2: " <<  std::floor2( number ) << std::endl;
    std::cout << floor << " floor2: " <<  std::floor2( floor ) << std::endl;
    std::cout << number << " ceil2:  " <<  std::ceil2( number ) << std::endl;
    std::cout << ceil << " ceil2:  " <<  std::ceil2( ceil ) << std::endl;
    std::cout << floor << " ispow2: " << std::boolalpha << std::ispow2( floor ) << std::endl;
    std::cout << ceil << " ispow2: " << std::boolalpha << std::ispow2( ceil ) << std::endl;

    std::cout << "Lets check bits just to give you an idea what is happening" << std::endl;
    std::cout << "number in binary: "  << std::bitset< 16 >( number ) << std::endl;
    std::cout << "floor in binary:  "  << std::bitset< 16 >( floor ) << std::endl;
    std::cout << "ceil in binary:   "  << std::bitset< 16 >( ceil ) << std::endl;
    std::cout << std::endl;

    std::cout << "For shifting bits c++ has some options" << std::endl;
    std::cout << "  - <<, >> - bitwise left/right shift" << std::endl;
    std::cout << "  - std::rotl, std::rotr - bitwise left/right rotarion" << std::endl;

    std::cout << "number in binary: " << std::bitset< 16 >( number ) << std::endl;
    std::cout << "rotl(number, 8):  " << std::bitset< 16 >( std::rotl( number, 8 ) ) << std::endl;
    std::cout << "number << 8:      " << std::bitset< 16 >( number << 8 ) << std::endl;
    std::cout << "rotr(number, 8):  " << std::bitset< 16 >( std::rotr( number, 8 ) ) << std::endl;
    std::cout << "number >> 8:      " << std::bitset< 16 >( number >> 8 ) << std::endl;
}

/**
 * These examples show how to do bit manipulations and operation in C++
 * Standart bit operation are shown as well as utility functions from C++20 STL bit.h
 */
int main()
{
    bit_examples();
}