#include "priority_queue.h"
#include <iostream>

using namespace std;    

 
int main()
{
     Heap<int> pq(20);
 
    // Note: The element's value decides priority
 
    pq.push(3);
    pq.push(2);
    pq.push(15);
    pq.push(8);
 
    cout << "Size is " << pq.size() << endl;
 
    cout << "Heap: " << pq.toString()<< endl;

    cout << pq.top() << endl;
    pq.pop();
 
    cout << pq.top();
    pq.pop();
 
    pq.push(5);
    pq.push(4);
    pq.push(45);
 
    cout << endl << "Size is " << pq.size() << endl;
 
    cout << pq.top() << endl;
    pq.pop();
 
    cout << pq.top() << endl;
    pq.pop();
 
    cout << pq.top() << endl;
    pq.pop();
 
    cout << pq.top() << endl;
    pq.pop();
 
    return 0;
}