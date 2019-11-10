#include <bit>
#include <bitset>
#include <arpa/inet.h>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

inline uint64_t NUM( uint8_t x ){ return x; }

SCENARIO( "CPU can interpret bits in BIG endian or little endian" )
{
    GIVEN( "Some network data representing port in BIG endian" )
    {
        auto SWAP_UINT16 = []( uint16_t x){ return ((x) >> 8) | ((x) << 8); }; // ntohs

        uint16_t port = htons( 80 );

        WHEN( "The data needs to be interperet on our endian" )
        {
            std::endian e = std::endian::native;

            THEN( "Then data needs convertion to correct represention" )
            {
                uint16_t portOur = e == std::endian::big ? port : SWAP_UINT16( port );

                REQUIRE( portOur == 80u );
            }
        }
    }
}

SCENARIO( "Bit manipulations" )
{
    // We can also use uint16_t, uint32_t or uint64_t (1B, 4B, 8B) variable
    uint8_t bits = 0b01001011u;

    SECTION( "Bitwise AND" )
    {
        uint8_t mask = 0x0F; // 0b00001111
        uint8_t result = bits & mask;

        REQUIRE( result == 0b00001011u );
    }

    SECTION( "Bitwise OR" )
    {
        uint8_t mask = 0xF0; // 0b11110000
        uint8_t result = bits | mask;

        REQUIRE( result == 0b11111011u );
    }

    SECTION( "Bitwise XOR" )
    {
        uint8_t mask = 0xF0; // 0b11110000
        uint8_t result = bits ^ mask;


        REQUIRE( result == 0b10111011u );
    }

    SECTION( "Bitwise NOT" )
    {
        uint8_t result = ~bits; // We get negation by aplying ~ (tilda) operator in front of number

        REQUIRE( NUM( result ) == 0b10110100u );
    }

    SECTION( "Left shift" )
    {
        // shifting 01001011

        uint8_t l1 = bits << 1;
        uint8_t l3 = bits << 3;
        uint8_t l8 = bits << 8;
        uint16_t l10 = bits << 10;

        REQUIRE( NUM( l1 ) == 0b10010110u );
        REQUIRE( NUM( l3 ) == 0b01011000u );
        REQUIRE( NUM( l8 ) == 0b00000000u /* 0 */ );
        REQUIRE( l10 == 0b0010110000000000u );
    }

    SECTION( "Right shift" )
    {
        // shifting 01001011

        uint8_t r1 = bits >> 1;
        uint8_t r3 = bits >> 3;
        uint8_t r8 = bits >> 8;
        uint16_t r10 = bits >> 10;

        REQUIRE( NUM( r1 ) == 0b00100101u );
        REQUIRE( NUM( r3 ) == 0b00001001u );
        REQUIRE( NUM( r8 ) == 0b00000000u /* 0 */ );
        REQUIRE( r10 == 0b0000000000000000u );
    }
}

SCENARIO( "Representing colors as RGB with alpha value" )
{
    uint32_t RGBA = 0xE64155FF; // Redish fully opaque color

    WHEN( "Need to get RED value" )
    {
        // Lets first prepare the mask, remember that bitwise AND works 1 & 1 = 1 and everything
        // else is 0
        // We can use this to zero everything else except for RED value
        uint32_t mask = 0xFF000000;

        // Do the masking - the result is 0xXX000000
        uint32_t result_32_bit = RGBA & mask;

        // The result contains RED value but the value is on wrong position ( bit 24 - bit 31 )
        // We need it in bit 0 - 7, so just move it to left by 24 places
        uint8_t result_red = ( RGBA & mask ) >> 24;

        REQUIRE( result_32_bit == 0xE6000000u );
        REQUIRE( NUM( result_red ) == 0xE6u );

        WHEN( "Need to represent RED as bits" )
        {
            // Usually when printing bytes the functions prints them as numbers or strings
            // And after all our RGBA is a 32bit (4bytes) unsigned number
            // To print the bites as a sequence of 0 and 1 (among other stuff) c++ provides std::bitset
            std::bitset< 32 > bits_result_32 = result_32_bit;
            std::bitset< 8 > bits_red = result_red;

            THEN( "Use std::bitset<> methods" )
            {
                // Now to print it just use the to_string() method
                REQUIRE( bits_result_32.to_string().length() == 32 );
                REQUIRE( bits_result_32.to_string() == "11100110000000000000000000000000" );

                REQUIRE( bits_red.to_string().length() == 8 );
                REQUIRE( bits_red.to_string() == "11100110" );
            }
        }
    }
}
