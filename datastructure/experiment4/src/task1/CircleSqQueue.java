package task1;

public class CircleSqQueue {
    private Object[] queueElem;     //队列存储空间
    private int front;              //队首的引用，若队列不空，指向队列元素
    private int rear;               //队尾的引用，若队列不空，指向队尾元素的下一个位置

    public CircleSqQueue(int capacity) {
        this.queueElem = new Object[100];
        front = 0;
        rear = 0;
    }

    void offer(Object x) throws Exception {
        if((rear + 1) % queueElem.length == front)
            throw new Exception("队列已满");        //输出异常
        else {                                     //队列未满
            queueElem[rear] = x;                   //x赋给队尾元素
            rear = (rear+1) % queueElem.length;    //修改队尾指针
        }
    }

    Object poll(){              //移除队首元素并返回其值，如果此队列为空，则返回null
        if (front == rear)      //队列为空
            return null;
        else {
            Object t = queueElem[front];            //取出队首元素
            front = (front + 1) % queueElem.length; //更改队首的位置
            return t;                               //返回队首元素
        }
    }

    void display(){
        int start = front;
        int over = rear;
        while(start != over){
            System.out.print(queueElem[start] + " ");
            start = (start + 1) % queueElem.length;
        }
        System.out.println();
    }


    public Object[] getQueueElem() {
        return queueElem;
    }

    public void setQueueElem(Object[] queueElem) {
        this.queueElem = queueElem;
    }

    public int getFront() {
        return front;
    }

    public void setFront(int front) {
        this.front = front;
    }

    public int getRear() {
        return rear;
    }

    public void setRear(int rear) {
        this.rear = rear;
    }
}
