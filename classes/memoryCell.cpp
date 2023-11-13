/**
 * Like intCell but for any type
*/
#include <iostream>
#include <string>
using namespace std;

template <typename Object>
class MemoryCell
{
    public:
        explicit MemoryCell( const Object & initialValue = Object() ) : storedValue( initialValue ){
        }
        const Object & read() const{
            return storedValue;
        }
        void write( const Object & x ){
            storedValue = x;
        }
    private:
        Object storedValue;
};

int main() {
    MemoryCell<int> firstObj;
    MemoryCell<string> strObj{( "hello ")};

    firstObj.write(37);
    strObj.write( strObj.read() + "world" );
    cout << firstObj.read() << endl << strObj.read() << endl;

    return 0;
}