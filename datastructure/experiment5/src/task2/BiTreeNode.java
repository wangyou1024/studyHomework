package task2;

public class BiTreeNode {
    private Object data;                //结点的数据域
    private BiTreeNode lchild,rchild;   //左右孩子域

    //构造一个空结点
    public BiTreeNode(){
        this(null);
    }

    //构造一棵左、右孩子域为空的二叉树
    public BiTreeNode(Object data){
        this(data,null,null);
    }

    //构造一棵数据域和左、右孩子域都不为空的二叉树
    public BiTreeNode(Object data, BiTreeNode lchild, BiTreeNode rchild){
        this.data = data;
        this.lchild = lchild;
        this.rchild = rchild;
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public BiTreeNode getLchild() {
        return lchild;
    }

    public void setLchild(BiTreeNode lchild) {
        this.lchild = lchild;
    }

    public BiTreeNode getRchild() {
        return rchild;
    }

    public void setRchild(BiTreeNode rchild) {
        this.rchild = rchild;
    }
}
