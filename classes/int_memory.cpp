#include <iostream>
using namespace std;
/**
 * A class for simulating an integer memory cell
*/
class IntCell
{
    private:
        int storedValue;

    public:
    /**
     * Construct the IntCell
     * Initial value is 0.
    */
    IntCell() {
        storedValue = 0;
    }

   /**
    * Construct the IntCell.
    * Initial value is initialValue
   */
    IntCell( int initialValue ) { 
        storedValue = initialValue;
    }

    /**
     * Return the stored value.
    */
   int read() { 
    return storedValue;
    }

    /**
     * Change the stored value to x.
    */
   void write( int x ) {
    storedValue = x;
   }
};

int main() {
    // Create inValue object and call contructor with different value
    IntCell intValue(2);
    //  Print
    intValue.write( 6 );
    cout << intValue.read();
};