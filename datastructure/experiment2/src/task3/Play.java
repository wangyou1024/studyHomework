package task3;

import java.util.Scanner;

public class Play {

    public static List createList(int size) {
        List list = new List(1);
        for (int i = size; i > 1; i--) {
            list.insert(i);
        }
        return list;
    }

    public static void choose(List list, int k, int dieNumber) {
        int i = 1;
        int[] die = new int[dieNumber];  //死亡人序号
        Node p = list.getHead();
        for (int j = 0; j < dieNumber; j++) {
            while (i < k - 1) {
                p = p.getNext();
                i++;
            }
            //删除并记录
            die[j] = p.getNext().getData();
            p.setNext(p.getNext().getNext());
            p = p.getNext();
            i = 1;    //重数
        }
        System.out.println("The die is: ");
        for (int j = 0; j < die.length; j++) {
            System.out.print(die[j] + " ");
        }
        System.out.println();
        System.out.println("The live is: ");
        list.display();
    }

    public static void main(String[] args) {
        System.out.println("请输入总游客数：");
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        List list = createList(size);
        System.out.println("所有人序号是:");
        list.display();
        System.out.println("请输入死者报号：(<" + list.getSize() + ")");
        int die;
        do {
            die = sc.nextInt();
            if(die < list.getSize())
                break;
            else
                System.out.println("步长小于" + list.getSize());
        }while (true);
        int dieNumber;
        System.out.println("请输入死亡人数：");
        do {
            dieNumber = sc.nextInt();
            if(dieNumber < list.getSize())
                break;
            else
                System.out.println("死亡人数小于" + list.getSize());
        }while (true);
        choose(list, die,dieNumber);
    }
}
