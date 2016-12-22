#include<bits/stdc++.h>

using namespace std;

set<char>s;
map<char,int>freq;
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
    if(!root)
        return;
    if(root->data!='~'){
        ans.push_back(make_pair(root->data,str));
    }
    What_Is_The_Answer(root->l,str+"1");
    What_Is_The_Answer(root->r,str+"0");
}

void Make_Huffman_Tree(){

    node *left,*right,*top;
    priority_queue<node*,vector<node*>,comp> MinHeap;
    for(int i=0;i<vec.size();i++){
        MinHeap.push(new node(vec[i],freq[vec[i]]));
    }
    while(MinHeap.size()!=1){
        left=MinHeap.top();
        MinHeap.pop();
        right=MinHeap.top();
        MinHeap.pop();
        top=new node('~',left->frq+right->frq);
        top->r=right;
        top->l=left;
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
    bitset<8> bits;
    while(sstream>>bits)
    {
        char c = char(bits.to_ulong());
        output += c;
    }     //in this part the binary numbers which show the ascii code alter to string
    for(int i=0;i<output.size();i++){
        freq[output[i]]++;
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