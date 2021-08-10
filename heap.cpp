
#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long int
using namespace std;
void I_O(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("T:\\input_output\\input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("T:\\input_output\\output.txt", "w", stdout);
#endif 
}
class Heap{
    private :
       int a[100]={0},size=0;

    public :
        int top(){
            if(empty()){
                cout<<"Heap underflow"<<endl;
                return -1;
            }

            return a[1];
        }   

        void pop(){
            swap(a[1],a[size]);
            size--;
            int node =1;
            while(left(node)<=size){
                int child;
                if(right(node)>size || a[left(node)]>a[right(node)] ){
                    child=left(node);
                }
                else{
                    child=right(node);
                }

                if(a[node]>a[child]){
                    break;
                }   
                else{
                    swap(a[child],a[node]);
                    node=child;
                }
            }

        }

        bool empty(){
            return (size==0);
        }

        void insert(int val){
            int node=++size;
            a[node]=val;
            int root=1;
            while(node!=root){
    
                int p=parent(node);
        
                if(a[p]>a[left(p)] && a[p]>a[right(p)]){
                    break;
                }
                int child=(a[left(p)]>a[right(p)]) ? left(p) : right(p);
                swap(a[child],a[p]);
                node=p; 
            }
        }

        int getSize(){
            return size;
        }

        int parent(int node){
            return node/2;
        }

        int left(int node){
            return 2*node;
        }
        int right(int node){
            return 2*node+1;
        }






};
int main()
{
    //I_O();
    Heap h;
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int p;
            cin>>p;
            h.insert(p);
        }
        else if(x==2){
            cout<<h.top();
        }
        else if(x==3){
            h.pop();
        }
    }

}
