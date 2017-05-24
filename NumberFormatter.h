
#ifndef NUMBERFORMATTER_H
#define NUMBERFORMATTER_H

class PhoneNoFormatter {
public:
    PhoneNoFormatter( );
    virtual ~PhoneNoFormatter( );
    void format( const std::string& input, std::string& output );
    
private:
    void validate( std::string& s );
};

#endif /* NUMBERFORMATTER_H */

