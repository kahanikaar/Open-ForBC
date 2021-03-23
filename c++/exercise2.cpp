/*
Implementing element-wise sum of vectors parallely and logging individual steps.

Function elementsum()
    Sums the provided elements and stores the value in reference to the results vector.
    Parameters:
         second (element from second vector)
         result (reference of indexed element of vector where sum is returned)

Function logsum()
    Prints the log details of the index whose values were added last.
    Parameters:
        num (Index where addition happened last)

Function sum()
    For adding the vectors element wise parallely and log the results from different thread and returning the resulting vector.
    Parameters:
        first: First vector to be added referenced
        second: Second vector to be added referenced
    Returns: Resulting vector after sum
    Return type: template type

*/

#include<bits/stdc++.h>

using namespace std;

template <typename T>
void elementsum(T second,T *result)
{
*result+=second;
}

template <typename T>
void logsum(T num)
{
    cout<<"\n"<<"Sum of Element "<<num<<" completed.";
}

template <typename T>
vector<T> sum(const vector<T>&first, const vector<T>& second)
{
    assert(first.size()==second.size());
    vector<T> result(first.begin(),first.end());
    cout<<"Summation process started!";
    for(int i=0;i<first.size();++i)
    {
        std::thread t1(elementsum<T>,second[i],&result[i]);
        t1.join();
        std::thread t2(logsum<T>,i);
        t2.detach();
    }
    return result;
}

int main()
{
   vector<int> A{10,20,30};
   vector<int> B{20,30,40};
   vector<int> C;
   C=sum(A,B);
   for(int i=0; i < C.size(); i++)
   cout << "\n"<<C.at(i) << ' ';
   return 0;
}
