package task2;

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

    public BiTree(String preOrder, String inOrder, int preIndex, int inIndex, int count) {
        if (count > 0) {
            char r = preOrder.charAt(preIndex);
            int i = 0;
            for (; i < count; i++) {
                if (r == inOrder.charAt(i + inIndex))
                    break;
            }
            root = new BiTreeNode(r);
            root.setLchild(new BiTree(preOrder, inOrder,preIndex+1,inIndex,i).root);
            root.setRchild(new BiTree(preOrder, inOrder,preIndex+i+1,inIndex+i+1,count-i-1).root);

        }
    }

    private static void exChange1(BiTreeNode T) throws Exception{
        SqStack s = new SqStack(100);
        if (T != null) {
            s.push(T);
            do {
                T = (BiTreeNode) s.pop();
                if (T.getLchild() != null || T.getRchild() != null) {
                    BiTreeNode p = (BiTreeNode) T.getLchild();
                    T.setLchild(T.getRchild());
                    T.setRchild(p);
                }
                if (T.getLchild() != null)
                    s.push(T.getLchild());
                if (T.getRchild() != null)
                    s.push(T.getRchild());
            }while (!s.isEmpty());
        }
    }

    private static void exChange2(BiTreeNode T){
        if (T != null){
            if (T.getLchild() != null || T.getRchild() != null){
                BiTreeNode p = (BiTreeNode)T.getLchild();
                T.setLchild(T.getRchild());
                T.setRchild(p);
            }
            exChange2(T.getLchild());
            exChange2(T.getRchild());
        }
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
