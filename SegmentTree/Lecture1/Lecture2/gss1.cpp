#include<bits/stdc++.h>
#define ll long long int
// https://www.spoj.com/problems/GSS1/
struct node{
    ll max_sum;
    ll sum;
    ll bps;
    ll bss;
};
void build(std::vector<ll>&arr,std::vector<node*>&tree,ll s,ll e,ll tidx){
    if(s==e){
        tree[tidx]->max_sum = tree[tidx]->sum = tree[tidx]->bps = tree[tidx]->bss = arr[s];
        return;
    }
    ll mid=s+(e-s)/2;
    build(arr,tree,s,mid,2*tidx);
    build(arr,tree,mid+1,e,2*tidx+1);
    tree[tidx]->sum=tree[2*tidx]->sum+tree[2*tidx+1]->sum;
   tree[tidx]->max_sum = std::max({tree[2*tidx]->max_sum, tree[2*tidx+1]->max_sum, tree[2*tidx]->sum + tree[2*tidx+1]->bps, tree[2*tidx+1]->sum + tree[2*tidx]->bss, tree[2*tidx]->bss+tree[2*tidx+1]->bps});
    tree[tidx]->bps=std::max({tree[2*tidx]->sum+tree[2*tidx+1]->bps,tree[2*tidx]->bps});
    tree[tidx]->bss=std::max({tree[2*tidx+1]->sum+tree[2*tidx]->bss,tree[2*tidx+1]->bss});
}
node* query(std::vector<node*>&tree,ll s,ll e,ll l,ll r,ll tidx){
    node* temp=new node();
    temp->sum=temp->max_sum=temp->bss=temp->bps=INT_MIN;
    if(r<s or l>e){
        return temp;
    }
    if(s>=l and e<=r){
        return tree[tidx];
    }
    ll mid=s+(e-s)/2;
    node *left=query(tree,s,mid,l,r,2*tidx);
    node *right=query(tree,mid+1,e,l,r,2*tidx+1);
    temp->sum=left->sum+right->sum;
    temp->bps=std::max({left->bps,right->bps+left->sum});
    temp->bss=std::max({right->bss,left->bss+right->sum});
  temp->max_sum = std::max({left->max_sum, right->max_sum, left->sum + right->bps, right->sum + left->bss, left->bss+right->bps});
    return temp;
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<ll>arr(n);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::vector<node*>tree(4*n);
    for(int i=0;i<=4*n-1;i++){
        tree[i]=new node();
    }
    build(arr,tree,0,n-1,1);
    int q;
    std::cin>>q;
    while (q--){
        int l, r;
        std::cin>>l>>r;
        std::cout<<query(tree,0,n-1,l-1,r-1,1)->max_sum<<"\n";
    }
return 0;
}