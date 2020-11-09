#include <iostream>
#include "ShoppingCart.hpp"
#include "Drink.hpp"
#include "Vegetable.hpp"
#include "JunkFood.hpp"
using namespace std;

int main()
{

std::cout << std::boolalpha;



    Grocery* Veg = new Vegetable("Mixed-Salad",2.99,1);
    Grocery* Junk = new JunkFood("Avocado Chips",1.99,1);
    Grocery* Coke = new Drink("Coke",3.99,1);
    Grocery* Vegg = new Vegetable("Endives", 1.99, 1);


    ShoppingCart cart1, cart2;

    cart1.add(Veg), cart2.add(Veg);
    cart1.add(Junk), cart2.add(Junk);
    cart1 += cart2;
    cart1 -= cart2;

bool equal = cart1 == cart2;
bool notequal = cart1 != cart2;
bool greater = cart1 > cart2;
bool lesser = cart1 < cart2;


cout << cart1.getCurrentSize() << endl;
cout << cart2.getCurrentSize() << endl;
std::cout << notequal << std::endl;
std::cout << equal << std::endl;
//std::cout << greater << endl;
//cout << lesser << endl;




}
