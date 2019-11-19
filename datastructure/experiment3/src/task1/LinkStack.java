package task1;

public class LinkStack {
    private Node top;

    public LinkStack() {
    }

    void push(Object e){
        Node p = new Node(e);       //构造一个值为e的新结点p
        p.setNext(top);             //将p插入到链栈的栈顶
        top = p;
    }

    Object pop(){
        if(top == null)             //如果栈空
            return null;
        else{
            Node p = top;           //p指向待删的栈顶元素
            top = top.getNext();    //删除栈顶元素
            return p.getData();     //返回被删除的栈顶元素的数据值
        }
    }

    void display(){
        Node p = top;
        while(p != null){
            System.out.print(p.getData().toString()  + " ");
            p = p.getNext();
        }
    }



    public Node getTop() {
        return top;
    }

    public void setTop(Node top) {
        this.top = top;
    }
}
