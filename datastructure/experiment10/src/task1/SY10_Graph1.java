package task1;

/**
 * @author 王游
 * @date 2019/11/17
 */

public class SY10_Graph1 {
    public final static int INFINITY = Integer.MAX_VALUE;
    public static void main(String[] args) throws Exception{
        MGraph G = new MGraph();
        G.createGraph();
        System.out.println("图的广度遍历序列为：");
        BTraverser.BFSTraverse(G);
        System.out.println("图的深度遍历序列为：");
        DTraverser.DFSTraverse(G);
        System.out.println();
    }
}
