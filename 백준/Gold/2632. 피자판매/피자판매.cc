#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int pizza;
    int m,n;
    cin>>pizza>>m>>n;
    int a[m];
    int b[n];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];  
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    vector<int> apizza;
    vector<int> bpizza;
    int tt=0;
    for(int i=0;i<m;i++)
    {
        if(a[i]<=pizza)
        {
            apizza.push_back(a[i]);
            int j=i+1;
            if(j==m)j=0;
            int sum=a[i];
            while(sum<=pizza && i!=j)
            {
                sum+=a[j];
                if(sum<=pizza)apizza.push_back(sum);
                else break;
                j++;
                if(j==m)j=0;
                if(i==j && tt==1)
                {
                    apizza.pop_back();
                }
                if(i==j && tt==0)
                {
                    tt=1;
                }
            }
        }
    }
    tt=0;
    for(int i=0;i<n;i++)
    {
        if(b[i]<=pizza)
        {
            bpizza.push_back(b[i]);
            int j=i+1;
            if(j==n)j=0;
            int sum=b[i];
            while(sum<=pizza && i!=j)
            {
                sum+=b[j];
                if(sum<=pizza)bpizza.push_back(sum);
                else break;
                j++;
                if(j==n)j=0;
                if(i==j && tt==1)
                {
                    bpizza.pop_back();
                }
                if(i==j && tt==0)
                {
                    tt=1;
                }
            }
        }
    }
    apizza.push_back(0);
    bpizza.push_back(0);
    sort(apizza.begin(),apizza.end());
    sort(bpizza.begin(),bpizza.end());
    int res=0;
    for(int i=0;i<apizza.size();i++)
    {
        res+=upper_bound(bpizza.begin(),bpizza.end(),pizza-apizza[i])-
 lower_bound(bpizza.begin(),bpizza.end(),pizza-apizza[i]);
    }
    cout<<res;
    return 0;
}
