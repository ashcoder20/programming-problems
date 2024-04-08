//https://lightoj.com/problem/triangle-partitioning

#include<bits/stdc++.h>
using namespace std;

#define sq(x)       ((x)*(x))
#define pi          acos(-1.0)
#define deg(a)      180.0*a/pi
#define rad(a)      pi*a/180.0
#define endl        "\n"
#define yes         printf("YES\n")
#define no          printf("NO\n")
#define pb          push_back
#define sp          " "
#define mem(a,b) memset(a, b, sizeof(a) )
#define eps       10e-9

typedef long long int          ll;
typedef unsigned long long int ull;
typedef  vector<int>   vi;
typedef  vector<char>  vc;

double area(double a,double b,double c)
{
    double s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc=1;
    double ab,ac,bc,r,abc,ad,ae,de,ade,trap,low,high;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        cin>>ab>>ac>>bc>>r;
        abc=area(ab,ac,bc);
        low=eps,high=ab;
        while(low+eps<high)
        {
            ad=(low+high)/2;
            ae=ad*ac/ab;
            de=ad*bc/ab;
            ade=area(ad,ae,de);
            trap=abc-ade;
            if(ade/trap <r) low=ad;
            else high=ad;
        }
        printf("Case %d: %lf\n",i,ad);
    }
    return 0;
}

//ad/ab=ae/ac
//ae=ad*ac/ab
//ad/ab=de/bc
//de=ad*bc/ab
