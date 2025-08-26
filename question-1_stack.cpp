#include<bits/stdc++.h>
using namespace std;
class stpr{
    public:
    int n;
    int top=-1;
    stpr(int sz){
        n=sz;
    }
    vector<int> ar;
    void push()
    {
        cout<<"enter stack elements:\n";
        for(int i=0;i<n;i++){
            top++;
            cin>>ar[top];
        }
    }
    void pop(){
        top--;
    }
    bool isempty(){
        if(top==-1)
        return true;
        else return false;
    }
    void topelement(){
        if(!isempty())
            cout<<ar[top]<<'\n';
        else
            cout<<"stack is empty so no top element is present."<<'\n';
    }
    void chapo(){
        cout<<endl;
        for(int i=0;i<=top;i++){
            cout<<ar[i]<<" ";
        }
    }

};
int main(){
    int sz;
    cout<<"enter no of elemenets for stack: ";
    cin>>sz;
    stpr ob(sz);
    ob.push();
    ob.pop();
    if(ob.isempty())
        cout<<"khali h.\n";
    else 
        ob.topelement();
    ob.chapo();
    return 0;
}
