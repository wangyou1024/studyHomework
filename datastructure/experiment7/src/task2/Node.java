package task2;

public class Node {
    private int key;            //存放记录关键字值
    private Node next;          //后继结点的引用

    public Node(int key) {
        this.key = key;
    }

    public Node(int key, Node next) {
        this.key = key;
        this.next = next;
    }

    public int getKey() {
        return key;
    }

    public void setKey(int key) {
        this.key = key;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    @Override
    public String toString() {
        return "Node{" +
                "key=" + key +
                ", next=" + next +
                '}';
    }
}
