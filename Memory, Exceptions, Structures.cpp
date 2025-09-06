//<----------------------DYNAMIC MEMORY MANAGEMENT----------------->

/*
    in cpp, stack memory is automatically allocated for variables at compile time and has fixed size
    dynamic memory allocation on heap provides better control and flexibility
    allocation -> 'new'         deallocation -> 'delete'    keywords

    request memory from heap using 'new' and dellocated using 'delete' at runtime
    used for arrays(with unknows sizes), linked lists and trees, where idea of exact size is vague

*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int* ptr;
    /*
    kwynote, int* ptr == int *ptr, but when defnining multiple variables theres issue
        int* ptr1, ptr2; ptr1 is pointer to int, while ptr2 is int
        this int *ptr1, *ptr2;  ensures that both are pointer
        or int* ptr1, *ptr2;    also works
        better declare separately if needed.
    */

    ptr = new int(6);
    cout<< *ptr << endl;    // prints the data pointed by ptr, 6
    cout << ptr << endl;    // prints the pointer holding the memort address of 6.    

    int* nums = new int[10];    // nums points to first address of memory allocated to array of size 10
    for(int i=0; i<10; i++) cin >> nums[i];
    for(int i=0; i<10; i++) cout << nums[i] << " ";


    // exception handling
    int *p = new int(100000);
    if(!*p){ cout<< "Memory allocation failed; "<< endl; exit(0); } 
    // memory allocation fails if heap does not have memory to spare.

    delete ptr;    // frees/deallocates the memory location held by pointer
    delete[] nums;  // deletes all the memory locations held by nums

}

/*
MEMORY LEAKS : the memory allocated for a purpose is not freed after the purpose is over. if pointer/address to memory is lost, it will remain allocated.

DANGLING POINTERS: memory pointed by pointer is accesses after it is deallocated/freed. this leads to crashes/garbasge data (unexpected behaviour)
*/



//<-------------------- Structures, Unions, Enumerations------------------->

/*
structure is udf where we combine different data types into one, like 'node'
dissimilar to array as structure stores non homogenous entries in it
each member in strcture has its own memory
*/
struct struct_nm{
    int property1;
    string property2;
    bool property3;
};

//vector<struct_nm> myDS;
int main(){
    struct_nm data = {12, "string", true};
    cout << data.property1 << data.property2 << data.property3 << " ";
}

/*
    union is same as structure, but the members of union does not have separate spaces. they share same memory space
*/


/*
    enumerations are UDFs consisting of named integral constants.
    meakes code readable by meaningful names to constants.
*/

enum enum_nm{
    val1,val2,val3
};

int main(){
    enum_nm obj = val2;

    switch(obj){
        case val1:  // do something
                    break;
        case val2:  // do something
                    break;
        case val3:  // do something
                    break;
        default:
                    break;
    }
    return 0;
}




//<-------------------------------EXCEPTIOJN HANDLING---------------------------->

/*
    exception handling is mechanism to detect and manage runtime errors
    instead of terminating programs abruptly, c++ allows throws exceptions and catches them for graceful handling
    ex: division by zero, accessing invalid memory, i/o failures etc
*/

//Throwing Exception:
    // use 'throw' keyword to throw an exception when program experiences unexpected situations

// Catching Exception:
    // program searches for matching 'catch' block to intercept and handle the 'throw' errors.

// Handling the error:
    // 'catch' block ususally contains logic to respond to a particular error. allows recovery or graceful termination.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 7,y=0;
    try{
        if(y!=0){
            return x/y;
        }else{
            throw -1;   // throwing zero division exception
        }
    }

    catch(int e){
        cout << "Exceptoin: " << e;
    }

    return 0;
}

/*
Exception:
    1.logic_error
        i. invalid_argument
        ii. domain_error
        iii. length_eror
        iv. out_of_range
    
    2. runtime_error
        i. range_error
        ii. overflow_error
        iii. underflow_error
    
    3.  bad_alloc
    4. bad_cast
    5.bad_function_call
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums= {1,2,3,4,5};

    try{
        nums.at(10);
        // accessing index out of bounds
    }
    catch(out_of_range e){
        // catching the out of range error
        cout << "Index out of range" << e.what();
        // e.waht briefs about the error
    }
}

// there is nested try catch block implementation for specific catering

/*
try{
// parent 'try' throws expection e2
    try{
        // throw e1
    }
    catch(exception e1){
        // catch e1
    }
}
catch(exception e2){
    // caatch expection e2
}

*/