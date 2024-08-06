#ifndef InterfaceCollectionable_hpp
#define InterfaceCollectionable_hpp

class InterfaceCollectionable
{
protected:
    InterfaceCollectionable();
    virtual void setAsTaked() = 0;
public:
    ~InterfaceCollectionable();
};
#endif