#include <iostream>
#include ".\sort.hpp"
using namespace std;

int main()
{
    //create a queue of capacity 4 that accepts the data type string.
    queue<string> q(4);
    cout<<"=========================================\n";
    cout<<"\t    Queue 1 (Strings) \n";
    cout<<"=========================================\n";
    q.peek();
    q.enqueue("bad");
    q.enqueue("d");
    q.enqueue("go");
    q.enqueue("a");
    q.display();
    q.peek();
    cout << "The queue size is " << q.size() << endl;
    q.checkCap();

    cout<<"-----------------------------------------\n";
    q.dequeue();
    q.dequeue();
    q.display();

    cout<<"-----------------------------------------\n";
    q.dequeue();
    q.dequeue();
    q.display();

    cout<<"=========================================\n";
    cout<<"\t     Queue 2 (Int) \n";
    cout<<"=========================================\n";

    //create a queue of capacity 10
    queue<int> q2(10);
    q2.checkCap();
    q2.enqueue(7);
    q2.enqueue(4);
    q2.enqueue(9);
    q2.enqueue(3);
    q2.enqueue(10);
    q2.enqueue(8);
    q2.enqueue(2);
    q2.enqueue(1);

    cout<<"-----------------------------------------\n";
    q2.checkCap();
    q2.display();
    q2.peek();

    q2.quickSort(0, q2.size()-1);
    cout<<endl;
    cout<<"-------  Queue has been sorted  ---------\n";
    cout<<endl;
    q2.display();
    q2.peek();

    int result = q2.binarySearch(9, 0, q2.size()-1 );
    if (result == -1)
        cout<<"Element not found."<<endl;
    else
        printf("Element is found at index %d.", result);
        cout<<endl;

    int result2 = q2.binarySearch(20, 0, q2.size()-1 );
    if (result2 == -1)
        cout<<"Element not found.";
    else
        printf("Element is found at index %d.", result);
        cout<<endl;

    cout<<"=========================================\n";
    

    return 0;
}
