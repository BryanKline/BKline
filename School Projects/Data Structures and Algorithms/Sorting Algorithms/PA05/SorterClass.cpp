// Program Information ////////////////////////////////////////////////////////
/**
 * @file SorterClass.cpp
 * 
 * @brief Implementation file for SorterClass class
 * 
 * @author Bryan Kline
 *
 * @details Implements all member methods for SorterClass class
 *
 * @version 1.00 
 *          Bryan Kline (02/21/2016)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef SORTERCLASS_CPP
#define SORTERCLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "SorterClass.h"
#include "SimpleVector.cpp"

// SorterClass class implementation ///////////////////////////////////////////

/**
 *@brief Implementation of SorterClass default constructor
 *
 *@details Default constructor of base class constructs the object
 *
 *@pre Assumes an uninitialized SorterClass object
 *
 *@post The object's vector has nodes created for it in the amount of the
 *      parameter passed in
 *
 *@par Algorithm  
 *     The default constructor of the base class, SimpleVector, is invoked
 *     with an initializer  
 *
 *@exception None
 *
 *@param[in] newCapacity
 *           An int that corresponds to the capacity of the vector (int)
 *
 *@return None
 *
 *@note Initializer used
 *
 */
template <class DataType>
SorterClass<DataType>:: SorterClass
       ( 
        int newCapacity // in: vector capacity
       )
     : SimpleVector<DataType>( newCapacity )
{
    // initializer used
}

/**
 *@brief Implementation of SorterClass parameterized constructor
 *
 *@details Parameterized constructor of base class constructs the object
 *
 *@pre Assumes an uninitialized SorterClass object
 *
 *@post The object's vector has nodes created for it and filled by the
 *      parameters passed in
 *
 *@par Algorithm  
 *     The parameterized constructor of the base class, SimpleVector, is
 *     invoked with an initializer    
 *
 *@exception None
 *
 *@param[in] newCapacity
 *           An int that corresponds to the capacity of the vector (int)   
 *
 *@param[in] fillValue
 *           A const reference parameter of type DataType which will be used to
 *           fill the vector (DataType)
 *
 *@return None
 *
 *@note Initializer used
 *
 */
template <class DataType>
SorterClass<DataType>:: SorterClass
       ( 
        int newCapacity, // in: vector capacity 
        const DataType &fillValue // in: data to fill vector with
       )
     : SimpleVector<DataType>( newCapacity, fillValue )
{
    // initializer used
}

/**
 *@brief Implementation of SorterClass copy constructor
 *
 *@details Copy constructor of base class constructs the object
 *
 *@pre Assumes an uninitialized SorterClass object
 *
 *@post The object's vector has nodes created for it and filled with the
 *      same values as those of the vector passed in as a parameter
 *
 *@par Algorithm  
 *     The copy constructor of the base class, SimpleVector, is invoked
 *     with an initializer 
 *
 *@exception None
 *
 *@param[in] copiedVector
 *           A reference parameter of type SorterClass that will have its
 *           values copied into the calling object (SorterClass<DataType>)
 *
 *@return None
 *
 *@note Initializer used
 *
 */
template <class DataType>
SorterClass<DataType>:: SorterClass
       ( 
        const SorterClass<DataType> &copiedVector // in: vector to be copied
       ) 
    : SimpleVector<DataType>( copiedVector )
{
    // initializer used
}

/**
 *@brief Implementation of SorterClass destructor
 *
 *@details The base class method resize deletes all vector nodes
 *
 *@pre Assumes an initialized SorterClass object
 *
 *@post All nodes in the vector are deleted and data members are set to
 *      default values
 *
 *@par Algorithm  
 *     The base class method resize is called with an argument of zero to
 *     clear the vector and set data members to default values
 *
 *@exception None
 *
 *@param None
 *
 *@return None
 *
 *@note None
 *
 */
template <class DataType>
SorterClass<DataType>:: ~SorterClass
       (
        // no parameters
       )
{
    this->resize( 0 );
}

/**
 *@brief Implementation of SorterClass method to add an item to the vector
 *
 *@details The item passed in as parameter is added to the end of the vector
 *
 *@pre Assumes an initialized SorterClass object
 *
 *@post The SorterClass object has the item passed in as parameter added to
 *      the vector
 *
 *@par Algorithm  
 *     An if statement checks whether the vector is full and if so more nodes
 *     are created with resize and then the method insertAtIndex is called 
 *     to insert the item
 *
 *@exception Base class method setAtIndex is indirectly invoked which throws
 *           a logic error if an index given to it is out of bounds
 *
 *@param[in] addedItem
 *           A const reference parameter of type DataType which corresponds to 
 *           the item to be added to the vector (DataType)   
 *
 *@return None
 *
 *@note None
 *
 */
template <class DataType>
void SorterClass<DataType>:: add
       (
        const DataType &addedItem // in: the item to be added to the vector
       )
{
    int size = this->getSize();
    int capacity = this->getCapacity();   
    
    // condition: size is equal to capacity
    if( size == capacity )
    {    
        // condition: there are no nodes    
        if( capacity == 0 )
        {
            this->resize( 1 );
        }
        else
        {
            this->resize( capacity + capacity );
        }
    }

    this->insertAtIndex( size, addedItem );
}

/**
 *@brief Implementation of SorterClass method to remove an item from the vector
 *
 *@details The item passed in as parameter is searched fro in the vector and if
 *         it's there it is removed and stored in the parameter
 *
 *@pre Assumes an initialized SorterClass object with nodes and a size greater
 *     than zero
 *
 *@post The item passed in as parameter is removed from the vector if it's
 *      found and then that item is stored in the parameter
 *
 *@par Algorithm  
 *     An if statement checks for nodes and then the method findAtIndex is
 *     called to find the item in the vector, if it's not found then false
 *     is returned, if it is then removeAtIndex is called to remove it 
 *
 *@exception Base class method removeAtIndex is indirectly invoked which
 *           throws a logic error if an index given to it is out of bounds
 *
 *@param[out] removedItem
 *            A reference parameter of type DataType that is to be searched for
 *            in the vector and removed and then stored in the parameter
 *            (DataType)
 *
 *@return A bool corresponding to whether or not there are nodes with values
 *        and whether or not the item was found (bool)
 *
 *@note None
 *
 */
template <class DataType>
bool SorterClass<DataType>:: remove
       ( 
        DataType &removedItem // out: item which will be searched for in the
                              //      the vector and removed
       )
{
    int index;
    int size = this->getSize();
    int capacity = this->getCapacity();
    
    // condition: there are nodes and size is greater than zero
    if( size > 0 && capacity > 0 )
    {
        index = findIndexFor( removedItem );

        // condition: the item is not in the vector
        if( index == NOT_FOUND )
        {
            return false;
        }
        
        removeAtIndex( index, removedItem );

        return true;
    }

    return false;
}

/**
 *@brief Implementation of SorterClass method to find an item in the vector
 *
 *@details Takes in an item of type DataType and searches for it in the vector
 *
 *@pre Assumes an initialized SorterClass object with nodes
 *
 *@post The item passed in as a parameter is searched for in the vector and
 *      and the SorterClass object is unchanged
 *
 *@par Algorithm  
 *     An if statement checks that there are nodes and then if so a counter
 *     controlled loop moves through the vector and each item is compared with
 *     the DataType method compareTo and if there is a match then the index
 *     is returned, otherwise NOT_FOUND (-1) is returned
 *
 *@exception None
 *
 *@param[in] searchItem
 *           A const reference parameter of type DataType which is to be
 *           searched for in the vector (DataType)
 *
 *@return An int corresponding to the index at which the item passed in
 *        as a parameter was found, NOT_FOUND (-1) is returned if it's not
 *        found (int)
 *
 *@note Assumes that DataType has a compareTo method
 *
 */
template <class DataType>
int SorterClass<DataType>:: findIndexFor
       ( 
        const DataType &searchItem // in: the item to be searched for
       )
{
    int counter;
    int size = this->getSize();
    int capacity = this->getCapacity();
    DataType temp;
  
    // condition: there are nodes
    if( capacity > 0 )
    {  
        for( counter = 0; counter < size; counter++ )
        {
            temp = this->getAtIndex( counter );    

            // condition: there is a match with the item 
            if( searchItem.compareTo( temp ) == 0 )
            {
                return counter;
            }
        }
    }

    return NOT_FOUND;
}

/**
 *@brief Virtual SorterClass method to sort items in vector
 *
 *@details Leaves implementation to derived classes to sort items in the 
 *         vector
 *
 *@pre Assumes an initialized class object inherited from SorterClass
 *     containing nodes
 *
 *@post The items in the vector of the derived classed are sorted
 *
 *@par Algorithm  
 *     As a virtual method, derived classes will implement the method
 *
 *@exception None
 *
 *@param None
 *
 *@return None
 *
 *@note Derived classes will implement this method
 *
 */
template <class DataType>
void SorterClass<DataType>:: sort
       (
        // no parameters
       )
{
    // virtual function without implementation
}

/**
 *@brief Implementation of SorterClass method to copy and item from one
 *       index to another
 *
 *@details The item at one index is copied into another
 *
 *@pre Assumes an initialized SorterClass object with nodes
 *
 *@post The item at one index specified by one of the parameters is copied
 *      into the index specified by the other parameter
 *
 *@par Algorithm  
 *     An if statement checks whether the parameters are within the bounds of
 *     the vector size and if there are nodes and if so the base class methods
 *     getAtIndex and setAtIndex get the item from one index and set it at the
 *     other 
 *
 *@exception Base class method setAtIndex is invoked which throws a logic
 *           error if an index given to it is out of bounds
 *
 *@param[in] indexTo
 *           An int corresponding to the index to which the item will be
 *           copied (int) 
 *
 *@param[in] indexFrom
 *           An int corresponding to the index from which the item will be
 *           copied (int)  
 *
 *@return None
 *
 *@note None
 *
 */
template <class DataType>
void SorterClass<DataType>:: copyFromTo
       ( 
        int indexTo, // in: the index to which an item is copied
        int indexFrom // in: the index from which the item copied
       )
{
    int size = this->getSize();
    int capacity = this->getCapacity();
    DataType temp;
        
    // condition: both parameters are in the bounds of size and there are nodes
    if( size > indexTo && size > indexFrom && capacity > 0 )
    {
        temp = this->getAtIndex( indexFrom );
        this->setAtIndex( indexTo, temp );
    }    
}

/**
 *@brief Implementation of SorterClass method to swap items at two indices
 *
 *@details The items at the two indices specified by the parameters are swapped
 *
 *@pre Assumes an initialized SorterClass object with nodes and valid index 
 *     parameters
 *
 *@post The items at the indices specified by the parameters are swapped
 *
 *@par Algorithm  
 *     An if statement checks that there are nodes and that the indices are
 *     and if so then the base class method getAtIndex gets the item at the
 *     first index, stores it in a temporary DataType variable, then uses
 *     the base class method setAtIndex to set the item at the other index
 *     into the first and then puts the item in temp into the other index
 *
 *@exception Base class method setAtIndex is invoked which throws a logic
 *           error if an index given to it is out of bounds
 *
 *@param[in] oneIndex
 *           An int corresponding to an index at which an item is to be swapped
 *           (int)
 *
 *@param[in] otherIndex
 *           An int corresponding to the other index at which an item is to be
 *           swapped (int)
 *
 *@return None
 *
 *@note None
 *
 */
template <class DataType>
void SorterClass<DataType>:: swapBetween
       ( 
        int oneIndex, // in: the first index to swap
        int otherIndex // in: the other index to swap
       )
{
    int size = this->getSize();
    int capacity = this->getCapacity();
    DataType temp;

    // condition: there are nodes and the indices are valid
    if( size > oneIndex && size > otherIndex && capacity > 0 )
    {
        temp = this->getAtIndex( oneIndex ); 
        this->setAtIndex( oneIndex, this->getAtIndex( otherIndex ) );
        this->setAtIndex( otherIndex, temp );
    }
}

/**
 *@brief Implementation of SorterClass method to insert an item in the vector
 *
 *@details The index given as a parameter specifies where the DataType item
 *         is to be inserted and subsequent items are shifted down 
 *
 *@pre Assumes an initialized SorterClass object with nodes and a valid index 
 *     parameter
 *
 *@post The vector contains the item inserted at the index specified and the
 *      items after it are shifted down
 *
 *@par Algorithm  
 *     An if statement checks that the index is valid and that there's room
 *     to shift items down and if so then if size is greater than zero then
 *     a counter controlled loop shifts everything down one, then the method
 *     setAtIndex inserts the item and the size is incremented
 *
 *
 *@exception Base class method setAtIndex is invoked which throws a logic
 *           error if an index given to it is out of bounds
 *
 *@param[in] insertIndex
 *           An int corresponding to the index at which the item is to be 
 *           inserted (int)
 *
 *@param[in] itemToInsert
 *           A const referenced parameter of type DataType corresponding to the
 *           item to be inserted (DataType) 
 *
 *@return None
 *
 *@note None
 *
 */
template <class DataType>
void SorterClass<DataType>:: insertAtIndex
       ( 
        int insertIndex, // in: the index at which the item will be inserted
        const DataType &itemToInsert // in: the item to be inserted
       )
{
    int counter;
    int size = this->getSize();
    int capacity = this->getCapacity();

    // condition: insertIndex is valid and capacity is greater than size
    if( insertIndex >= 0 && insertIndex < capacity && capacity > size
                                                       && insertIndex <= size )
    {
        // condition: the UtilityVector object is not empty
        if( size > 0 )
        {
            for( counter = ( size - 1 ); counter >= insertIndex; counter-- )
            {
                copyFromTo( ( counter + 1 ), counter );
            }
        }

        this->setAtIndex( insertIndex, itemToInsert ); 
        this->incrementSize();
    }
}

/**
 *@brief Implementation of SorterClass method to remove an item from the vector
 *
 *@details The index given as a parameter specifies the location from which the
 *         DataType item is to be removed and subsequent items are shifted up 
 *
 *@pre Assumes an initialized SorterClass object with nodes and a valid index 
 *     parameter
 *
 *@post The vector has the item removed at the index specified, the items after
 *      it are shifted up and then DataType parameter stores the item removed
 *
 *@par Algorithm  
 *     An if statement checks that the index is valid and if it is then the 
 *     DataType parameter receives the item at that index with a call to
 *     getAtIndex, then an if statement checks that there are more than one
 *     node, if so a counter controlled loop shifts everything in the vector
 *     up one and size is decremented, otherwise zeroSize is called
 *
 *
 *@exception None
 *
 *@param[in] removalIndex
 *           An int corresponding to the index at which the item is to be 
 *           removed (int)
 *
 *@param[out] removedItem
 *            A const referenced parameter of type DataType corresponding to the
 *            item to be removed which will store the removed item (DataType)
 *
 *@return None
 *
 *@note None
 *
 */
template <class DataType>
void SorterClass<DataType>:: removeAtIndex
       ( 
        int removalIndex, // in: the index at which the item will be removed
        DataType &removedItem // out: parameter which will store the removed
                              //      item
       )
{
    int counter;
    int size = this->getSize();
    int capacity = this->getCapacity();

    // condition: removalIndex is valid
    if( removalIndex >= 0 && removalIndex < capacity 
                                                   && ( removalIndex < size ) )
    {
        removedItem = this->getAtIndex( removalIndex );

        // condition: size is greater than one
        if( size > 1 )
        {  
            for( counter = removalIndex; counter < ( size - 1 ); counter++ )
            {
                copyFromTo( counter, ( counter + 1 ) );
            } 
            
            this->decrementSize();
        }
        else
        {
            this->zeroSize();
        }
    }   
}


// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef SORTERCLASS_CPP

