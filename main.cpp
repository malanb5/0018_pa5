#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

struct Node{

    int data;

    Node * next;

    void add(int num){
        data += num;
    }

    Node(){
        data = 10;
        next = NULL;
    }

    Node(int data){
        this->data = data;
        next = NULL;
    }

    Node(int data, Node * n1){
        this->data = data;
        next = n1;
    }
};
/**
 * print's a list of nodes
 * this is a destructive version of printList
 * @param list
 */

void printList(Node * & list){
    while(list != NULL){
        cout << (*list).data <<" --> ";
        list = (*list).next;
    }
    cout <<"NULL"<<endl;
}

/**
 * This is a non-destructive version of printList which makes a copy
 * This works because nothing is actually being destroyed. It's pointer
 * newList points to the same location in memory as list however the difference
 * is that newList keeps on pointing to next pointers until it reaches
 * NULL -- the original list pointer is still intact
 * @return
 */
void printListNonD(Node * & list){

    Node * newList = list;

    while(newList != NULL){
        cout << (*newList).data << " --> ";
        newList = (*newList).next;
    }
    cout <<"NULL"<<endl;
}

int main() {
    /**
     * Initializes two primitives on the Stack
     */
    int val1 = 4;
    int val2 = 5;

    /**
     * Allocates two int pointers.  They are not pointing to anything just a undefined place in memory.
     */
    int * p1;
    int * p2;

    /**
     * p1 is assigned to the address of val1 which is a place in memory on the stack.
     * p2 is assigned to p1, both point to the same address in memory
     */

    p1 = & val1;
    p2 = p1;

    cout <<p1<<"<-- this is p1's location in memory\n";
    cout<< p2<<"<-- this is p2's location in memory\n";

    /**
     * The value of p1's and p2's memory location is assigned to the value of p2.
     * Both pointers will now have the value of val2 of address val1.
     */
    *p2 = val2;

    cout << * p1 << "<-- this is p1's value "<<endl;
    cout << * p2 << "<-- this is p2's value "<<endl;

    /**
     * node1 and node2 are Node type pointers and assigned to Node objects on the heap
     * new dynamically allocates memory for the Node structure or class on the heap
     * There is no garbage collector so the Nodes will exist until they are deleted
     */

    Node * node1 = new Node(4);
    Node * node2 = new Node(7, node1);
    Node * node3 = node1;

    cout << node1 << " <-- This is node1's address\n";
    cout << node2 << " <-- This is node2's address\n\n";

    // Assigns Node pointer node1 to point to node2's Node address on the heap
    node1 = node2;

    cout << node1 << " <-- this is node1's address now\n";
    cout << node2 << " <-- this is node2's address now\n";

    // Shows two ways to dereference the pointer node1 which now points to node2's address
    cout << node1->data<< " <-- this is node1's data\n";
    cout << (*node1).data << " <-- this is node1's data \n";

    // node1 points to it's old memory location.  This would be case of a dangling pointer.
    cout << (*node1).next << " <-- this is node1's next pointer, it was assigned to it's old location \n";
    cout << (*(*node1).next).data << " <-- This points to the old location of node 1 which has been reassigned to point"
                                     "to node2 \n";

    // node3 which points to node1's location is modified which modifies node1's old location in memory
    (*node3).add(10);

    cout << (*(*node1).next).data << " <-- this has the effect of changing node1's old address\n";

    Node * node4 = new Node(5);
    Node * node5 = new Node(6, node4);
    Node * node6 = new Node(7, node5);

    Node * newList = node6;

    while(newList != NULL){
        cout << (*newList).data << " --> ";
        newList = (*newList).next;
    }
    cout <<"NULL"<<endl;

    /**
     * Non-destructive call to printList
     */
     cout<<node6<<" <--this is node6's address" << endl;

    printListNonD(node6);
    printListNonD(node6);

    /**
     * Destructive call to printList
     */
    printList(node6);
    printList(node6);

    return 0;
}