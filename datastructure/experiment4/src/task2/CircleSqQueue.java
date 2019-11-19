package task2;

public class CircleSqQueue {
    private int[] queueElem;
    private int rear;                   //只用队尾指针指示循环顺序队列，其指向当前队尾元素
    //循环队列类的构造函数
    public CircleSqQueue(int maxSize){
        rear = -1;                      //队尾初始化为-1
        queueElem = new int[maxSize];   //为队列分配maxsize个存储单元
    }

    //入队：把指定的元素x插入队列的队尾
    public void offer(int x){
        rear = (rear + 1) % queueElem.length;   //修改队尾指针
        queueElem[rear] = x;                    //x赋给队尾元素
    }

    public int getElem(int i) {
        return queueElem[i];
    }

    public int[] getQueueElem() {
        return queueElem;
    }

    public void setQueueElem(int[] queueElem) {
        this.queueElem = queueElem;
    }

    public int getRear() {
        return rear;
    }

    public void setRear(int rear) {
        this.rear = rear;
    }
}
