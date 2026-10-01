#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
//顺序存储二叉树的创建
#define MAX_TREE_SIZE 100
/*
 * 顺序存储二叉树结点
 * - data：结点数据
 * - used：当前位置是否有结点
 */
typedef struct {
    int data;
    bool used;
} SeqTreeNode;

/*
 * 顺序存储二叉树
 * - nodes：结点数组
 * - size：数组最大容量
 */
typedef struct {
    SeqTreeNode nodes[MAX_TREE_SIZE];
    int size;
} SeqBiTree;
void init_tree(SeqBiTree *tree)//初始化二叉树
{   
    for(int i=0;i<MAX_TREE_SIZE;i++)//依靠循环实现初始化
    {
    tree->nodes[i].used=false;
    tree->nodes[i].data=0;
    }
    tree->size=0;
}
bool set_root(SeqBiTree *tree, int value)//根的创建
{
    if(tree->nodes[1].used==true)
    return false;
    tree->nodes[1].data=value;//数据设置
    tree->nodes[1].used=true;//内存已使用
    tree->size=1;
    return true;
}
bool set_left_child(SeqBiTree *tree, int parent_node, int value)//左孩子的创建
{  
    if(tree->nodes[parent_node].used==false)
    {
        return false;
    }
    int left_node=parent_node*2;
    if(left_node>MAX_TREE_SIZE)
    {
        return false;
    }
    if(tree->nodes[left_node].used!=false)
    {
        return false;
    }
    tree->nodes[left_node].data=value;//数据设置
    tree->size++;
    tree->nodes[left_node].used=true;
}
bool set_right_child(SeqBiTree *tree, int parent_node, int value)//右孩子的创建
{
    if(tree->nodes[parent_node].used==false)
    {
        return false;
    }
    int right_node=parent_node*2+1;
    if(right_node>MAX_TREE_SIZE)
    {
        return false;
    }
    if(tree->nodes[right_node].used==false)
    {
        return false;
    }
    tree->nodes[right_node].data=value;
    tree->size++;
    tree->nodes[right_node].used=true;
}
void level_order(SeqBiTree *tree)//打印
{   
    printf("打印整棵树,节点为空打印-1\n");
    int start=1;
    int end=start*2-1;
    int i=1;
    int m=-1;
     while(start<MAX_TREE_SIZE)//层数打印循环设置
     {
       while(i<MAX_TREE_SIZE&&i<=end)//每层打印循环
     {   
        if(tree->nodes[i].used==false)//若为空输出-1
        {
            printf("%3d",m);
        }
        else
        {
        printf("%3d",tree->nodes[i].data);
        }
        i++;
     }
     start=end+1;//初始
     end=start*2-1;//结束
     printf("\n");//换行
      }
}
int main(void)//三层的二叉树
{
    SeqBiTree tree;//二叉树的创建
    init_tree(&tree);
    set_root(&tree, 10);
    set_left_child(&tree, 1, 20);
    set_right_child(&tree, 1, 2);
    set_left_child(&tree, 2, 22);
    set_right_child(&tree, 2, 12);
    set_left_child(&tree, 3, 25);
    set_right_child(&tree, 3, 1);
    level_order(&tree);//打印
}
