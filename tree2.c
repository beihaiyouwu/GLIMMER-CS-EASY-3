#include <stdio.h>
#include <stdlib.h>
//链式存储二叉树的创建打印
typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;
TreeNode* create_node(int value)//节点的创建
{  
    TreeNode* p=malloc(sizeof(TreeNode));//内存分配
    p->data=value;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void preprint(TreeNode* t)//前序遍历
{
    if(t==NULL)
    return;
    else
    {
        printf("%3d",t->data);//根左右
        preprint(t->left);
        preprint(t->right);
    }
}
void midprint(TreeNode* t)//中序遍历
{
    if(t==NULL)
    return;
    else
    {
        midprint(t->left);//左根右
        printf("%3d",t->data);
        midprint(t->right);
        
    }
}
void lastprint(TreeNode* t)//后序遍历
{
    if(t==NULL)
    return;
    else
    {
        lastprint(t->left);//左有根
        lastprint(t->right);
        printf("%3d",t->data);
    }
}

int depth(TreeNode *root, int current_depth, int max_depth)//
{
    if(root==NULL)
    {
      return max_depth;
    }
    current_depth++;
    if(current_depth>max_depth)
    {
        max_depth=current_depth;
    }
    int left_max=depth(root->left,current_depth,max_depth);
    int right_max=depth(root->right,current_depth,max_depth);
    return (left_max>right_max?left_max:right_max);
   
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
    //打印
    printf("前序打印；\n");
    preprint(root);
    printf("\n中序打印；\n");
    midprint(root);
    printf("\n后序打印；\n");
    lastprint(root);
    int m=depth(root,0,0);
    printf("\n最大深度为：%d",m);

    return 0;  
}