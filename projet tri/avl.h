#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int      height;
} node;

node *find(int e, node *t );
node *insert(int e, node *t );
node *delet ( int e, node *t );
void Inorder(node *t);
void display_avl(node *t);


#endif // AVL_H_INCLUDED
