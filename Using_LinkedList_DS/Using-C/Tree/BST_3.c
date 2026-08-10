#include<stdio.h>
#include<stdlib.h>


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

// Function Declarations

struct BST_Node* CreateNode(int);
struct BST* CreateTree(void);
void Insert(struct BST*, int);
struct BST_Node* SearchNode(struct BST_Node*, int);
int Search(struct BST*, int);
void Enqueue(struct Queue*, struct BST_Node*);
struct BST_Node* Dequeue(struct Queue* );
int IsQueueEmpty(struct Queue* );

void Inorder(struct BST_Node* );
void Preorder(struct BST_Node* );
void Postorder(struct BST_Node* );
void LevelOrder(struct BST* );

struct BST_Node* Minimum(struct BST_Node* );
struct BST_Node* Maximum(struct BST_Node* );

struct BST_Node* InorderSuccessorNode(struct BST_Node* );
struct BST_Node* InorderPredecessorNode(struct BST_Node* );

int InorderSuccessor(struct BST*, int);
int InorderPredecessor(struct BST*, int);

void DeleteNode(struct BST*, int);

struct BST_Node* CreateNode(int data)
{
    struct BST_Node* newnode = (struct BST_Node* )malloc(sizeof(struct BST_Node ));

    if(newnode == NULL)
    {
        printf("Memory allocation failed...\n");
        exit(EXIT_FAILURE);
    }

    newnode -> data = data;
    newnode -> parent = NULL;
    newnode -> left = NULL;
    newnode -> right = NULL;

    return newnode;
}

struct BST* CreateTree(void)
{
    struct BST* tree = (struct BST* )malloc(sizeof(struct BST ));

    if(tree == NULL)
    {
        printf("Memory allocation failed..\n");
        exit(EXIT_FAILURE);
    }

    tree -> root = NULL;
    tree -> nr_elements = 0;
}


void Insert(struct BST* tree, int data)
{
    struct BST_Node* newnode = CreateNode(data);
    struct BST_Node* temp;

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
    struct BST_Node* temp = root;

    while(temp != NULL)
    {
        if(temp -> data == data)
        {
            return temp;
        }
        
        if(data < root -> data)
        {
            temp = temp -> left;
        }
        else
        {
            temp = temp -> right;
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
    else
    {
        return 0;
    }
}

void Enqueue(struct Queue* q, struct BST_Node* node)
{
    struct QueueNode* temp;

    temp = (struct QueueNode* )malloc(sizeof(struct QueueNode));

    temp -> tNode = node;
    temp -> next = NULL;

    if(q -> rear == NULL)
    {
        q -> front = temp;
        q -> rear = temp;
        return;
    }

    q->rear->next = temp;
    q -> rear = temp;
}

struct BST_Node* Dequeue(struct Queue* q)
{
    struct QueueNode* temp;
    struct BST_Node* node;

    if(q -> front == NULL)
    {
        return NULL;
    }

    temp = q -> front;

    node = temp -> tNode;

    q -> front = q -> front -> next;

    if(q -> front == NULL)
    {
        q -> rear = NULL;
    }

    free(temp);

    return node;
}

int IsQueueEmpty(struct Queue * Q)
{
    if(Q -> front == NULL)
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
        printf("[%d] -> ",root -> data);
        Inorder(root -> right);
    }
}


void Preorder(struct BST_Node* root)
{
    if(root != NULL)
    {
        printf("[%d] -> ",root -> data);
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
        printf("[%d] -> ",root -> data);
    }
}

void LevelOrder(struct BST* tree)
{
    struct Queue q;
    struct BST_Node *temp;

    if(tree -> root == NULL)
    {
        return;
    }

    q.front = NULL;
    q.rear = NULL;

    Enqueue(&q, tree -> root);

    printf("[START]->");

    while(!IsQueueEmpty(&q))
    {
        temp = Dequeue(&q);

        printf("[%d]->",temp -> data);

        if(temp -> left != NULL)
        {
            Enqueue(&q, temp -> left);
        }

        if(temp -> right != NULL)
        {
            Enqueue(&q, temp -> right);
        }
    }

    printf("[END]\n");
}

struct BST_Node* Minimum(struct BST_Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    while(root -> left != NULL)
    {
        root = root -> left;
    }

    return root;
}

struct BST_Node* Maximum(struct BST_Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    while(root -> right != NULL)
    {
        root = root -> right;
    }

    return root;
}

struct BST_Node* InorderSuccessorNode(struct BST_Node* node)
{
    struct BST_Node* x;
    struct BST_Node* y;

    if(node == NULL)
    {
        return NULL;
    }

    if(node -> right != NULL)
    {
        x = node -> right;

        while(x -> left != NULL)
        {
            x = x-> left;
        }

        return x;
    }

    x = node;
    y = x -> parent;

    while(y != NULL && x == y -> right)
    {
        x = y;
        y = y -> parent;
    }

    return y;
}

struct BST_Node* InorderPredecessorNode(struct BST_Node* node)
{
    struct BST_Node* x;
    struct BST_Node* y;

    if(node == NULL)
    {
        return NULL;
    }

    if(node -> left != NULL)
    {
        x = node -> left;

        while(x -> right != NULL)
        {
            x = x-> right;
        }

        return x;
    }

    x = node;
    y = x -> parent;

    while(y != NULL && x == y -> left)
    {
        x = y;
        y = y -> parent;
    }

    return y;
}