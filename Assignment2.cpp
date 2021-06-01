#include <iostream>
#include <stack>
using namespace std;


//struct to represent recursive calls
struct generateSubsetCall
{
    int* a;
    int curr_subset[100];
    int ik, in, istart, iremain, currentIndex;

};

// function which generates every subset of size k from set a
void  GenerateSubsets( int *a, int n, int k )
{
    //start call which is considered as the first function call
    // GenerateSubsets(a, k, n, 0, k);
    generateSubsetCall startCall;
    startCall.a = a;
    startCall.ik=k;
    startCall.in=n;
    startCall.currentIndex=0;
    startCall.istart=0;
    startCall.iremain=k;

    //stack to push function calls in it
    stack<generateSubsetCall> s;
    s.push(startCall);

    while(! s.empty())
    {
        //booleans to indicate which if condition was entered
        bool if1 = false, if2 = false;
        generateSubsetCall call = s.top();
        s.pop();

        // base case
        if(call.istart == call.in)
        {
            if(call.currentIndex == call.ik)
            {
                //print subsets
                for(int i=0 ; i<call.ik ; i++)
                {
                    cout<<call.curr_subset[i]<< " ";
                }
                cout<<endl;
                continue; // break from recursion
            }
        }
        generateSubsetCall c1Temp, c2Temp;
        // Use the current item
        if(call.iremain >0)
        {
            call.curr_subset[call.currentIndex++]= a[call.istart];

            //GenerateSubsets(a, k, n, start+1, remain-1);
            generateSubsetCall c1 = call;
            c1.istart=call.istart+1;
            c1.iremain=call.iremain-1;
            call.currentIndex--;

            // store it in temp to store it in stack if this condition was satisfied
            c1Temp = c1;
            if1 = true;

        }
        // Ignore the current item
        if(call.in-call.istart>call.iremain)
        {

            //GenerateSubsets(a, k, n, start+1, remain);
            generateSubsetCall c2 = call;
            c2.istart=call.istart+1;

            // store it in temp to store it in stack if this condition was satisfied
            c2Temp = c2;
            if2 = true;
        }

        // check which condition was satisfied
        if(if2)
            s.push(c2Temp);
        if(if1)
            s.push(c1Temp);

    }

}
int main()
{
    int a[]= {1,3,5,8,10};
    int n=sizeof(a)/sizeof(a[0]), k=3;
    GenerateSubsets(a, n, k);
    return 0;
}

//TASK DESCRIPTION

//#include <iostream>
//using namespace std;
//
//int cur_ind;
//int cur_subset[100];
//void GenerateSubsets(int* a, int k, int n, int start, int remain)
//{
//    // Base case
//    if(start==n)
//    {
//        if(cur_ind==k){int i; for(i=0;i<k;i++) cout<<cur_subset[i]<<" "; cout<<endl;}
//        return;
//    }
//    // Use the current item
//    if(remain>0)
//    {
//        cur_subset[cur_ind++]=a[start];
//        GenerateSubsets(a, k, n, start+1, remain-1);
//        cur_ind--;
//    }
//    // Ignore the current item
//    if(n-start>remain)
//    {
//        GenerateSubsets(a, k, n, start+1, remain);
//    }
//}
//void GenerateSubsets(int* a, int k, int n)
//{
//    cur_ind=0;
//    GenerateSubsets(a, k, n, 0, k);
//}
//int main()
//{
//    int a[]={1,3,5,8,10}; int n=sizeof(a)/sizeof(a[0]), k=3;
//    GenerateSubsets(a, k, n);
//    return 0;
//}
////----------------------------------------------------------------------------
////* Write a C++ code that does the following:
////* You are not allowed to use any built-in functions except: <cstdlib>, <cstdio>, <cstring>, <iostream>, <stack>.
////* You are not allowed to use string class, vector, or anything from STL libraries except <stack>.
////* Convert the above function to a non-recursive function using the simulating recursion method using stack in Lecture04_Subprograms.
////* Simulate recursion as specified in our lecture, without using any recursive call directly or indirectly.
////* You are not allowed to use bitmasks. You are not allowed to use any other method than the method described in Lecture04_Subprograms applied to the above function.
////* Your code must be general to handle any array of integers.
////
//





