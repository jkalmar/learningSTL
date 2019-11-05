#include <bit>
#include <bitset>
#include <iostream>

void bit_cast_example()
{

}

void ispow2_example()
{
    std::cout << "1 ispow2: " << std::ispow2( 1u ) << std::endl;
    std::cout << "2 ispow2: " << std::ispow2( 2u ) << std::endl;
    std::cout << "3 ispow2: " <<  std::ispow2( 3u ) << std::endl;
    std::cout << "4 ispow2: " <<  std::ispow2( 4u ) << std::endl;
    std::cout << "65556 ispow2: " <<  std::ispow2( 65556u ) << std::endl;

}

void ceil2_example()
{
    std::cout << "4 ceil2: " <<  std::ceil2( 4u ) << std::endl;
    std::cout << "3 ceil2: " <<  std::ceil2( 3u ) << std::endl;
    std::cout << "65556 ceil2: " <<  std::ceil2( 65556u ) << std::endl;
}

void floor2_example()
{
    std::cout << "4 floor2: " <<  std::floor2( 4u ) << std::endl;
    std::cout << "3 floor2: " <<  std::floor2( 3u ) << std::endl;
    std::cout << "65556 floor2: " <<  std::floor2( 65556u ) << std::endl;
}
void log2p1_example()
{
    uint64_t number = 0b111100001; // 9 bits

    __uint128_t big_number = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF;

    std::cout << number << " log2p1: " <<  std::log2p1( number ) << std::endl;

}

void rotl_example()
{
    uint8_t i = 0b00011101;
    std::cout << "i          = " << std::bitset<8>(i) << '\n';
    std::cout << "rotl(i,0)  = " << std::bitset<8>(std::rotl(i,0)) << '\n';
    std::cout << "rotl(i,1)  = " << std::bitset<8>(std::rotl(i,1)) << '\n';
    std::cout << "rotl(i,4)  = " << std::bitset<8>(std::rotl(i,4)) << '\n';
    std::cout << "rotl(i,9)  = " << std::bitset<8>(std::rotl(i,9)) << '\n';
    std::cout << "rotl(i,-1) = " << std::bitset<8>(std::rotl(i,-1)) << '\n';
}

void rotr_example()
{

}

void countl_zero_example()
{

}

void countl_one_example()
{

}

void countr_zero_example()
{

}

void countr_one_example()
{

}

void popcount_example()
{

}

void endian_example()
{
    if(std::endian::native == std::endian::big)
    {
        std::cout << "BIG endian" << std::endl;
    }
    else if(std::endian::native == std::endian::little)
    {
        std::cout << "little endian" << std::endl;
    }
    else
    {
        std::cout << "unknown" << std::endl;
    }
}

 
int main()
{
    endian_example();
    rotl_example();
    ceil2_example();
    floor2_example();
    ispow2_example();
    log2p1_example();



}

/**
TODO: things to cover:
    - bit_cast
    - ispow2
    - ceil2
    - floor2
    - log2p1
    - rotl      ... OK
    - rotr
    - countl_zero
    - countl_one
    - countr_zero
    - countr_one
    - popcount
    - endian    ... OK
*/

