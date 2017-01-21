// Program Information ////////////////////////////////////////////////////////
/**
 * @file SorterClass.h
 *
 * @brief Definition file for SorterClass class
 * 
 * @details Specifies all member methods of the SorterClass class
 *
 * @version 1.00 
 *          Michael Leverington (29 January 2016)
 *          Original code
 *
 * @Note Requires SimpleVector.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef SORTERCLASS_H
#define SORTERCLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "SimpleVector.h"

using namespace std;

// Class constants /////////////////////////////////////////////////////////////

template <class DataType>
class SorterClass: public SimpleVector<DataType>
   {
    public:

       // constants
       static const int DEFAULT_CAPACITY = 10;
       static const int NOT_FOUND = -1;

       // constructors
       SorterClass( int newCapacity = DEFAULT_CAPACITY );
       SorterClass( int newCapacity, const DataType &fillValue );
       SorterClass( const SorterClass<DataType> &copiedVector ); 

       // destructor
       virtual ~SorterClass();

       // modifiers

          // adds item to list
          void add( const DataType &addedItem );

          // removes item from list
          bool remove( DataType &removedItem );

          // finds index for item in list
          int findIndexFor( const DataType &searchItem );

          // sorting action, to be derived in sub classes
          virtual void sort();

          // allows copying from one index location to another 
          void copyFromTo( int indexTo, int indexFrom );

          // allows swapping from one index location to another
          void swapBetween( int oneIndex, int otherIndex );

          // allows insertion at a given index
          void insertAtIndex( int insertIndex, const DataType &itemToInsert ); 

          // allows insertion at a given index
          void removeAtIndex( int removalIndex, DataType &removedItem ); 

   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef SORTERCLASS_H

