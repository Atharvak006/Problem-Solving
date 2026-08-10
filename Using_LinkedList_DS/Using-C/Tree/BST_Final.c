#include<stdio.h>
#include<stdlib.h>

/*----------------------------------------------------------
    BST NODE
----------------------------------------------------------*/

struct BST_node
{
    int data;
    struct BST_node *left;
    struct BST_node *right;
    struct BST_node *parent;
};

/*----------------------------------------------------------
    BST
----------------------------------------------------------*/

struct BST
{
    struct BST_node *root;
    int nr_elements;
};

/*----------------------------------------------------------
    QUEUE NODE
----------------------------------------------------------*/

struct QueueNode
{
    struct BST_node *tNode;
    struct QueueNode *next;
};

/*----------------------------------------------------------
    QUEUE
----------------------------------------------------------*/

struct Queue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};

/*----------------------------------------------------------
    FUNCTION DECLARATIONS
----------------------------------------------------------*/

struct BST_node* CreateNode(int);

struct BST* CreateTree(void);

void Insert(struct BST*, int);

struct BST_node* SearchNode(struct BST_node*, int);

int Search(struct BST*, int);

void Enqueue(struct Queue*, struct BST_node*);

struct BST_node* Dequeue(struct Queue*);

int IsQueueEmpty(struct Queue*);

/* Traversals */

void Inorder(struct BST_node*);
void Preorder(struct BST_node*);
void Postorder(struct BST_node*);
void LevelOrder(struct BST*);

/* Min / Max */

struct BST_node* Minimum(struct BST_node*);
struct BST_node* Maximum(struct BST_node*);

/* Successor / Predecessor */

struct BST_node* InorderSuccessorNode(struct BST_node*);
struct BST_node* InorderPredecessorNode(struct BST_node*);

int InorderSuccessor(struct BST*, int);
int InorderPredecessor(struct BST*, int);

/* Delete */

void DeleteNode(struct BST*, int);

/*----------------------------------------------------------
    CREATE NODE
----------------------------------------------------------*/

struct BST_node* CreateNode(int data)
{
    struct BST_node *newnode;

    newnode = (struct BST_node*)malloc(sizeof(struct BST_node));

    if(newnode == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    newnode->data = data;

    return newnode;
}

/*----------------------------------------------------------
    CREATE TREE
----------------------------------------------------------*/

struct BST* CreateTree(void)
{
    struct BST *tree;

    tree = (struct BST*)malloc(sizeof(struct BST));

    if(tree == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    tree->root = NULL;
    tree->nr_elements = 0;

    return tree;
}

/*----------------------------------------------------------
    INSERT
----------------------------------------------------------*/

void Insert(struct BST *tree, int data)
{
    struct BST_node *newnode;
    struct BST_node *run;

    newnode = CreateNode(data);

    if(tree->root == NULL)
    {
        tree->root = newnode;
        tree->nr_elements++;
        return;
    }

    run = tree->root;

    while(1)
    {
        if(data <= run->data)
        {
            if(run->left == NULL)
            {
                run->left = newnode;
                newnode->parent = run;
                break;
            }

            run = run->left;
        }
        else
        {
            if(run->right == NULL)
            {
                run->right = newnode;
                newnode->parent = run;
                break;
            }

            run = run->right;
        }
    }

    tree->nr_elements++;
}

/*----------------------------------------------------------
    SEARCH NODE
----------------------------------------------------------*/

struct BST_node* SearchNode(struct BST_node *root, int data)
{
    while(root != NULL)
    {
        if(data == root->data)
            return root;

        if(data < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return NULL;
}

/*----------------------------------------------------------
    SEARCH
----------------------------------------------------------*/

int Search(struct BST *tree, int data)
{
    if(SearchNode(tree->root, data) != NULL)
        return 1;

    return 0;
}

/*----------------------------------------------------------
    QUEUE FUNCTIONS
----------------------------------------------------------*/

void Enqueue(struct Queue *Q, struct BST_node *node)
{
    struct QueueNode *temp;

    temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));

    temp->tNode = node;
    temp->next = NULL;

    if(Q->rear == NULL)
    {
        Q->front = temp;
        Q->rear = temp;
        return;
    }

    Q->rear->next = temp;
    Q->rear = temp;
}

struct BST_node* Dequeue(struct Queue *Q)
{
    struct QueueNode *temp;
    struct BST_node *node;

    if(Q->front == NULL)
        return NULL;

    temp = Q->front;

    node = temp->tNode;

    Q->front = Q->front->next;

    if(Q->front == NULL)
        Q->rear = NULL;

    free(temp);

    return node;
}

int IsQueueEmpty(struct Queue *Q)
{
    if(Q->front == NULL)
        return 1;

    return 0;
}

/*----------------------------------------------------------
    INORDER
----------------------------------------------------------*/

void Inorder(struct BST_node *root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        printf("[%d]->", root->data);
        Inorder(root->right);
    }
}

/*----------------------------------------------------------
    PREORDER
----------------------------------------------------------*/

void Preorder(struct BST_node *root)
{
    if(root != NULL)
    {
        printf("[%d]->", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

/*----------------------------------------------------------
    POSTORDER
----------------------------------------------------------*/

void Postorder(struct BST_node *root)
{
    if(root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("[%d]->", root->data);
    }
}

/*----------------------------------------------------------
    LEVEL ORDER
----------------------------------------------------------*/

void LevelOrder(struct BST *tree)
{
    struct Queue Q;
    struct BST_node *temp;

    if(tree->root == NULL)
        return;

    Q.front = NULL;
    Q.rear = NULL;

    Enqueue(&Q, tree->root);

    printf("[START]->");

    while(!IsQueueEmpty(&Q))
    {
        temp = Dequeue(&Q);

        printf("[%d]->", temp->data);

        if(temp->left != NULL)
            Enqueue(&Q, temp->left);

        if(temp->right != NULL)
            Enqueue(&Q, temp->right);
    }

    printf("[END]\n");
}

/*----------------------------------------------------------
    MINIMUM
----------------------------------------------------------*/

struct BST_node* Minimum(struct BST_node *root)
{
    if(root == NULL)
        return NULL;

    while(root->left != NULL)
        root = root->left;

    return root;
}

/*----------------------------------------------------------
    MAXIMUM
----------------------------------------------------------*/

struct BST_node* Maximum(struct BST_node *root)
{
    if(root == NULL)
        return NULL;

    while(root->right != NULL)
        root = root->right;

    return root;
}

/*----------------------------------------------------------
    INORDER SUCCESSOR NODE
----------------------------------------------------------*/

struct BST_node* InorderSuccessorNode(struct BST_node *node)
{
    struct BST_node *x;
    struct BST_node *y;

    if(node == NULL)
        return NULL;

    if(node->right != NULL)
    {
        x = node->right;

        while(x->left != NULL)
            x = x->left;

        return x;
    }

    x = node;
    y = x->parent;

    while(y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*----------------------------------------------------------
    INORDER PREDECESSOR NODE
----------------------------------------------------------*/

struct BST_node* InorderPredecessorNode(struct BST_node *node)
{
    struct BST_node *x;
    struct BST_node *y;

    if(node == NULL)
        return NULL;

    if(node->left != NULL)
    {
        x = node->left;

        while(x->right != NULL)
            x = x->right;

        return x;
    }

    x = node;
    y = x->parent;

    while(y != NULL && x == y->left)
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*----------------------------------------------------------
    INORDER SUCCESSOR
----------------------------------------------------------*/

int InorderSuccessor(struct BST *tree, int data)
{
    struct BST_node *node;
    struct BST_node *succ;

    node = SearchNode(tree->root, data);

    if(node == NULL)
    {
        printf("Invalid Data\n");
        return -1;
    }

    succ = InorderSuccessorNode(node);

    if(succ == NULL)
    {
        printf("%d has no successor\n", data);
        return -1;
    }

    return succ->data;
}

/*----------------------------------------------------------
    INORDER PREDECESSOR
----------------------------------------------------------*/

int InorderPredecessor(struct BST *tree, int data)
{
    struct BST_node *node;
    struct BST_node *pred;

    node = SearchNode(tree->root, data);

    if(node == NULL)
    {
        printf("Invalid Data\n");
        return -1;
    }

    pred = InorderPredecessorNode(node);

    if(pred == NULL)
    {
        printf("%d has no predecessor\n", data);
        return -1;
    }

    return pred->data;
}
/*----------------------------------------------------------
    DELETE NODE
----------------------------------------------------------*/

void DeleteNode(struct BST *tree, int data)
{
    struct BST_node *z;
    struct BST_node *y;

    z = SearchNode(tree->root, data);

    if(z == NULL)
    {
        printf("%d : Invalid Data\n", data);
        return;
    }

    /*-------------------------------
        CASE 1 : NO LEFT CHILD
    -------------------------------*/

    if(z->left == NULL)
    {
        if(z->parent == NULL)
        {
            tree->root = z->right;
        }
        else if(z == z->parent->left)
        {
            z->parent->left = z->right;
        }
        else
        {
            z->parent->right = z->right;
        }

        if(z->right != NULL)
            z->right->parent = z->parent;

        free(z);
    }

    /*-------------------------------
        CASE 2 : NO RIGHT CHILD
    -------------------------------*/

    else if(z->right == NULL)
    {
        if(z->parent == NULL)
        {
            tree->root = z->left;
        }
        else if(z == z->parent->left)
        {
            z->parent->left = z->left;
        }
        else
        {
            z->parent->right = z->left;
        }

        if(z->left != NULL)
            z->left->parent = z->parent;

        free(z);
    }

    /*-------------------------------
        CASE 3 : TWO CHILDREN
    -------------------------------*/

    else
    {
        y = z->right;

        while(y->left != NULL)
            y = y->left;

        if(y != z->right)
        {
            y->parent->left = y->right;

            if(y->right != NULL)
                y->right->parent = y->parent;

            y->right = z->right;
            y->right->parent = y;
        }

        y->left = z->left;
        y->left->parent = y;

        if(z->parent == NULL)
        {
            tree->root = y;
        }
        else if(z == z->parent->left)
        {
            z->parent->left = y;
        }
        else
        {
            z->parent->right = y;
        }

        y->parent = z->parent;

        free(z);
    }

    tree->nr_elements--;
}

/*----------------------------------------------------------
    MAIN
----------------------------------------------------------*/

int main(void)
{
    struct BST *T;
    struct BST_node *v;

    int L[] = {100,50,150,25,75,125,200,15,17,130,135};
    int nL[] = {-100,-200,5000,1000,3565,34635};

    int L2[] = {100,50,150,40,60,200,55,70,175,250,
                80,160,180,225,275,158,210,155,156};

    int i;

    /*------------------------------------------
        CREATE TREE
    ------------------------------------------*/

    T = CreateTree();

    printf("Root : %p\n", T->root);
    printf("No. of Elements : %d\n\n", T->nr_elements);

    /*------------------------------------------
        INSERT
    ------------------------------------------*/

    for(i = 0; i < 11; i++)
        Insert(T, L[i]);

    /*------------------------------------------
        MANUAL TRAVERSAL
    ------------------------------------------*/

    printf("MANUAL TRAVERSAL\n\n");

    v = T->root;

    printf("%d\n", v->data);
    printf("%d\n", v->left->data);
    printf("%d\n", v->right->data);
    printf("%d\n", v->left->left->data);
    printf("%d\n", v->left->right->data);
    printf("%d\n", v->right->left->data);
    printf("%d\n", v->right->right->data);
    printf("%d\n", v->left->left->left->data);
    printf("%d\n", v->left->left->left->right->data);
    printf("%d\n", v->right->left->right->data);
    printf("%d\n\n", v->right->left->right->right->data);

    /*------------------------------------------
        TRAVERSALS
    ------------------------------------------*/

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

    /*------------------------------------------
        SEARCH PRESENT
    ------------------------------------------*/

    printf("SEARCH (Present)\n");

    for(i = 0; i < 11; i++)
    {
        if(Search(T, L[i]))
            printf("%d is present in BST\n", L[i]);
    }

    printf("\n");

    /*------------------------------------------
        SEARCH ABSENT
    ------------------------------------------*/

    printf("SEARCH (Absent)\n");

    for(i = 0; i < 6; i++)
    {
        if(!Search(T, nL[i]))
            printf("%d is not present in BST\n", nL[i]);
    }

    printf("\n");

    /*------------------------------------------
        NEW TREE
    ------------------------------------------*/

    free(T);

    T = CreateTree();

    for(i = 0; i < 19; i++)
        Insert(T, L2[i]);

    printf("Printing New Tree (Inorder)\n");
    printf("[START]->");
    Inorder(T->root);
    printf("[END]\n\n");

    /*------------------------------------------
        SUCCESSOR
    ------------------------------------------*/

    printf("Successor of 150 : %d\n",
            InorderSuccessor(T,150));

    printf("Successor of 80 : %d\n\n",
            InorderSuccessor(T,80));

    printf("ALL SUCCESSORS\n");

    for(i = 0; i < 19; i++)
    {
        int s;

        s = InorderSuccessor(T,L2[i]);

        if(s != -1)
            printf("SUCC(%d) = %d\n",L2[i],s);
    }

    printf("\n");

    /*------------------------------------------
        PREDECESSOR
    ------------------------------------------*/

    printf("ALL PREDECESSORS\n");

    for(i = 18; i >= 0; i--)
    {
        int p;

        p = InorderPredecessor(T,L2[i]);

        if(p != -1)
            printf("PRED(%d) = %d\n",L2[i],p);
    }

    printf("\n");

    /*------------------------------------------
        LEVEL ORDER
    ------------------------------------------*/

    printf("LEVEL ORDER\n");
    LevelOrder(T);

    printf("\n\n");

    /*------------------------------------------
        DELETE TEST
    ------------------------------------------*/

    printf("DELETE TEST\n\n");

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
