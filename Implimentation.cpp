//Map , Iterator:

#include<bits/stdc++.h>
#include<map>
using namespace std;
int main()
{
    map <int,string> customer;
    customer[100]="tajrian";
    customer[123]="xyz";
    customer[145]="fsdfsf";
    customer[171]="dfsd";
    customer[200]="dfsf";
    customer.insert(pair<int,string>(205,"shourobh"));

    map<int,string>::iterator p= customer.begin();
    while(p!=customer.end()){
        cout<<p->second<<endl;
        p++;
    }
}


//---------------------------------------
