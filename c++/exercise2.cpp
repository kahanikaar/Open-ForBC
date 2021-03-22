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
