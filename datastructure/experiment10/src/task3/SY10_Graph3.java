package task3;

import java.util.Scanner;

/**
 * @author 王游
 * @date 2019/11/17
 */

public class SY10_Graph3 {
    public final static int INFINITY = Integer.MAX_VALUE;
    public static MGraph creat(){
        Place[] places = new Place[14];
        places[0] = new Place("正校门","这里是正校门");
        places[1] = new Place("东校门","这里是东校门");
        places[2] = new Place("西校门","这里是西校门");
        places[3] = new Place("北校门","这里是北校门");
        places[4] = new Place("食堂","这是吃饭的地方");
        places[5] = new Place("磁悬浮列车实验室","这里可以做实验");
        places[6] = new Place("樱花大道","这里可以谈恋爱");
        places[7] = new Place("图书馆","这里是学习的好地方");
        places[8] = new Place("体育场","这是体育场，不是体育馆");
        places[9] = new Place("体育馆","这是体育馆，不是体育场");
        places[10] = new Place("游泳馆","这是可以游泳的地方");
        places[11] = new Place("礼堂","这是举办活动的地方");
        places[12] = new Place("教学楼","这是正常学习的地方");
        places[13] = new Place("宿舍","这是宿舍");
        GraphKind kind = GraphKind.valueOf("UDN");
        int vexNum = 14;
        int arcNum = 18;
        int[][] arcs = {
                {INFINITY,INFINITY,INFINITY,INFINITY,35,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,5,INFINITY,INFINITY},
                {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,75,INFINITY,INFINITY,10},
                {INFINITY,INFINITY,INFINITY,INFINITY,30,INFINITY,INFINITY,5,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY},
                {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,15,50,INFINITY,15,20,INFINITY,INFINITY,INFINITY},
                {35,INFINITY,30,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,60,INFINITY,INFINITY,40,INFINITY,INFINITY},
                {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,45,INFINITY,INFINITY,10,INFINITY,INFINITY},
                {INFINITY,INFINITY,INFINITY,15,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY},
                {INFINITY,INFINITY,5,50,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY},
                {INFINITY,INFINITY,INFINITY,INFINITY,60,45,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,50,INFINITY,INFINITY},
                {INFINITY,INFINITY,INFINITY,15,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,20,INFINITY,INFINITY,100},
                {INFINITY,75,INFINITY,20,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,20,INFINITY,INFINITY,INFINITY,INFINITY},
                {5,INFINITY,INFINITY,INFINITY,40,10,INFINITY,INFINITY,50,INFINITY,INFINITY,INFINITY,25,INFINITY},
                {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,25,INFINITY,20},
                {INFINITY,10,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,100,INFINITY,INFINITY,20,INFINITY},
        };
        return new MGraph(kind,vexNum,arcNum,places,arcs);
    }

    public static boolean over(boolean[] visited) {
        for (int i = 0; i < visited.length; i++) {
            if (visited[i] == false){
                return false;
            }
        }
        return true;
    }

    public static int[] dijkstra(int[][] matrix, int v0){
        int vertexCount = matrix.length;
        boolean[] isInUSet = new boolean[vertexCount];
        int[] distant = new int[vertexCount];
        int[] parent = new int[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            isInUSet[i] = false;
            distant[i] = matrix[v0][i];
            parent[i] = v0;
        }
        isInUSet[v0] = true;
        distant[v0] = 0;
        parent[v0] = -1;
        for (int i = 0; i < vertexCount; i++){
            int minCost = Integer.MAX_VALUE;
            int minIndex = v0;
            for (int w = 0; w < vertexCount; w++){
                if (!isInUSet[w]) {
                    if (distant[w] < minCost){
                        minIndex = w;
                        minCost = distant[w];
                    }
                }
            }
            if (minCost < Integer.MAX_VALUE){
                isInUSet[minIndex] = true;
            }
            else
                break;
            for (int w = 0; w < vertexCount; w++){
                if (!isInUSet[w] && matrix[minIndex][w] < INFINITY && (minCost + matrix[minIndex][w] < distant[w])) {
                    distant[w]  = minCost + matrix[minIndex][w];
                    parent[w] = minIndex;
                }
            }
        }
        return parent;
    }

    //Prim算法
    public static MGraph findAllWay(MGraph G,String begin) {
        boolean[] visited = new boolean[G.getVexNum()];         //通过是否访问来区分迪杰特拉的两个集合
        Place place = new Place(begin);
        for (int i = 0; i < G.getVexNum(); i++){
            visited[i] = false;
        }
        //生成只含单源最短路径的邻接矩阵
        int[][] arcs = new int[G.getVexNum()][G.getVexNum()];
        for (int i = 0; i < arcs.length; i++){
            for (int j = 0; j < arcs[i].length; j++){
                arcs[i][j] = INFINITY;
            }
        }
        visited[G.locateVex(place)] = true;
        while (over(visited) == false){
            int start = 0;
            int end = 0;
            int min = INFINITY;
            //找到已访问点中到未访问的点的最短路径
            for (int i = 0; i < G.getVexNum(); i++){
                if (visited[i]){
                    for (int j = 0; j < G.getVexNum(); j++){
                        if (!visited[j] && G.getArcs()[i][j] < min){
                            min = G.getArcs()[i][j];
                            start = i;
                            end = j;
                        }
                    }
                }
            }
            arcs[start][end] = min;
            arcs[end][start] = min;
            visited[end] = true;
        }
        return new MGraph(G.getKind(),G.getVexNum(),G.getArcNum(),G.getVexs(),arcs);    //只含单源最短路径的短径
    }
    public static int[] findAWay(MGraph G, String top, String begin,String end) throws Exception {
        MGraph newG = findAllWay(G,top);
        boolean[] visited = new boolean[newG.getVexNum()];
        for (int i = 0; i < visited.length; i++){
            visited[i] = false;
        }
        visited[G.locateVex(new Place(begin))] = true;
        int[] ways = new int[newG.getVexNum()];
        for (int i = 0; i < ways.length; i++){
            ways[i] = INFINITY;
        }
        ways[0] = newG.locateVex(new Place(begin));
        int temp = 1;
        //用栈的思想找路
        while (over(visited) == false){
            int i;
            for (i = 0; i < newG.getVexNum(); i++){
                if (newG.getArcs()[ways[temp-1]][i] < INFINITY && visited[i] == false){
                    ways[temp] = i; //入栈
                    visited[i] = true;
                    temp++;
                    if (i == newG.locateVex(new Place(end))) {
                        for (int j = temp; j < newG.getVexNum(); j++){
                            ways[j] = INFINITY;
                        }
                        return ways;
                    }
                    break;
                }
            }
            if (i == G.getVexNum())
                temp--;         //弹栈
        }
        return null;
    }
    public static int wayLength(int[] way, MGraph G) {
        int sum = -1;
        int i = 0;
        if (way != null) {
            while (way[i] >= 0 && way[i] < INFINITY) {
                if (way[i + 1] >= 0 && way[i + 1] < INFINITY) {
                    sum += G.getArcs()[way[i]][way[i + 1]];
                }
                else
                    break;
                i++;
            }
        }
        return sum;
    }

    public static void display(int[] parent,MGraph G,int end) throws Exception {
        String path = ((Place)G.getVex(end)).getName();
        int p = parent[end];
        while(p != -1) {
            path = ((Place)G.getVex(p)).getName() + "->" + path;
            p = parent[p];
        }
        System.out.println(path);
    }


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int i = 0;
        MGraph G = creat();
        while (i != 3){
            System.out.println("1--查看景点详情  2--寻找最短路径  3--退出");
            i = sc.nextInt();
            switch (i){
                case 1:System.out.print("请输入景点：");
                String name = sc.next();
                System.out.println("详情:");
                System.out.println(((Place)G.getVex(G.locateVex(new Place(name)))).getInformation());
                    break;
                case 2:System.out.println("请输入起点：");
                    String begin = sc.next();
                    System.out.println("请输入终点");
                    String end = sc.next();
                    int[] parent =  dijkstra(G.getArcs(),G.locateVex(new Place(begin)));
                    display(parent,G,G.locateVex(new Place(end)));
                    break;
                case 3:break;
            }
        }
    }

}
