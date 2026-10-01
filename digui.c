#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode//二叉树节点创建
{
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right; //右子树指针
}TreeNode;
typedef struct Stack{//栈结构体
    TreeNode **arr;//数组存访问Treenode的指针
    int top;//栈顶标记，初始为-1
    int capacity;//容量
} Stack;
TreeNode* create_node(int value)//二叉树节点的创建
{  
    TreeNode* p=malloc(sizeof(TreeNode));//内存分配
    p->data=value;
    p->left=NULL;
    p->right=NULL;
    return p;
}
Stack *createStack(int capacity)//创建栈
{
    Stack *stack = malloc(sizeof(Stack));//开辟空间
    stack->arr = malloc(sizeof(TreeNode *) * capacity);//为数组开辟空间
    stack->top = -1;//初始为-1
    stack->capacity = capacity;//设置最大容量
    return stack;//返回栈指针
}
int isEmpty(Stack *stack) {//判断栈是否为空
    return stack->top == -1;//若为空返回1，非空返回0
}
void push(Stack *stack, TreeNode *node) {//入栈函数
    if (stack->top == stack->capacity - 1) {
        return;//如果栈满了直接返回
    }
    stack->arr[++stack->top] = node;//先将top值加1，再在arr数组中存入这个指向Treenode的指针node
}
TreeNode *pop(Stack *stack) {//出栈函数
    if (isEmpty(stack)) //栈空直接返回
    {
        return NULL;
    }
    return stack->arr[stack->top--];//非空则返回存在arr中的相应指针，从大往小，从上往下
}

void preorderTraversal(TreeNode *root) // 补全这个函数
{
    if(root==NULL)//如果是空返回
    return;
    Stack* stk=createStack(100);//创建内存为100的栈指针
    push(stk,root);//入栈
    while(!isEmpty(stk))//结束判断
    {
        TreeNode* cur=pop(stk);//出栈
        printf("%d\t",cur->data);//打印
        if(cur->right!=NULL)//先压右
        {
            push(stk,cur->right);
        }
        if(cur->left!=NULL)//后压左
        {
            push(stk,cur->left);
        }
    

    } 
}
void inorder(TreeNode* root)//中序打印
{
    if(root==NULL)
    return;
    Stack* stk=createStack(100);
    TreeNode* cur=root;
    while(cur!=NULL||!isEmpty(stk))
    {
        while(cur!=NULL)//一直向左，直到为空
        {
            push(stk,cur);//入栈
            cur=cur->left;
        }
        cur=pop(stk);//出栈
        printf("%d\t",cur->data);
        cur=cur->right;//往右走
    }
}
void postorder(TreeNode* root)//后续遍历
{
    if(root==NULL)
    return;
    TreeNode* cur=root;
    TreeNode* pre=NULL;//记录上一个已经打印的节点
    Stack* stk=createStack(100);
    while(cur!=NULL||!isEmpty(stk))
    {
        while(cur!=NULL)
        {
            push(stk,cur);//一直往左入栈
            cur=cur->left;
        }
        cur=stk->arr[stk->top];//先不急出栈，指向栈顶
        if(cur->right==NULL||pre==cur->right)
        {
            cur=pop(stk);//满足条件，右无或已访问直接打印
            printf("%d\t",cur->data);
            pre=cur;//更新pre
            cur=NULL;//下一轮直接回栈顶
        }
        else{
            cur=cur->right;//如果还有右往右走
        }
    }
    free(stk);
}
int main(void)
{
    //二叉树的创建
   TreeNode* root=create_node(1);
    root->left=create_node(2);
    root->right=create_node(3);
    root->left->left=create_node(4);
    root->left->right=create_node(5);
    root->right->left=create_node(6);
    root->right->right=create_node(7);
    printf("前序打印；");
    preorderTraversal(root);//使用栈和循环实现前序遍历
    printf("\n");
    printf("中序打印；");
    inorder(root);
    printf("\n");
    printf("后序打印；");
    postorder(root);
return 0;
}  
