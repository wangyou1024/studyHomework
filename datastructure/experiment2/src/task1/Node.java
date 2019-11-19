package task1;

public class Node {
    private Object data; //存放结点值
    private Node next; //后继结点的引用
    //无参数时的构造函数
    public Node(){
        this(null,null);
    }
    //带一个参数时的构造函数
    public Node (Object data){
        this(data,null);
    }
    //带两个参数时的构造函数
    public Node (Object data, Node next){
        this.data=data;
        this.next=next;
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}
