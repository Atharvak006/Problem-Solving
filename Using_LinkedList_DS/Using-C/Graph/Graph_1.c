#include<stdio.h>
#include<stdlib.h>

struct HNode
{
    int v;
    struct HNode* prev;
    struct HNode* next;
};

struct HList
{
    struct HNode* head;
};

struct HNode* CreateHNode(int v)
{
    struct HNode* newnode = (struct HNode* )malloc(sizeof(struct HNode));

    newnode -> next = NULL;
    newnode -> prev = NULL;
    newnode -> v = v;

    return newnode;
}

void InitHList(struct HList* list)
{
    list -> head = CreateHNode(-1);

    list -> head -> next = list -> head;
    list -> head -> prev = list -> head;
}

void HGenericInsert(struct HNode* start, struct HNode* mid, struct HNode* end)
{
    mid -> next = end;
    mid -> prev = start;

    start -> next = mid;
    end -> prev = mid;
}

void HInsertEnd(struct HList* list, int v)
{
    HGenericInsert(list -> head -> prev, CreateHNode(v), list -> head);
}

struct HNode* HSearch(struct HList* list, int v)
{
    struct HNode* run = list -> head -> next;

    while(run != list -> head)
    {
        if(run -> v == v)
        {
            return run;
        }

        run = run -> next;
    }   

    return NULL;
}

void HDelete(struct HNode* node)
{
    node -> prev -> next = node -> next;
    node -> next -> prev = node -> prev;

    free(node);
}

struct VNode
{
    int v;

    struct HList adjList;

    struct VNode* prev;
    struct VNode* next;
};

struct VList
{
    struct VNode* head;
};

struct VNode* CreateVNode(int v)
{
    struct VNode* newnode = (struct VNode* )malloc(sizeof(struct VNode));

    newnode -> v = v;
    InitHList(&newnode -> adjList);

    newnode -> prev = NULL;
    newnode -> next = NULL;

    return newnode;
}

void InitVList(struct VList* list)
{
    list -> head = CreateVNode(-1);

    list -> head -> next = list -> head;
    list -> head -> prev = list -> head;
}

void VGenericInsert(struct VNode* start, struct VNode* mid, struct VNode* end)
{
    mid -> next = end;
    mid -> prev = start;

    start -> next = mid;
    end -> prev = mid;
}

void VInsertEnd(struct VList* list, int v)
{
    VGenericInsert(list -> head -> prev, CreateVNode(v), list -> head);
}

struct VNode* VSearch(struct VList* list, int v)
{
    struct VNode* run = list -> head -> next;

    while(run != list -> head)
    {
        if(run -> v == v)
        {
            return run;
        }

        run = run -> next;
    }

    return NULL;
}

void VDelete(struct VNode* node)
{
    node -> prev -> next = node -> next;
    node -> next -> prev = node -> prev;

    free(node);
}

// Graph

struct Graph
{
    struct VList verticalList;

    int nrVertices;
    int nrEdges;
};

void InitGraph(struct Graph* G)
{
    InitVList(&G->verticalList);

    G->nrVertices = 0;
    G->nrEdges = 0;
}

void AddVertex(struct Graph *G, int v)
{
    if(VSearch(&G->verticalList,v) != NULL)
    {
        printf("Vertex %d already exists\n",v);
        return;
    }

    VInsertEnd(&G->verticalList,v);

    G->nrVertices++;
}

void AddEdge(struct Graph* G, int start, int end)
{
    struct VNode* vStart = VSearch(&G->verticalList,start);
    struct VNode* vEnd = VSearch(&G->verticalList,end);

    if(vStart == NULL || vEnd == NULL)
    {
        printf("Vertex not found\n");
        return;
    }

    if((HSearch(&vStart -> adjList,end) != NULL) && (HSearch(&vEnd->adjList,start) != NULL))
    {
        printf("Edge already exists \n");
        return;
    }

    HInsertEnd(&vStart -> adjList,end);
    HInsertEnd(&vEnd -> adjList,start);

    G->nrEdges++;
}

void RemoveEdge(struct Graph* G, int start, int end)
{
    struct VNode* vStart = VSearch(&G->verticalList,start);
    struct VNode* vEnd = VSearch(&G->verticalList,end);


    if(vStart == NULL || vEnd == NULL)
    {
        printf("Vertex Not Found\n");
        return;
    }

    struct HNode* p = HSearch(&vStart -> adjList, end);
    struct HNode* q = HSearch(&vEnd -> adjList, start);

    if(p == NULL || q == NULL)
    {
        printf("Edge Not present\n");
        return;
    }

    HDelete(p);
    HDelete(q);

    G->nrEdges--;
}

void RemoveVertex(struct Graph *G, int v)
{
    struct VNode* r = VSearch(&G->verticalList,v);

    if(r == NULL)
    {
        printf("Vertex Not found\n");
        return;
    }

    struct HNode* run = r -> adjList.head -> next;

    while(run != r->adjList.head)
    {
        struct HNode* next = run -> next;

        struct VNode* adj = VSearch(&G->verticalList,run -> v);

        struct HNode* tmp = HSearch(&adj->adjList,v);

        HDelete(tmp);

        HDelete(run);

        G->nrEdges--;

        run = next;
    }

    VDelete(r);

    G->nrVertices--;
}

void PrintGraph(struct Graph *G, char *msg)
{
    printf("\n%s\n",msg);

    printf("|G.V| = %d |G.E| = %d\n",G->nrVertices,G->nrEdges);


    struct VNode* vrun = G->verticalList.head->next;

    while(vrun != G->verticalList.head)
    {
        printf("[%d] <-> ",vrun -> v);

        struct HNode* hrun = vrun -> adjList.head->next;

        while(hrun != vrun -> adjList.head)
        {
            printf("[%d] <-> ",hrun -> v);

            hrun = hrun -> next;
        }

        printf("END\n");

        vrun = vrun -> next;
    }
}

int main(void)
{   
    struct Graph G;

    InitGraph(&G);

    int i;

    for(i = 0; i < 8; i++)
    {
        AddVertex(&G,i);
    }

    int E[][2] = {
        {0,1},{1,2},{2,3},{3,4},
        {4,5},{5,6},{6,7},{7,0},
        {1,6},{6,3},{5,2},{7,2}
    };

    for(i = 0; i < 12; i++)
    {
        AddEdge(&G,E[i][0], E[i][1]);
    }

    PrintGraph(&G,"Initial State");

    RemoveEdge(&G,2,3);
    RemoveEdge(&G,5,6);

    printf("After removing edge (2,3) and (5,6)\n");

    RemoveVertex(&G,3);

    PrintGraph(&G,"After Removing Vertex 3");

    RemoveVertex(&G,7);

    PrintGraph(&G,"After Removing Vertex 7");

    return 0;
}