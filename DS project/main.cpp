#include<bits/stdc++.h>
#include <string>
#include <sstream>
#include <bitset>
#include<map>
#include<set>
#include <queue>

using namespace std;

set<char>s;
map<char,int>frs;
vector<char>vec;
vector<pair<char,string>>ans;

struct node {
    int frq;
    node *l, *r;
    char data;
    node(char data,int frq){
        this->frq=frq;
        this->data=data;
        l= NULL;
        r= NULL;
    }
};

struct comp {
    bool operator()(node *l, node *r) {

        return (l->frq > r->frq);
    }


};

void What_Is_The_Answer(node *root,string str){
    //while(!root){
        cerr<<root->l->data<<root->r->data<<endl;
        //root=root->l;
    //}
    if(!root)
        return;
    if(root->data!='~'){
        ans.push_back(make_pair(root->data,str));
    }
    //cerr<<str<<endl;
    What_Is_The_Answer(root->l,str+"0");
    What_Is_The_Answer(root->r,str+"1");
}

void Make_Huffman_Tree(){

    node *left,*right,*top;
    priority_queue<node*,vector<node*>,comp> MinHeap;
    //cerr<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++){
        //cerr<<vec[i]<<endl;
        if(vec[i]!=NULL)
            MinHeap.push(new node(vec[i],frs[vec[i]]));
    }
    while(MinHeap.size()!=1){
        left=MinHeap.top();
        MinHeap.pop();
        right=MinHeap.top();
        MinHeap.pop();
        top=new node('~',left->frq+right->frq);
        //top->l=left;
        //top->r=right;
        top->r=left;
        top->l=right;
        MinHeap.push(top);
    }
    What_Is_The_Answer(MinHeap.top(),"");
}

int main() {

    ios::sync_with_stdio(0);

    string input ;
    cin>>input;
    stringstream sstream(input);
    string output;
    while(sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }

    //int n=output.size();
    for(int i=0;i<output.size();i++){
        frs[output[i]]++;
        s.insert(output[i]);
    }
    set<char>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        vec.push_back(*it);
    }
    Make_Huffman_Tree();
    map<char,string> ans2;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" : "<<ans[i].second<<endl;
        ans2[ans[i].first]=ans[i].second;
    }
    for(int i=0;i<output.size();i++){
        cout<<ans2[output[i]];
    }
    cout<<endl;

   return 0;
}