#include <stdio.h> 

#define N 5

void printa(int a [], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int maxi (int a[], int n, int start, int end) {
    int i, location;
    int tempmax = a[start];
    location = start;
    for (i = start; i <= end ; i++) {
      if (a[i] > tempmax)  {
        tempmax = a[i]; 
        location = i;
      }
    }
    return location;
}

void sort(int a[], int n) {
    int i, m, temp;
    int start, end;
    for (i = 1; i <= n-1; i++) {
      
       m =  maxi(a, n, 0, n-i);
       printf("\n");
       temp = a[m];
       a[m] = a[n-i];
       a[n-i] = temp;
       printa(a, n);
    }
}

int main() {

   int a[ ]  = { 20, 100, 40,  0, 10};
   printa(a, N);

   sort(a, N);

   printa(a, N);

   return 0;

}   
   
