package task2;

/**
 * @author 王游
 * @date 2019/11/17
 */

public class SY10_Graph2 {

    public static void CC_BFS(IGraph G) throws Exception {
        boolean[] visited = new boolean[G.getVexNum()];         //访问标志数组
        for (int v = 0; v < G.getVexNum(); v++){                //访问标志数组初始化
            visited[v] = false;
        }
        LinkQueue Q = new LinkQueue();                          //辅助队列Q
        LinkQueue P = new LinkQueue();                          //辅助队列P，用于记录连通分量的顶点
        int i = 0;                                              //用于记录连通分量的个数
        for (int v = 0; v < G.getVexNum(); v++){
            P.clear();                                          //队列清空
            if (!visited[v]){                                   //v尚未访问
                visited[v] = true;
                P.offer(G.getVex(v));
                Q.offer(v);                                     //v入队列
                while (!Q.isEmpty()){
                    int u = (Integer)Q.poll();                  //队头元素出队列并赋值给u
                    for (int w = G.firstAdjVex(u); w >= 0; w = G.nextAdjVex(u,w)){
                        if (!visited[v]){                       //w为u的尚未访问的邻接顶点
                            visited[w] = true;
                            P.offer(G.getVex(w));
                            Q.offer(w);
                        }
                    }
                }
                System.out.println("图的第" + ++i + "个连通分量为：");
                while (!P.isEmpty()){
                    System.out.print(P.poll().toString() + " ");
                }
                System.out.println();
            }
        }
    }
    public static void main(String[] args) throws Exception{
        MGraph G = new MGraph();
        G.createGraph();
        System.out.println("图的所有连通分量为：");
        CC_BFS(G);
    }
}
