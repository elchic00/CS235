/****************************************************************************************************************************
Title        : ArrayBag.cpp
Auhor        : Andrew Alagna
Description  : implement ArrayBag header file which will be the base class for ShoppingCart
Dependencies : ArrayBag.hpp
****************************************************************************************************************************/


#include "ArrayBag.hpp"

/* Default constructor */
template <class ItemType>
ArrayBag<ItemType>::ArrayBag() : item_count_{0}
{
}

/* Will get the index of a given item in the array. Taken from textbook. */
template <typename ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    while (!found && (searchIndex < item_count_))
    {
        if(items_[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }
    }
    return result;
}

/* returns # of items in caller */
template <typename ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return item_count_;
}

/* returns if the bag is empty */
template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

/* adds an entry to the caller*/
template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& new_entry)
{
    bool hasRoom = (item_count_ < DEFAULT_CAPACITY);
    if(hasRoom)
    {
        items_[item_count_] = new_entry;
        item_count_++;
    }
    return hasRoom;
}

/* removes an entry from the bag. taken from textbook out of pg. 110 */
template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& an_entry)
{
    int locatedIndex = getIndexOf(an_entry);
    bool canRemove = !isEmpty() && (locatedIndex > -1);
    if (canRemove)
    {
        item_count_--;
        items_[locatedIndex] = items_[item_count_];
    }
    return canRemove;
}

/* sets the # of items in the bag to 0 */
template <class ItemType>
void ArrayBag<ItemType>::clear()
{
    item_count_ = 0;
}

/* returns if an item exists in the caller. taken from textbook page 106. */
template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& an_entry) const
{
    bool found = false;
    int curIndex = 0;
    while (!found && (curIndex < item_count_))
    {
        if (an_entry == items_[curIndex])
        {
            found = true;
        }
        curIndex++;
    }
    return found;
}

/* returns frequency of a given item in the bag. taken from textbook pg 106. */
template <typename ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& an_entry) const
{
    int frequency = 0;
    int curIndex = 0;
    while (curIndex < item_count_)
    {
        if (items_[curIndex] == an_entry)
        {
            frequency++;
        }
        curIndex++;
    }
    return frequency;
}

/* set union of the caller and given bag */
template <typename ItemType>
void ArrayBag<ItemType>::operator+=(const ArrayBag<ItemType>& a_bag)
{
    if(item_count_ < DEFAULT_CAPACITY)
    {
        /* Traverses through the caller bag and checks if a given bag's items are already in it
         *  if not, add it to the bag. Else do not add */
        for (size_t i = 0; i < a_bag.item_count_; i++)
        {
            if(!this->contains(a_bag.items_[i]))
                this->add(a_bag.items_[i]);
        }
    }
}

/* set difference between caller and given bag */
template <typename ItemType>
void ArrayBag<ItemType>::operator-=(const ArrayBag<ItemType>& a_bag)
{
    if(!this->isEmpty())
    {
        /* Traverse through the caller bag and check if it has any of the given bag's items. Remove item if found */
        for (size_t i = 0; i < a_bag.item_count_; i++)
        {
            this->remove(a_bag.items_[i]);
        }
    }
}

/* set intersection of caller and given bag */
template <typename ItemType>
void ArrayBag<ItemType>::operator/=(const ArrayBag<ItemType>& a_bag)
{
    if(!this->isEmpty())
    {
        /* Traverse through the caller bag and remove any item not in the given bag  */
            for (size_t i = 0; i < a_bag.item_count_; i++)
            {
                if (!a_bag.contains(items_[i]))
                    this->remove(items_[i]);
            }
    }
}

/* equal comparison operator between two bags */
template <typename ItemType>
bool ArrayBag<ItemType>::operator==(const ArrayBag<ItemType>& a_bag)
{
    bool canBeEqual = (item_count_ == a_bag.item_count_);
    if (canBeEqual)
    {
        /* Travers caller bag and check if it contains the same item's as the given bag. return false
         * if any item in the given bag is not in the caller bag. else return true.*/
        for (int i = 0; i < a_bag.item_count_ - 1; i++)
        {
            if (!this->contains(a_bag.items_[i]))
                return false;
        }
    }
    return true;
}

/* not equal comparison operator (overloaded) */
template <typename ItemType>
bool ArrayBag<ItemType>::operator!=(const ArrayBag<ItemType>& a_bag)
{
    int sameItems = 0;
    bool canBeUnequal = (item_count_ != a_bag.item_count_);
    if (canBeUnequal)
    {
        /* Traverse through the caller bag and check if it contains the same items in the given bag
         * return true if they dont contain the same items, else return false */
        for (size_t i = 0; i < a_bag.item_count_ - 1; i++)
        {
            if(this->contains(a_bag.items_[i]))
                sameItems++;
        }
    }
    if(sameItems != item_count_)
        return true;
    else
        return false;
}

