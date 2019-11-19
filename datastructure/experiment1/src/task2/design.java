package task2;

import java.util.Scanner;

public class design {
    private static void creatSortSqList(SqList L, int n) throws Exception{
        Scanner sc=new Scanner(System.in);
        System.out.print("请输入有序顺表中的各个数据元素：");
        for(int i = 0; i < n; i++)
            L.insert(i,sc.nextInt());
    }
    private static void removePublic(SqList A, SqList B, SqList C) throws Exception{
        int i = 0, j = 0, k = 0;
        while(j < B.length()&&k<C.length()){
            if((Integer)B.get(j) < (Integer)C.get(k))
                j++;
            else if((Integer)B.get(j)>(Integer)C.get(k))
                k++;
            else{       //B.get(i) == C.get(k),则B.get(j)是B和C的公共元素
                while (i < A.length() && (Integer)A.get(i)<(Integer)B.get(j))
                    i++;
                while (i < A.length()&&(Integer)A.get(i) == (Integer)B.get(j))  //防止A中有重复的需要删除
                    A.remove(i);
                j++;k++;
            }
        }
    }
    public static void main(String[] args) throws Exception{
        Scanner sc=new Scanner(System.in);
        System.out.print("请输入A的长度: ");
        int ALength = sc.nextInt();
        SqList ASqList = new SqList(ALength);
        creatSortSqList(ASqList,ALength);
        System.out.print("请输入B的长度: ");
        int BLength = sc.nextInt();
        SqList BSqList = new SqList(BLength);
        creatSortSqList(BSqList,BLength);
        System.out.print("请输入C的长度: ");
        int CLength = sc.nextInt();
        SqList CSqList = new SqList(CLength);
        creatSortSqList(CSqList,CLength);
        System.out.println("Before test:");
        ASqList.display();
        removePublic(ASqList,BSqList,CSqList);
        System.out.println("After test:");
        ASqList.display();
    }
}
