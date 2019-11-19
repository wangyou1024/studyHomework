package task2;

import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入索引表长度：");
        int length = sc.nextInt();
        IndexList indexList = new IndexList(length);
        for (int i = 0; i < length; i++){
            System.out.print("请输入第" + (i+1) + "个索引值");
            IndexNode indexNode = new IndexNode(sc.nextInt());
            System.out.print("请输入结点值（输入0结束）：");
            int value = sc.nextInt();
            while (value != 0){
                indexNode.addNode(new Node(value));
                value = sc.nextInt();
            }
            indexList.insert(i+1,indexNode);
        }
        System.out.print("请输入查找内容:");
        int find = sc.nextInt();
        System.out.println(indexList.findrecord(indexList,find).toString());

    }
}
