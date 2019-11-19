package task1;

import java.util.Scanner;

public class SY2_LinkList1 {
    private static void creat(LinkList L) throws Exception{
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入链表中的各元素（0为结束）：");
        for (int x = sc.nextInt(); x != 0; x = sc.nextInt()) {
            L.insert(0, new Integer(x));
        }
    }
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        LinkList L = new LinkList();
        creat(L);
        System.out.println("建立的单链表为：");
        L.display();
        System.out.println("请输入待插入的位置i(0~curLen):");
        int i = sc.nextInt();
        System.out.println("请输入待插入的数据值x:");
        int x = sc.nextInt();
        L.insert(i, new Integer(x));
        System.out.println("插入后的链表为：");
        L.display();
        System.out.println("请输入待删除元素的位置（0~curLen-1):");
        i=sc.nextInt();
        L.remove(i);
        System.out.println("删除后的链表为： ");
        L.display();
        System.out.println("请输入待查找的数据元素的位序号（0~curLen-1）:");
        i = sc.nextInt();
        Object o = L.get(i);
        System.out.println("此单链表中第" + i + "个结点的数据元素为" + o);
    }
}
