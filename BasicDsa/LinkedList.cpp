#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}



void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

struct Node{
	Node* next;
	int data;
	Node(int data){
		this->next=NULL;
		this->data=data;
	}
};
void AddatHead(Node *&head,int data){
Node *n=new Node(data);
n->next=head;
head=n;
}
void AddAttail(Node *&head,int data){
	if(head==NULL){
		head= new Node(data);
		return;
	}
	Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new Node(data);
	return;
}
int sizeOfll(Node *head){
	int sz=0;
	while(head!=NULL){
		head=head->next;
		sz++;
	}
	return sz;
}
void insert(Node *&head,int data,int pos=0){
if(pos==0){
	AddatHead(head,data);
	return;
}
if(pos>=sizeOfll(head)){
	AddAttail(head,data);
	return;
}
Node*temp=head;
while(pos!=1){
	temp=temp->next;
	pos--;
}
Node * n=new Node(data);
n->next=temp->next;
temp->next=n;
return;
}
void deleteAtTail(Node *&head){
	Node *temp=head;
	Node *prev=NULL;
	while(temp->next!=NULL){
		prev=temp;
	    temp=temp->next;
	}
	delete temp;
	prev->next=NULL;
	return;
}
void deleteAthead(Node *&head){
if(head==NULL){
	return;
}
Node *temp=head;
head=head->next;
delete temp;
return;
}
void Delete(Node *&head,int pos=0){
if(head==NULL){
	return;
}
if(pos==0){
	deleteAthead(head);
	return;
}
if(pos>sizeOfll(head)){
	deleteAtTail(head);
	return;
}
int jump=0;
Node *temp=head;
while(jump!=1){
 pos--;
 temp=temp->next;	
}
Node *nodeTobeDeleted=temp->next;
temp->next=temp->next->next;
nodeTobeDeleted->next=NULL;
delete nodeTobeDeleted;
return;
}

void delete2(Node *&head,int pos=0){
	if(head==NULL){
	return;
}
if(pos==0){
	deleteAthead(head);
	return;
}
if(pos>sizeOfll(head)){
	deleteAtTail(head);
	return;
}
int jump=0;
Node *temp=head;
Node *prev=NULL;
while(jump<=pos-1){
 prev=temp;
 temp=temp->next;	
 pos--;
}
prev->next=temp->next;
delete temp;
return;
}

void BuildList(Node *&head){
	int data;
	cin>>data;
	while(data!=-1){
		AddAttail(head,data);
		cin>>data;
	}
}
void Disp(Node *head){
	while(head!=NULL){
		std::cout<<head->data<<" ";
		head=head->next;
	}
}

std::istream& operator >>(std::istream &is,Node *&head){
	BuildList(head);
	return is;
    
}
std::ostream& operator <<(std::ostream &os,Node *&head){
	Disp(head);
	return os;
}
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[]) {
	file_i_o();
	Node *head1=NULL;
	std::cin>>head1;
	insert(head1,56,3);
	delete2(head1,2);
	std::cout<<head1;
	return 0;
}