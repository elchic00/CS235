/****************************************************************************************************************************
Title         :   Vegetable.cpp
Auhor         :   Andrew Alagna
Description    :  implementation file of class "Vegetable" to use in a Dynamic Array
Dependencies   :  Vegetable.hpp
Created        :  9/11/2020
****************************************************************************************************************************/


#include "Vegetable.hpp"

//Set the quantity_ to 1, Set name_, unit_price_, and unit_weight_ to what was given by the user, then update cost.
Vegetable::Vegetable(std::string name, double price, double weight): Grocery(name, price, weight) {
    updateCost();
}

//Override updateCost function from Groceries to update the total_price of given Vegetable.
void Vegetable::updateCost() {
    total_price_ =  (quantity_ * (unit_price_ * unit_weight_));
}

