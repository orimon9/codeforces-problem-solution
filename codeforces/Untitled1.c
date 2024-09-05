#include <stdio.h>
int main ()
{
int n,p,sum=0;
scanf ("%d %d",&n,&p);
int a[p];
for (int i=0;i<p;i++)
     {
         scanf ("%d",&a[i]);
     }
int q;
scanf ("%d",&q);
int b[q];
for (int i=0;i<q;i++)
     {
         scanf ("%d",&b[i]);
     }
     int j;

     for (int i=1;i<=n;i++)
     {
       for (j=0;j<n;j++)
       {
           if (a[j]==i || b[j]==i)
           {
               sum++;
               break;
           }
       }
     }
     if (sum>=n)
     {
         printf ("I become the guy.");
     }

     else
     {
         printf ("Oh, my keyboard!");
     }
return 0;
}
