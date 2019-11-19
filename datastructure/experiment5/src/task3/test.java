package task3;

import java.util.Scanner;

public class test {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入二叉树的标明了空子树的后根遍历序列：");
        String postStr = sc.next();
        System.out.print("请输入二叉树的标明了空子树的中根遍历序列：");
        String inStr = sc.next();
        BiTree T = new BiTree(postStr,inStr,0,0,inStr.length(),0);
        while (true){
            System.out.println("-----------------------------------------------------------");
            System.out.println(" 1 -- 先根遍历  2 -- 中根遍历  3 -- 后根遍历");
            System.out.println("4 -- 统计结点个数  5 -- 统计叶结点个数  6 -- 查找路径 7 -- 退出");
            System.out.println("-----------------------------------------------------------");
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
                case 6:System.out.print("请输入结点值：");
                    char data = sc.next().charAt(0);
                    System.out.print("路径为(从0开始，0为左，1为右)：");
                    T.findPath(data);break;
                case 7:return;
            }
        }
    }
}
