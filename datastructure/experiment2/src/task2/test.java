package task2;

import java.util.Scanner;

public class test {
    private static void creatDuLCircleLinkList(DuLinkList L, int n) throws Exception{
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入双向循环表中的各元素值：");
        for(int i = 0; i < n; i++){
            L.insert(i,new Integer(sc.nextInt()));   //将新结点插入到表尾
        }
    }
    private static void move(DuLinkList L){
        Object temp;
        DuLNode p = L.getHead().getNext(),  //p指向双向循环链L的第一个结点
        q = L.getHead().getPrior(); //q指向双向循环链L的最后一个结点
        if (!L.isEmpty()){
            while (!p.equals(q)){
                while (!p.equals(q) && ((Integer)p.getData()).intValue() > 0)
                    p = p.getNext();        //从左往右扫描
                while (!p.equals(q) && ((Integer)q.getData()).intValue() < 0)
                    q = q.getPrior(); //从右往左扫描
                if(!p.equals(q)){
                    temp=p.getData();   //p 与 q 结点的数据值置换
                    p.setData(q.getData());
                    q.setData(temp);
                    if(p.getNext().equals(q))
                        p = q;  //使其不继续扫描下去
                    else {
                        p = p.getNext();
                        q = q.getPrior();
                    }
                }
            }
        }
    }
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入要插入的个数：");
        int i = sc.nextInt();
        DuLinkList L = new DuLinkList();
        creatDuLCircleLinkList(L, i);
        System.out.println("插入后的是链表：");
        L.display();
        move(L);
        System.out.println("移动后的链表是：");
        L.display();
    }
}
