//sorting in c::

#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//compare the elements and shift the largest to the left position   TimeComplexity : o(n^2);
void bubble_sort(int arr[] , int n){
    int i, j, temp;
    for(int i=0 ; i< n; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j] , &arr[j+1]);
            }
        }
    }
    printf("sorted array is : ");
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
        
    }
}

//shifting the smallest to the left most part       TimeComplexity : o(n^2);
void insertion_sort(int arr[] , int n){
    int i,j;
    for(int i=1 ; i< n; i++){
        int j =i;
       while(j>0 && arr[j] < arr[j-1]){
          swap(&arr[j] , &arr[j-1]);
           j--;
       }
    }
    printf("sorted array is : ");
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
        
    }
}

//we first find the smallest element and swap it with the element in the first position and then find the second smallest element and swap it to second position    Time complexity : n^2;
void selection_sort(int arr[] , int n){
    int i,j,minIndex;
    for(int i=0; i<n ;i++){
        minIndex = i;
        for(int j=i+1 ; j<n ; j++){
            if(arr[j] < arr[minIndex])  minIndex = j;
        }
        swap(&arr[i] , &arr[minIndex]);
    }
    printf("sorted array is : ");
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
}

//we first find a pivot element which is the last element such that all the elemets smaller to it are on the left side and greater on right side and then repeat the step reccursively on both left and right side
//Time complexity : o(n^2) as worstcase and o(nlog(n)) as best case;
int partiton(int a[] , int first , int last){
    int pivot = a[last];
    int i = first-1;
    for(int j = first ; j<last ; j++){
        if(a[j] <= pivot){
            i++;
            swap(&a[i] ,&a[j]);
             //i++;
        }
    }swap(&a[i+1] , &a[last]);
    return i+1;
}
void quick_sort(int a[] , int first , int last){
    if(first < last){
        int pt = partiton(a , first , last);
        quick_sort(a , first , pt-1);
        quick_sort(a , pt , last);
    }
}
//merge sort : arr is divided into subpart and then join in sorted order    TimeComplexity : nlog(n)
void merge(int a[] , int first , int m ,int last){
    int i,j,k;
    int n1 = m - first -1;
    int n2 = last -1;
    
    //creating 2 arrays::
    int l[n1], r[n2];
    
    //coping data to the arrays temprorly::
    for(int i =0 ; i < n1 ; i++){
        l[i] = a[first + i];
    }
    for(int i =first ; i < n2 ; i++){
        r[i] = a[m +1+i];
    }
    
    //merge temprorly arrays back into the array::
    i=0;
    j=0;
    k=first;
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            a[k] = l[i];
            i++;
            k++;
        }
         else{
            a[k] = r[j];
            j++;
            k++;
        }
    }
    
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        a[k] = l[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
     while (j < n2) {
        a[k] = r[j];
        j++;
        k++;
    }
}
void merge_sort(int a[] , int first , int last){
    if(first < last){
        int m = first + (last-first)/2;
        //sorting the 2 halfs
        merge_sort( a ,  first ,  m);
        merge_sort( a ,  m+1 ,  last);
        //merging the 2 halfs
        merge(a , first , m , last);
    }   
}

int main()
{
    int arr[5] = {2,3,8,1,5};
    
    printf("using bubble sort \n");
    bubble_sort( arr , 5);
    
    printf("\n\nusing insertion sort  \n");
    insertion_sort( arr , 5);
    
    printf("\n\nusing selection sort  \n");
    selection_sort( arr , 5);
    
    printf("\n\nusing quick sort  \nsorted array is : ");
    quick_sort( arr , 0 , 4);
    for(int i=0 ;i< 5 ;i++){
            printf("%d",arr[i]);
    }
    printf("\n\nusing merge sort  \nsorted array is : ");
    quick_sort( arr , 0 , 4);
    for(int i=0 ;i< 5 ;i++){
            printf("%d",arr[i]);
    }
    
    return 0;
}



