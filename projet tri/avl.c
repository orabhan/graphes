

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "avl.h"


/*
    remove all nodes of an AVL tree
*/
void dispose(node *t)
{
    if( t != NULL )
    {
        dispose( t->left );
        dispose( t->right );
        free( t );
    }
}

/*
    find a specific node's key in the tree
*/
node *find(int e, node *t )
{
    if( t == NULL )
        return NULL;
    if( e < t->data )
        return find( e, t->left );
    else if( e > t->data )
        return find( e, t->right );
    else
        return t;
}

/*
    find minimum node's key
*/
node *find_min( node *t )
{
    if( t == NULL )
        return NULL;
    else if( t->left == NULL )
        return t;
    else
        return find_min( t->left );
}


   /*/ trouver maximum NODE's clé/*/

node *find_max( node *t )
{
    if( t != NULL )
        while( t->right != NULL )
            t = t->right;

    return t;
}

//trouver le hauteur de AVL//
static int height( node *n )
{
    if( n == NULL )
        return -1;
    else
        return n->height;
}

//return le max de 2 int//
static int max( int l, int r)
{
    return l > r ? l: r;
}

//une rotation a gauche//

static node *single_rotate_with_left( node *k2 )
{
    node* k1 = NULL;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    return k1;
}

//une rotation a droite//

static node *single_rotate_with_right( node *k1 )
{
    node* k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
    k2->height = max( height( k2->right ), k1->height ) + 1;

    return k2;
}

//double rotation a gauche //

static node *double_rotate_with_left( node *k3 )
{
    /* Rotation entre k1 et k2 */
    k3->left = single_rotate_with_right( k3->left );

    /* rotation entre k2 et k3 */
    return single_rotate_with_left( k3 );
}

//double rotation a droite//


static node *double_rotate_with_right( node *k1 )
{
    /* rotation entre K3 et k2 */
    k1->right = single_rotate_with_left( k1->right );

    /* rotation entre k1 and k2 */
    return single_rotate_with_right( k1 );
}

//insérer un nouveau noeud dans l'arbre//

node *insert(int e, node *t )
{
    if( t == NULL )
    {
        /* créer un noeud */
        t = (node*)malloc(sizeof(node));
        if( t == NULL )
        {
            fprintf (stderr, "Out of memory!!! (insert)\n");
            exit(1);
        }
        else
        {
            t->data = e;
            t->height = 0;
            t->left = t->right = NULL;
        }
    }
    else if( e < t->data )
    {
        t->left = insert( e, t->left );
        if( height( t->left ) - height( t->right ) == 2 )
            if( e < t->left->data )
                t = single_rotate_with_left( t );
            else
                t = double_rotate_with_left( t );
    }
    else if( e > t->data )
    {
        t->right = insert( e, t->right );
        if( height( t->right ) - height( t->left ) == 2 )
            if( e > t->right->data )
                t = single_rotate_with_right( t );
            else
                t = double_rotate_with_right( t );
    }


    t->height = max( height( t->left ), height( t->right ) ) + 1;
    return t;
}

// supprimer un noeud de l'arbre//

node *delet( int e, node *t )
{
    printf( "Sorry; Delete is unimplemented; %d remains\n", e );
    return t;
}


//afficher l'arbre//
void display_avl(node *t)
{
    if (t == NULL)
        return;
    printf("%d",t->data);

    if(t->left != NULL)
        printf("(L:%d)",t->left->data);
    if(t->right != NULL)
        printf("(R:%d)",t->right->data);
    printf("\n");

    display_avl(t->left);
    display_avl(t->right);
}

void Inorder(node *t)
{

    if(t!=NULL)
    {
Inorder(t->left);

printf("%d ",t->data);

Inorder(t->right);
    }

}

