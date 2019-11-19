package task3;

import java.util.Scanner;

/**
 * @author 王游
 * @date 2019/11/17
 */

public class SY_HashSearch3 {
    static HashTable T = null;
    //建立待查找的哈希表
    public static void createHashtable() throws Exception {
        String[] names = {"Liyong","Zhaoqian","Zhangyou","Zhangqiang","DenChao","Chenyuan","Wangzha","Liling","Liqiang","Liuke",
                            "Shunyou","Lilei","Liuming","Zhangliang","Liming","Wangyong","Wangqiang","Lifang","Tayong","WangDong"};
        T = new HashTable(20);
        for (int i = 0; i < names.length; i++) {
            T.hashInsert(names[i]);
        }
    }

    public static void main(String[] args) throws Exception {
        System.out.println("---创建哈希表---");
        createHashtable();
        System.out.println("创建的哈希表为：");
        T.Hashdisplay();
        System.out.println("请输入待查找的关键字：");
        Scanner sc = new Scanner(System.in);
        String key = sc.next();
        RecordNode p = T.hashSearch(key);
        if ((p.getKey()).compareTo(key) == 0)
            System.out.println("查找成功！");
        else
            System.out.println("查找失败！");
    }
}
