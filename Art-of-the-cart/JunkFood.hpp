/****************************************************************************************************************************
Title         :   JunkFood.cpp
Auhor         :   Andrew Alagna
Description    :  header file/interface of class "JunkFood" to use in a Dynamic Array
Created        :   9/11/2020
Dependencies   :  Grocery.hpp
****************************************************************************************************************************/

#ifndef CART_JUNKFOOD_HPP
#define CART_JUNKFOOD_HPP
#include "Grocery.hpp"

class JunkFood : public Grocery {
public:
    JunkFood(std::string name  , double price , double weight);

protected:
    virtual void updateCost() override;
};

#endif //CART_JUNKFOOD_HPP
