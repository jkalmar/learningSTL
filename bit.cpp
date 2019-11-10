#include <bit>
#include <bitset>
#include <iostream>

using namespace std;

void endian_example()
{
    if(endian::native == endian::big)
    {
        cout << "This machine uses BIG endian" << endl;
    }
    else if(endian::native == endian::little)
    {
        cout << "This machine uses little endian" << endl;
    }
    else
    {
        cout << "This machine endian is unknown" << endl;
    }
}

void bit_examples()
{
    endian_example();

    uint16_t number = 0x1D10u; // 0b0001110100010000u;

    cout << "Printing bits in number is easy using bitset" << endl;
    cout << number << " as bitstring: " << bitset< 16 >( number ) << endl;
    cout << endl;

    cout << "Counting bits" << endl;
    cout << "how many actuall bits we need to represent the number?" << endl;
    cout << number << " log2p1:       " <<  log2p1( number ) << endl;
    cout << endl;

    cout << "how many 0, or 1 bits is in the number from left or right" << endl;
    cout << "To count bits from left use countl_zero or countl_one" << endl;
    cout << "Left zeros in:  " << bitset< 16 >( number ) << " " << countl_zero( number ) << endl;
    cout << "Left ones in:   " << bitset< 16 >( number ) << " " << countl_one( number ) << endl;

    cout << "To count bits from right use countr_zero or countr_one" << endl;
    cout << "Right zeros in: " << bitset< 16 >( number ) << " " << countr_zero( number ) << endl;
    cout << "Right ones in:  " << bitset< 16 >( number ) << " " << countr_one( number ) << endl;

    cout << "how many 1s in total are in number" << endl;
    cout << "All ones in:    " << bitset< 16 >( number ) << " " << popcount( number ) << endl;
    cout << endl;

    cout << "To do some power operations we can use:" << endl;
    cout << " - ispow2" << endl;
    cout << " - floor2" << endl;
    cout << " - ceil2" << endl;

    uint16_t floor = floor2( number ); // find nearest integral power of two that is <= than number
    uint16_t ceil = ceil2( number );   // find nearest integral power of two that is >= than number

    cout << number << " ispow2: " << boolalpha << ispow2( number ) << endl;
    cout << number << " floor2: " <<  floor2( number ) << endl;
    cout << floor << " floor2: " <<  floor2( floor ) << endl;
    cout << number << " ceil2:  " <<  ceil2( number ) << endl;
    cout << ceil << " ceil2:  " <<  ceil2( ceil ) << endl;
    cout << floor << " ispow2: " << boolalpha << ispow2( floor ) << endl;
    cout << ceil << " ispow2: " << boolalpha << ispow2( ceil ) << endl;

    cout << "Lets check bits just to give you an idea what is happening" << endl;
    cout << "number in binary: "  << bitset< 16 >( number ) << endl;
    cout << "floor in binary:  "  << bitset< 16 >( floor ) << endl;
    cout << "ceil in binary:   "  << bitset< 16 >( ceil ) << endl;
    cout << endl;

    cout << "For shifting bits c++ has some options" << endl;
    cout << "  - <<, >> - bitwise left/right shift" << endl;
    cout << "  - rotl, rotr - bitwise left/right rotarion" << endl;

    cout << "number in binary: " << bitset< 16 >( number ) << endl;
    cout << "rotl(number, 8):  " << bitset< 16 >( rotl( number, 8 ) ) << endl;
    cout << "number << 8:      " << bitset< 16 >( number << 8 ) << endl;
    cout << "rotr(number, 8):  " << bitset< 16 >( rotr( number, 8 ) ) << endl;
    cout << "number >> 8:      " << bitset< 16 >( number >> 8 ) << endl;
}

/**
 * These examples show how to do bit manipulations and operation in C++
 * Standart bit operation are shown as well as utility functions from C++20 STL bit.h
 */
int main()
{
    bit_examples();
}