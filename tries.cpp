
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
class Node{
    public : 
    char data;
    bool isTerminal;
    unordered_map<char,Node*>children;
    Node(char ch){
        this->data=ch;
        this->isTerminal=false;
    }

};
class Trie{
    public : 
    Node *root;
    Trie(){
        this->root= new Node('\0');
    }

    void insert(string str){
        Node *temp=this->root;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }
            else{
                Node *n=new Node(ch);
                temp->children[ch]=n;
                temp=n;
            }
        }
        temp->isTerminal=true;
        return ;
    }

    bool search(string str){
        Node *temp=this->root;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }
            else{
                return false;
            }
        }
        return (temp->isTerminal==true);


    }
    void helperDFS(Node *root,string str,string osf){
        if(root==NULL){
            return ;

        }
        if(root->isTerminal){
            cout<<str+osf<<"\n";
        }
        for(auto ch : root->children){
            helperDFS(ch.second,str,osf+ch.first);
        }

    }
    void printPrefix(string str){
        Node *temp=this->root;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }
            else{
                cout<<"its not present";
                return ;
            }
        }
        helperDFS(temp,str,"");
    }
};

int main()
{
   // I_O();
    string str;
    int t;
    cin>>t;
    Trie tr;
    while(t--){
        cin>>str;
        tr.insert(str);
    }
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        cout<<((tr.search(str)==true) ? "YES" : "NO");
    }
    int prefix;
    cin>>prefix;
    while(prefix--){
        string str;
        cin>>str;
        cout<<"Prefixes ans"<<endl;
        tr.printPrefix(str);
    }

}
