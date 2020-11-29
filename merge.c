#include<stdio.h>
#include<time.h>
double totaltime=0;

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int *a, int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

void print(int *a,int n)
{
    long i,p;
    printf("\nSorted array is:\n ");
    for (i=0; i<10; i++)
    {
        printf(" %d",a[i]);
    }

    if(n>10)
    {
        printf("..............");
        p=n-10;
        for (i=p; i<n; i++)
        {
            printf(" %d",a[i]);
        }
    }

}

void main()
{

    clock_t start, end;
   long  int *a,*b,*c;
    long int n,i,j;
    char ch;
    printf("--------------------------------------------------Bubble Sort-----------------------------------------------------------\n");

    do{
    printf("\nEnter the range of  elements in array :");
    scanf("%d",&n);
    a= (long int*)malloc(n * sizeof(long int));
    b= (long int*)malloc(n * sizeof(long int));
    c= (long int*)malloc(n * sizeof(long int));


    printf("\n--------------------------------Sorting of Random numbers--------------------------\n");
    for (i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    start = clock();
    mergeSort(a, 0, n- 1);
    end = clock();
    //printf("\n%d",etime);
    totaltime=((double) (end - start)) / CLOCKS_PER_SEC;
    print(a,n);
    printf("\n total time in sorting: %f",totaltime);
    printf(" sec\n");

    printf("\n------------------Sorting of numbers which are sorted in ascending order------------\n");
    for (i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
     start = clock();
    mergeSort(b, 0,n- 1);
    end = clock();
    //printf("\n%d",etime);
    totaltime=((double) (end - start)) / CLOCKS_PER_SEC;
    print(b,n);
    printf("\n total time in sorting: %f",totaltime);
    printf(" sec\n");

    printf("\n------------------Sorting of numbers which are sorted in descending order-----------\n");
       for (i=0,j=n-1; i < n; i++,j--)
    {
        c[i] = b[j];


    }
    start = clock();
    mergeSort(c,0,n- 1);
    end = clock();
    //printf("\n%d",etime);
    totaltime=((double) (end - start)) / CLOCKS_PER_SEC;
    print(c,n);
    printf("\n total time in sorting: %f",totaltime);
    printf(" sec\n");

    printf("\n Do you want to continue ? Press 'y' to continue:");
    fflush(stdin);
    scanf("%c",&ch);
     free(a);

    }while((ch=='y') || (ch=='Y'));


}


