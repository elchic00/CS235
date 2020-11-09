/****************************************************************************************************************************
Title         :   Grocery.hpp
Auhor         :   Team FBK
Description   :   header/interface file of a dynamically resizeable array class
****************************************************************************************************************************/


#ifndef CART_GROCERY_HPP
#define CART_GROCERY_HPP




#include <string>

class Grocery
{
public:
    Grocery(std::string name, double price, double weight);
    bool incrementQuantity();
    bool decrementQuantity();
    double getTotalPrice() const;                   // returns total_price_
    double getUnitPrice() const;                    // returns unit_cost_
    double getUnitWeight() const;                   // returns unit_weight_
    int getQuantity() const;                        // returns quantity_
    std::string getName() const;                    // returns name_
    bool operator==(const Grocery &rhs) const;      // Comparison operator overload

protected:

    virtual void updateCost() = 0;

    std::string name_;
    int quantity_;
    double unit_price_;
    double unit_weight_;
    double total_price_;
}; // end Grocery

#endif

