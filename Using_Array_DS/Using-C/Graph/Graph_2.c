#include<stdio.h>
#include<stdlib.h>

#define MAXVERTICES 20
#define MAXEDGES 20


struct HList
{
    int arr[MAXEDGES];
    int size;
};

struct VNode
{
    int val;
    struct HList adjlist;
    int exists;
};

struct Graph
{
    struct VNode vertices[MAXVERTICES];

    int nrVertices;
    int nrEdges;
};

void InitHList(struct HList* list)
{
    list -> size = 0;    
}

void InitGraph(struct Graph* G)
{
    int i;

    for(i=0; i<MAXVERTICES; i++)
    {
        G -> vertices[i].exists = 0;
        G -> vertices[i].val = -1;

        InitHList(&G->vertices[i].adjlist);
    }

    G -> nrVertices = 0;
    G -> nrEdges = 0;
}

int HSearch(struct HList* list, int v)
{
    int i;

    for(i=0; i<list -> size; i++)
    {
        if(list -> arr[i] == v)
        {
            return i;
        }
    }

    return -1;
}

void HInsertEnd(struct HList* list, int v)
{
    if(list -> size >= MAXEDGES)
    {
        printf("Adjacency List is full\n");
        return;
    }

    list -> arr[list -> size] = v;
    list -> size++;
}

void HDelete(struct HList* list, int index)
{
    int i;
    for(i=index; i<list->size-1; i++)
    {
        list -> arr[i] = list -> arr[i+1];
    }

    list -> size--;
}

int VSearch(struct Graph* G, int v)
{
    int i;

    for(i=0; i<MAXVERTICES; i++)
    {
        if(G -> vertices[i].exists == 1 && G ->vertices[i].val == v)
        {
            return i;
        }
    }
    return -1;
}

void AddVertex(struct Graph* G, int v)
{
    int index;

    if(VSearch(G,v) != -1)
    {
        printf("Vertex %d already exists !!! \n",v);
        return;
    }

    for(index = 0; index < MAXVERTICES; index++)
    {
        if(G ->vertices[index].exists == 0)
        {
            G ->vertices[index].val = v;
            G ->vertices[index].exists = 1;

            InitHList(&G->vertices[index].adjlist);

            G -> nrVertices++;

            return;
        }
    }

    printf("Vertex array is full\n");
}

void AddEdge(struct Graph* G, int start, int end)
{
    int vStart = VSearch(G,start);
    int vEnd = VSearch(G,end);

    if(vStart == -1 || vEnd == -1)
    {
        printf("Vertex not found...\n");
        return;
    }


    if((HSearch(&G ->vertices[vStart].adjlist, end) != -1) && (HSearch(&G ->vertices[vEnd].adjlist, start) != -1))
    {
        printf("Edge Already Exists..\n");
        return;
    }

    HInsertEnd(&G -> vertices[vStart].adjlist, end);
    HInsertEnd(&G -> vertices[vEnd].adjlist, start);

    G->nrEdges++;
}

void RemoveEdge(struct Graph* G, int start, int end)
{
    int vStart = VSearch(G,start);
    int vEnd = VSearch(G,end);

    if(vStart == -1 || vEnd == -1)
    {
        printf("Vertex Not found..!!\n");
        return;
    }

    int p = HSearch(&G -> vertices[vStart].adjlist, end);
    int q = HSearch(&G -> vertices[vEnd].adjlist, start);

    if(p == -1 || q == -1)
    {
        printf("Edge Not present\n");
        return;
    }

    HDelete(&G -> vertices[vStart].adjlist, p);
    HDelete(&G -> vertices[vEnd].adjlist, q);

    G -> nrEdges--;
}

void RemoveVertex(struct Graph* G, int v)
{
    int r = VSearch(G,v);

    if(r == -1)
    {
        printf("Vertex not found..\n");
        return;
    }

    while(G -> vertices[r].adjlist.size > 0)
    {
        int neighbour = G -> vertices[r].adjlist.arr[0];

        int adj = VSearch(G, neighbour);

        int tmp = HSearch(&G -> vertices[adj].adjlist, v); 

        HDelete(&G -> vertices[adj].adjlist, tmp);

        HDelete(&G -> vertices[r].adjlist, 0);

        G -> nrEdges--;
    }

    G -> vertices[r].exists = 0;
    G -> vertices[r].val = -1;

    InitHList(&G -> vertices[r].adjlist);

    G -> nrVertices--;
}

void PrintGraph(struct Graph* G, char *msg)
{
    int i;
    int j;

    printf("\n%s\n",msg);

    printf("|G.V| = %d |G.E| = %d\n",G ->nrVertices, G ->nrEdges);

    for(i=0; i<MAXVERTICES; i++)
    {
        if(G -> vertices[i].exists == 1)
        {
            printf("[%d] <-> ",G -> vertices[i].val);

            for(j=0; j < G->vertices[i].adjlist.size; j++)
            {
                printf("[%d] <-> ",G -> vertices[i].adjlist.arr[j]);
            }

            printf("END\n");
        }
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

    RemoveEdge(&G,2,3);
    RemoveEdge(&G,5,6);

    PrintGraph(&G, "After removing edge (2,3) and (5,6)");

    RemoveVertex(&G,3);

    PrintGraph(&G,"After Removing Vertex 3");

    RemoveVertex(&G,7);

    PrintGraph(&G,"After Removing Vertex 7");

    return 0;
}