#include<stdio.h>
#include<stdlib.h>
#define max 20

int q[max],f=0,r=0;
int visited2[max]={0};
int visited1[max]={0};
typedef struct arcNode
{
	int adjvex;
	struct arcNode *nextarc;
}arcNode;

typedef struct VNode
{
	char data;
	arcNode *firstarc;
}VNode,AdjList[max];

typedef struct
{
	AdjList vertices;
	int vexnum,arcnum;
}aLGraph;

void CreatGraph(aLGraph &G)
{
	int i=0,j=0,k=0,m=0,n=0;
	char ch1=0,ch2=0;
	char  a[200],ch=0;
	arcNode *p=NULL,*q=NULL;
	scanf("%d",&G.vexnum);
	getchar();
	for(i=0;i<G.vexnum;i++)
    {
		scanf("%c",&G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc=NULL;
	}
	scanf("%d",&G.arcnum);
	getchar();
	for(n=0;n<G.arcnum*2;n++)
	{
		if(ch=='\n'||ch==' ')
			scanf("%c",&ch);
		scanf("%c",&ch);
		if(ch=='\n'||ch==' ')
			scanf("%c",&ch);
		a[n]=ch;
	}
	for(i=0;i<G.arcnum;i++)
	{
		ch1=a[n-2];
		ch2=a[n-1];
		n=n-2;
		for(j=0;j<G.vexnum;j++)
		{
			if(G.vertices[j].data==ch1)
				k=j;
			if(G.vertices[j].data==ch2)
				m=j;
		}
		p=(arcNode *)malloc(sizeof(arcNode));
		p->nextarc=NULL;
		p->adjvex=m;
		q=G.vertices[k].firstarc;
		if(!q)
			G.vertices[k].firstarc=p;
		else{
			while(q->nextarc)
			{
				q=q->nextarc;
			}
			q->nextarc=p;
		}
	}
}
void DFS(aLGraph G,int v){
	arcNode *p=NULL;
	int w=0;
	visited1[v]=1;
	printf("%c  ",G.vertices[v].data);
	p=G.vertices[v].firstarc;
	while(p){
		w=p->adjvex;
		if(!visited1[w])
			DFS(G,w);
			p=p->nextarc;
	}
}
void DFSTraverse(aLGraph G)
{
	int v=0;
	for(v=0;v<G.vexnum;v++)
    {
		visited1[v]=0;
    }
	for(v=0;v<G.vexnum;v++)
    {
		if(!visited1[v])
			DFS(G,v);
	}
}

void BFSTraverse(aLGraph G,int s)
{
	arcNode *p=NULL;
    if(!visited2[s])
    {
        printf("%c  ",G.vertices[s].data);
        visited2[s]=1;
        p=G.vertices[s].firstarc;
        while(p){
            if(!visited2[p->adjvex])
                q[r++]=p->adjvex;
            p=p->nextarc;
        }
    }
    while(f<r)
    {
       BFSTraverse(G,q[f++]);
    }
}
int main()
{
	aLGraph G;
	CreatGraph(G);
	DFSTraverse(G);
	printf("\n");
	BFSTraverse(G,0);
	return 0;
}







