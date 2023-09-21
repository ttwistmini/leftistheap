#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

typedef struct Node
{
   int data;
   int priority;
   Node* left;
   Node* right;

   Node(int key,int p)
   {
      data = key;
      priority = p;
      left = right = NULL;
   }
}
node;

int dist(node*);
void check_leftist(node*&);
void insert(node*&,node*&);
void deleteMax(node*&);
int minOperationsToMode(vector<int>&,int);

int main()
{
   int n,t;
   cout<<"Enter the number of elements: ";
   cin>>n;
   vector<int> A;
   cout<<"Enter the elements of the list"<<endl;
   for(int i = 0; i < n; i++)
   {
      cin>>t;
      A.push_back(t);
   }
   int M;
   cout<<"Enter the value of M: ";
   cin>>M;
   int result = minOperationsToMode(A, M);
   cout<<"Minimum operations to make "<<M<<" the mode: "<<result<<endl;
   return 0;
}

int dist(node* root)
{
   if(root == NULL)
      return -1;
   else
      return min(dist(root->left),dist(root->right))+1;
}

void check_leftist(node*& root)
{
   if(dist(root) != dist(root->right)+1)
   {
      swap(root->left,root->right);
   }
}

void insert(node*& root,node*& key)
{
   if(root == NULL)
   {
      root = key;
      return;
   }
   if(key == NULL)
      return;
   if(root->priority >= key->priority)
   {
      if(root->left == NULL)
         insert(root->left,key);
      else if(root->right == NULL)
         insert(root->right,key);
      else
      {
         insert(root->right,key);
      }
   }
   else if(root->priority < key->priority)
   {
      swap(root,key);
      insert(root,key);
   }
   check_leftist(root);
}

void deleteMax(node*& root)
{
   node* temp = root;
   insert(root->left,root->right);
   root = root->left;
   delete temp;
}

int minOperationsToMode(vector<int>& A, int M)
{
   unordered_map<int, int> freqMap;
   for(int num : A)
   {
      freqMap[num]++;
   }

   node* pq = NULL;
   node* temp = NULL;
   for(const auto& entry : freqMap)
   {
      int num = entry.first;
      if(num == M)
         continue;
      int freq = entry.second;
      temp = new node(num,freq);
      insert(pq,temp);
   }

   int operations = 0;

   while(pq->priority > freqMap[M])
   {
      int num = pq->data;
      int freq = pq->priority;
      deleteMax(pq);
      if(freq - 1 != 0)
      {
         node* t = new node(num,freq-1);
         insert(pq,t);
      }

      operations++;
      freqMap[M]++;
      freqMap[num]--;
   }

   return operations;
}
