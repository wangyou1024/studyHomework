package task3;

public class WaitPersons {
    private WaitPerson front;
    private WaitPerson rear;

    public WaitPersons() {
        front = rear = null;
    }

    void offer(WaitPerson x){
        if(front != null) {    //队列非空
            rear.setNext(x);
            rear = x;           //改变队列尾的位置
        }
        else
            front = rear = x;
    }

    WaitPerson poll(){
        if(front != null) {     //队列非空
            WaitPerson p = front;     //p指向队列头结点
            front = front.getNext();
            if(p == rear)       //被删的结点是队尾结点
                rear = null;
            return p; //返回队列头结点数据
        }else
            return null;
    }

    void display(){
        WaitPerson p = front;
        while (p != null){
            System.out.print(p.toString() + " ");
            p = p.getNext();
        }
        System.out.println();

    }


    public WaitPerson getFront() {
        return front;
    }

    public void setFront(WaitPerson front) {
        this.front = front;
    }

    public WaitPerson getRear() {
        return rear;
    }

    public void setRear(WaitPerson rear) {
        this.rear = rear;
    }
}
