package task1;

import java.util.Scanner;

public class SY5_BiTree1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入二叉树的标明了空子树的先根遍历序列：");
        String preStr = sc.next();
        BiTree T = new BiTree(preStr);
        while (true){
            System.out.println("-------------------------------------------------");
            System.out.println(" 1 -- 先根遍历  2 -- 中根遍历  3 -- 后根遍历");
            System.out.println("4 -- 统计结点个数  5 -- 统计叶结点个数  6 -- 退出");
            System.out.println("-------------------------------------------------");
            System.out.print("请输入选择（1-6）：");
            int i = sc.nextInt();
            switch (i) {
                case 1:System.out.print("先根遍历为：");
                T.preRootTraverse(T.getRoot());
                System.out.println();break;
                case 2:System.out.print("中根遍历为：");
                    T.inRootTraverse(T.getRoot());
                    System.out.println();break;
                case 3:System.out.print("后根遍历为：");
                    T.postRootTraverse(T.getRoot());
                    System.out.println();break;
                case 4:int m = T.countNode(T.getRoot());
                    System.out.print("二叉树的结点个数为："+m);
                    System.out.println();break;
                case 5:int n = T.countLeafNode(T.getRoot());
                System.out.print("二叉树的叶结点的个数为：" + n);
                    System.out.println();break;
                case 6:return;
            }
        }
    }
}
