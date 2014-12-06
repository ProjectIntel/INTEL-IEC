#include<iostream.h>
#include<conio.h>
#include<stdio.h>
int maxSubArraySum(int a[], int size)
{
   int max_so_far = 0, max_ending_here = 0;
   int i;
   for(i = 0; i < size; i++)
   {
     max_ending_here = max_ending_here + a[i];
     if(max_ending_here < 0)
        max_ending_here = 0;
     if(max_so_far < max_ending_here)
        max_so_far = max_ending_here;
    }
    return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
int s,i;
scanf("%d",s);
   for(i=0;i<s;i++)
{
   scanf("%d",a[i]);
}
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   printf("%d\n", max_sum);
   getchar();
   return 0;
}
