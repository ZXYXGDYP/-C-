#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0
#define MAX_VERTEX_NUM 10//最大顶点数
#define MAXEDGE 20
#define INFINITY 1000
#define MAXSIZE 50
//dijiesite*************************
typedef int Patharc[MAX_VERTEX_NUM];    /* 用于存储最短路径下标的数组 */
typedef int ShortPathTable[MAX_VERTEX_NUM];/* 用于存储到各点最短路径的权值和 */
//*******************8
typedef int Status;
typedef int Boolean;
Boolean visited[MAX_VERTEX_NUM]; /* 访问标志的数组 */
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
}MGraph;
/* 循环队列的顺序存储结构 */
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* 头指针 */
	int rear;		/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}Queue;
/* 初始化一个空队列Q */
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* 队列空的标志 */
		return TRUE;
	else
		return FALSE;
}

/* 若队列未满，则插入元素e为Q新的队尾元素 */
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* 队列满的判断 */
		return ERROR;
	Q->data[Q->rear]=e;			/* 将元素e赋值给队尾 */
	Q->rear=(Q->rear+1)%MAXSIZE;/* rear指针向后移一位置， */
								/* 若到最后则转到数组头部 */
	return  OK;
}

/* 若队列不空，则删除Q中队头元素，用e返回其值 */
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			/* 队列空的判断 */
		return ERROR;
	*e=Q->data[Q->front];				/* 将队头元素赋值给e */
	Q->front=(Q->front+1)%MAXSIZE;	/* front指针向后移一位置， */
									/* 若到最后则转到数组头部 */
	return  OK;
}
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;  



