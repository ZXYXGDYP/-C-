#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "STDIO.h"


/*#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX_NUM 10//最大顶点数
#define INFINITY INT_MAX
typedef int Status;
typedef enum {DG=1,DN,UDG,UDN} GraphKind;  //四种图的枚举类型
typedef int VRType;                        //边信息（0/1）或者权值信息 权值
typedef char VertexType;                   //顶点类型
typedef int InfoType;                      //信息类型
//弧单元
typedef struct ArcCell
{
    VRType adj;             //权值
    //InfoType *info;         //边的补充信息
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct 
{
    AdjMatrix arcs;                       //邻接矩阵
    int vexnum,arcnum;                    //顶点数量和边的数量
    GraphKind kind;                       //图的类型
    VertexType vexs[MAX_VERTEX_NUM];      //顶点集合
}MGraph;*/



//LocateVex定位v在顶点集合中的位置
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
        printf("请输入权值");
        scanf("%d",&k);
        G->arcs[i][j].adj=k;
        break;
    case UDN:
        printf("请输入权值");
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
//创建图
Status CreateGraph(MGraph *G){
    printf("请输入图的类型号码\n");
    scanf("%d",& (G->kind));
    switch (G->kind)
    {
    case DG:
        printf("创建一个有向图\n");
        CreateDG(G);
        break;
    case UDG:
        printf("创建一个无向图\n");
        CreateUDG(G);
        break;    
    case DN:
        printf("创建一个有向网");
        CreateDN(G);
        break;
    case UDN:
        printf("创建一个无向网\n");
        CreateUDN(G);
        break;            
    default:
        printf("请输入正确的数字\n");
        break;
    }
} 
Status CreateDG(MGraph *G){
    int i,j,k,w;
    char v1,v2;
    int  Incinfo;
    printf("请输入定顶点数量，边的数量以及是否有额外信息（额外信息用0/1表示）\n");
    scanf("%d%d%d",&G->vexnum,&G->arcnum,&Incinfo);
    printf("请输入顶点的名字\n");
    for ( i = 0; i < G->vexnum; i++)
    {
        getchar();
        scanf("%c",&G->vexs[i]);}//输入顶点名字   
    for ( i = 0; i < G->vexnum; i++){
        for ( j = 0; j < G->vexnum; j++){
            G->arcs[i][j].adj =0;
            // G->arcs[i][j]->info= NULL;

        }
    }
    for(i=0;i<G->arcnum;i++){
        printf("输入边的两个顶点以及权重");
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
    printf("请输入定顶点数量，边的数量以及是否有额外信息（额外信息用0/1表示）\n");
    scanf("%d%d%d",&G->vexnum,&G->arcnum,&Incinfo);
    printf("请输入顶点的名字\n");
    for ( i = 0; i < G->vexnum; i++)
    {
        getchar();
        scanf("%c",&G->vexs[i]);}//输入顶点名字   
    for ( i = 0; i < G->vexnum; i++){
        for ( j = 0; j < G->vexnum; j++){
            G->arcs[i][j].adj =0;
            // G->arcs[i][j]->info= NULL;

        }
    }
    for(i=0;i<G->arcnum;i++){
        printf("输入边的两个顶点\n");
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
    printf("请输入定顶点数量，边的数量以及是否有额外信息（额外信息用0/1表示）");
    scanf("%d%d%d",&G->vexnum,&G->arcnum,&Incinfo);
    printf("请输入顶点的名字");
    for ( i = 0; i < G->vexnum; i++)
    {
        getchar();
        scanf("%c",&G->vexs[i]);}//输入顶点名字   
    for ( i = 0; i < G->vexnum; i++){
        for ( j = 0; j < G->vexnum; j++){
            G->arcs[i][j].adj =INFINITY;
            // G->arcs[i][j]->info= NULL;

        }
    }
    for(i=0;i<G->arcnum;i++){
        printf("输入边的两个顶点");
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
    printf("请输入定顶点数量，边的数量以及是否有额外信息（额外信息用0/1表示）");
    scanf("%d%d%d",&G->vexnum,&G->arcnum,&Incinfo);
    printf("请输入顶点的名字");
    for ( i = 0; i < G->vexnum; i++)
    {
        getchar();
        scanf("%c",&G->vexs[i]);}//输入顶点名字   
    for ( i = 0; i < G->vexnum; i++){
        for ( j = 0; j < G->vexnum; j++){
            G->arcs[i][j].adj =INFINITY;
            // G->arcs[i][j]->info= NULL;

        }
    }
    for(i=0;i<G->arcnum;i++){
        printf("输入边的两个顶点");
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
    printf("请输入数字来显示要查看的内容，1：sta，2：arc，3：vex");
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
        printf("输入错误");
        break;
    }
    //PrintArc(G);
}
Status PrintSta(MGraph G){
    printf("显示顶点的个数，边的个数，图的种类");
    printf("%d%d%s",G.vexnum,G.arcnum,G.kind);
    return OK;
}//打印顶点个数，边个数和图的种类
Status PrintVexs(MGraph G){
    int i;
    printf("显示顶点集合");
    for ( i = 0; i < G.vexnum; i++)
    {
        printf("%c",G.vexs[i]);
    }
    return OK;
    
}//打印顶点集
Status PrintArc(MGraph G){
    int i,j;
    for (i = 0; i < G.vexnum; i++){
        for (j = 0; j < G.vexnum; j++){
        printf("%d\t",G.arcs[i][j].adj);
    }
        printf("\n");
    }
    
    
    return OK;
}  //打印邻接矩阵 
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
}//清空一个表

Status DFS(MGraph G, int i){
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);
	for(j = 0; j < G.vexnum; j++)
		if(G.arcs[i][j].adj != 0 && !visited[j])
 			DFS(G, j);              // 递归

}//DFS
Status DFSTraverse(MGraph G){
	int i;
 	for(i = 0; i < G.vexnum; i++)
 		visited[i] = FALSE;         //初始化
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
    InitQueue(&Q);		/* 初始化一辅助用的队列 */
    for(i = 0; i < G.vexnum; i++)  /* 对每一个顶点做循环 */
    {
		if (!visited[i])	/* 若是未访问过就处理 */
		{
			visited[i]=TRUE;		/* 设置当前顶点访问过 */
			printf("%c ", G.vexs[i]);/* 打印顶点，也可以其它操作 */
			EnQueue(&Q,i);		/* 将此顶点入队列 */
			while(!QueueEmpty(Q))	/* 若当前队列不为空 */
			{
				DeQueue(&Q,&i);	/* 将队对元素出队列，赋值给i */
				for(j=0;j<G.vexnum;j++) 
				{ 
					/* 判断其它顶点若与当前顶点存在边且未访问过  */
					if((G.arcs[i][j].adj != 0||G.arcs[i][j].adj!=INFINITY) && !visited[j]) 
					{ 
 						visited[j]=TRUE;			/* 将找到的此顶点标记为已访问 */
						printf("%c ", G.vexs[j]);	/* 打印顶点 */
						EnQueue(&Q,j);				/* 将找到的此顶点入队列  */
					} 
				} 
			}
		}
	}
} //邻接矩阵的广度遍历算法
/* 交换权值 以及头和尾 */
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

/* 对权值进行排序 */
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
	printf("权排序之后的为:\n");
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

/* 生成最小生成树 */
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, j, n, m;
	int k = 0;
	int parent[MAX_VERTEX_NUM];//kan有木有环
	
	Edge edges[MAXEDGE];

	/* 构建边集数组并排序********************* */
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
		parent[i] = 0;	//初始化数组值为0

	printf("打印最小生成树：\n");
	for (i = 0; i < G.arcnum; i++)
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m) //没有huan
		{
			parent[n] = m;	//把边放进生成树
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

//迪杰斯特爸爸
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{    
	int v,w,k,min;    
	int final[G.vexnum];
	for(v=0; v<G.vexnum; v++)    /* 初始化数据 */
	{        
		final[v] = 0;			//标尺数组
		(*D)[v] = G.arcs[v0][v].adj;//赋值
		(*P)[v] = 0;	   //路径数组
	}

	(*D)[v0] = 0;    //v0自己玩
	final[v0] = 1;   //v0自己玩        
	   
	for(v=1; v<G.vexnum; v++)   
	{
		min=INFINITY;          
		for(w=0; w<G.vexnum; w++)     
		{            
			if(!final[w] && (*D)[w]<min)             
			{                   
				k=w;                    
				min = (*D)[w];    // w离v0近             
			}        
		}        
		final[k] = 1;   
		for(w=0; w<G.vexnum; w++) 
		{
			// 还有更短的
			if(!final[w] && (min+G.arcs[k][w].adj<(*D)[w]))   
			{ 
				(*D)[w] = min+G.arcs[k][w].adj;  //改成更短的               
				(*P)[w]=k;        
			}       
		}   
	}
}

Status Show_Dijkstra(MGraph G,int v0,Patharc P, ShortPathTable D){
    
    int i,j;
    printf("最短路径倒序如下:\n");    
	for(i=1;i<G.vexnum;++i)   //搞P
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
	printf("\n源点到各顶点的最短路径长度为:\n");  //搞D
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
