package task3;

/**
 * @author 王游
 * @date 2019/11/17
 */

public interface IGraph {

    void createGraph();

    int getVexNum();

    int getArcNum() ;

    Object getVex(int v) throws Exception;

    int locateVex(Object vex);

    int firstAdjVex(int v) throws Exception;

    int nextAdjVex(int v, int w) throws Exception;
}

