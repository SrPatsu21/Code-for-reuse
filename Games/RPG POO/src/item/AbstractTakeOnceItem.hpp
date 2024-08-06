#ifndef AbstractTakeOnceItem_hpp
#define AbstractTakeOnceItem_hpp

#include "./InterfaceCollectionable.hpp"
#include "../entity/AbstractCharacter.hpp"

class AbstractCharacter;

class AbstractTakeOnceItem : public InterfaceCollectionable
{
private:
    bool taked;
    AbstractCharacter* owner;
protected:
    AbstractTakeOnceItem();
    AbstractTakeOnceItem(bool taked, AbstractCharacter* own);

public:

    ~AbstractTakeOnceItem();

    virtual bool isTaked();
    virtual void setAsTaked();
    virtual void setAsUntaked();
    virtual void setOwner(AbstractCharacter* owner);
    virtual void removeOwner();
    virtual AbstractCharacter* getOwner();
};

#endif