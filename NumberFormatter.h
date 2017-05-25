
#ifndef NUMBERFORMATTER_H
#define NUMBERFORMATTER_H

class PhoneNoFormatter {
public:
    PhoneNoFormatter( );
    virtual ~PhoneNoFormatter( );
    void format( std::string& line );
    
private:
    void validate( std::string& s );
};

#endif /* NUMBERFORMATTER_H */

