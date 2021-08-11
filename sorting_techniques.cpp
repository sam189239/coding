#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void print_arr(int a[], int n){
    for(int i = 0; i < n; i++) cout<<a[i]<<" ";
    cout<<"\n";
}

class sorting{
    public:
        void bubble_sort(int a[], int n){
            bool swapped;
            int count = 0;
            for(int i = 0; i < n-1; i++){
                swapped = false;
                for(int j = 0; j < n-1; j++){
                    count++;
                    if(a[j]>a[j+1]){
                        swap(a[j],a[j+1]);
                        swapped = true;
                    }
                }
                if(!swapped) break;
            }
            cout<<"Number of steps: "<<count<<"\n";
        }

        void selection_sort(int a[], int n){
            int count = 0;
            for(int i = 0; i < n; i++){
                for(int j = i; j < n; j++){
                    count++;
                    if(a[i]>a[j]) swap(a[i],a[j]);
                }
            }
            cout<<"Number of steps: "<<count<<"\n";
        }

        void insertion_sort(int a[], int n){
            int count = 0;
            int j, i;
            for(i = 1; i < n; i++){
                int key = a[i];
                for(j = i-1; j >= 0 && a[j]>key; j--){
                    a[j+1] = a[j];
                    count++;
                }
                a[j+1] = key;
            }
            cout<<"Number of steps: "<<count<<"\n";
        }

        int quick_sort(int a[], int low, int high){
            static int count = 0;
            if(low<high){
                int pivot = a[high-1];
                int i = low, j = low;
                while(j<high-1){
                    if(pivot>a[j]) swap(a[i++], a[j]);
                    j++; count++;
                }
                int c;
                swap(a[i], a[high-1]);
                c = quick_sort(a, low, i);
                c = quick_sort(a, i+1, high);
            }
            else{
                return count;
            }
            return count;
        }

        int merge_sort(int a[], int low, int high){
            static int count = 0;
            int mid = (low+high)/2;
            int c;
            if(low<high){
                count++;
                c = merge_sort(a, low, mid);
                c = merge_sort(a, mid+1, high);
                merge(a, low, mid, high);
            }
            else return count;

            return count;
        }

        void merge(int a[], int low, int mid, int high){
            int len1 = mid - low + 1;
            int len2 = high - mid;
            int temparr1[len1], temparr2[len2];
            for (auto i = 0; i < len1; i++)
                temparr1[i] = a[low + i];
            for (auto j = 0; j < len2; j++)
                temparr2[j] = a[mid + 1 + j];
            int i = 0, j = 0, k = low;
            while(i<len1 && j<len2){
                if(temparr1[i]<=temparr2[j]){
                    a[k++] = temparr1[i++];
                }
                else{
                    a[k++] = temparr2[j++];
                }
            }
            while(i<len1) a[k++] = temparr1[i++];
            while(j<len2) a[k++] = temparr2[j++];
        }
        
};

int main(){
    sorting sorter;
    // int a[10] = {9, 23, 78, 10, 5, 45, 105, 23, 29, 0}, n = 10;
    int a[20] = {9, 23, 78, 10, 5, 45, 105, 23, 29, 0, 9, 25, 49, 123, 85, 5, 15, 999, 31, 4}, n = 20;
    int b[20]; 
    copy(begin(a), end(a), begin(b));
    cout<<"Original Array:\t";
    print_arr(a, 10);
    cout<<"Using Bubble Sort: ";
    sorter.bubble_sort(b, n);
    print_arr(b, n); copy(begin(a), end(a), begin(b));
    cout<<"Using Selection Sort: ";
    sorter.selection_sort(b, n);
    print_arr(b, n); copy(begin(a), end(a), begin(b));
    cout<<"Using Insertion Sort: ";
    sorter.insertion_sort(b, n);
    print_arr(b, n); copy(begin(a), end(a), begin(b));
    cout<<"Using Merge Sort: ";
    int count = sorter.merge_sort(b, 0, n-1);
    cout<<"Number of steps: "<<count<<"\n";
    print_arr(b, n); copy(begin(a), end(a), begin(b));
    count = sorter.quick_sort(b, 0, n);
    cout<<"Number of steps: "<<count<<"\n";
    print_arr(b, n); copy(begin(a), end(a), begin(b));
    return 0;
}
