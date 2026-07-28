#include<iostream>
#include<vector>

using namespace std;

class MyClass
{
    public:

    void Merge(vector<int>& arr, int p, int q, int r)
    {
        int n1 = q - p + 1;
        int n2 = r - q;

        vector<int> list1(n1);
        vector<int> list2(n2);

        int i = 0;

        while(i < n1)
        {
            list1[i] = arr[p+i]; // we cannot use push_back here because size of vector is fixed is n1
            i++;
        }

        i = 0;
        while(i < n2)
        {
            list2[i] = arr[q+1+i]; // we cannot use push_back here because size of vector is fixed is n2
            i++;
        }

        i=0;
        int j = 0, k = 0;

        while(true)
        {
            if(list1[i] <= list2[j])
            {
                arr[p+k] = list1[i];
                k = k+1;
                i = i+1;
                
                if(i == n1)
                {
                    while(j < n2)
                    {
                        arr[p+k] = list2[j];
                        k++;
                        j++;
                    }
                    break;
                }
            }
            else
            {
                arr[p+k] = list2[j];
                j = j+1;
                k = k+1;
                if(j == n2)
                {
                    while(i < n1)
                    {
                        arr[p+k] = list1[i];
                        i++;
                        k++;
                    }
                    break;
                }
            }
        }

    }
    void MergeSort(vector<int>& arr, int p, int r)
    {
        if(p < r)
        {
            int q = (p+r)/2;
            MergeSort(arr,p,q);
            MergeSort(arr,q+1,r);
            Merge(arr,p,q,r);
        }
    }
        
};

int main(void)
{
    int n;
    cout<<"Enter the size of array/vector: ";
    cin>>n;

    vector<int> arr(n);

    printf("Enter the elements of the array: \n");
    
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    printf("Before sorting: \n");

    for(int i = 0; i < n; i++)
    {
        cout <<arr[i]<< " ";
    }

    printf("\nAfter sorting: \n");

    MyClass obj;
    obj.MergeSort(arr,0,n-1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}