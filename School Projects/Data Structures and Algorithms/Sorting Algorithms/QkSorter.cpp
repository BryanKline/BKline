// Program Information ////////////////////////////////////////////////////////
/**
 * @file QkSorter.cpp
 * 
 * @brief Implementation file for QkSorter class
 * 
 * @author Bryan Kline
 *
 * @details Implements all member methods for QkSorter class
 *
 * @version 1.00
 *          Bryan Kline (02/24/16)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef QKSORTERCLASS_CPP
#define QKSORTERCLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "QkSorter.h"
#include "StudentType.h"
#include "SorterClass.cpp"

// QkSorter class implementation  /////////////////////////////////////////////

/**
 *@brief Implementation of QkSorter default constructor
 *
 *@details The base class default constructor is called with an initializer
 *
 *@pre Assumes an uninitialized QkSorter object
 *
 *@post An uninitialized QkSorter object
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
QkSorter:: QkSorter()
    : SorterClass<StudentType>:: SorterClass()
{

}


/**
 *@brief Implementation of QkSorter parameterized constructor
 *
 *@details The base class parameterized constructor is called with an
 *         initializer
 *
 *@pre Assumes an uninitialized QkSorter object
 *
 *@post An initialized QkSorter object with nodes created for the vector
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
QkSorter:: QkSorter
       ( 
        int initialCapacity // in: the capacity of the vector
       )
    : SorterClass<StudentType>:: SorterClass( initialCapacity )
{
    // initializer used
}

/**
 *@brief Implementation of QkSorter copy constructor
 *
 *@details The base class copy constructor is called with an initializer
 *
 *@pre Assumes an uninitialized QkSorter object
 *
 *@post A QkSorter object with the same nodes and values as the object 
 *      passed in as a parameter
 *
 *@par Algorithm  
 *     The base class copy constructor is called with an initializer
 *
 *@exception None
 *
 *@param[in] copiedSorter
 *           A const referenced parameter that corresponds to the QkSorter
 *           object to be copied into the local object 
 *           (SorterClass<StudentType>)
 *
 *@return None
 *
 *@note Initializer used
 *
 */
QkSorter:: QkSorter
       ( 
        const SorterClass<StudentType> &copiedSorter // in: the object to be 
                                                     //     copied
       )
    : SorterClass<StudentType>:: SorterClass( copiedSorter )
{
    // initializer used
}



/**
 *@brief Implementation of QkSorter destructor
 *
 *@details Destructs the QkSorter object
 *
 *@pre An initialized QkSorter object with nodes
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
QkSorter:: ~QkSorter
       (
        // no parameters
       )
{
    this->resize( 0 );
}


/**
 *@brief Implementation of QkSorter method to sort items with quick sort
 *
 *@details Calls sorterHelper to sort items in the vector with quick sort
 *
 *@pre Assumes an initialized QkSorter object with nodes which will hold
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
void QkSorter:: sort
       (
        // no parameters
       )
{
    int left = 0;
    int right = ( this->getSize() - 1 );

    sortHelper( left, right );
}


/**
 *@brief Implementation of QkSorter method to assist in sorting items with 
 *       quick sort
 *
 *@details Calls the method partition and itself recursively to sort items in
 *         the vector with quick sort
 *
 *@pre Assumes an initialized QkSorter object with nodes which will hold
 *     objects of type StudentType
 *
 *@post A pivot index is determined with all items smaller to the left of it
 *      and all items larger to the right and then the method is called 
 *      recursively on the two sides of the pivot with the lower and upper
 *      halves of the vector passed in as indices
 *
 *@par Algorithm  
 *     An if statement checks that the lower index is less than the upper
 *     index and if so then the method partition is called to get an index
 *     corresponding to the pivot and then the vector halves below and above
 *     that pivot are sorted recursively with additional calls to sortHelper
 *
 *@exception None
 *
 *@param[in] leftLimitIndex
 *           An int corresponding to the lower index of the vector (int)
 *
 *@param[in] rightLimitIndex
 *           An int corresponding to the upper index of the vector (int)
 *
 *@return None
 *
 *@note The items in the vector must have a compareTo method 
 *
 */
void QkSorter:: sortHelper
       ( 
        int leftLimitIndex, // in: the lower index
        int rightLimitIndex // in: the upper index
       )
{
    int pivot;    

    // condition: the lower index is less than the upper
    if( leftLimitIndex < rightLimitIndex )
    {
        pivot = partition( leftLimitIndex, rightLimitIndex );
        sortHelper( leftLimitIndex, ( pivot - 1 ) );
        sortHelper( ( pivot + 1 ), rightLimitIndex );
    }
}


/**
 *@brief Implementation of QkSorter method to assist in sorting items with 
 *       by determining the pivot
 *
 *@details A pivot is chosen, the lower part of the vector, then it is moved
 *         relative to the other items in the vector until it is sorted
 *
 *@pre Assumes an initialized QkSorter object with nodes which will hold
 *     objects of type StudentType
 *
 *@post One item in the vector is in its correct location, the pivot, and
 *      its index is returned
 *
 *@par Algorithm  
 *     An event controlled loop, while the lower index is not equal to the
 *     upper index, checks whether pivot is less than the upper index or
 *     greater than the lower index, if the former then the item at pivot
 *     is compared at the upper index, they are swapped if the item at pivot
 *     is larger, otherwise the upper index is decremented, and likewise but
 *     in the opposite manner with the lower index if the latter
 *
 *@exception None
 *
 *@param[in] leftLimitIndex
 *           An int corresponding to the lower index (int)
 *
 *@param[in] rightLimitIndex
 *           An int corresponding to the upper index (int)
 *   
 *@return An int corresponding to the pivot, or the index which is correctly
 *        sorted (int)
 *
 *@note The items in the vector must have a compareTo method 
 *
 */
int QkSorter:: partition
       ( 
        int leftLimitIndex, // in: the lower index
        int rightLimitIndex // in: the upper index
       )
{
    int pivot = leftLimitIndex;
    StudentType temp1;
    StudentType temp2;

    while( leftLimitIndex != rightLimitIndex )
    {   
        // condition: the pivot is below the upper index
        if( pivot < rightLimitIndex )
        {
            temp1 = this->getAtIndex( pivot );
            temp2 =  this->getAtIndex( rightLimitIndex ); 
    
            // condition: the item at the pivot is less than the item at the
            //            upper index
            if( temp1.compareTo( temp2 ) < 0 )
            {
                rightLimitIndex--;
            }
            else
            {
                this->swapBetween( pivot, rightLimitIndex );
                pivot = rightLimitIndex;
            }
        }
        // condition: the pivot is above lower index
        if( pivot > leftLimitIndex )
        {
            temp1 = this->getAtIndex( pivot );
            temp2 =  this->getAtIndex( leftLimitIndex );    

            // condition: the item at the pivot is greater than the item at the
            //            lower index
            if( temp1.compareTo( temp2 ) > 0 )
            {
                leftLimitIndex++;   
            }
            else
            {
                this->swapBetween( pivot, leftLimitIndex );
                pivot = leftLimitIndex;                 
            }
        }
    }

    return pivot;
}

// Terminating precompiler directives  ////////////////////////////////////////

#endif      // ifndef QKSORTERCLASS_CPP

