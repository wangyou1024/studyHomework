package task3;

public class Position {

    private int x;
    private int y;
    private int direction;
    private Position next;

    public Position(int x, int y, int direction) {
        this.x = x;
        this.y = y;
        this.direction = direction;
    }

    @Override
    public String toString() {
        return "("+x+","+y+","+direction+")";
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getDirection() {
        return direction;
    }

    public void setDirection(int direction) {
        this.direction = direction;
    }

    public Position getNext() {
        return next;
    }

    public void setNext(Position next) {
        this.next = next;
    }
}
