package task1;

import java.util.Scanner;

public class SY3_Stack1 {
    public static void main(String[] args) throws Exception{
        SqStack Sq = new SqStack(100);
        LinkStack Sl = new LinkStack();
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入栈的长度：");
        int n = sc.nextInt();
        System.out.println("请输入栈中的各元素值：");
        for(int i = 0; i < n; i++){
            int x = sc.nextInt();
            Sq.push(x);
            Sl.push(x);
        }
        System.out.println("建立的顺序栈中各元素值为（从栈顶到栈底）：");
        Sq.display();
        System.out.println("\n建立的链栈中各元素值为（从栈顶到栈底）：");
        Sl.display();
        System.out.println("\n请输入待入栈的元素值e：");
        int e = sc.nextInt();
        Sq.push(e);
        Sl.push(e);
        System.out.println("入栈后的顺序栈中各元素值为(从栈顶到栈底)：");
        Sq.display();
        System.out.println("\n入栈后的链栈中各元素值为（从栈顶到栈底）：");
        Sl.display();
        System.out.println("\n删除栈顶元素后，顺序栈中各元素值为(从栈顶到栈底)：");
        Sq.pop();
        Sq.display();
        System.out.println("\n删除栈顶元素后，链栈中各元素值为（从栈顶到栈底）：");
        Sl.pop();
        Sl.display();
    }
}
