#include <iostream>
using namespace std;

template <class X>
class queue

{
    X *arr;         //an array to store queue elements
    int capacity;   //maximum capacity of the queue (size)
    int front;      //to track the first element in the queue
    int rear;       //to track the last element  in the queue
    int count;      //size count of the queue (to increment)
 
public:
    queue(int size = 10);     //constructor with default size 10 
 
    void dequeue();
    void enqueue(X x);
    void peek();
    int size();
    bool isEmpty();
    bool isFull();
    void display();
    void checkCap();
    int partition(int lb, int ub);
    int quickSort(int lb, int ub);
    int binarySearch(int x, int lb, int ub);
};
 
//Constructor
template <class X>
queue<X>::queue(int size)
{
    arr = new X[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

//function to add an item to the queue
template <class X>
void queue<X>::enqueue(X item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    else
    {
        cout << item << " (+)" << endl;
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;    
    }
}
 
//function to remove the front element
template <class X>
void queue<X>::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    else
    {
        cout << arr[front]<< " (-)" << endl;
 
        front = (front + 1) % capacity;
        count--;
    }
}
 
//function to print the front element of the queue
template <class X>
void queue<X>::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        cout << "The front element is " << arr[front] << endl;  
    }
}

//function to return the size of the queue
template <class X>
int queue<X>::size() {
    return count;
}
 
//function to check if the queue is empty or not
template <class X>
bool queue<X>::isEmpty() {
    return (size() == 0); //will return true if size()==0 and false if not.
}
 
//function to check if the queue is full or not
template <class X>
bool queue<X>::isFull() {
    return (size() == capacity); //will return true if size() is filled to the max capacity and false if not.
}

//function to display the elements inside the queue
template <class X>
void queue<X>::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }else
    {
        cout << "Queue elements are : ";
        for (int i = front; i <= rear; i++) //will traverse through the queue and print i element then increments itself to print the next element
            cout << arr[i] << " ";
        cout << endl;
    }
}

//function to check the current capacity of the queue
template <class X>
void queue<X>::checkCap(){
    if (isEmpty()) {
        cout << "The queue is empty\n";
    }
    else if(isFull()) 
    {
    cout << "The queue is full\n"; 
    }
    else {
        cout << "The queue is not empty\n";
    }
}

//function to determine the partition of the elements in the queue for quick sort.
template <class X>
int queue<X>::partition(int lb, int ub) //lb is lowerbound, ub is upperbound
{
    int pivot = arr[lb]; //uses the lowerbound element as the pivot
    int start = lb;
    int end = ub;

    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
    
        if(start<end){
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb], arr[end]);
    return end;
}

//recursive function to sort the elements in the queue using quickSort algorithm
template <class X>
int queue<X>::quickSort(int lb, int ub){
    if (lb<ub){ 
        int p = partition(lb, ub);

        quickSort(lb, p-1); 
        quickSort(p+1, ub);
    }
}

template <class X>
int queue<X>::binarySearch(int x, int lb, int ub) {
  
	// Repeat until the lowerbound and upperbound meet each other
    while (lb <= ub) {
        int mid = lb + (ub - lb) / 2;

        if (arr[mid] == x)
        return mid;

        if (arr[mid] < x)
        lb = mid + 1;

        else
        ub = mid - 1;
    }
    return -1; 
}