package task1;

import java.util.Scanner;

public class SY7_Search1 {
    static SeqList ST = null;
    //建立待查找的顺序表
    public static void createSearchList() throws Exception {
        ST = new SeqList(20);
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入查找表的表长：");
        int n = sc.nextInt();
        KeyType[] k = new KeyType[n];
        System.out.print("请输入查找表中的关键字序列：");
        for (int i =0; i < n; i++){
            k[i] = new KeyType(sc.nextInt());
        }
        for (int i = 0; i < n; i++){
            RecordNode r = new RecordNode(k[i]);
            ST.insert(i,r);
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        KeyType key1,key2;
        boolean flag = true;
        while (flag) {
            System.out.println("1 -- 顺序查找    2 -- 二分查找     3 -- 退出");
            System.out.print("请输入选择（1-3）：");
            int i = sc.nextInt();
            switch (i) {
                case 1:
                    System.out.println("创建顺序查找表");
                    createSearchList();
                    System.out.print("请输入两个待查找的关键字：");
                    key1 = new KeyType(sc.nextInt());
                    key2 = new KeyType(sc.nextInt());
                    System.out.println("seqSearch(" + key1.getKey() + ")=" + ST.seqSearch(key1));
                    System.out.println("seqSearch(" + key2.getKey() + ")=" + ST.seqSearch(key2));
                    break;
                case 2:
                    System.out.println("创建有序的顺序查找表");
                    createSearchList();
                    System.out.print("请输入两个待查找的关键字：");
                    key1 = new KeyType(sc.nextInt());
                    key2 = new KeyType(sc.nextInt());
                    System.out.println("binarySearch(" + key1.getKey() + ")=" + ST.binarySearch(key1));
                    System.out.println("binarySearch(" + key2.getKey() + ")=" + ST.binarySearch(key2));
                    break;
                case 3:
                    flag = false;
                    break;
            }
        }
    }
}
