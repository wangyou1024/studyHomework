package task2;

public class DuLinkList {
    private DuLNode head;   //双向循环链表的头结点
    private int size=0;
    //构造函数：构造一个只含头结点的空双向循环链表

    public DuLinkList() {
        head = new DuLNode();   //初始化头结点
        head.setPrior(head);    //初始化头结点的前驱和后继
        head.setNext(head);
    }
    public void insert(int i, Object x) throws Exception{
        DuLNode p = head.getNext();         //初始化，p指向头结点，j为计数器
        int j = 0;
        while (j < i && !p.equals(head)) {   //寻找插入位置i
            p = p.getNext();
            ++j;
        }

        if(j != i && !p.equals(head))   //i小于0或者大于表长
            throw new Exception("插入位置不合理");//输出异常

        DuLNode s = new DuLNode(x); // 生成新结点
        p.getPrior().setNext(s);
        s.setPrior(p.getPrior());
        s.setNext(p);
        p.setPrior(s);
        size++;
    }

    void display(){
        DuLNode p = head;
        int i = 0;
        while (p.getNext() != null && i < size){
            p = p.getNext();
            System.out.print(p.getData() + " ");
            i++;
        }
        System.out.println();
    }

    boolean isEmpty(){
        if(this.head.getNext() == null){
            return true;
        }
        else
            return false;
    }

    public DuLNode getHead() {
        return head;
    }

    public void setHead(DuLNode head) {
        this.head = head;
    }
}
