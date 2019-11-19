package task3;

/**
 * @author 王游
 * @date 2019/11/17
 */

public class HashTable {
    private RecordNode[] table;         //哈希表的对象数组
    public HashTable(int size){         //构造指定大小的哈希表
        this.table = new RecordNode[size];
        for (int i = 0; i < table.length; i++) {
            table[i] = new RecordNode(" ");
        }
    }

    public int hash(int key){           //除留余数法哈希函数，除数是哈希表长度
        return ((key % 19)+20) % 20;
    }

    //在开放地址哈希表中查找关键字值为key的记录，若哈希表满，则返回null，否则返回关键字为key或为null的记录结点
    public RecordNode hashSearch(String name){
        int i = hash(name.hashCode());
        int j = 0;
        while ((table[i].getKey().compareTo(" ") != 0)
                && (table[i].getKey().compareTo(name) != 0)
                && (j < table.length)) {
            //该位置中不为空并且关键字与key不相等
            j++;
            i = (i + j) % 20;            //用线性探测再散列法求得下一探测地址
        }//i指示查找到的记录在表中的存储位置或指示插入位置
        if (j >= table.length){
            System.out.println("哈希表已满");
            return null;
        }
        else
            return table[i];
    }

    //查找不成功且表不满时，插入关键字值为key的记录到开放地址哈希表中
    public void hashInsert(String name) {
        RecordNode p = hashSearch(name);

        if (p.getKey().compareTo(" ") == 0) {
            p.setKey(name);
            System.out.println("插入成功！" + name);
        }
        else {
            System.out.println(" 此关键字记录已存在或哈希表已满");
        }
    }

    //哈希表的输出函数
    void Hashdisplay() {
        for (int i = 0; i < table.length; i++){
            System.out.print(table[i].getKey().toString() + " ");
        }
        System.out.println();
    }

    public RecordNode[] getTable() {
        return table;
    }

    public void setTable(RecordNode[] table) {
        this.table = table;
    }
}
