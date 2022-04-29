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
    q.enqueue("bad"); //it accepts words too not only letters
    q.enqueue("d");
    q.enqueue("go");
    q.enqueue("a");
    q.display();                                        //displaying the elements in the queue
    q.peek();                                           //checking the front element in the queue
    cout << "The queue size is " << q.size() << endl;   //checking queue size
    q.checkCap();                                       //seeing the capacity of the queue

    cout<<"-----------------------------------------\n";
    q.dequeue(); //removing elements from the front.
    q.dequeue();
    q.display();

    cout<<"-----------------------------------------\n";
    q.dequeue();
    q.dequeue();
    q.display(); //will display queue is empty bcs there is no element left in the queue.

    cout<<"=========================================\n";
    cout<<"\t     Queue 2 (Int) \n";
    cout<<"=========================================\n";

    //create a queue of capacity 10 that accepts the data type int.
    queue<int> q2(10);
    q2.checkCap();  //checking the capacity of the queue
    q2.enqueue(7);  //adding elements in the queue
    q2.enqueue(4);
    q2.enqueue(9);
    q2.enqueue(3);
    q2.enqueue(10);
    q2.enqueue(8);
    q2.enqueue(2);
    q2.enqueue(1);

    cout<<"-----------------------------------------\n";
    q2.checkCap();
    q2.display(); //displaying the elements in the queue before it is sorted
    q2.peek();    //checking the front element of the queue (for comparison)

    q2.quickSort(0, q2.size()-1); //sorting the queue
    cout<<endl;
    cout<<"-------  Queue has been sorted  ---------\n";
    cout<<endl;
    q2.display(); //display of the sorted queue
    q2.peek();    //checking the front element of the queue (for comparison)

    //binary searching the element 9
    int result = q2.binarySearch(9, 0, q2.size()-1 );

    //printing the result of the binary search
    if (result == -1) 
        cout<<"Element not found."<<endl;
    else
        printf("Element is found at index %d.", result);
        cout<<endl;

    //binary searching the element 20
    int result2 = q2.binarySearch(20, 0, q2.size()-1 );

    //printing the result of the binary search
    if (result2 == -1)
        cout<<"Element not found.";
    else
        printf("Element is found at index %d.", result);
        cout<<endl;

    cout<<"=========================================\n";
    

    return 0;
}
