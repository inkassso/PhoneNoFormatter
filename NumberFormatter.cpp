
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

void PhoneNoFormatter::format( string& line ) {
    if ( line.empty( ) )
        return;
    
    validate( line );
    
    if ( line.length( ) == 9 )
        line.insert( 0, "+420" );
    if ( line.length( ) == 14 )
        line.replace( 0, 2, "+" );
    else if ( line.length( ) != 13 )
        throw logic_error( string("Invalid length: ").append( to_string(line.length( )) ) );
    
    for ( uint pos = line.length( ) - 9; pos < line.length( ); pos += 4 ) {
        line.insert( pos, " " );
    }
} 