package task3;

public class Stack {
    private Position top;

    public Stack() {
    }

    public void push(Position e){
        e.setNext(top);
        top = e;
    }
    public Position  pop(){
        if(top == null)
            return null;
        else{
            Position p = top;
            top = top.getNext();
            return p;
        }
    }

    public boolean isEmpty(){
        return top == null;
    }

    public void display(){
        Stack replace = new Stack();
        Position p = top;
        while (p != null){
            replace.push(new Position(p.getX(),p.getY(),p.getDirection()));
            p = p.getNext();
        }
        p = replace.top;
        while (p != null){
            System.out.print(p.toString() + " ");
            p = p.getNext();
        }
    }

    public Position getTop() {
        return top;
    }

    public void setTop(Position top) {
        this.top = top;
    }
}
