/****************************************************************************************************************************
Title         :   DynamicArray.hpp
Auhor         :   Team FBK
Description   :   header/interface file of a dynamically resizeable array class
****************************************************************************************************************************/

#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
//#include <string>
#include <iostream>

template <class T>
class DynamicArray
{

public:

    DynamicArray();
    ~DynamicArray();

    virtual bool add(const T &new_entry);
    virtual bool remove(const T &an_item);

    bool contains(const T &an_entry) const;
    bool isEmpty() const;
    bool setItems(T *new_items_arr, const size_t &size);

    size_t getCapacity() const;
    size_t getOccupiedSpaces() const;
    T *getItems() const;

    void clear();

protected:

    bool atCapacity() const;
    int getIndexOf(const T &target) const;
    void resize();

    size_t current_capacity_;
    size_t item_count_;
    T *items_;
};// end DynamicArray

#include "DynamicArray.cpp"
#endif //CART_DYNAMICARRAY_HPP
