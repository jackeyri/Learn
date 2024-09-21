//ͼ�Ļ��������㷨
#include <stdio.h>
#include <malloc.h>
//ͼ�����ִ洢�ṹ
#define INF 32767				//�����
#define	MAXV 100				//��󶥵����
typedef char InfoType;

//���¶����ڽӾ�������
typedef struct
{	int no;						//������
	InfoType info;				//����������Ϣ
} VertexType;					//��������
typedef struct
{	int edges[MAXV][MAXV];		//�ڽӾ�������
	int n,e;					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MatGraph;						//������ͼ�ڽӾ�������

//���¶����ڽӱ�����
typedef struct ANode
{	int adjvex;					//�ñߵ��ڽӵ���
	struct ANode *nextarc;		//ָ����һ���ߵ�ָ��
	int weight;					//�ñߵ������Ϣ����Ȩֵ�������ͱ�ʾ��
} ArcNode;						//�߽ڵ�����
typedef struct Vnode
{	InfoType info;				//����������Ϣ
	int count;					//��Ŷ������,����������������
	ArcNode *firstarc;			//ָ���һ����
} VNode;						//�ڽӱ�ͷ�ڵ�����
typedef struct 
{	VNode adjlist[MAXV];		//�ڽӱ�ͷ�ڵ�����
	int n,e;					//ͼ�ж�����n�ͱ���e
} AdjGraph;						//������ͼ�ڽӱ�����

//------------------------------------------------------------
//----�ڽӾ���Ļ��������㷨----------------------------------
//------------------------------------------------------------
void CreateMat(MatGraph &g,int A[MAXV][MAXV],int n,int e) //����ͼ���ڽӾ���
{
	int i,j;
	g.n=n; g.e=e;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
}
void DispMat(MatGraph g)	//����ڽӾ���g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]!=INF)
				printf("%d\t",g.edges[i][j]);
			else
				printf("%s\t","��");
		printf("\n");
	}
}
//------------------------------------------------------------

//------------------------------------------------------------
//----�ڽӱ�Ļ��������㷨------------------------------------
//------------------------------------------------------------
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e) //����ͼ���ڽӱ�
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<n;i++)						//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)						//����ڽӾ�����ÿ��Ԫ��
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)	//����һ����
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ���ڵ�p
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;	//����ͷ�巨����ڵ�p
				G->adjlist[i].firstarc=p;
			}
	G->n=n; G->e=n;
}
void DispAdj(AdjGraph *G)	//����ڽӱ�G
{
	ArcNode *p;
	for (int i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d[%d]��",p->adjvex,p->weight);
			p=p->nextarc;
		}
		printf("��\n");
	}
}
void DestroyAdj(AdjGraph *&G)	//����ͼ���ڽӱ�
{
	ArcNode *pre,*p;
	for (int i=0;i<G->n;i++)		//ɨ�����еĵ�����
	{	pre=G->adjlist[i].firstarc;	//pָ���i����������׽ڵ�
		if (pre!=NULL)
		{	p=pre->nextarc;
			while (p!=NULL)			//�ͷŵ�i������������б߽ڵ�
			{	free(pre);
				pre=p; p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);						//�ͷ�ͷ�ڵ�����
}
//------------------------------------------------------------

//------------------------------------------------------------------------------------
//----------------ͼ��������ȱ����͹�����ȱ������ڽӱ�-----------------------
//------------------------------------------------------------------------------------
int visited[MAXV];						//ȫ������
void DFS(AdjGraph *G,int v)				//�ݹ�������ȱ����㷨
{
	ArcNode *p;
	visited[v]=1;                   	//���ѷ��ʱ��
	printf("%3d",v); 					//��������ʶ���ı��
	p=G->adjlist[v].firstarc;      		//pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
	while (p!=NULL) 
	{	
		if (visited[p->adjvex]==0)		//��p->adjvex����δ����,�ݹ������
			DFS(G,p->adjvex);    
		p=p->nextarc;              		//pָ�򶥵�v����һ�����Ļ�ͷ���
	}
}
void DFS1(AdjGraph *G,int v)		//�ǵݹ�������ȱ����㷨
{
	ArcNode *p;
	int St[MAXV];
	int top=-1,w,x,i;
    for (i=0;i<G->n;i++) 
		visited[i]=0;				//������ʱ�־���ó�0
	printf("%3d",v);				//���ʶ���v
	visited[v]=1;					//�ö���v�ѷ���
	top++; St[top]=v;				//������v��ջ
	while (top>-1)					//ջ����ѭ��
	{
		x=St[top]; 					//ȡջ������x��Ϊ��ǰ����
		p=G->adjlist[x].firstarc;	//�Ҷ���x�ĵ�һ�����ڵ�
		while (p!=NULL)
		{
			w=p->adjvex;			//x�����ڵ�Ϊw
			if (visited[w]==0)		//������wû�з���
			{
				printf("%3d",w);	//���ʶ���w
				visited[w]=1;		//�ö���w�ѷ���
				top++;				//������w��ջ
				St[top]=w;
				break;				//�˳�ѭ�������ٴ���ջ���Ķ���(���ֺ���ȳ�)
			}
			p=p->nextarc;			//�Ҷ���x����һ�����ڵ�
		}
		if (p==NULL) top--;			//������x��û�����ڵ㣬������ջ
	}
	printf("\n");
}
void BFS(AdjGraph *G,int v)					//������ȱ����㷨		
{
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;			//���廷�ζ��в���ʼ��
	int visited[MAXV];            			//�����Ŷ���ķ��ʱ�־������
	int w,i;
	for (i=0;i<G->n;i++) visited[i]=0;		//���ʱ�־�����ʼ��
	printf("%3d",v); 						//��������ʶ���ı��
	visited[v]=1;              				//���ѷ��ʱ��
	rear=(rear+1)%MAXV;
	queue[rear]=v;             				//v����
	while (front!=rear)       				//�����в���ʱѭ��
	{	
		front=(front+1)%MAXV;
		w=queue[front];       				//���Ӳ�����w
		p=G->adjlist[w].firstarc; 			//�Ҷ���w�ĵ�һ�����ڵ�
		while (p!=NULL) 
		{	
			if (visited[p->adjvex]==0) 		//�����ڵ�δ������
			{	
				printf("%3d",p->adjvex);  	//�������ڵ�
				visited[p->adjvex]=1;		//�øö����ѱ����ʵı�־
				rear=(rear+1)%MAXV;			//�ö������
				queue[rear]=p->adjvex; 		
           	}
           	p=p->nextarc;              		//����һ�����ڵ�
		}
	}
	printf("\n");
}














