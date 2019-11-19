package task2;

public class DuLNode {
    private Object data;    //存放结点值
    private DuLNode prior;//前驱结点的引用
    private DuLNode next;//后继结点的引用

    public DuLNode() {
    }

    public DuLNode(Object data) {
        this.data = data;
        prior = this;
        next = this;
    }

    public DuLNode(Object data, DuLNode prior, DuLNode next) {
        this.data = data;
        this.prior = prior;
        this.next = next;
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public DuLNode getPrior() {
        return prior;
    }

    public void setPrior(DuLNode prior) {
        this.prior = prior;
    }

    public DuLNode getNext() {
        return next;
    }

    public void setNext(DuLNode next) {
        this.next = next;
    }
}
