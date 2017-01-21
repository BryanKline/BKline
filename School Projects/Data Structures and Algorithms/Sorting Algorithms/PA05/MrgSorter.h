// Program Information ////////////////////////////////////////////////////////
/**
 * @file MrgSorter.h
 *
 * @brief Definition file for MrgSorter class using insertion sort,
 *        derived from SorterClass
 * 
 * @details Specifies all member methods of the MrgSorter Class
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

#ifndef MRGSORTERCLASS_H
#define MRGSORTERCLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include "StudentType.h"
#include "SorterClass.h"

// Class definition  //////////////////////////////////////////////////////////

class MrgSorter: public SorterClass<StudentType>
  {
    public: 

      // local constants

      // Constructors
      MrgSorter();
      MrgSorter( int initialCapacity ); 
      MrgSorter( const SorterClass<StudentType> &copiedSorter );

      // Destructor
      virtual ~MrgSorter();

      // Virtual Functions Defined
       
         // Sort List Using compareTo()
         virtual void sort(); 

    private:

      // sort helper operations
      void sortHelper( int leftIndex, int rightIndex );
      void mergeData( int leftIndex, int middleIndex, int rightIndex );
  };

  #endif // ifndef MRGSORTERCLASS_H


