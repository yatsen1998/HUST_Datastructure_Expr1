#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define TREE_INIT_SIZE 100
#define OVERFLOW -1

typedef int Status;
typedef char TElemType;

typedef struct BitNode{
struct data{
char name=0;
TElemType number=0;
}data;
struct BitNode *lchild,*rchild;
}BitNode,*BiTree;

Status InitBiTree(BiTree &T);
Status CheckInit(BiTree T);
Status DestroyBiTree(BiTree &T);
Status CreateBiTree(BiTree &T);
Status ClearBiTree(BiTree &T);
Status BiTreeEmpty(BiTree &T);
Status BiTreeDepth(BiTree &T);
Status Visit(BiTree T);
char Root(BiTree &T);
BiTree Locate(BiTree T,TElemType e);
TElemType Value(BiTree T,TElemType e);
Status Assign(BiTree &T,TElemType e,TElemType value);
BiTree Parent(BiTree T,TElemType e);
BiTree LeftChild(BiTree T,TElemType e);
BiTree RightChild(BiTree T,TElemType e);
BiTree LeftSibling(BiTree T,TElemType e);
BiTree RightSibling(BiTree T,TElemType e);
Status InsertChild(BiTree &T,BitNode *pl,int LR,BiTree &NT);
Status DeleteChild(BiTree &T,BitNode *pl,int LR);
Status PreOrderTraverse(BiTree T,Status (* Visit)(BiTree T));
Status InOrderTraverse(BiTree T,Status (* Visit)(BiTree T));
Status PostOrderTraverse(BiTree T,Status (* Visit)(BiTree T));
void level(BiTree T,int h,Status (* Visit)(BiTree T));
Status LevelOrderTraverse(BiTree T,Status (* Visit)(BiTree T));
Status ReadBiTree(BiTree &T);
void ReadBiTree2(BiTree &T,FILE *fp);
Status WriteBiTree(BiTree &T);
void WriteBiTree2(BiTree &T, FILE *fp);

char value;
char c=ERROR;
BiTree p=NULL;
int main()
{
    BiTree T[10];

    int num=1,op=1;
    int LR;
    char e,temp;
     while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Binary Tree On Chain Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. InitBiTree       13. LeftSibling\n");
	printf("    	  2. DestroyBiTree    14. RightSibling\n");
	printf("    	  3. CreateBiTree     15. InsertChild\n");
	printf("    	  4. ClearBiTree      16. DeleteChild\n");
	printf("    	  5. BiTreeEmpty      17. PreOrderTraverse\n");
	printf("    	  6. BiTreeDepth      18. InOrderTraverse\n");
	printf("    	  7. Root             19. PostOrderTraverse\n");
	printf("          8. Value            20. LevelOrderTraverse\n");
	printf("          9. Assign           21. SwitchBiTree\n");
	printf("         10. Parent           22. ReadBiTree\n");
	printf("         11. LeftChild        23. WriteBiTree\n");
    printf("         12. RightChild       0. Exit\n");
    printf("-------------------------------------------------\n");
    printf("    目前操作的树为：%d\n    选择你的操作[0~23]:",num);

	scanf("%d",&op);
    switch(op){
     case 1:if(InitBiTree(T[num-1])==OK)
                printf("二叉树初始化成功！\n");
            else
                printf("二叉树初始化失败！\n");
            getchar();getchar();
            break;
    case 2:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            if(DestroyBiTree(T[num-1])==OK)
                printf("二叉树销毁成功！\n");
            else
                printf("二叉树销毁失败！\n");
            getchar();getchar();
            break;
    case 3:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("请输入结点的关键字和值(中间请不要加空格)：\n");
            CreateBiTree(T[num-1]);
            getchar();getchar();
            break;
    case 4:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            if(ClearBiTree(T[num-1])==1)
            printf("清除成功!");
            else printf("清除失败!");
            getchar();getchar();
            break;
    case 5: if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            BiTreeEmpty(T[num-1]);
            getchar();getchar();
            break;
    case 6:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("树深度为%d",BiTreeDepth(T[num-1]));
            getchar();getchar();
            break;
    case 7:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("根结点值为%c",T[num-1]->data.number);
            getchar();getchar();
            break;
            scanf("%c",&e);
    case 8:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("请输入欲查找结点关键字:\n");
            getchar();
            scanf("%c",&e);
            temp=Value(T[num-1],e);
            if(temp==FALSE)
                printf("不存在节点\n");
            else printf("节点值为%c",temp);
            c=ERROR;
            getchar();getchar();
            break;
    case 9:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            c=ERROR;
            printf("请依次输入待赋值结点关键字以及待赋值:\n");
            getchar();
            scanf("%c%c",&e,&value);
            if(Assign(T[num-1]->lchild,e,value)==OK)
            printf("赋值成功");
            else
            printf("赋值失败或没有该节点");
            getchar();getchar();
        break;
    case 10:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("请输入操作的节点:\n");
            getchar();
            scanf("%c",&e);
            Parent(T[num-1],e);
            if(p!=NULL)
            printf("该节点父母节点为：%c",p->data.name);
            else printf("该节点无父母节点!\n");
            p=NULL;
            getchar();getchar();
        break;
    case 11:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("请输入操作的节点:\n");
            getchar();
            scanf("%c",&e);
            LeftChild(T[num-1],e);
            if(p!=NULL)
            printf("该节点左孩子为：%c",p->data.name);
            else printf("该节点无左孩子或没有该节点!\n");
             p=NULL;
            getchar();getchar();
        break;
    case 12:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("请输入操作的节点:\n");
            getchar();
            scanf("%c",&e);
            RightChild(T[num-1],e);
            if(p!=NULL)
            printf("该节点右孩子为：%c",p->data.name);
            else printf("该节点无右孩子或没有该节点!\n");
             p=NULL;
            getchar();getchar();
        break;
    case 13:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("请输入操作的节点:\n");
            getchar();
            scanf("%c",&e);
            LeftSibling(T[num-1],e);
            if(p!=NULL)
            printf("该节点左兄弟为：%c",p->data.name);
            else printf("该节点无左兄弟或没有该节点!\n");
             p=NULL;
            getchar();getchar();
        break;
    case 14:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("请输入操作的节点:\n");
            getchar();
            scanf("%c",&e);
            RightSibling(T[num-1],e);
            if(p!=NULL)
            printf("该节点右兄弟为：%c",p->data.name);
            else printf("该节点无右兄弟或没有该节点!\n");
             p=NULL;
            getchar();getchar();
        break;
    case 15:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            p=NULL;
            BiTree NT;
            printf("请构造待插入子树:\n");
            CreateBiTree(NT);
            getchar();
            printf("请输入待插入结点的关键字以及插入位置(0为左子树，1为右子树):\n");
            scanf("%c%d",&e,&LR);
            if(InsertChild(T[num-1],Locate(T[num-1],e),LR,NT)==OK)
            printf("插入成功");
            else
            printf("插入失败");
            getchar();getchar();
        break;
    case 16:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            p=NULL;
            getchar();
            printf("请输入待删除子树结点的关键字以及待删除的子树(0为左子树，1为右子树):\n");
            scanf("%c%d",&e,&LR);
            if(DeleteChild(T[num-1]->lchild,Locate(T[num-1]->lchild,e),LR)==OK)
            printf("删除成功");
            else
            printf("删除失败");
            getchar();getchar();
        break;
    case 17:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("先序遍历为：\n");
            PreOrderTraverse(T[num-1],Visit);
            getchar();getchar();
        break;
    case 18:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("中序遍历为：\n");
            InOrderTraverse(T[num-1],Visit);
            getchar();getchar();
        break;
    case 19:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("后序遍历为：\n");
            PostOrderTraverse(T[num-1],Visit);
            getchar();getchar();
        break;
    case 20:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("层序遍历为：\n");
            LevelOrderTraverse(T[num-1],Visit);
            getchar();getchar();
        break;
    case 21:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            printf("请输入欲操作的树编号：\n");
            scanf("%d",&num);
            while(num>10||num<0){
                printf("请重新输入!\n");
                scanf("%d",&num);
            }
            getchar();getchar();
        break;
    case 22:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            if (!T[num-1]) printf("原二叉树不存在!\n");
            else
            {
            if (ReadBiTree(T[num-1])) printf("读取成功!\n");
            else printf("读取失败！\n");
            }
            getchar(); getchar();
        break;
    case 23:if(CheckInit(T[num-1])==FALSE)
            {
                getchar();getchar();
                break;
            }
            if (!T[num-1]) printf("原二叉树不存在!\n");
            else
            {
            if(WriteBiTree(T[num-1])) printf("存储成功!\n");
            else printf("存储失败！\n");
            }
            getchar(); getchar();
        break;
    case 0:
        break;
    }
}
}
Status InitBiTree(BiTree &T)
{
    T = (BitNode*)malloc(sizeof(BitNode));
    if(!T) exit(OVERFLOW);
    T->data.name='!';
    T->data.number='!';
    T->lchild=NULL;
    T->rchild=NULL;//创建根节点
    return OK;
}
Status CheckInit(BiTree T)
{
    if(T)
    return OK;
    printf("二叉树未初始化\n");
    return ERROR;
}
Status DestroyBiTree(BiTree &T)
{
    T=NULL;
    free(T);//摧毁根节点
    return OK;
}

Status CreateBiTree(BiTree &T)
{
    TElemType ch;
    char na;
    getchar();
    scanf("%c",&na);
    scanf("%c",&ch);
    if(na=='!')
        T = NULL;
    else
    {
        if(!T) exit(OVERFLOW);
        T = (BitNode*)malloc(sizeof(BitNode));
        T->data.name=na;
        T->data.number=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}
Status ClearBiTree (BiTree &T)
{
    if(T==NULL) return OK;
    T=NULL;
    free(T);
    return OK;
}
Status BiTreeEmpty(BiTree &T)
{
    if(T->data.number=='!')
    {
        printf("树为空");
        return FALSE;
    }
    printf("树不为空");
    return TRUE;
}
int BiTreeDepth(BiTree &T)
{
    if(T==NULL){
        return 0;
    }
    int nLeft=BiTreeDepth(T->lchild);
    int nRight=BiTreeDepth(T->rchild);
    return nLeft>nRight?nLeft+1:nRight+1;
}
Status Visit(BiTree T)
{
    printf("%c %c\n",T->data.name,T->data.number);
    return OK;
}
BiTree Root(BiTree T)
{
    return T;
}
BitNode* Locate(BiTree T,TElemType e)
{
    if(T)
    {
        if(T->data.name==e)
        p=T;
        Locate(T->lchild,e);
        Locate(T->rchild,e);
    }
    return p;
}

TElemType Value(BiTree T,TElemType e)
{
    if(T){
        if(T->data.name==e)
            c =  T->data.number;
        else{
            Value(T->lchild,e);
            Value(T->rchild,e);
    }
    }
    return c;
}
Status Assign(BiTree &T,TElemType e,TElemType value)
{
    if(T)
    {
        if(T->data.name==e)
        {
            T->data.number=value;
            c=OK;
            return c;
        }
        else
        Assign(T->lchild,e,value);
        Assign(T->rchild,e,value);
    }
    return c;
}
BiTree Parent(BiTree T,TElemType e)
{
  if(T){
    if(T->lchild){
        if(T->lchild->data.name==e){
            p=T;
            return p;
			}
        else
            Parent(T->lchild,e);
		}
    if(T->rchild){
        if(T->rchild->data.name==e){
            p=T;
            return p;
			}
        else
            Parent(T->rchild,e);
		}
    }
     return p;
}
BiTree LeftChild(BiTree T,TElemType e)
{
  if(T){
    if(T->lchild){
        if(T->data.name==e){
            p=T->lchild;
            return p;
			}
        else
            LeftChild(T->lchild,e);
		}
    if(T->rchild){
        if(T->data.name==e){
            p=T->lchild;
            return p;
			}
        else
            LeftChild(T->rchild,e);
		}
    }
     return p;
}
BiTree RightChild(BiTree T,TElemType e)
{
      if(T){
    if(T->lchild){
        if(T->data.name==e){
            p=T->rchild;
            return p;
			}
        else
            RightChild(T->lchild,e);
		}
    if(T->rchild){
        if(T->data.name==e){
            p=T->rchild;
            return p;
			}
        else
            RightChild(T->rchild,e);
		}
    }
     return p;
}
BiTree LeftSibling(BiTree T,TElemType e)
{
  if(T){
    if(T->lchild){
        if(T->rchild->data.name==e){
            p=T->lchild;
            return p;
			}
        else
            LeftSibling(T->lchild,e);
		}
    if(T->rchild){
        if(T->rchild->data.name==e){
            p=T->lchild;
            return p;
			}
        else
            LeftSibling(T->rchild,e);
		}
    }
     return p;
}
BiTree RightSibling(BiTree T,TElemType e)
{
 if(T){
    if(T->lchild){
        if(T->lchild->data.name==e){
            p=T->rchild;
            return p;
			}
        else
            RightSibling(T->lchild,e);
		}
    if(T->rchild){
        if(T->lchild->data.name==e){
            p=T->rchild;
            return p;
			}
        else
            RightSibling(T->rchild,e);
		}
    }
     return p;
}
Status InsertChild(BiTree &T,BitNode *pl,int LR,BiTree &NT)
{
     if(pl!=NULL)
   {
       if(LR==0)
    {
        NT->rchild=pl->lchild;
        pl->lchild=NT;
    }
    else
    {
        NT->rchild=pl->rchild;
        pl->rchild=NT;
    }
    return OK;
   }
   return ERROR;
}
Status DeleteChild(BiTree &T,BitNode *pl,int LR)
{
    if(pl!=NULL)
    {
        if(LR)
        {
            pl->rchild=NULL;
        }
        else
        {
            pl->lchild=NULL;
        }
        return OK;
    }
    return ERROR;
}
Status PreOrderTraverse(BiTree T,Status (* Visit)(BiTree T))
{
	if (T) {
		Visit(T);
		PreOrderTraverse(T->lchild, Visit);
		PreOrderTraverse(T->rchild, Visit);
	}
	else
		return OK;
}
Status InOrderTraverse(BiTree T,Status (* Visit)(BiTree T))
{
    if (T) {

		InOrderTraverse(T->lchild, Visit);
		Visit(T);
		InOrderTraverse(T->rchild, Visit);
	}
	else
		return OK;

}
Status PostOrderTraverse(BiTree T,Status (* Visit)(BiTree T))
{
   if (T) {

		PostOrderTraverse(T->lchild, Visit);
		PostOrderTraverse(T->rchild, Visit);
		Visit(T);
	}
	else
		return OK;

}
void level(BiTree T, int h, Status (* Visit)(BiTree T))
{
    if(T)
    {
        if(h==1)
            Visit(T);

        else{
            level(T->lchild,h-1, Visit);
            level(T->rchild,h-1, Visit);
        }
    }
}

Status LevelOrderTraverse(BiTree T,Status (* Visit)(BiTree T))
{
        if(T)
   {
    int h=BiTreeDepth(T);
    int i;
    for(i=1;i<=h;i++)
    {
        level(T,i, Visit);
    }return OK;

    }else return OK;
}
Status ReadBiTree(BiTree &T)
{
	FILE *fp;
	char ch; int i;
	char filename[30];
	printf("输入文件名:");
	scanf("%s", filename);
	if ((fp = fopen(filename,"r")) == NULL)
	{
		printf("File open error\n ");
		return 0;
	}
	ReadBiTree2(T,fp);
	return OK;
}
void ReadBiTree2(BiTree &T,FILE *fp)
{
	char ch; int i;
	fscanf(fp,"%c",&ch);
	while (ch ==' '||ch=='\n')
	{
		fscanf(fp,"%c",&ch);
	}
	fscanf(fp,"%c",&i);
	if (i =='!') T = NULL;
	else
	{
		T=(BiTree)malloc(sizeof(BitNode));
		T->data.name=ch;
		T->data.number=i;
		ReadBiTree2(T->lchild, fp);
		ReadBiTree2(T->rchild, fp);
	}
	return;
}
Status WriteBiTree(BiTree &T)
{
	printf("输入文件名:");
	char filename[30]; FILE* fp;
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("File open error\n ");
		return 0;
	}
	WriteBiTree2(T, fp);
	fclose(fp);
	return 1;
}
void WriteBiTree2(BiTree &T, FILE *fp)
{
	if (T)
	{
		fprintf(fp, "%c", T->data.name);
		fprintf(fp, "%c ", T->data.number);
		WriteBiTree2(T->lchild,fp);
		WriteBiTree2(T->rchild,fp);
	}
	else
	{
	    fprintf(fp, "%c",'!');
        fprintf(fp, "%c ",'!');
	}
	return;
}
