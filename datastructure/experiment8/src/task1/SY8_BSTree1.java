package task1;

import java.util.Scanner;

public class SY8_BSTree1 extends BSTree {
    public SY8_BSTree1(BiTreeNode root) {
        super(root);
    }

    public void inOrderTraverse(BiTreeNode p) {     //中根遍历以p结点为根的二叉树
        if (p != null) {
            inOrderTraverse(p.getLchild());
            System.out.print(((RecordNode)p.getData()).getKey() + " ");
            inOrderTraverse(p.getRchild());
        }
    }

    public static void main(String args[]) {
        BSTree bsTree = new SY8_BSTree1(null);
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入二叉排序树的结点个数：");
        int n = sc.nextInt();
        System.out.print("请输入结点的关键字序列：");
        for (int i = 0; i < n; i++){            //输入关键字序列
            bsTree.insertBST(sc.nextInt(),null);
        }

        System.out.println("\n创建的二叉排序树的中序遍历序列为：  ");
        ((SY8_BSTree1)bsTree).inOrderTraverse(bsTree.getRoot());
        System.out.println();
    }
}
