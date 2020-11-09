/****************************************************************************************************************************
Title         :   ShoppingCart.cpp
Auhor         :   Andrew Alagna
Description   :  Implementation of class "ShoppingCart" to use as derived class of Dynamic Array
Dependencies  : ShoppingCart.hpp
Created       :   9/11/2020
****************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include "ShoppingCart.hpp"


/* Default Constructor: set curr_contents_weight to 0 and inherit from DynamicArray */
ShoppingCart::ShoppingCart() : curr_contents_weight_{0} ,  DynamicArray<Grocery*>() {
}

//Destructor for ShoppingCart which calls parent class's(DynamicArray) destructor.
ShoppingCart::~ShoppingCart(){
    DynamicArray<Grocery*>::clear();
}
/**
   adds new_entry to the caller; if the entry
   already exists in the caller, increment
   quantity_ in the object, and increment
   the curr_contents_weight_ of the caller
   by the unit_weight_ of the added item.

   @pre    :   the addition of the weight of
               new_entry does not bring the
               curr_contents_weight_ over the
               carrying capacity

   @return :   true if the addition is successful
*/

bool ShoppingCart::add(Grocery* new_entry) {

    if (contains(new_entry) && ((curr_contents_weight_ + new_entry->getUnitWeight()) < 350)) {
        curr_contents_weight_ += new_entry->getUnitWeight();
        items_[getIndexOf(new_entry)]->incrementQuantity();
        return true;
    }
    else if (((curr_contents_weight_+new_entry->getUnitWeight()) < 350)) {
            DynamicArray::add(new_entry);
            curr_contents_weight_ += new_entry->getUnitWeight();
            return true;
    }else
            return false;
}

/**
   removes the first instance of an_item from the caller;
   if the entry already exists in the caller, decrement
   quantity_ in the object, and decrement the
   curr_contents_weight_ of the caller by the
   unit_weight_ of the added item.
   --> !!!THIS FUNCTION MUST CALL garbageClear()!!! <--
   @return :   true if the addition is successful
*/

bool ShoppingCart::remove(Grocery *an_item) {
    if(contains(an_item)){
            if( items_[getIndexOf(an_item)] == an_item) {//check if the given item already exists. Decrement if true.
                items_[getIndexOf(an_item)]->decrementQuantity();
            }//end if
        curr_contents_weight_ -= an_item->getUnitWeight();
        garbageClear();
        return true;
    }else
        return false;
}
/**
   iterates through caller and removes items whose quantity_ == 0
   --> !!!THIS FUNCTION MUST CALL DynamicArray::remove()!!! <--
   @post   :   every item in the caller has quantity_ >= 1
*/
void ShoppingCart::garbageClear() {

    for(int i = 0; i < this->item_count_ ; i++)//Runs through the cart as long as items are in it.
        if( items_[i]->getQuantity() == 0)
            DynamicArray::remove(items_[i]);
}
/* Getter: curr_contents_weight_ */
double ShoppingCart::getCurrentWeight() {
    return curr_contents_weight_;
}

/** displays shopping cart contents in required format */
double ShoppingCart::checkout()
{
    if (item_count_ == 0)
    {
        std::cout << "Your cart is empty!" << std::endl;
        return 0;
    }

    double total = 0;
    for (size_t i = 0; i < item_count_; i++)
    {
        std::cout << "\n" << std::setw(10) << std::left <<
                  items_[i]->getName() << "\t" << items_[i]->getQuantity()
                  << "\t" << std::fixed << std::setprecision(2)
                  << items_[i]->getTotalPrice();
        total += items_[i]->getTotalPrice();
    }
    std::cout << std::setfill('-') << std::setw(40) << "\n"
              << std::endl << "Total:                  "
              << total << std::endl << std::endl;
    clear();
    return total;
}





