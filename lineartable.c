#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define N 10
typedef int status;
typedef int ElemType; //数据元素类型定义

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{  //顺序表（顺序结构）的定义
	ElemType * elem;
	int length;
	int listsize;
	int flag=0;
}SqList;
/*-----page 19 on textbook ---------*/
status IntiaList(SqList & L);
status DestroyList(SqList & L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType & e);
status LocateElem(SqList L,ElemType e); //简化过
status PriorElem(SqList L,ElemType cur,ElemType & pre_e);
status NextElem(SqList L,ElemType cur,ElemType & next_e);
status ListInsert(SqList & L,int i,ElemType e);
status ListDelete(SqList & L,int i,ElemType & e);
status ListTraverse(SqList L);  //简化过
status ListReadFile(SqList &L);
status ListWriteFile(SqList &L);
status ChooseList();
/*--------------------------------------------*/
int main(void){
  SqList L[N];  int op=1;
  ElemType e;int i,cur;
  int num=0;
  while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. IntiaList       8. PriorElem\n");
	printf("    	  2. DestroyList     9. NextElem\n");
	printf("    	  3. ClearList      10. ListInsert \n");
	printf("    	  4. ListEmpty      11. ListDelete\n");
	printf("    	  5. ListLength     12. ListTraverse\n");
	printf("    	  6. GetElem        13. ReadFiles\n");
	printf("    	  7. LocateElem     14. WriteFiles\n");
	printf("          0. Exit           15. ChooseList\n");
	printf("-------------------------------------------------\n");
	printf("    目前操作表为表%d\n",num+1);
	printf("    请选择你的操作[0~15]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 if(IntiaList(L[num])==OK){
            printf("线性表创建成功！\n");
		 }
		     else printf("线性表创建失败！\n");
         printf("\n----IntiaList功能实现！\n");
		 getchar();getchar();
		 break;
	   case 2:
	       if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
         if(DestroyList(L[num])==OK)
		 printf("\n----DestroyList功能实现！\n");
		 else printf("实现失败！");
		 getchar();getchar();
		 break;
	   case 3:
	       if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
         if(ClearList(L[num])==OK)
		 printf("\n----ClearList功能实现！\n");
		 else printf("实现失败！");
		 getchar();getchar();
		 break;
	   case 4:
	       if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
	     if(ListEmpty(L[num])==OK)
		 printf("线性表为空！");
		 else printf("线性表不为空！");
		 printf("\n----ListEmpty功能实现！\n");
		 getchar();getchar();
		 break;
	   case 5:
        if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
         printf("\n表长为%d!\n",ListLength(L[num]));
		 printf("\n----ListLength功能实现！\n");
		 getchar();getchar();
		 break;
	   case 6:
	       if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
        printf("请输入查找的序号:\n");
	       scanf("%d",&i);
	     GetElem(L[num],i,e);
	     if(!GetElem(L[num],i,e))
            printf("该数不存在!");
		 printf("\n----GetElem功能实现！\n");
		 getchar();getchar();
		 break;
	   case 7:
	       if(L[num].flag==0){
         printf("未创建线性表!\n");
         getchar();getchar();
         break;
        }
	       printf("请输入查找的数:\n");
         scanf("%d",&e);
         if(LocateElem(L[num],e)==0)
            printf("该数不存在!\n");
         if(LocateElem(L[num],e)!=ERROR)
         printf("查找的数序号为%d",LocateElem(L[num],e));
		 printf("\n----LocateElem功能实现！\n");
		 getchar();getchar();
		 break;
	   case 8:
	       if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
         ElemType pre_e;
         printf("请输入指定数的序号:\n");
         scanf("%d",&cur);
         if(cur!=1)
         printf("前驱数据为%d!\n",PriorElem(L[num],cur,pre_e));
         else printf("无前驱数据!");
		 printf("\n----PriorElem功能实现!");
		 getchar();getchar();
		 break;
	   case 9:
	       if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
         ElemType next_e;
         printf("请输入指定数的序号:\n");
         scanf("%d",&cur);
         if(cur!=L[num].length)
         printf("后继数据为%d!\n",NextElem(L[num],cur,next_e));
         else printf("无后继数据!");
		 printf("\n----NextElem功能实现!");
		 getchar();getchar();
		 break;
	   case 10:
	       if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
	       printf("请输入插入的位置:\n");
	       scanf("%d",&i);
	       printf("请输入插入的数据:\n");
	       scanf("%d",&e);
	       ListInsert(L[num],i,e);
		 printf("\n----ListInsert功能实现！\n");
		 getchar();getchar();
		 break;
	   case 11:
	       if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
         printf("请输入删除数据的序号：\n");
         scanf("%d",&i);
         ListDelete(L[num],i,e);
         printf("删除的数据为%d",e);
		 printf("\n----ListDelete功能实现！\n");
		 getchar();getchar();
		 break;
	   case 12:
	       if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
		 if(!ListTraverse(L[num])) printf("线性表是空表！\n");
		 printf("\n----ListTraverse功能实现！\n");
		 getchar();getchar();
		 break;
       case 13:
         ListReadFile(L[num]);
         printf("\n----ListReadFile功能实现！\n");
         getchar();getchar();
         break;
       case 14:
           if(L[num].flag==0){
         printf("未创建线性表!\n");
        getchar();getchar();
         break;
        }
         ListWriteFile(L[num]);
         printf("\n----ListWriteFile功能实现！\n");
         getchar();getchar();
         break;
       case 15:
         num=ChooseList();
         printf("当前你操作的线性表为表%d\n",num+1);
         printf("\n----ChooseList功能实现！\n");
         getchar();getchar();
	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");
  return 0;
}//end of main()
/*--------page 23 on textbook --------------------*/
status IntiaList(SqList & L){
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L.elem) exit(OVERFLOW);
	L.length=0;
    L.listsize=LIST_INIT_SIZE;
    L.flag=1;
	return OK;
}
status DestroyList(SqList & L)
{
    if(L.elem)
    {
        free(L.elem);
        L.elem=NULL;
        L.flag=0;
        return OK;
    }
    else
        return ERROR;
}
status ClearList(SqList &L)
{
    L.length=0;
    return OK;
}
status ListEmpty(SqList L)
{
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}
int ListLength(SqList L)
{

    if(L.elem)
    return L.length;
}
status GetElem(SqList L,int i,ElemType & e)
{
    if(L.length==0||L.elem==NULL||i>=L.length||i<0)
        return ERROR;
    e=L.elem[i-1];
    printf("查找序号对应数为:%d",e);
    return OK;
}
status LocateElem(SqList L,ElemType e)
{
    status i;
    if(L.elem)
    {
        for(i=0;i<L.length;i++)
          {
               if(L.elem[i]==e)
                 return i+1;
          }
    }
    return ERROR;
}
status PriorElem(SqList L,ElemType cur,ElemType & pre_e)
{
    int i;
    i=LocateElem(L,cur);
    if(cur!=1)
    pre_e= L.elem[i-2];
    return pre_e;
    return ERROR;
}
status NextElem(SqList L,ElemType cur,ElemType & next_e)
{
    int i;
    i=LocateElem(L,cur);
    if(cur!=L.length)
    next_e= L.elem[i];
    return next_e;
    return ERROR;
}
status ListInsert(SqList & L,int i,ElemType e)
{

    ElemType *p,*q,*newbase;
    if(i<1) return ERROR;
    if(i>L.length+1) i=L.length+1;
    if(L.length>=L.listsize){
        newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW);
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    q=&(L.elem[i-1]);
    for(p=&(L.elem[L.length-1]);p>=q;--p)
    *(p+1)=*p;
    *q=e;
    ++L.length;
    return OK;
}
status ListDelete(SqList & L,int i,ElemType & e)
{
    ElemType *p,*q;
    if(i<1||i>L.length+1) return ERROR;
    p=&(L.elem[i-1]);
    e=*p;
    q=L.elem+L.length-1;
    for(++p;p<=q;++p)
        *(p-1)=*p;
    --L.length;
    return OK;
}
status ListReadFile(SqList &L){
    FILE *fp;
    char filename[30];
    printf("输入文件名:");
    scanf("%s",filename);
    L.length=0;
    if((fp=fopen(filename,"r"))==NULL){
        printf("File Open Error!\n");
        return ERROR;
    }
    while(fscanf(fp,"%d ",&L.elem[L.length])!=EOF)
    L.length++;
    fclose(fp);
    return OK;
}
status ListWriteFile(SqList &L){
    FILE*fp;
    char filename[30];
    int i=0;
    printf("输入文件名:");
    scanf("%s",filename);
    if ((fp=fopen(filename,"w"))==NULL)
	{
	  printf("File open error\n");
	  return 1;
	}
	while(i<L.length)
    {
        fprintf(fp,"%d ",L.elem[i]);
        i++;
    }
    fclose(fp);
    return OK;
}
status ListTraverse(SqList L){
   int i;
   printf("\n-----------all elements -----------------------\n");
   for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);
   printf("\n------------------ end ------------------------\n");
   return L.length;
}
int ChooseList(){
   int m;
   printf("选择你要操作的线性表(1~10):");
   scanf("%d",&m);
   return m-1;
}



