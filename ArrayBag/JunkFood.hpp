/****************************************************************************************************************************
Title        : JunkFood.hpp
Auhors       : Nursima Donuk & Nigel Ferrer
Description  : header/interface file of a JunkFood object class which inherits from the abstract Grocery class
Dependencies : Grocery.hpp
****************************************************************************************************************************/


#ifndef THEBAG_JUNKFOOD_HPP
#define THEBAG_JUNKFOOD_HPP



#include "Grocery.hpp"

class JunkFood : public Grocery
{
public:
    /**
        Constructor
        @param name   : name of item
        @param price  : the unit price of the item
        @param weight : the unit weight of the item
        @post         : updateCost() has been called, which appropriately sets Grocery::total_price_
    */
    JunkFood(std::string name, double price, double weight);

private:
    /**
        Calculates and sets Grocery::total_price_ if Grocery::quantity_ >= 0
        by the formula:

            total_price_ = quantity_ * unit_price_
    */
    void updateCost();
}; // end JunkFood


#endif //THEBAG_JUNKFOOD_HPP
