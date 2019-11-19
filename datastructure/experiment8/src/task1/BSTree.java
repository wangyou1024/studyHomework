package task1;

public class BSTree {
    protected BiTreeNode root;          //树的根结点

    public BSTree(BiTreeNode root) {
        this.root = root;
    }

    //在二叉排序树中插入结点的算法：在二叉排序树中插入关键字key，数控项为thElement的结点，
    //若插入成功，则返回true，否则返回false
    public boolean insertBST(Comparable key, Object theElement) {
        if (key == null || !(key instanceof Comparable)) {
            //不能插入空对象或不可比较大小的对象
            return false;
        }
        if (root == null){
            root = new BiTreeNode(new RecordNode(key,theElement));      //建立根结点
            return true;
        }
        return insertBST(root, key, theElement);
    }

    //递归算法，将关键字为key，数据项为theElement的结点插入到以p为根的二叉排序树中，若插入
    //成功，则返回true，否则返回false;
    public boolean insertBST(BiTreeNode p, Comparable key, Object theElement){
        if (key.compareTo(((RecordNode)p.getData()).getKey()) == 0){
            return false;                           //不插入关键字重复的结点
        }
        if (key.compareTo(((RecordNode)p.getData()).getKey()) < 0) {
            if (p.getLchild() == null) {            //若p的左子树为空
                p.setLchild(new BiTreeNode(new RecordNode(key,theElement)));
                //建立叶子结点，作为p的左孩子
                return true;
            }
            else{                   //若p的左子树非空
                return insertBST(p.getLchild(),key,theElement);
                //插入到p的左子树中
            }
        }
        else if (p.getRchild() == null){                //若p的右子树为空
            p.setRchild(new BiTreeNode(new RecordNode(key, theElement)));
            //建立叶子结点，作为p的右孩子
            return true;
        }
        else{         //若p的右子树非空
            return insertBST(p.getRchild(), key, theElement);
            //插入到p的右子树中
        }
    }

    public BiTreeNode getRoot() {
        return root;
    }

    public void setRoot(BiTreeNode root) {
        this.root = root;
    }
}
