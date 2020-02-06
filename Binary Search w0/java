import java.util.*;
class BinSearch
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter the number of testcases");
int t = sc.nextInt();
for(int i=0;i<t;i++)
{
System.out.println("Enter the number of elements in array and element to be searched");
int n = sc.nextInt();
int ele = sc.nextInt();
int l = 0;
int h = n-1;
System.out.println("Enter the elements");
int a[] = new int[n];
for(int j=0;j<n;j++)
a[j] = sc.nextInt();
while(l<=h)
{
int mid = (l+h)/2;
if(a[mid]==ele)
{
System.out.println("1 (Element is present)");
break;
}
else if(a[mid]<ele)
l = mid+1;
else
h = mid-1;
}
if(l>h)
System.out.println("-1 (Element is not present)");
}
}
}
