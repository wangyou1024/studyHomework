package task1;

public class LinkList {
    private Node head;
    public LinkList(){
        this.head=new Node();
    }
    Object get(int i) throws Exception {
        Node p = head.getNext(); //初始化，p指向结点，j为计数器
        int j = 0;
        while (p != null && j < i){  //从首结点开始向后查找，直到p指向第i个结点或p为空
            p = p.getNext();        //指向后继结点
            ++j;                    //计数器的值增1
        }
        if(j>i || p == null){       //i小于0或者大于表长减1
            throw new Exception("第" + i + " 个元素不存在"); //抛出异常
        }
        return p.getData();         //返回结点p的数据域的值
    }
    void insert(int i, Object x) throws Exception{
        Node p = head;          //初始化p为头结点，j为计数器
        int j = -1;
        while(p != null && j < i-1){    //寻找i个结点的前驱
            p = p.getNext();
            ++j;                    //计数器的值增1
        }
        if (j>i-1 || p == null)     //i不合法
            throw new Exception("插入位置不合理");//异常

        Node s = new Node(x);       //生成新结点
        s.setNext(p.getNext());     //插入单链表中
        p.setNext(s);
    }
    void remove(int i ) throws Exception{
        Node p = head;
        int j = -1;
        while(p.getNext() != null && j < i-1){
            p = p.getNext();
            ++j;
        }
        if(j > i-1 || p.getNext() == null){
            throw new Exception("删除位置不合理");
        }
        p.setNext(p.getNext().getNext());
    }
    void display(){
        Node p = head;
        int i = 0;
        while(p.getNext() != null){
            p = p.getNext();
            System.out.print(p.getData().toString() + " ");
        }
        System.out.println();
    }
}
