#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "STDIO.h"


/*#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX_NUM 10//��󶥵���
#define INFINITY INT_MAX
typedef int Status;
typedef enum {DG=1,DN,UDG,UDN} GraphKind;  //����ͼ��ö������
typedef int VRType;                        //����Ϣ��0/1������Ȩֵ��Ϣ Ȩֵ
typedef char VertexType;                   //��������
typedef int InfoType;                      //��Ϣ����
//����Ԫ
typedef struct ArcCell
{
    VRType adj;             //Ȩֵ
    //InfoType *info;         //�ߵĲ�����Ϣ
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct 
{
    AdjMatrix arcs;                       //�ڽӾ���
    int vexnum,arcnum;                    //���������ͱߵ�����
    GraphKind kind;                       //ͼ������
    VertexType vexs[MAX_VERTEX_NUM];      //���㼯��
}MGraph;*/



//LocateVex��λv�ڶ��㼯���е�λ��
Status LocateVex(MGraph *G,char v){
    int i;
    for(i=0;i<G->vexnum;i++){
        if (G->vexs[i]==v)
        {
            return i;
        }
        
    }
}
// Status Input(MGraph *G,char v)
// Status GetVex(MGraph G,char v)
// Status PutVex(MGraph *G,int value)
//Status FirstVex(G,v)
//Status NextVex(G,v)
Status InsertVex(MGraph *G,char v){
    G->vexs[G->vexnum]=v;
    G->vexnum++;
    return OK;
}
Status DeleteVex(MGraph *G,char v){
 G->vexs[G->vexnum-1]=0;
    G->vexnum--;
    return OK;
}   
Status InsertArc(MGraph *G,char v,char w){
    int i,j,k;
    i=LocateVex(G,v);
    k=LocateVex(G,w);

    switch (G->kind)
    {
    case DG:
        G->arcs[i][j].adj=1;
        break;
    case UDG:
        G->arcs[i][j].adj=1;
        G->arcs[j][i].adj=1;
        break;
    case DN:
        printf("������Ȩֵ");
        scanf("%d",&k);
        G->arcs[i][j].adj=k;
        break;
    case UDN:
        printf("������Ȩֵ");
        scanf("%d",&k);
        G->arcs[i][j].adj=k;
        G->arcs[j][i].adj=k;
        break;
    default:
        break;
    }
    G->arcnum++;
    return OK;
}
//����ͼ
Status CreateGraph(MGraph *G){
    printf("������ͼ�����ͺ���\n");
    scanf("%d",& (G->kind));
    switch (G->kind)
    {
    case DG:
        printf("����һ������ͼ\n");
        CreateDG(G);
        break;
    case UDG:
        printf("����һ������ͼ\n");
        CreateUDG(G);
        break;    
    case DN:
        printf("����һ��������");
        CreateDN(G);
        break;
    case UDN:
        printf("����һ��������\n");
        CreateUDN(G);
        break;            
    default:
        printf("��������ȷ������\n");
        break;
    }
} 
Status CreateDG(MGraph *G){
    int i,j,k,w;
    char v1,v2;
    int  Incinfo;
    printf("�����붨�����������ߵ������Լ��Ƿ��ж�����Ϣ��������Ϣ��0/1��ʾ��\n");
    scanf("%d%d%d",&G->vexnum,&G->arcnum,&Incinfo);
    printf("�����붥�������\n");
    for ( i = 0; i < G->vexnum; i++)
    {
        getchar();
        scanf("%c",&G->vexs[i]);}//���붥������   
    for ( i = 0; i < G->vexnum; i++){
        for ( j = 0; j < G->vexnum; j++){
            G->arcs[i][j].adj =0;
            // G->arcs[i][j]->info= NULL;

        }
    }
    for(i=0;i<G->arcnum;i++){
        printf("����ߵ����������Լ�Ȩ��");
        getchar();
        scanf("%c%c",&v1,&v2);
        k=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G->arcs[k][j].adj=1;
        // if (Incinfo)
        // {
            
        // }
        
    }
    return OK;
} //CreateDG
Status CreateUDG(MGraph *G){
    int i,j,k,w;
    char v1,v2;
    int  Incinfo;
    printf("�����붨�����������ߵ������Լ��Ƿ��ж�����Ϣ��������Ϣ��0/1��ʾ��\n");
    scanf("%d%d%d",&G->vexnum,&G->arcnum,&Incinfo);
    printf("�����붥�������\n");
    for ( i = 0; i < G->vexnum; i++)
    {
        getchar();
        scanf("%c",&G->vexs[i]);}//���붥������   
    for ( i = 0; i < G->vexnum; i++){
        for ( j = 0; j < G->vexnum; j++){
            G->arcs[i][j].adj =0;
            // G->arcs[i][j]->info= NULL;

        }
    }
    for(i=0;i<G->arcnum;i++){
        printf("����ߵ���������\n");
        getchar();
        scanf("%c%c",&v1,&v2);
        k=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G->arcs[k][j].adj=1;
        // if (Incinfo)
        // {
            
        // }
        G->arcs[j][k]=G->arcs[k][j];
    }
    return OK;
} //CreateUDG 
Status CreateDN(MGraph *G){
    int i,j,k,w;
    char v1,v2;
    int  Incinfo;
    printf("�����붨�����������ߵ������Լ��Ƿ��ж�����Ϣ��������Ϣ��0/1��ʾ��");
    scanf("%d%d%d",&G->vexnum,&G->arcnum,&Incinfo);
    printf("�����붥�������");
    for ( i = 0; i < G->vexnum; i++)
    {
        getchar();
        scanf("%c",&G->vexs[i]);}//���붥������   
    for ( i = 0; i < G->vexnum; i++){
        for ( j = 0; j < G->vexnum; j++){
            G->arcs[i][j].adj =INFINITY;
            // G->arcs[i][j]->info= NULL;

        }
    }
    for(i=0;i<G->arcnum;i++){
        printf("����ߵ���������");
        getchar();
        scanf("%c%c%d",&v1,&v2,&w);
        k=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G->arcs[k][j].adj=w;
        // if (Incinfo)
        // {
            
        // }
        //G->arcs[j][k]=G->arcs[k][j];
    }
    return OK;
} //CreateDN 
Status CreateUDN(MGraph *G){
    int i,j,k,w;
    char v1,v2;
    int  Incinfo;
    printf("�����붨�����������ߵ������Լ��Ƿ��ж�����Ϣ��������Ϣ��0/1��ʾ��");
    scanf("%d%d%d",&G->vexnum,&G->arcnum,&Incinfo);
    printf("�����붥�������");
    for ( i = 0; i < G->vexnum; i++)
    {
        getchar();
        scanf("%c",&G->vexs[i]);}//���붥������   
    for ( i = 0; i < G->vexnum; i++){
        for ( j = 0; j < G->vexnum; j++){
            G->arcs[i][j].adj =INFINITY;
            // G->arcs[i][j]->info= NULL;

        }
    }
    for(i=0;i<G->arcnum;i++){
        printf("����ߵ���������");
        getchar();
        scanf("%c%c%d",&v1,&v2,&w);
        k=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G->arcs[k][j].adj=w;
        // if (Incinfo)
        // {
            
        // }
        G->arcs[j][k]=G->arcs[k][j];
    }
    return OK;
} //CreateUDN 
Status Print(MGraph G){
    int k=3;
    printf("��������������ʾҪ�鿴�����ݣ�1��sta��2��arc��3��vex");
    scanf("%d",&k);
    switch (k)
    {
    case 1:
        PrintSta(G);
        break;
    case 2:
        PrintArc(G);
        break;    
    case 3:
        PrintVexs(G);
        break; 
         
    default:
        printf("�������");
        break;
    }
    //PrintArc(G);
}
Status PrintSta(MGraph G){
    printf("��ʾ����ĸ������ߵĸ�����ͼ������");
    printf("%d%d%s",G.vexnum,G.arcnum,G.kind);
    return OK;
}//��ӡ����������߸�����ͼ������
Status PrintVexs(MGraph G){
    int i;
    printf("��ʾ���㼯��");
    for ( i = 0; i < G.vexnum; i++)
    {
        printf("%c",G.vexs[i]);
    }
    return OK;
    
}//��ӡ���㼯
Status PrintArc(MGraph G){
    int i,j;
    for (i = 0; i < G.vexnum; i++){
        for (j = 0; j < G.vexnum; j++){
        printf("%d\t",G.arcs[i][j].adj);
    }
        printf("\n");
    }
    
    
    return OK;
}  //��ӡ�ڽӾ��� 
Status DestroyGraph(MGraph *G){
        int i,j;
        for ( i = 0; i < MAX_VERTEX_NUM; i++)
        for ( j = 0; j < MAX_VERTEX_NUM; j++)
           {G->arcs[i][j].adj =0;
            G->vexs[j]==0;}
            G->arcnum=0;
            G->vexnum=0;
            G->kind=0; 
    return OK;
}//���һ����

Status DFS(MGraph G, int i){
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);
	for(j = 0; j < G.vexnum; j++)
		if(G.arcs[i][j].adj != 0 && !visited[j])
 			DFS(G, j);              // �ݹ�

}//DFS
Status DFSTraverse(MGraph G){
	int i;
 	for(i = 0; i < G.vexnum; i++)
 		visited[i] = FALSE;         //��ʼ��
	for(i = 0; i < G.vexnum; i++)
 		if(!visited[i])   
			DFS(G, i);
}

void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i = 0; i < G.vexnum; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);		/* ��ʼ��һ�����õĶ��� */
    for(i = 0; i < G.vexnum; i++)  /* ��ÿһ��������ѭ�� */
    {
		if (!visited[i])	/* ����δ���ʹ��ʹ��� */
		{
			visited[i]=TRUE;		/* ���õ�ǰ������ʹ� */
			printf("%c ", G.vexs[i]);/* ��ӡ���㣬Ҳ������������ */
			EnQueue(&Q,i);		/* ���˶�������� */
			while(!QueueEmpty(Q))	/* ����ǰ���в�Ϊ�� */
			{
				DeQueue(&Q,&i);	/* ���Ӷ�Ԫ�س����У���ֵ��i */
				for(j=0;j<G.vexnum;j++) 
				{ 
					/* �ж������������뵱ǰ������ڱ���δ���ʹ�  */
					if((G.arcs[i][j].adj != 0||G.arcs[i][j].adj!=INFINITY) && !visited[j]) 
					{ 
 						visited[j]=TRUE;			/* ���ҵ��Ĵ˶�����Ϊ�ѷ��� */
						printf("%c ", G.vexs[j]);	/* ��ӡ���� */
						EnQueue(&Q,j);				/* ���ҵ��Ĵ˶��������  */
					} 
				} 
			}
		}
	}
} //�ڽӾ���Ĺ�ȱ����㷨
/* ����Ȩֵ �Լ�ͷ��β */
void Swapn(Edge *edges,int i, int j)
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}

/* ��Ȩֵ�������� */
void sort(Edge edges[],MGraph *G)
{
	int i, j;
	for ( i = 0; i < G->arcnum; i++)
	{
		for ( j = i + 1; j < G->arcnum; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				Swapn(edges, i, j);
			}
		}
	}
	printf("Ȩ����֮���Ϊ:\n");
	for (i = 0; i < G->arcnum; i++)
	{
		printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
	}

}


int Find(int *parent, int f)
{
	while ( parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/* ������С������ */
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, j, n, m;
	int k = 0;
	int parent[MAX_VERTEX_NUM];//kan��ľ�л�
	
	Edge edges[MAXEDGE];

	/* �����߼����鲢����********************* */
	for ( i = 0; i < G.vexnum-1; i++)
	{
		for (j = i + 1; j < G.vexnum; j++)
		{
			if (G.arcs[i][j].adj<INFINITY)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G.arcs[i][j].adj;
				k++;
			}
		}
	}
	sort(edges, &G);
	/* ******************************************* */


	for (i = 0; i < G.vexnum; i++)
		parent[i] = 0;	//��ʼ������ֵΪ0

	printf("��ӡ��С��������\n");
	for (i = 0; i < G.arcnum; i++)
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m) //û��huan
		{
			parent[n] = m;	//�ѱ߷Ž�������
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

//�Ͻ�˹�ذְ�
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[G.vexnum];
	for(v=0; v<G.vexnum; v++)    /* ��ʼ������ */
	{        
		final[v] = 0;			//�������
		(*D)[v] = G.arcs[v0][v].adj;//��ֵ
		(*P)[v] = 0;	   //·������
	}

	(*D)[v0] = 0;    //v0�Լ���
	final[v0] = 1;   //v0�Լ���        
	   
	for(v=1; v<G.vexnum; v++)   
	{
		min=INFINITY;          
		for(w=0; w<G.vexnum; w++)     
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    // w��v0��             
			}        
		}        
		final[k] = 1;   
		for(w=0; w<G.vexnum; w++) 
		{
			// ���и��̵�
			if(!final[w] && (min+G.arcs[k][w].adj<(*D)[w]))   
			{ 
				(*D)[w] = min+G.arcs[k][w].adj;  //�ĳɸ��̵�               
				(*P)[w]=k;        
			}       
		}   
	}
}

Status Show_Dijkstra(MGraph G,int v0,Patharc P, ShortPathTable D){
    
    int i,j;
    printf("���·����������:\n");    
	for(i=1;i<G.vexnum;++i)   //��P
	{       
		printf("v%d - v%d : ",v0,i);
		j=i;
		while(P[j]!=0)
		{
			printf("%d ",P[j]);
			j=P[j];
		}
		printf("\n");
	}    
	printf("\nԴ�㵽����������·������Ϊ:\n");  //��D
	for(i=1;i<G.vexnum;++i)        
		printf("v%c - v%c : %d \n",G.vexs[0],G.vexs[i],D[i]);
    return OK;
}
int main(){
    int v0=0;
    int check = 1;
    MGraph G;
    Patharc P;    
	ShortPathTable D;
    // DestroyGraph(&G);
     CreateGraph(&G);
    // DFSTraverse(G);
    Print(G);
    // MiniSpanTree_Kruskal(G);
    // ShortestPath_Dijkstra(G, v0, &P, &D);  
    // Show_Dijkstra(G,v0,P,D);
	switch (check)
    {
    case 1:
        if(G.kind==UDN)
        MiniSpanTree_Kruskal(G);
        else
        {
            printf("bunengxiagao");
        }
        
        break;
    case 2:
        if(G.kind=DN)
        {
        ShortestPath_Dijkstra(G, v0, &P, &D);  
        Show_Dijkstra(G,v0,P,D);
        }
        else
        {
            printf("bunengxiagao");
        }
        

    default:
        printf("bunengxiagao");
        break;
    }   
    system("pasue");
    return 0;
}
