// Program Information ////////////////////////////////////////////////////////
/**
 * @file BblSorter.h
 *
 * @brief Definition file for BblSorter class using insertion sort,
 *        derived from SorterClass
 * 
 * @details Specifies all member methods of the BblSorter Class
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

#ifndef BBLSORTERCLASS_H
#define BBLSORTERCLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include "StudentType.h"
#include "SorterClass.cpp"

// Class definition  //////////////////////////////////////////////////////////

class BblSorter: public SorterClass<StudentType>
  {
    public: 

      // local constants

      // Constructors
      BblSorter();
      BblSorter( int initialCapacity ); 
      BblSorter( const SorterClass<StudentType> &copiedSorter );

      // Destructor
      virtual ~BblSorter();

      // Virtual Functions Defined
       
         // Sort List Using StudentType compareTo()
         virtual void sort(); 

    private:

       // sorting helper method
       bool sortHelper( int index );
  };

  #endif // ifndef BBLSORTERCLASS_H


