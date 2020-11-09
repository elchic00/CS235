/****************************************************************************************************************************
Title          :   Drink.cpp
Auhor          :   Andrew Alagna
Description    :   implementation file of class "Drink" to use in a Dynamic Array
Dependencies   :   Drink.hpp
Created        :   9/11/2020
****************************************************************************************************************************/


#include "Drink.hpp"

//Set the quantity_ to 1, Set name_, unit_price_, and unit_weight_ to what was given by the user, then update cost.
Drink::Drink(std::string name, double price, double weight): Grocery(name, price, weight) {
    updateCost();
}

//Override updateCost function from Groceries to update the total_price of given Drink.
void Drink::updateCost() {
   total_price_ = quantity_ * (unit_price_ * ((unit_weight_ * 16)/ 33.814 ));
}
