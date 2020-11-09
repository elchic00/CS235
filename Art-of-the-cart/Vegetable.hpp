/****************************************************************************************************************************
Title         :   JunkFood.hpp
Auhor         :   Andrew Alagna
Description    :  header/interface file of class "Vegetable" to use in a Dynamic Array
Created        :   9/11/2020
Dependencies   :  Grocery.hpp
****************************************************************************************************************************/

#ifndef CART_VEGETABLE_HPP
#define CART_VEGETABLE_HPP


#include "Grocery.hpp"


class Vegetable: public Grocery {

public:
    Vegetable(std::string name , double price , double weight );

protected:
      void updateCost() override;

};


#endif //CART_VEGETABLE_HPP
