#include "leftistheap.h"
int main()
{
	node* root;
	for(int i=0;i<10;i++)
		root=insert(root,i);
	levelordertraversal(root);
	return 0;
}
