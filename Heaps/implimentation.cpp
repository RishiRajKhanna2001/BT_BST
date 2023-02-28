#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

    heap()
    {
        arr[0]=-1;
        size=0;
    }

void insert(int data)
{
  size=size+1;
  int index=size;
  arr[index]=data;

  while(index>1)
  {
    int parent=index/2;
    if(arr[parent]<arr[index])
    {
       swap(arr[parent],arr[index]);
    }
    else
    {
        return;
    }
  }
}

void print()
{
    for(int i=0;i<=size;i++)
    {
        cout<<arr[i]<<"->";
    }
    cout<<endl;
}

void deleteFromHeap()
{
    if(size==0)
    {
        cout<<"heap is empty";
        return ;
    }
    arr[1]=arr[size];
    size--;
    int i=1;
    while(i<size)
    {
        int left=2*i;
        int right=2*i+1;
        if(left<size && arr[left]>arr[i])
        {
            swap(arr[left],arr[i]);
            i=left;
        }
        else if(right<size && arr[right]>arr[i])
        {
            swap(arr[right],arr[i]);
            i=right;
        }
        else
        {
            return ;
        }
    }
}

};
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<n && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);
    }
}


int main()
{
    heap h;
    h.insert(10);
    h.insert(10);
    h.insert(10);
    h.insert(10);
    h.insert(10);
    h.insert(10);
    h.print();
    h.deleteFromHeap();
    int n=6;
    int arr[n]={-1,54,23,45,57,78};
    int i=n/2;
    for(int i=n/2;i>=1;i--)
    {
        heapify(arr,n,i);
    }
    cout<<"printing the array : "<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<arr[i]<<"->";
    }
    cout<<"printing the array : "<<endl;
    heapSort(arr,n);
    for(int i=1;i<n;i++)
    {
        cout<<arr[i]<<"->";
    }
    cout<<endl;
    return 0;
}