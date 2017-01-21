// Program Information ////////////////////////////////////////////////////////
/**
 * @file PA03.cpp
 *
 * @brief Driver program to exercise the SorterClass,
 *        which uses the SimpleVector class
 * 
 * @details Allows for testing all SorterClass methods 
 *          in an interactive environment
 *
 * @version 1.20
 *          Michael Leverington (10 February 2016)
 *          Updated for use with UtilityVector and SorterClass
 * 
 *          1.10
 *          Michael Leverington (30 January 2016)
 *          Updated for use with UtilityVector
 * 
 *          1.00 
 *          Michael Leverington (07 September 2015)
 *          Original code
 *
 * @Note Requires SimpleVector.cpp, UtilityVector.cpp,
 *                StudentType.h, PriorityQueue.cpp
 */

// Precompiler directives /////////////////////////////////////////////////////

   // none

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "SimpleTimer.h"
#include "StudentType.h"
#include "SimpleVector.cpp"
#include "BblSorter.h"
#include "QkSorter.h"
#include "MrgSorter.h"

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

const int LARGE_STR_LEN = 100;
const int STD_STR_LEN = 50;
const int SMALL_STR_LEN = 25;

const int SORTER_ITEMS = 3;

const bool VERBOSE = true;
const bool SHOW_TIME = true;

const char SEMICOLON = ';';
const char ENDLINE_CHAR = '\n';

const bool SORTED = true;
const bool UNSORTED = false;

// Free function prototypes  //////////////////////////////////////////////////

bool getALine( istream &consoleIn, StudentType &inData );
void displayList( SorterClass<StudentType> &students, 
                                                   char dispID, bool sorted );

// Main function implementation  //////////////////////////////////////////////

int main()
   {
    SorterClass<StudentType> *sorterPtrArray[ SORTER_ITEMS ];
    StudentType studentData;
    char studentName[ STD_STR_LEN ];
    SimpleTimer timer;
    char sortLtrs[] = { 'B', 'M', 'Q' };
    char sortNames[][ SMALL_STR_LEN ] = { "Bubble", "Merge", "Quick" };
    char sortTimes[ SORTER_ITEMS ][ SMALL_STR_LEN ];
    int index;

    // load objects
    sorterPtrArray[ 0 ] = new BblSorter;
    sorterPtrArray[ 1 ] = new MrgSorter;
    sorterPtrArray[ 2 ] = new QkSorter;

    // load data /////////////////////////////////////////////////////////////

    if( VERBOSE )
       {
        cout << endl << "Enter list of students: " << endl;
       }

    while( getALine( cin, studentData ) )
       {
        sorterPtrArray[ 0 ]->add( studentData );
       }

    
    // assign data to other objects //////////////////////////////////////////
    for( index = 1; index < SORTER_ITEMS; index++ )
       {
        *sorterPtrArray[ index ] = *sorterPtrArray[ index - 1 ];
       }

    // display lists, unsorted ///////////////////////////////////////////////
    for( index = 0; VERBOSE && index < SORTER_ITEMS; index++ )
       {
        displayList( *sorterPtrArray[ index ], sortLtrs[ index ], UNSORTED );

        cout << endl;
       }


    // remove operations /////////////////////////////////////////////////////

    strcpy( studentName, "Wro" );
    studentData.setStudentData( studentName, 123456, 'M' );

    for( index = 0; index < SORTER_ITEMS; index++ )
       {
        sorterPtrArray[ index ]->remove( studentData );
       }

    // all sort operations ///////////////////////////////////////////////////
    for( index = 0; index < SORTER_ITEMS; index++ )
       {
        timer.start();
        sorterPtrArray[ index ]->sort();
        timer.stop();

        timer.getElapsedTime( sortTimes[ index ] );

        if( VERBOSE )
           {
            displayList( *sorterPtrArray[ index ], sortLtrs[ index ], SORTED );
            cout << endl;
           }
       }

    // Results displayed /////////////////////////////////////////////////////
    for( index = 0; index < SORTER_ITEMS; index++ )
       {
        displayList( *sorterPtrArray[ index ], sortLtrs[ index ], SORTED );

        if( SHOW_TIME )
           {
            cout << "Elapsed Time for " << sortNames[ index ] << ": " 
                 << sortTimes[ index ] << " seconds." << endl << endl;
           }

        else
           {
            cout << endl;
           }
       }

    return 0;
   }

// Free function implementation  //////////////////////////////////////////////

bool getALine( istream &consoleIn, StudentType &inData )
   {
    char inputStr[ STD_STR_LEN ];
    char tempName[ STD_STR_LEN ];
    int tempID;
    char tempGender, dummyChar;

    cin.getline( inputStr, STD_STR_LEN, SEMICOLON );

    if( strcmp( inputStr, "QUIT" ) != 0 )
       {
        strcpy( tempName, inputStr );

        cin >> dummyChar >> tempID;

        cin >> dummyChar >> tempGender;

        cin.ignore( 10, ENDLINE_CHAR );

        inData.setStudentData( tempName, tempID, tempGender );

        return true;
       }

    return false;
   }

void displayList( SorterClass<StudentType> &students, 
                                                    char dispID, bool sorted )
   {
    int index = 0;
    StudentType studentData;
    char studentStr[ LARGE_STR_LEN ];

    cout << "List " << dispID;

    if( sorted )
       {
        cout << " (sorted):";
       }

    else
       {
        cout << " (unsorted):";
       }

    cout << endl;

    for( index = 0; index < students.getSize(); index++ )
       {
        studentData = students.getAtIndex( index );

        studentData.toString( studentStr );

        cout << studentStr << endl;
       }
   }













