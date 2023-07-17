#include<bits/stdc++.h>
using namespace std;
int quick(int *a, int beg, int endd)
{
    int left = beg;
    int right = endd;
    int loc = beg;
    while(a[loc]<=a[right] && loc!= right)
    {
        right--;
    }
    if(loc==right) return loc;

    if(a[loc]>a[right])
    {
        swap(a[loc],a[right]);
        loc = right;

    }
    while(a[left]<=a[loc] && loc!=left)
    {

        left++;
    }
        if(loc==left) return loc;

    if(a[left]>a[loc])
    {
        swap(a[loc],a[left]);
        loc = left;
    }


    return quick(a,left,right);
}
void quicksort(int *a, int sizee)
{
    stack<int>lower;
    stack<int> upper;
    if(sizee>1)
    {
        lower.push(0);
        upper.push(sizee-1);
    }
    while(!lower.empty() || !upper.empty())
    {
        int beg = lower.top();
        lower.pop();
        int endd = upper.top();
        upper.pop();
        int loc = quick(a,beg,endd);
        if(beg<loc-1)
        {
            lower.push(beg);
            upper.push(loc-1);
        }
        if(loc+1<endd)
        {
            lower.push(loc+1);
            upper.push(endd);
        }
    }

}
void print_array(int *a)
{
    for(int i = 0; i<12;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main() {
    int a[12] = {44,33,11,55,77,90,40,60,99,22,88,66};
    print_array(a);
    quicksort(a,12);
    cout<<endl;
    print_array(a);
    return 0;
}
