package task3;

import java.util.Scanner;

public class SY8_BSTree3 {
    public static void main(String args[]) {
        Student[] students = new Student[5];
        students[0] = new Student("1001","王小红",88,98);
        students[1] = new Student("1002","李小平",78,67);
        students[2] = new Student("1003","赵一飞",87,86);
        students[3] = new Student("1004","张春江",67,56);
        students[4] = new Student("1005","吴占豪",88,78);
        BSTree bsTree = new BSTree(null);
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < students.length; i++){
            bsTree.insertBST(students[i].getNumber(),students[i]);
        }
        System.out.print("请输入查找学号：");
        String number = sc.next();
        Student student = bsTree.search(number,bsTree.getRoot());
        if (student == null){
            System.out.println("查找失败");
        }
        else
            System.out.println(student.toString());
        System.out.print("请输入删除学号：");
        number = sc.next();
        student = (Student) ((RecordNode) bsTree.removeBST(number)).getElement();
        if (student == null){
            System.out.println("删除失败");
        }
        else
            System.out.println(student.toString());


//        System.out.print("请输入二叉排序树的结点个数：");
//        int n = sc.nextInt();
//        System.out.print("请输入结点的关键字序列：");
//        for (int i = 0; i < n; i++){            //输入关键字序列
//            bsTree.insertBST(sc.nextInt(),null);
//        }
//
//        System.out.print("请输入删除的结点");
//        bsTree.removeBST(sc.nextInt());
//        System.out.println("\n删除后的二叉排序树的中序遍历序列为：  ");
//        bsTree.inOrderTraverse(bsTree.getRoot());
//        System.out.println();


    }
}
