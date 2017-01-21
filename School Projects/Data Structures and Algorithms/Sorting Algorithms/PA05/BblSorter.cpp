// Program Information ////////////////////////////////////////////////////////
/**
 * @file BblSorter.cpp
 * 
 * @brief Implementation file for BblSorter class
 * 
 * @author Bryan Kline
 *
 * @details Implements all member methods for BblSorter class
 *
 * @version 1.00
 *          Bryan Kline (02/24/16)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef BBLSORTERCLASS_CPP
#define BBLSORTERCLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "BblSorter.h"
#include "StudentType.h"
#include "SorterClass.cpp"

// BblSorter class implementation /////////////////////////////////////////////

/**
 *@brief Implementation of BblSorter default constructor
 *
 *@details The base class default constructor is called with an initializer
 *
 *@pre Assumes an uninitialized BblSorter object
 *
 *@post An uninitialized BblSorter object
 *
 *@par Algorithm  
 *     The base class default constructor is called with an initializer
 *
 *@exception None
 *
 *@param None
 *
 *@return None
 *
 *@note Initializer used
 *
 */
BblSorter:: BblSorter
       (
        // no parameters
       )
    : SorterClass<StudentType>:: SorterClass()
{
    // initializer used
}

/**
 *@brief Implementation of BblSorter parameterized constructor
 *
 *@details The base class parameterized constructor is called with an
 *         initializer
 *
 *@pre Assumes an uninitialized BblSorter object
 *
 *@post An initialized BblSorter object with nodes created for the vector
 *      in the amount of the parameter passed in
 *
 *@par Algorithm  
 *     The base class parameterized constructor is called with an initializer
 *
 *@exception None
 *
 *@param[in] initialCapacity
 *           An int corresponding to the number of nodes that will be created
 *           for the vector (int)
 *
 *@return None
 *
 *@note Initializer used
 *
 */
BblSorter:: BblSorter
       ( 
        int initialCapacity // in: the capacity of the vector
       )
    : SorterClass<StudentType>:: SorterClass( initialCapacity )
{
    // initializer used
}

/**
 *@brief Implementation of BblSorter copy constructor
 *
 *@details The base class copy constructor is called with an initializer
 *
 *@pre Assumes an uninitialized BblSorter object
 *
 *@post A BblSorter object with the same nodes and values as the object 
 *      passed in as a parameter
 *
 *@par Algorithm  
 *     The base class copy constructor is called with an initializer
 *
 *@exception None
 *
 *@param[in] copiedSorter
 *           A const referenced parameter that corresponds to the BblSorter
 *           object to be copied into the local object 
 *           (SorterClass<StudentType>)
 *
 *@return None
 *
 *@note Initializer used
 *
 */
BblSorter:: BblSorter
       ( 
        const SorterClass<StudentType> &copiedSorter // in: the object to be 
                                                     //     copied
       )
    : SorterClass<StudentType>:: SorterClass( copiedSorter )
{
    // initializer used
}

/**
 *@brief Implementation of BblSorter destructor
 *
 *@details Destructs the BblSorter object
 *
 *@pre Assumes an initialized BblSorter object with nodes
 *
 *@post All memory allocated to nodes is freed and data members are set to
 *      default values
 *
 *@par Algorithm  
 *     The base class method resize is called with an argument of zero to
 *     clear all nodes and set data members to default values
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
BblSorter:: ~BblSorter
       (
        // no parameters
       )
{
    this->resize( 0 );
}

/**
 *@brief Implementation of BblSorter method to sort items in the vector
 *
 *@details The method sortHelper is called to sort the items in ascending order
 *
 *@pre Assumes an initialized BblSorter object with nodes which will hold
 *     objects of type StudentType
 *
 *@post The vector has its items arranged in ascending order
 *
 *@par Algorithm  
 *     A counter controlled loop calls the method sortHelper while a bool
 *     corresponding to whether or not there has been a swap is true
 *
 *@exception None
 *
 *@param None
 *
 *@return None
 *
 *@note The items in the vector must have a compareTo method for the sortHelper
 *      method
 *
 */
void BblSorter:: sort
       (
        // no parameters
       )
{
    int index = 0;
    bool swapped = true;
   
    while( swapped )
    {
        swapped = sortHelper( index );  
    }
}

/**
 *@brief Implementation of BblSorter method to assist in sorting the items in
 *       the vector
 *
 *@details The items in the vector are sorted with recursive bubble sort into
 *         ascending order
 *
 *@pre Assumes an initialized BblSorter object with nodes which will hold
 *     objects of type StudentType
 *
 *@post The vector has its items arranged in ascending order
 *
 *@par Algorithm  
 *     An if statement checks if the current index is at the end of the vector,
 *     which is the base case, and if not then an if statement checks whether
 *     the item at the next index is greater than the one at the current index,
 *     with a call to the StudentType method compareTo, and if so the items are
 *     swapped with a call to the base class method swapBetween, the method is
 *     then called again recursively until hitting the base case
 *
 *@exception None
 *
 *@param None
 *
 *@return None
 *
 *@note The items in the vector must have a compareTo method
 *
 */
bool BblSorter:: sortHelper
       ( 
        int index // in: the index at which to start the pass
       )
{
    int lastIndex = ( this->getSize() - 1 );
    bool swapped = false;
    bool notSorted = false;
    StudentType currentItem = this->getAtIndex( index );
    StudentType nextItem = this->getAtIndex( index + 1 );

    // condition: the current index is not the second to the last index
    if( index != lastIndex )
    {
        // condition: the item at the current index is less than the item at
        //            the next index
        if( currentItem.compareTo( nextItem ) > 0 )
        {
            this->swapBetween( index, ( index + 1 ) );
            swapped = true;
        }
        notSorted = sortHelper( index + 1 );

        // condition: there was previously a swap
        if( swapped )
        {
            notSorted = true;
        }
    }

    return notSorted;
}

// Terminating precompiler directives  ////////////////////////////////////////

#endif      // ifndef BBLSORTERCLASS_CPP

