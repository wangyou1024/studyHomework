package task2;

/**
 * @author 王游
 * @date 2019/11/16
 */

public class HashTable {        //采用链地法的哈希表类
    private LinkList[] table;

    public HashTable(int size){         //构造指定大小的哈希表
        this.table = new LinkList[size];
        for (int i = 0; i < table.length; i++) {
            table[i] = new LinkList();
        }
    }

    public int hash(int key) {
        return key % 13;
    }

    //在哈希表中查找指定对象，若查找成功，则返回结点;否则返回null
    public Node search(Node element) throws Exception {
        int key = element.getData().hashCode();
        int i = hash(key);
        int index = table[i].indexOf(element);          //返回元素在单链表中的位置
        if (index >= 0) {
            return (Node)table[i].get(index);           //返回在单链表中找到的结点
        }
        else{
            return null;
        }
    }

    public void insert(Node element) throws Exception {     //在哈希表中插入指定元素
        int key = element.getData().hashCode();             //每个对象的hashCode()方法返回整数值
        int i = hash(key);                                  //计算哈希地址
        table[i].insert(0,element);

    }

    public LinkList[] getTable() {
        return table;
    }

    public void setTable(LinkList[] table) {
        this.table = table;
    }

    public void display(){
        for (int i = 0; i < this.table.length; i++){
            System.out.print(i + ".");
            table[i].display();
        }
    }
}






