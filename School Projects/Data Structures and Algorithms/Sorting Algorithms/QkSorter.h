// Program Information ////////////////////////////////////////////////////////
/**
 * @file QkSorter.h
 *
 * @brief Definition file for QkSorter class using insertion sort,
 *        derived from SorterClass
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the QkSorter Class
 *
 * @version 1.10
 *          Michael Leverington (12 February 2016)
 *          Updated for use with new SorterClass
 *
 *          1.00 
 *          Michael Leverington (19 September 2015)
 *          Original code
 *
 * @Note Requires StudentType.h, SorterClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef QKSORTERCLASS_H
#define QKSORTERCLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include "StudentType.h"
#include "SorterClass.h"

// Class definition  //////////////////////////////////////////////////////////

class QkSorter: public SorterClass<StudentType>
  {
    public: 

      // local constants

      // Constructors
      QkSorter();
      QkSorter( int initialCapacity ); 
      QkSorter( const SorterClass<StudentType> &copiedSorter );

      // Destructor
      virtual ~QkSorter();

      // Virtual Functions Defined
       
         // Sort List Using StudentType compareTo()
         virtual void sort(); 

    private:

      // helpers for sorting
      void sortHelper( int leftLimitIndex, int rightLimitIndex );
      int partition( int leftLimitIndex, int rightLimitIndex );
  };

  #endif // ifndef QKSORTERCLASS_H


