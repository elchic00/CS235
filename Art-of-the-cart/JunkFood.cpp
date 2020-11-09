/****************************************************************************************************************************
Title         :   JunkFood.cpp
Auhor         :   Andrew Alagna
Description   :  implementation file of class "JunkFood" to use in a Dynamic Array
Dependencies  :   JunkFood.hpp
Created       :   9/11/2020
****************************************************************************************************************************/

#include "JunkFood.hpp"

//Set the quantity_ to 1, Set name_, unit_price_, and unit_weight_ to what was given by the user, then update cost.
JunkFood::JunkFood(std::string name, double price, double weight) : Grocery(name, price, weight) {
    updateCost();
}

//Override updateCost function from Groceries to update the total_price of given JunkFood.
void JunkFood::updateCost() {
    total_price_ = (quantity_ * unit_price_);
}