package task2;

import java.util.Scanner;

public class SY8_BSTree2 {


    public static void main(String args[]) {
        BSTree bsTree = new BSTree(null);
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入二叉排序树的结点个数：");
        int n = sc.nextInt();
        System.out.print("请输入结点的关键字序列：");
        for (int i = 0; i < n; i++){            //输入关键字序列
            bsTree.insertBST(sc.nextInt(),null);
        }

        System.out.print("请输入删除的结点");
        bsTree.removeBST(sc.nextInt());
        System.out.println("\n删除后的二叉排序树的中序遍历序列为：  ");
        bsTree.inOrderTraverse(bsTree.getRoot());
        System.out.println();


    }
}
