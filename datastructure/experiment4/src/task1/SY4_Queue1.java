package task1;

import java.util.Scanner;

public class SY4_Queue1 {
    public static void main(String[] args) throws Exception{
        CircleSqQueue Q1 = new CircleSqQueue(100);      //创建一个容量为100空顺序队列对象Q1
        LinkQueue Q2 = new LinkQueue();                          //创建一个空链队列对象Q2
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入队列的长度：");
        int n = sc.nextInt();
        System.out.println("请输入队列中的各元素值：");
        for(int i = 0; i < n; i++){
            int data = sc.nextInt();
            Q1.offer(data);                                       //data入顺序队列Q1
            Q2.offer(data);                                       //data入链队列Q2
        }
        System.out.println("建立的顺序队列中各元素值为（从队首到队尾）：");
        Q1.display();
        System.out.println("\n建立的链队列中各元素值为（从队首到队尾）：");
        Q2.display();
        System.out.print("\n请输入待入队的元素值x:");
        int x = sc.nextInt();
        Q1.offer(x);
        System.out.println("\n入队后的循环顺序队列中各元素值为（从队首到队尾）：");
        Q1.display();
        Q2.offer(x);
        System.out.println("\n入队后的链队列中各元素值为（从队首到队尾）：");
        Q2.display();
        Object t1 = Q1.poll();
        Object t2 = Q2.poll();
        if(t1 != null && t2 != null){
            System.out.println("\n删除的循环顺序队列的队首元素为" + t1);
            System.out.println("删除的链队列的队首元素为" + t2);
            System.out.println("删除队首元素后，循环顺序队列中各元素值为（队首到队尾）：");
            Q1.display();
            System.out.println("\n删除队首元素后，链队列中各元素值为（队首到队尾）：");
            Q2.display();
        }
    }
}
