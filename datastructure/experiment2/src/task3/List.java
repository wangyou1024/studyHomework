package task3;

public class List {
    private Node head;
    private int size;

    public List(int data) {
        head = new Node(data);
        head.setNext(head);
        size = 1;
    }

    public void insert(int data){
        Node p = head;
        Node x = new Node(data);    //头插法
        x.setNext(p.getNext());
        p.setNext(x);
        size++;
    }

    public void display(){
        Node p = head;
        int i = 0;
        for (i = 0; i < size; i++){
            System.out.print(p.getData() + " ");
            p = p.getNext();
            if(p.getData() == head.getData())
                break;
        }
        System.out.println();
    }



    public Node getHead() {
        return head;
    }

    public void setHead(Node head) {
        this.head = head;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }
}
