#include <iostream>

#include "NumberFormatter.h"

using namespace std;

/*
 * 
 */
int main( int argc, char** argv ) {

    string line, out;
    PhoneNoFormatter formatter;
    long lineNr = 1;
    try {
        while ( getline( cin, line ).good( ) ) {
            formatter.format( line );
            cout << line << endl;
            ++lineNr;
        }
    } catch ( const exception& ex ) {
        cerr << "Line " << lineNr << ": " << ex.what( ) << endl;
        return 1;
    }
    
    return 0;
}

