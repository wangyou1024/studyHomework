package task1;

public class BiTree {
    private BiTreeNode root;            //树的根结点
    //由标明空子树的先根遍历序列建立一棵二叉树
    private static int index = 0;       //用于记录preStr的索引值
    public BiTree(String preStr){
        char c = preStr.charAt(index++);//取出字符串索引为Index的字符，且index增1
        if (c != '#'){
            root = new BiTreeNode(c);
            root.setLchild(new BiTree(preStr).root);
            root.setRchild(new BiTree(preStr).root);
        }else
            root = null;
    }

    void preRootTraverse(BiTreeNode T){
        if(T != null){
            System.out.print(T.getData());
            preRootTraverse(T.getLchild());
            preRootTraverse(T.getRchild());
        }
    }

    void inRootTraverse(BiTreeNode T){
        if(T != null) {
            inRootTraverse(T.getLchild());
            System.out.print(T.getData());
            inRootTraverse(T.getRchild());
        }
    }

    void postRootTraverse(BiTreeNode T){
        if (T != null){
            postRootTraverse(T.getLchild());
            postRootTraverse(T.getRchild());
            System.out.print(T.getData());
        }
    }

    int countNode(BiTreeNode T){
        int count = 0;
        if(T != null){
            ++count;
            count += countNode(T.getLchild());
            count += countNode(T.getRchild());
        }
        return count;
    }

    int countLeafNode(BiTreeNode T){
        int count = 0;
        if(T != null) {
            if(T.getLchild() == null && T.getRchild() == null){
                ++count;
            }
            else {
                count += countLeafNode(T.getLchild());
                count += countLeafNode(T.getRchild());
            }
        }
        return count;
    }

    public BiTreeNode getRoot() {
        return root;
    }

    public void setRoot(BiTreeNode root) {
        this.root = root;
    }
}
