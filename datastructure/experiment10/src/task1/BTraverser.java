package task1;

/**
 * @author 王游
 * @date 2019/11/17
 */

public class BTraverser {
    private static boolean[] visited;           //访问标志数组
    //对图G做广度优先遍历
    public static void BFSTraverse(IGraph G) throws Exception {
        visited = new boolean[G.getVexNum()];       //访问标志数组
        for (int v = 0; v < G.getVexNum(); v++){
            visited[v] = false;
        }
        for (int v = 0; v < G.getVexNum(); v++){
            if (!visited[v])
                BFS(G,v);
        }
    }

    public static void BFS(IGraph G, int v) throws Exception {
        visited[v] = true;
        System.out.print(G.getVex(v).toString() + " ");
        LinkQueue Q = new LinkQueue();          //辅助队列Q
        Q.offer(v);                             //v入队列
        while (!Q.isEmpty()) {
            int u = (Integer) Q.poll();         //队头元素出队列并赋值给u
            for (int w = G.firstAdjVex(u); w >= 0; w = G.nextAdjVex(u,w)){          //w为u的尚未访问的邻接顶点
                if (!visited[w]) {
                    visited[w] = true;
                    System.out.print(G.getVex(w).toString() + " ");
                    Q.offer(w);
                }
            }
        }
        System.out.println();
    }
}
