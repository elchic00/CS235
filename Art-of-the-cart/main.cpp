#include <iostream>

#include "Drink.hpp"
#include "JunkFood.hpp"
#include "ShoppingCart.hpp"
#include "Vegetable.hpp"

int main() {



    Grocery* Veg = new Vegetable("Mixed-Salad",2.99,1);
    Grocery* Junk = new JunkFood("Avocado Chips",1.99,1);
    Grocery* Coke = new Drink("Coke",1.99,2);
    Grocery* Vegg = new Vegetable("Endives", 1.32, 3);


    ShoppingCart cart;

cart.add(Veg);
cart.add(Junk);
cart.add(Coke);
cart.add(Vegg);
cart.checkout();

//cart.checkout();





}
