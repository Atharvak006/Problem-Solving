#include <stdio.h>

#define MAX_VERTICES 20
#define MAX_EDGES 20


/*================ GRAPH =================*/

struct HList
{
    int arr[MAX_EDGES];
    int size;
};

struct VNode
{
    int val;
    struct HList adjList;
    int exists;
};

struct Graph
{
    struct VNode vertices[MAX_VERTICES];

    int nrVertices;
    int nrEdges;
};


/*================ INITIALIZATION =================*/

void InitHList(struct HList *list)
{
    list->size = 0;
}


void InitGraph(struct Graph *G)
{
    int i;

    for(i = 0; i < MAX_VERTICES; i++)
    {
        G->vertices[i].exists = 0;
        G->vertices[i].val = -1;

        InitHList(&G->vertices[i].adjList);
    }

    G->nrVertices = 0;
    G->nrEdges = 0;
}


/*================ HLIST =================*/

int HSearch(struct HList *list, int v)
{
    int i;

    for(i = 0; i < list->size; i++)
    {
        if(list->arr[i] == v)
        {
            return i;
        }
    }

    return -1;
}


void HInsertEnd(struct HList *list, int v)
{
    if(list->size >= MAX_EDGES)
    {
        printf("Adjacency list is full\n");
        return;
    }

    list->arr[list->size] = v;
    list->size++;
}


void HDelete(struct HList *list, int index)
{
    int i;

    for(i = index; i < list->size - 1; i++)
    {
        list->arr[i] = list->arr[i + 1];
    }

    list->size--;
}


/*================ VLIST =================*/

int VSearch(struct Graph *G, int v)
{
    int i;

    for(i = 0; i < MAX_VERTICES; i++)
    {
        if(G->vertices[i].exists == 1 &&
           G->vertices[i].val == v)
        {
            return i;
        }
    }

    return -1;
}


/*================ ADD VERTEX =================*/

void AddVertex(struct Graph *G, int v)
{
    int index;

    if(VSearch(G, v) != -1)
    {
        printf("Vertex %d already Exists !!!\n", v);
        return;
    }

    for(index = 0; index < MAX_VERTICES; index++)
    {
        if(G->vertices[index].exists == 0)
        {
            G->vertices[index].val = v;
            G->vertices[index].exists = 1;

            InitHList(&G->vertices[index].adjList);

            G->nrVertices++;

            return;
        }
    }

    printf("Vertex array is full\n");
}


/*================ ADD EDGE =================*/

void AddEdge(struct Graph *G, int start, int end)
{
    int vStart = VSearch(G, start);
    int vEnd = VSearch(G, end);

    if(vStart == -1 || vEnd == -1)
    {
        printf("Vertex not found..!!!\n");
        return;
    }

    if(HSearch(&G->vertices[vStart].adjList, end) != -1 &&
       HSearch(&G->vertices[vEnd].adjList, start) != -1)
    {
        printf("Edge Already exists!!!\n");
        return;
    }

    HInsertEnd(&G->vertices[vStart].adjList, end);
    HInsertEnd(&G->vertices[vEnd].adjList, start);

    G->nrEdges++;
}


/*================ REMOVE EDGE =================*/

void RemoveEdge(struct Graph *G, int start, int end)
{
    int vStart = VSearch(G, start);
    int vEnd = VSearch(G, end);

    if(vStart == -1 || vEnd == -1)
    {
        printf("Vertex not found..!!!\n");
        return;
    }

    int p = HSearch(&G->vertices[vStart].adjList, end);
    int q = HSearch(&G->vertices[vEnd].adjList, start);

    if(p == -1 || q == -1)
    {
        printf("Edge not present\n");
        return;
    }

    HDelete(&G->vertices[vStart].adjList, p);
    HDelete(&G->vertices[vEnd].adjList, q);

    G->nrEdges--;
}


/*================ REMOVE VERTEX =================*/

void RemoveVertex(struct Graph *G, int v)
{
    int r = VSearch(G, v);

    if(r == -1)
    {
        printf("Vertex Not found..\n");
        return;
    }

    /*
        Remove all edges connected to vertex v.
    */

    while(G->vertices[r].adjList.size > 0)
    {
        int neighbour =
            G->vertices[r].adjList.arr[0];

        int adj = VSearch(G, neighbour);

        int tmp =
            HSearch(&G->vertices[adj].adjList, v);

        HDelete(&G->vertices[adj].adjList, tmp);

        HDelete(&G->vertices[r].adjList, 0);

        G->nrEdges--;
    }

    /*
        Remove the vertex itself.
    */

    G->vertices[r].exists = 0;
    G->vertices[r].val = -1;

    InitHList(&G->vertices[r].adjList);

    G->nrVertices--;
}


/*================ PRINT GRAPH =================*/

void PrintGraph(struct Graph *G, char *msg)
{
    int i;
    int j;

    printf("\n%s\n", msg);

    printf("|G.V| = %d |G.E| = %d\n",
           G->nrVertices,
           G->nrEdges);

    for(i = 0; i < MAX_VERTICES; i++)
    {
        if(G->vertices[i].exists == 1)
        {
            printf("[%d] <-> ", G->vertices[i].val);

            for(j = 0;
                j < G->vertices[i].adjList.size;
                j++)
            {
                printf("[%d] <-> ",
                       G->vertices[i].adjList.arr[j]);
            }

            printf("END\n");
        }
    }
}


/*================ MAIN =================*/

int main(void)
{
    struct Graph G;

    InitGraph(&G);

    int i;

    for(i = 0; i < 8; i++)
    {
        AddVertex(&G, i);
    }


    int E[][2] =
    {
        {0,1},
        {1,2},
        {2,3},
        {3,4},
        {4,5},
        {5,6},
        {6,7},
        {7,0},
        {1,6},
        {6,3},
        {5,2},
        {7,2}
    };


    for(i = 0; i < 12; i++)
    {
        AddEdge(&G, E[i][0], E[i][1]);
    }


    PrintGraph(&G, "Initial State");


    RemoveEdge(&G, 2, 3);
    RemoveEdge(&G, 5, 6);

    PrintGraph(&G,
               "After removing edge (2,3) and (5,6)");


    RemoveVertex(&G, 3);

    PrintGraph(&G,
               "After Removing Vertex 3");


    RemoveVertex(&G, 7);

    PrintGraph(&G,
               "After Removing Vertex 7");


    return 0;
}