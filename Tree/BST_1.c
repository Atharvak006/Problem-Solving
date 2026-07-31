#include<stdio.h>
#include<stdlib.h>

// Structures 
struct BST_Node
{
    int data;
    struct BST_Node* left;
    struct BST_Node* right;
    struct BST_Node* parent;
};

struct BST
{
    struct BST_Node* root;
    int nr_elements;
};

struct QueueNode
{
    struct BST_Node* tNode;
    struct QueueNode* next;
};

struct Queue
{
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct BST_Node* CreateNode(int);

struct BST* CreateTree(void);

void Insert(struct BST*, int);

struct BST_Node* SearchNode(struct BST_Node*, int);

int Search(struct BST* ,int);

void Enqueue(struct Queue* , struct BST_Node*);

struct BST_Node* Dequeue(struct Queue* );

int isQueueEmpty(struct Queue* );

void Inorder(struct BST_Node* );

void Preorder(struct BST_Node* );

void Postorder(struct BST_Node* );

void LevelOrder(struct BST* );

struct BST_Node* Minimum(struct BST_Node* );
struct BST_Node* Maximum(struct BST_Node* );

struct BST_Node* InOrderSuccessorNode(struct BST_Node* );
struct BST_Node* InOrderPredecessorNode(struct BST_Node* );

int InOrderSuccessor(struct BST* , int);
int InOrderPredecessor(struct BST* , int);

void DeleteNode(struct BST* , int);

/*
    CREATE NODE
*/

struct BST_Node* CreateNode(int data)
{
    struct BST_Node* newnode = (struct BST_Node* )malloc(sizeof(struct BST_Node));

    if(newnode == NULL)
    {
        printf("Memory allocation Failed\n");
        exit(EXIT_FAILURE);
    }    

    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> parent = NULL;
    newnode -> data = data;

    return newnode;
}

struct BST* CreateTree(void)
{
    struct BST* tree = (struct BST* )malloc(sizeof(struct BST ));

    if(tree == NULL)
    {
        printf("Memory allocation failed \n");
        exit(EXIT_FAILURE);
    }

    tree -> root = NULL;
    tree -> nr_elements = 0;
    
    return tree;
}


void Insert(struct BST* tree, int data)
{
    struct BST_Node* newnode;

    struct BST_Node* temp;

    newnode = CreateNode(data);

    if(tree -> root == NULL)
    {
        tree -> root = newnode;
        tree -> nr_elements++;
        return;
    }

    temp = tree -> root;

    while(1)
    {
        if(data <= temp -> data)
        {
            if(temp -> left == NULL)
            {
                temp -> left = newnode;
                newnode -> parent = temp;
                break;
            }

            temp = temp -> left;
        }
        else
        {
            if(temp -> right == NULL)
            {
                temp -> right = newnode;
                newnode -> parent = temp;
                break;
            }

            temp = temp -> right;
        }
    }

    tree -> nr_elements++;
}

struct BST_Node* SearchNode(struct BST_Node* root, int data)
{
    while(root != NULL)
    {
        if(data == root -> data)
        {
            return root;
        }

        if(data < root -> data)
        {
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }

    return NULL;
}

int Search(struct BST* tree, int data)
{
    if(SearchNode(tree -> root, data) != NULL)
    {
        return 1;
    }

    return 0;
}

void Inorder(struct BST_Node* root)
{
    if(root != NULL)
    {
        Inorder(root -> left);
        printf("[%d]->",root->data);
        Inorder(root -> right);
    }
}

void Preorder(struct BST_Node* root)
{
    if(root != NULL)
    {
        printf("[%d]->",root->data);
        Preorder(root -> left);
        Preorder(root -> right);
    }
}

void Postorder(struct BST_Node* root)
{
    if(root != NULL)
    {
        Postorder(root -> left);
        Postorder(root -> right);
        printf("[%d]->",root->data);
    }
}


int main(void)
{
    struct BST* T;
    struct BST_Node* v;

    int L[] = {100,50,150,25,75,125,200,15,17,130,135};


    int i = 0;

    T = CreateTree();

    printf("Before Inserting: \n");
    printf("No of elements : %d\n\n",T->nr_elements);

    /*
        Insert
    */

    for(i = 0; i < 11; i++)
    {
        Insert(T,L[i]);
    }

    printf("After Inserting: \n");

    printf("Root : %d\n", T->root->data);
    printf("No of elements : %d\n\n", T->nr_elements);

    printf("Inorder Traversal:\n");
    Inorder(T->root);
    printf("\n\n");

    printf("Preorder Traversal:\n");
    Preorder(T->root);
    printf("\n\n");

    printf("Postorder Traversal:\n");
    Postorder(T->root);
    printf("\n\n");

    printf("Search 75 : %s\n", Search(T, 75) ? "Found" : "Not Found");
    printf("Search 500 : %s\n", Search(T, 500) ? "Found" : "Not Found");
    
    return 0;
}