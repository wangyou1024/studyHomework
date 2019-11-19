package task3;

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

//    post作为用中序和后序建立的标志
    public BiTree(String postOrder, String inOrder, int postIndex, int inIndex, int count,int post){
        if (count > 0){
            char r = postOrder.charAt(postIndex+count -1);
            int i = 0;
            for (; i < count; i++){
                if (r == inOrder.charAt(i + inIndex))
                    break;
            }
            root = new BiTreeNode(r);
            root.setLchild(new BiTree(postOrder,inOrder,postIndex,inIndex,i,0).root);
            root.setRchild(new BiTree(postOrder,inOrder,postIndex+i,inIndex+i+1,count-i-1,0).root);
        }
    }


    public void findPath(Object data) throws Exception {
        SqStack node = new SqStack(100);
        SqStack path = new SqStack(100);
        node.push(root);
        path.push(new Integer(0));
        BiTreeNode temp = (BiTreeNode) node.pop();
        while (temp.getData() != data){
            if (temp.getLchild() == null){
                if (temp.getRchild() == null) {
                    if (temp == ((BiTreeNode) node.getTopData()).getLchild()) {
                        node.push(((BiTreeNode) node.getTopData()).getRchild());
                        path.pop();
                        path.push(1);
                    }
                    else if (temp == ((BiTreeNode) node.getTopData()).getRchild()){
                        if (temp == root.getRchild()){
                            System.out.println("无结点");
                        }
                        path.pop();
                    }
                }
                else {
                    node.push(temp);
                    node.push(temp.getRchild());
                    path.push(1);
                }
            }
            else {
                node.push(temp);
                node.push(((BiTreeNode)node.getTopData()).getLchild());
                path.push(0);
            }
            temp = (BiTreeNode) node.pop();
        }
        path.footToTop();
        System.out.println();

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
