package task2;

public class IndexNode {
    private int maxKey;                 //块中的最大关键字
    private Node head;                  //指向块中的第一个结点指针

    public IndexNode(int maxKey) {
        this.maxKey = maxKey;
    }

    public IndexNode(int maxKey, Node head) {
        this.maxKey = maxKey;
        this.head = head;
    }

    public void addNode(Node node){
        Node p = head;
        if (p == null){
            setHead(node);
        }
        else{
            while (p.getNext() != null){
                p = p.getNext();
            }
            p.setNext(node);
        }
    }

    public int getMaxKey() {
        return maxKey;
    }

    public void setMaxKey(int maxKey) {
        this.maxKey = maxKey;
    }

    public Node getHead() {
        return head;
    }

    public void setHead(Node head) {
        this.head = head;
    }
}
