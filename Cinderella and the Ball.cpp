#include<iostream>
#include<math.h>
using namespace std;

int gcd(int, int);
int main()
{
    int n, m, q, i;
    cin>>n>>m>>q;   //Inputs for the number of inner, and outer sectors, and the number of Queries to be answered
    int cx[q], cy[q], px[q], py[q];
    for(i=0;i<q;i++)
        cin>>cx[i]>>cy[i]>>px[i]>>py[i];
    int groupc, groupp, g;
    g=gcd(n,m);     //Finding the gcd of the sectors
    for(i=0;i<q;i++)
    {
        groupc  = ceil(cy[i]*g/cx[i]);  //Calculating the Group of the Princess
        groupp  = ceil(py[i]*g/px[i]);  //Calculating the Group of the Prince
        if(groupc==groupp)     //If they Belong to the same group, print YES, else print NO
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
}

int gcd(int n, int m)   //Using a Recursive Algorithm to find the gcd of 2 numbers
{
    if (n == 0) //Base conditions
       return m;
    if (m == 0)
       return n;
    if (n == m)
        return n;
    if (n > m)
        return gcd(n-m, m); //gcd doesn't change even if the smaller number is subtracted from the larger number
    return gcd(n, n-m);
}
