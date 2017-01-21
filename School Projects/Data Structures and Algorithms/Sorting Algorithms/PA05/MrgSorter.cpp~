// Program Information ////////////////////////////////////////////////////////
/**
 * @file MrgSorter.cpp
 * 
 * @brief Implementation file for MrgSorter class
 * 
 * @author Bryan Kline
 *
 * @details Implements all member methods for MrgSorter class
 *
 * @version 1.00
 *          Bryan Kline (02/24/16)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef MRGSORTERCLASS_CPP
#define MRGSORTERCLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "MrgSorter.h"
#include "StudentType.h"
#include "SorterClass.cpp"

// Global constant ////////////////////////////////////////////////////////////

static const int TWO = 2;

// MrgSorter class implementation  ////////////////////////////////////////////

/**
 *@brief Implementation of MrgSorter default constructor
 *
 *@details The base class default constructor is called with an initializer
 *
 *@pre Assumes an uninitialized MrgSorter object
 *
 *@post An uninitialized MrgSorter object
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
MrgSorter:: MrgSorter
       (
        // no parameters
       )
    : SorterClass<StudentType>:: SorterClass()
{
    // initializer used
}

/**
 *@brief Implementation of MrgSorter parameterized constructor
 *
 *@details The base class parameterized constructor is called with an
 *         initializer
 *
 *@pre Assumes an uninitialized MrgSorter object
 *
 *@post An initialized MrgSorter object with nodes created for the vector
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
MrgSorter:: MrgSorter
       ( 
        int initialCapacity // in: the capacity of the vector
       )
    : SorterClass<StudentType>:: SorterClass( initialCapacity )
{
    // initializer used
}

/**
 *@brief Implementation of MrgSorter copy constructor
 *
 *@details The base class copy constructor is called with an initializer
 *
 *@pre Assumes an uninitialized MrgSorter object
 *
 *@post A MrgSorter object with the same nodes and values as the object 
 *      passed in as a parameter
 *
 *@par Algorithm  
 *     The base class copy constructor is called with an initializer
 *
 *@exception None
 *
 *@param[in] copiedSorter
 *           A const referenced parameter that corresponds to the MrgSorter
 *           object to be copied into the local object 
 *           (SorterClass<StudentType>)
 *
 *@return None
 *
 *@note Initializer used
 *
 */
MrgSorter:: MrgSorter
       ( 
        const SorterClass<StudentType> &copiedSorter // in: the object to be 
                                                     //     copied
       )
    : SorterClass<StudentType>:: SorterClass( copiedSorter )
{
    // initializer used
}

/**
 *@brief Implementation of MrgSorter destructor
 *
 *@details Destructs the MrgSorter object
 *
 *@pre An initialized MrgSorter object with nodes
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
MrgSorter:: ~MrgSorter
       (
        // no parameters
       )
{
    this->resize( 0 );
}

/**
 *@brief Implementation of MrgSorter method to sort items with merge sort
 *
 *@details Calls sorterHelper to sort items in the vector with merege sort
 *
 *@pre Assumes an initialized MrgSorter object with nodes which will hold
 *     objects of type StudentType
 *
 *@post The items in the vector are sorted in ascending order
 *
 *@par Algorithm  
 *     The method sorterHelper is called with zero and the size of the vector
 *     minus one as parameters
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
void MrgSorter:: sort
       (
        // no parameters
       )
{
    int leftIndex = 0;
    int rightIndex = ( this->getSize() - 1 );

    sortHelper( leftIndex, rightIndex );
}
 
/**
 *@brief Implementation of MrgSorter method to assist in sorting items with 
 *       merge sort
 *
 *@details Calls itself recursively and the method mergeData to sort items in
 *         the vector with merege sort
 *
 *@pre Assumes an initialized MrgSorter object with nodes which will hold
 *     objects of type StudentType
 *
 *@post The vector or portions of the vector are broken down into subvectors
 *      and reassembled in an ascending order
 *
 *@par Algorithm  
 *     An if statement checks that the leftmost index is less than the
 *     rightmost and if so then the middle index is calculated and then the
 *     function is called again on the lower half of the vector, then again
 *     on the upper half, which in turn call each again recursively, until
 *     popping out and calling mergeData
 *
 *@exception None
 *
 *@param[in] leftIndex
 *           An int corresponding the the leftmost or smallest index in the 
 *           vector (int)
 *
 *@param[in] rightIndex
 *           An int corresponding the the rightmost or greatest index in the
 *           vector (int)
 *
 *@return None
 *
 *@note The items in the vector must have a compareTo method 
 *      Design inspiration from "Data Abstraction and Problem Solving with C++"
 *      by Carrano (pg. 315)
 *
 */
void MrgSorter:: sortHelper
       ( 
        int leftIndex, // in: the lower index
        int rightIndex // in: the upper index
       )
{
    int midIndex;    

    // condition: the lower index is less than the upper
    if( leftIndex < rightIndex )
    {
        midIndex = ( leftIndex + ( ( rightIndex - leftIndex ) / TWO ) );
    
        sortHelper( leftIndex, midIndex );
        sortHelper( ( midIndex + 1 ), rightIndex );     
        mergeData( leftIndex, midIndex, rightIndex );
    }
}

/**
 *@brief Implementation of MrgSorter method to assist in sorting items with 
 *       merge sort by merging the data
 *
 *@details Merges the data broken down by its calling method, sortHelper, into
 *         a sorted vector or subvector
 *
 *@pre Assumes an initialized MrgSorter object with nodes which will hold
 *     objects of type StudentType
 *
 *@post The vector or portions of the vector that were broken down into
 *      subvectors are reassembled in an ascending order
 *
 *@par Algorithm  
 *     An event controlled loop goes through the two halves of the vector or
 *     subvector and puts the smallest value into a temporary StudentType 
 *     array in order, then two event controlled loops check for remaining
 *     items and puts them into the temporary array, and lastly a counter
 *     controlled loop puts the sorted items from the temporary array into
 *     the vector or subvector
 *
 *@exception None
 *
 *@param[in] leftIndex
 *           An int corresponding to the lower index of the vector or subvector
 *           (int)
 *
 *@param[in] middleIndex
 *           An int corresponding to the middle index of the vector or
 *           subvector (int)
 *
 *@param[in] rightIndex
 *           An int corresponding to the upper index of the vector or subvector
 *           (int)
 *           
 *@return None
 *
 *@note The items in the vector must have a compareTo method 
 *      Design inspiration from "Data Abstraction and Problem Solving with C++"
 *      by Carrano (pg. 315)
 *
 */
void MrgSorter:: mergeData
       ( 
        int leftIndex, // in: the lower index
        int middleIndex, // in: the middle index
        int rightIndex // in: the upper index
       )
{
    int lowerFirst = leftIndex;
    int lowerLast = middleIndex;
    int upperFirst = ( middleIndex + 1 ); 
    int upperLast = rightIndex;
    int index = lowerFirst;
    int size = this->getSize();
    StudentType temp1;
    StudentType temp2;
    StudentType temp[size];

    while( ( lowerFirst <= lowerLast ) && ( upperFirst <= upperLast ) ) 
    {
        temp1 = this->getAtIndex( lowerFirst );
        temp2 = this->getAtIndex( upperFirst );

        // condition: if the first item is less than the second
        if( temp1.compareTo( temp2 ) < 0 )
        {
            temp[index] = this->getAtIndex( lowerFirst );
            lowerFirst++;
        }
        else
        {
            temp[index] = this->getAtIndex( upperFirst );
            upperFirst++;
        }
    
        index++;
    }
    
    while( lowerFirst <= lowerLast )
    {
        temp[index] = this->getAtIndex( lowerFirst );
        lowerFirst++;
        index++;
    }

    while( upperFirst <= upperLast )
    {
        temp[index] = this->getAtIndex( upperFirst );
        upperFirst++;
        index++;
    }

    for( index = leftIndex; index <= rightIndex; index++ )
    {
        this->setAtIndex( index, temp[index] );
    }
}

// Terminating precompiler directives  ////////////////////////////////////////

#endif      // ifndef MRGSORTERCLASS_CPP

