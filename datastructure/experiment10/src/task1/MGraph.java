package task1;

import java.util.Scanner;

/**
 * @author 王游
 * @date 2019/11/17
 */
public class MGraph implements IGraph {

    public final static int INFINITY = Integer.MAX_VALUE;
    private GraphKind kind; // 图的种类标志
    private int vexNum, arcNum; // 图的当前顶点数和边数
    private Object[] vexs; // 顶点
    private int[][] arcs;  // 邻接矩阵

    public MGraph(){
        this(null, 0, 0, null, null);
    }


    public MGraph(GraphKind kind, int vexNumi, int arcNum, Object[] vexs, int[][] arcs) {
        this.kind = kind;
        this.vexNum = vexNumi;
        this.arcNum = arcNum;
        this.vexs = vexs;
        this.arcs = arcs;
    }


    /**
     *图的创建算法 图的类型共有4种
     */
    public void createGraph() {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入图的类型：（UDG、DG、UDN、DN）");
        GraphKind kind = GraphKind.valueOf(sc.next());
        switch (kind) {
            case UDG:
                createUDG();
                break;
            case DG:
                createDG();
                break;
            case UDN:
                createUDN();
                break;
            case DN:
                createDN();
                break;
            default:
                break;
        }
    }


    /**
     *创建有向网
     */
    private void createDN() {
        Scanner sc = new Scanner(System.in);
        System.out.println("请分别输出图的顶点数、图的边数：");
        vexNum = sc.nextInt();
        arcNum = sc.nextInt();
        vexs = new Object[vexNum];
        System.out.println("请分别输出图的各个顶点：");
        for(int v = 0; v < vexNum; v++){
            vexs[v] = sc.next();
        }
        arcs = new int[vexNum][vexNum];
        // 初始化邻接矩阵
        for(int v = 0; v < vexNum; v++){
            for(int u = 0; u < vexNum; u++){
                arcs[v][u] = INFINITY;
            }
        }
        System.out.println("请输入各个边的两个顶点及其权值");
        for(int k = 0; k < arcNum; k++){
            int v = locateVex(sc.next());
            int u = locateVex(sc.next());
            arcs[v][u] = sc.nextInt();
        }
    }

    /**
     *创建无向网
     */
    private void createUDN() {
        Scanner sc = new Scanner(System.in);
        System.out.println("请分别输出图的顶点数、图的边数：");
        vexNum = sc.nextInt();
        arcNum = sc.nextInt();
        vexs = new Object[vexNum];
        System.out.println("请分别输出图的各个顶点：");
        for(int v = 0; v < vexNum; v++){
            vexs[v] = sc.next();
        }
        arcs = new int[vexNum][vexNum];
        // 初始化邻接矩阵
        for(int v = 0; v < vexNum; v++){
            for(int u = 0; u < vexNum; u++){
                arcs[v][u] = INFINITY;
            }
        }
        System.out.println("请输入各个边的两个顶点及其权值");
        for(int k = 0; k < arcNum; k++){
            int v = locateVex(sc.next());
            int u = locateVex(sc.next());
            arcs[v][u] = arcs[u][v] = sc.nextInt();
        }
    }


    /**
     *创建有向图
     */
    private void createDG() {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入顶点数");
        vexNum = sc.nextInt();
        System.out.println("输入边数");
        arcNum = sc.nextInt();
        System.out.println("输入各顶点");
        for(int i=0;i<vexNum;i++) {
            vexs[i] = sc.next();
        }
        arcs = new int[vexNum][vexNum];
        for(int i=0;i<arcNum;i++) {
            int m = locateVex(sc.next());
            int n = locateVex(sc.next());
            arcs[m][n] = 1;
        }
    }


    /**
     *创建无向图
     */
    private void createUDG() {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入顶点数");
        vexNum = sc.nextInt();//顶点数
        System.out.println("输入边数");
        arcNum = sc.nextInt();//边数
        vexs = new Object[vexNum];// 构造顶点集
        System.out.println("输入各顶点");
        for (int i = 0; i < vexNum; i++) {
            vexs[i] = sc.next();
        }
        arcs = new int[vexNum][vexNum];// 构造边集
        System.out.println("输入边关系");
        for (int i = 0; i < arcNum; i++) {
            int m = locateVex(sc.next());
            int n = locateVex(sc.next());
            arcs[m][n] = arcs[n][m] = 1;
        }
    }

    public int getVexNum() {
        return vexNum;
    }

    public int getArcNum() {
        return arcNum;
    }

    /**
     *根据顶点在数组中的位置返回顶点
     */
    public Object getVex(int v) throws Exception {
        if(v < 0 && v >= vexNum)
            throw new Exception("第" + v + "个顶点不存在");
        return vexs[v];
    }

    /**
     *顶点定位 根据顶点名返回其在数组中的位置
     */
    public int locateVex(Object vex) {
        for(int v = 0; v < vexNum; v++){
            if(vexs[v].equals(vex))
                return v;
        }
        return -1;
    }

    /**
     *查找第一个邻接点
     */
    public int firstAdjVex(int v) throws Exception {
        if(v < 0 && v >= vexNum)
            throw new Exception("第" + v + "个顶点不存在");

        for(int j = 0; j < vexNum; j++){
            if(arcs[v][j] != 0 && arcs[v][j] < INFINITY){
                return j;
            }
        }
        return -1;
    }

    /**
     * 查找下一个邻接点，已知顶点v以及一个邻接点w，返回v相对于w的下一个邻接点
     */
    public int nextAdjVex(int v, int w) throws Exception {
        if(v < 0 && v >= vexNum)
            throw new Exception("第" + v + "个顶点不存在");

        for(int j = w + 1; j < vexNum; j++){
            if(arcs[v][j] != 0 && arcs[v][j] < INFINITY){
                return j;
            }
        }
        return -1;
    }

    public void display(){
        for(int i = 0; i < vexNum; i++){
            for(int j = 0; j< vexNum; j++){
                if(arcs[i][j] == INFINITY)
                    System.out.print("+ ");
                else
                    System.out.print(arcs[i][j] + " ");
            }
            System.out.println();
        }
    }
}
