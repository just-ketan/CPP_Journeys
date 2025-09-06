//  <-----------UNORDERED SET---------------->

/*
an unordered set is container that stores unique elements in no specific order
Every Opertaion:
    Avg Case : O(1)
    worst case : O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> s;
    // adding element to unordered set
    for(int i=0; i<10; i++){    s.insert(i); }

    // popping from set
    for(auto iter = s.begin(); iter != s.end(); iter++){    cout<<*iter<<" "; }

    // get the size of set
    int size = s.size();
    
    if(s.empty()){ s.clear(); } // clearing set if empty
}

/*
cbegin()    -> first element of unordered set
cend()  -> last element of unordered set
bucket_size() = total no of elements in a specific bucket
max_bucket_count() ->   maximum number of buckets
*/




//  <----------- VECTOR ---------------->

/*
vectors are basically dynamic arrays with ability to change size whenever elements are added/deleted from them.
use 'iterators' to access/traverse through vectors
vector stores data in contiguous memory locations
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    for(int i=0; i<10; i++){    v.push_back(i); }   // inserts elements in the last 

    for(auto iter = v.begin(); iter != v.end(); iter++){    cout<< *iter << " "; }  // print elements

    // v.front()    --> peek element from front
    // v.back() --> peek element from last
    // v.size() --> get size of vector
    // v.pop_back() --> pop the element from back
    v.erase(v.begin());  // used to delete a specific element in vector

    for(int i=0; i<v.size(); i++){  cout << v[i] << " "; }

    v.clear();  // deletes all elements in the vector
}





//  <----------- SET ---------------->
/*
set is a container that stores unique elements in an order
every operation in O(1) in avg
otherwise O(N) in worst case
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;

    for(int i=0; i<10; i++){
        s.insert(i);
    }

    for(auto iter=s.begin(); iter!=s.end(); iter++){
        cout << *iter << " ";
    }

    int key;
    cin >> key;

    // s.find(key); -> finds the key in set and returns location, if not present returns s.end() location
    // s.empty() -> checks whether set is empty
    // s.size() -> gives the size of the set
    // s.erase() -> delete single element OR elements in a range
    // s.clear() -> deletes all elements in the set
}





//  <----------- MAPS ---------------->
/*
    maps are associative containers that store data as PAIRS
    PAIRS are key value pairs
    each key is unique and all data is automatically sorted in ascending order(wrt keys)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int, string> mp;

    map<int, string> mpi = {{1,"first"},
                            {2,"second"},
                            {3,"third"}
                        };
    
    mpi.insert({4,"fourth"});

    for( auto& p : mpi){
        cout<<p.first<<" "<< p.second << endl;
        // i guess p.first() is used to display KEYS
        // p.second() is used to display VALUES
    }

    // getting values via keys
    int key;
    cin >> key;
    //int val = mpi[key];

    mp.at(key) = /* some value*/ '0';   // updating value at key

    /*
    mp.find()   --> finds the location of key in map, if not found returns mp.end() location
    mp.erase(key) -> deletes an element 
    */

    // insert, update, delete, access, find -> O(lgN)
    // traveerse -> O(N)

    return 0;
}




//  <----------- STACK ---------------->
/*
    stack is a container that follows lifo order
    most recently inserted elemented is popped first and first inserted is popped last
    insertion and deletion happens from one end , called TOP
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    for(int i=0; i<5; i++)  st.push(i);

    // popping elements
    while(st.top() != -1){
        cout << st.top() << " ";    // access the element at top
        st.pop();   // pops element from top
    }

    /*
    st.empty() -> boolean value returning whether stack is empty
    st.size() -> returns the size of the stack
    */

    // how to traverse without affecting the stack ?
    stack<int> stc(st); // copy of original

    while(!stc.empty()){ cout<< stc.top();   stc.pop();  }

    // insert delete acces -> O(1)
    // traverse -> O(N)
}


//  <----------- QUEUE ---------------->
/*
    container that follows FIFO order
    the element moves in and out of queue in linear order
    the first to enter the queue leaves the queue the first
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;

    for(int i=0; i<5; i++)  q.push(i);

    // popping removes element from front
    while(q.size()!=0 /* or  !q.empty() */ ){
        // q.back() used to peek the last element
        cout << q.front() << " ";   // peek the front
        q.pop();    // remove the element
    }

    /*
    q.empty() -> checks if queue is empty
    q.size() -> returns the number of elements in queue
    */

    // traversal
    queue<int> qt(q);
    while(!qt.empty()){
        cout<< qt.front() <<" ";
        qt.pop();
    }

    // insert delete access(front, back) -> O(1)
    // traversal -> O(N)
}



//  <----------- Priority Queue ---------------->
/*
    priority queue is a queue with some priority assigned to elements
    also used to implement minheap
    structure --> pq < <data type>, <container>, <binary predicate function to govern comparision between two elements> >
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    // maxheap -> default beahaviour
    priority_queue<int> maxheap;

    maxheap.push(1);
    maxheap.push(123);
    maxheap.push(231);
    maxheap.push(12);
    maxheap.push(156);

    cout << maxheap.top();   // prints 231 as its greatest
    maxheap.pop();
    cout << maxheap.top();   // prints 156 as its greatest now

    // traversal
    priority_queue<int> pqt(maxheap);
    while(!pqt.empty()){    cout<< pqt.top() << " ";   pqt.pop();}
    // prints 231 156 123 12 1

    
    // minheap --> most useful variant
    priority_queue<int, vector<int>, greater<int>>  minheap;
        // less<int>    -> highest element have lesser priority
        // greater<int> -> smallest element have greater priority

    minheap.push(1);
    minheap.push(123);
    minheap.push(231);
    minheap.push(12);
    minheap.push(156);

    auto temp = minheap;
    while(!temp.empty()){   cout<< temp.top() <<" ";  temp.pop();}
    // prints 1 12 123 156 231


    return 0;
}
    /*
    pq.size() -> number of elements in priority queue
    pq.empty() -> boolean to check if pq is empty
    */