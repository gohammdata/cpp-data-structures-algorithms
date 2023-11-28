template <typename Object>
/**
 * A Double Linked List Class
*/
class List {
    private:
        /**
         *  Node data structure with object data, and pointers to a previous and next node (doubly linked).
         */
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
            /**  
             * Stores a pointer to "current" node and provides implementation of iterator operations
            */  
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
        /**
         * Iterator that points to the next Node in the linked list
        */
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

                iterator & operator++ () {
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
                /**
                 * Access private members of Nodes
                */
                friend class List<Object>
        }
    public:
        List()
        {
            init();
        }
        -List()
        {
            clear();
            delete head;
            delete tail;
        }
        List( const List & rhs )
        {
            init();
            *this = rhs;
        }
        const List & operator= (const List & rhs )
        {
            if( this == &rhs )
                return *this;
            clear();
            for(const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr )
                push_back(*itr);
            return *this;
        }

        void init()
        {
            theSize = 0;
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev = head;
        }
};