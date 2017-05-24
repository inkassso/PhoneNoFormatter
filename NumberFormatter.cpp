
#include <iostream>

#include "NumberFormatter.h"

using namespace std;

PhoneNoFormatter::PhoneNoFormatter( ) {
}

PhoneNoFormatter::~PhoneNoFormatter( ) {
}

void PhoneNoFormatter::validate( string& s ) {
    string::size_type pos = 0, count;
    while ( pos < s.length( ) ) {
        if ( isspace( s[pos] ) ) {
            count = 1;
            while ( pos + count < s.length( ) && isspace( s[pos + count] ) )
                ++count;
            s.erase( pos, count );
        }
        else {
            if ( !isdigit( s[pos] ) && ( s[pos] != '+' || pos != 0 ) )
                throw logic_error( string("Invalid character at index [").append( to_string(pos) ).append( "]: " ).append( s.c_str( ) + pos, 1 ) );
            ++pos;
        }
    }
}

void PhoneNoFormatter::format( const string& input, string& output ) {
    output = input;
    
    validate( output );
    
    if ( output.length( ) == 9)
        output.insert( 0, "+420" );
    if ( output.length( ) == 14 )
        output.replace( 0, 2, "+" );    
    else if ( output.length( ) != 13 )
        throw logic_error( string("Invalid length: ").append( to_string(output.length( )) ) );
    
    for ( uint pos = output.length( ) - 9; pos < output.length( ); pos += 4 ) {
        output.insert( pos, " " );
    }
} 