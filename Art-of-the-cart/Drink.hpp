/****************************************************************************************************************************
Title         :   Drink.hpp
Auhor         :   Andrew Alagna
Description    :  header/interface file of class "Drink" to use in a Dynamic Array
Created        :   9/11/2020
Dependencies   :  Grocery.hpp
****************************************************************************************************************************/

#ifndef CART_DRINK_HPP
#define CART_DRINK_HPP
#include "Grocery.hpp"

class Drink : public Grocery {

public:
        Drink(std::string name , double price , double weight);

protected:
        virtual void updateCost() override ;


};


#endif //CART_DRINK_HPP
