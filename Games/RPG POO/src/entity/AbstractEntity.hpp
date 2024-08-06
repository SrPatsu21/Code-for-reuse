#ifndef AbstractEntity_hpp
#define AbstractEntity_hpp

class AbstractEntity
{
    int bout;
protected:
    AbstractEntity();
public:
    ~AbstractEntity();
    virtual int getBout();
    virtual void passBout();
    
};

#endif