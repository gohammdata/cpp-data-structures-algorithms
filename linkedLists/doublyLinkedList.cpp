template <typename Object>
/**
 * A Double Linked List Class
*/
class List {
    private:
        // Node data structure with object data, and pointers to a previous and next node (doubly linked).
        struct Node {
            Object data;
            Node *prev;
            Node *next;
        //  Constructor for Node
            Node( const Object & d = Object(), Node *p = NULL, Node *n = NULL ) : data( d ), prev ( p ), next( n ) {

            }
        }
    public:
        /**
         * A constant iterator storing a pointer for a current node
        */
        class const_iterator {
            //  Stores a pointer to "current" node and provides implementation of iterator operations
            public:
                const_iterator() : current ( NULL ) {

                }
                const Object & operator* () const {
                    return retrieve();
                }
                const_iterator & operator++ () {
                    current = current->next;
                    return *this;
                }
                const_iterator operator++ ( int ) {
                    const_iterator old = *this;
                    ++( *this );
                    return old;
                }

                bool operator== ( const const_iterator & rhs ) const {
                    return current == rhs.current;
                }
                bool operator!= ( const const_iterator & rhs ) const {
                    return !( *this == rhs );
                }
            
            protected:
                Node *current;

                Object & retrieve() const {
                    return current->data;
                }

                const_iterator( Node *p ) : current( p ) {

                }
                /**
                 * Access private members of Nodes
                */
                friend class List<Object>;
        }

        class iterator : public const_iterator {
            public:
                iterator() {

                }

                Object & operator*() {
                    return retrieve();
                }
                const Object & operator* () const {
                    return const_iterator::operator*();
                }

                iteraotr & operator++ () {
                    current = current->next;
                    return *this;
                }

                iterator operator++ ( int ) {
                    iterator old = *this;
                    **( *this );
                    return old;
                }

            protected:
                iterator( Node *p ) : const_iterator( p ){

                }

                friend class List<Object>
        }
};