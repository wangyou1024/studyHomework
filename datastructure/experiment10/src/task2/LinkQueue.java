package task2;

/**
 * @author 王游
 * @date 2019/11/17
 */

public class LinkQueue {
    private Node front;
    private Node rear;

    public LinkQueue() {
        front = rear = null;
    }

    void offer(Object x){
        Node p = new Node(x);   //初始化新结点
        if(front != null) {     //队列非空
            rear.setNext(p);
            rear = p;           //改变队列尾的位置
        }
        else
            front = rear = p;
    }

    Object poll(){
        if(front != null) {     //队列非空
            Node p = front;     //p指向队列头结点
            front = front.getNext();
            if(p == rear)       //被删的结点是队尾结点
                rear = null;
            return p.getData(); //返回队列头结点数据
        }else
            return null;
    }

    void display(){
        Node p = front;
        while (p != null){
            System.out.print(p.getData().toString() + " ");
            p = p.getNext();
        }
        System.out.println();

    }

    public boolean isEmpty(){
        return front == null;
    }

    public void clear() {
        front = rear = null;
    }

    public Node getFront() {
        return front;
    }

    public void setFront(Node front) {
        this.front = front;
    }

    public Node getRear() {
        return rear;
    }

    public void setRear(Node rear) {
        this.rear = rear;
    }
}
