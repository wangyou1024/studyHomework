package task3;

public class test {

    public static void main(String[] args){
        /*初始化迷宫的二维数组*/
        char [][] mazearr = {
                {'1','1','1','1','1','1','1','1','1','1'} ,
                {'1','0','0','1','0','0','0','1','0','1'} ,
                {'1','0','0','1','0','0','0','1','0','1'} ,
                {'1','0','0','0','0','1','1','0','1','1'} ,
                {'1','0','1','1','1','0','0','1','0','1'} ,
                {'1','0','0','0','1','0','0','0','0','1'} ,
                {'1','0','1','0','0','0','1','0','1','1'} ,
                {'1','0','1','1','1','1','0','0','1','1'} ,
                {'1','1','1','0','0','0','1','0','1','1'},
                {'1','1','1','0','0','0','0','0','0','1'},
                {'1','1','1','1','1','1','1','1','1','1'} } ;
        Cell[][] maze = creat(mazearr);
        Stack path = findPath(maze,1,1,9,8);
        if(path.getTop() == null){
            System.out.println("没有路");
        }
        else {
            System.out.println("第一个数字为行数，第二个数字为列，第三个为方向（1向左，2向下，3向右，4向上）：");
            path.display();
        }

    }

    public static Cell[][] creat(char[][] maze){
        /*为迷宫的数据域分配空间*/
        Cell[][] cells = new Cell[maze.length][maze[0].length] ;

        /*将二维数组类型转换为迷宫*/
        for(int i=0 ; i<cells.length ; i++) {
            for (int j = 0; j < cells[i].length; j++) {
                /*获取数组元素*/
                Cell cell = new Cell();
                /*初始化该迷宫元素*/
                char c = maze[i][j];
                /*将二维数组元素转换为迷宫元素*/
                if (c == '1') {
                    cell.setMark('1');                         //设置标识位1
                } else if (c == '0') {
                    cell.setMark('0');                         //设置标识为0
                }
                cell.setX(i);                                  //设置横坐标
                cell.setY(j);                                  //设置纵坐标
                cell.setVisited(false);                         //设置访问标识

                /*将该元素放入迷宫对应位置*/
                cells[i][j] = cell;
            }
        }
        return cells;
    }

    private static Stack findPath(Cell[][] cells , int sx , int sy , int ex , int ey){
        Stack stack = new Stack() ;
        /*获取起点与终点*/
        Cell startCell = cells[sx][sy] ;
        Cell endCell = cells[ex][ey] ;
        /*将起点加入栈中*/
        stack.push(new Position(startCell.getX(),startCell.getY(),0));
        startCell.setVisited(true);                     //设置起点已被访问
        /*穷举出所有情况*/
        while(!stack.isEmpty()){
            /*取出栈顶元素，若其是终点，则顺序将所访问的节点标识制为* */
            Cell curCell = cells[stack.getTop().getX()][stack.getTop().getY()];
            if(curCell == endCell){
                stack.getTop().setDirection(1);
               return stack;
            }else{
                /*获取该点的横坐标和纵坐标*/
                int x = curCell.getX() ;
                int y = curCell.getY() ;
                /*若栈顶元素不为终点,判断上下左右位置是否合法，若合法压入栈*/
                if(cells[x+1][y].getMark() == '0' && cells[x+1][y].isVisited() == false){
                    stack.getTop().setDirection(2);
                    Position newPosition = new Position(x+1,y,0);
                    stack.push(newPosition);
                    cells[x+1][y].setVisited(true);
                }else if(cells[x][y+1].getMark() == '0' && cells[x][y+1].isVisited() == false){
                    stack.getTop().setDirection(1);
                    Position newPosition = new Position(x,y+1,0);
                    stack.push(newPosition);
                    cells[x][y+1].setVisited(true);
                }else if(cells[x-1][y].getMark() == '0' && cells[x-1][y].isVisited() == false){
                    stack.getTop().setDirection(4);
                    Position newPosition = new Position(x-1,y,0);
                    stack.push(newPosition);
                    cells[x-1][y].setVisited(true);
                }else if(cells[x][y-1].getMark() == '0' && cells[x][y-1].isVisited() == false){
                    stack.getTop().setDirection(3);
                    Position newPosition = new Position(x,y-1,0);
                    stack.push(newPosition);
                    cells[x][y-1].setVisited(true);
                }else{
                    stack.pop();                                                                   //若为死路则退栈
                }
            }
        }
        return stack ;
    }
}
