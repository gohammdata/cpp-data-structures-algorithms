// Removes every other item in a Doubly Linked List (or a Vector)
//  Efficient for a doubly linked list ut not really for a vector
template <typename Container>
void removeEveryOtherItem( Container & lst )
{
    typename Container::iterator itr = lst.begin();
    while( itr != lst.end() ) {
        itr = lst.erase( itr );
        if( itr != lst.end() )
            ++itr;
    }
}