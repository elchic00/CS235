/****************************************************************************************************************************
Title         :   ShoppingCart.hpp
Auhor         :   Andrew Alagna
Description    :  header/interface of class "ShoppingCart" to use as derived class of Dynamic Array
Created        :   9/11/2020
 Dependencies   :  Grocery.hpp & DynamicArray.hpp
****************************************************************************************************************************/


#ifndef CART_SHOPPINGCART_HPP
#define CART_SHOPPINGCART_HPP

#include "DynamicArray.hpp"
#include "Grocery.hpp"


class ShoppingCart: public DynamicArray<Grocery*> {
public:

    ShoppingCart();

    ~ShoppingCart();

    bool virtual add(Grocery * new_entry);

    bool virtual remove(Grocery * an_item) ;

    double checkout();

    void garbageClear();

    double getCurrentWeight();
private:
    double curr_contents_weight_;
};


#endif //CART_SHOPPINGCART_HPP
