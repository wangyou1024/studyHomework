package task3;

public class Cell {
    private int x ;                         //单元所在行
    private int y ;                         //单元所在列
    private boolean visited = false ;       //单元是否已被访问
    private char mark ;                     //单元格的类型,1表示墙,0表示路,*表示可行路径

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
    public boolean isVisited() {
        return visited;
    }
    public void setVisited(boolean visited) {
        this.visited = visited;
    }
    public char getMark() {
        return mark;
    }
    public void setMark(char mark) {
        this.mark = mark;
    }
}
