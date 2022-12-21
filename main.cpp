#include <iostream>
#include "ll.hpp"

int main(void)
{
    LinkedList ll(20);
    ll.insert(20);
    ll.insert(30);
    int values[10] = {1,2,3,4,5,6,7,8,9,10};
    ll.insert(values, 10);
    ll.showList();
    ll.removeLast(); 
    ll.showList();
    return(0);
}
