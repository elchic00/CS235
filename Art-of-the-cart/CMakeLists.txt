cmake_minimum_required(VERSION 3.17)
project(Cart)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cart main.cpp Vegetable.cpp  Drink.cpp  JunkFood.cpp  ShoppingCart.cpp  Grocery.cpp )
