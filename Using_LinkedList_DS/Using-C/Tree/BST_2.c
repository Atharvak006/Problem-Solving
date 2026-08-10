#include<stdio.h>
#include<stdlib.h>

struct BST_Node
{
    struct BST_Node* left;
    struct BST_Node* right;
    struct BST_Node* parent;
    int data;
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
    struct BST* tree;

    tree = (struct BST* )malloc(sizeof(struct BST));

    if(tree == NULL)
    {
        printf("Memory Allocation Failed\n");
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
    struct BST_Node* temp = root;

    while(temp != NULL)
    {
        if(temp -> data == data)
        {
            return temp;
        }

        if(data <= temp -> data)
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

    while(root ->right != NULL)
    {
        root = root -> right;
    }

    return root;
}

struct BST_Node* InOrderSuccessorNode(struct BST_Node* node)
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
            x = x -> left;
        }
        return x;
    }

    x = node;
    y = x -> parent;

    while(y != NULL && x == y -> right){
        x = y;
        y = y -> parent;
    }

    return y;
}


struct BST_Node* InOrderPredecessorNode(struct BST_Node* node)
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
            x = x -> right;
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
int InorderSuccessor(struct BST* tree, int data)
{
    struct BST_Node* node;
    struct BST_Node* succ;

    node = SearchNode(tree ->root, data);

    if(node == NULL)
    {
        printf("Invalid Data\n");
        return -1;
    }

    succ = InOrderSuccessorNode(node);

    if(succ == NULL)
    {
        printf("%d has no successor\n",data);
        return -1;
    }

    return succ -> data;
}

int InorderPredecessor(struct BST* tree, int data)
{
    struct BST_Node* node;
    struct BST_Node* pred;

    node = SearchNode(tree ->root, data);

    if(node == NULL)
    {
        printf("Invalid Data\n");
        return -1;
    }

    pred = InOrderPredecessorNode(node);

    if(pred == NULL)
    {
        printf("%d has no predecessor\n",data);
        return -1;
    }

    return pred -> data;
}


int main(void)
{
    
    struct BST* T;
    struct BST_Node* v;


    int L[] = {100,50,150,25,75,125,200,15,17,130,135};
    int nL[] = {-100,-200,5000,1000,3565,34635};

    int L2[] = {100,50,150,40,60,200,55,70,175,250,80,160,180,225,275,158,210,155,156};

    int i;

    T = CreateTree();

    printf("Root: %p\n",T->root);
    printf("No of elements : %d\n\n",T->nr_elements);

    for(i=0; i < 11; i++)
    {
        Insert(T,L[i]);
    }

    printf("Manual Traversal\n\n");

    v = T -> root;

    printf("%d\n",v->data);
    printf("%d\n",v->left->data);
    printf("%d\n",v->right->data);
    printf("%d\n",v->left->left->data);
    printf("%d\n",v->right->left->data);
    printf("%d\n",v->right->right->data);
    printf("%d\n",v->left->left->left->data);
    printf("%d\n",v->left->left->left->right->data);
    printf("%d\n",v->right->left->right->data);
    printf("%d\n\n",v->right->left->right->right->data);


    printf("INORDER\n");
    printf("[START]->");
    Inorder(T->root);
    printf("[END]\n\n");

    printf("PREORDER\n");
    printf("[START]->");
    Preorder(T->root);
    printf("[END]\n\n");    

    printf("POSTORDER\n");
    printf("[START]->");
    Postorder(T->root);
    printf("[END]\n\n");  

    printf("Search (Present)\n");

    for(i=0; i < 11; i++)
    {
        if(Search(T,L[i]))
        {
            printf("%d is present in BST\n",L[i]);
        }
    }

    printf("\n");

    printf("Search (Absent)\n");

    for(i=0; i < 6; i++)
    {
        if(!Search(T,L[i]))
        {
            printf("%d is not present in BST\n",nL[i]);
        }
    }

    printf("\n");

    free(T);

    T = CreateTree();

    for(i=0;i<19;i++)
    {
        Insert(T,L2[i]);
    }
    
    printf("Printing New tree(inorder) \n");
    printf("[START] ->");
    Inorder(T->root);
    printf("[END]\n\n");

    printf("Successor of 150 : %d\n",InorderSuccessor(T,150));

    printf("Successof of 80 : %d\n",InorderSuccessor(T,80));

    printf("All successors\n");

    for(i = 0; i < 19; i++)
    {
        int s;

        s = InorderSuccessor(T,L2[i]);

        if(s != -1)
        {
            printf("SUCC(%d) = %d\n",L2[i],s);
        }

        printf("\n");
    }

    printf("All Predecessors\n");

    for(i = 0; i < 19; i++)
    {
        int p;

        p = InorderPredecessor(T,L2[i]);

        if(p != -1)
        {
            printf("Pred(%d) = %d\n",L2[i],p);
        }

        printf("\n");
    }

    printf("Delete Test \n\n");

    for(i = 0; i < 19; i++)
    {
        printf("Removing %d\n",L2[i]);

        DeleteNode(T,L2[i]);

        printf("[START]->");
        Inorder(T->root);
        printf("[END]\n\n");
    }


    return 0;
}