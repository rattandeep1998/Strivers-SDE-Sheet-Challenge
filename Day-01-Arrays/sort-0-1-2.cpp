#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int i = 0;
   int j = 0;
   int k = n-1;

   while(j<=k) {
      if(arr[j] == 0) {
         swap(arr[i], arr[j]);
         i++;
         if(i>j) {
            j=i;
         }
      } else if (arr[j] == 1) {
         j++;
      } else {
         swap(arr[j], arr[k]);
         k--;
      }
   }
}