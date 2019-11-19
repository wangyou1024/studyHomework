package task2;

import jdk.nashorn.internal.ir.BaseNode;

public class IndexList {
    private IndexNode[] r;          //顺序表记录结点数组
    private int curlen = 0;             //顺序表长度，即记录个数

    public IndexList() {
    }

    public IndexList(IndexNode[] r) {
        this.r = r;
        this.curlen = this.r.length;
    }

    public IndexList(int length) {
        this.r = new IndexNode[length+1];
    }

    public void insert(int position, IndexNode node) {
        this.r[position] = node;
        this.curlen++;
    }

    public int length(){
        return this.curlen;
    }

    public int findblock(IndexList ST, int key){
        /*用二分查找法在索引表ST的索引表中确定关键字值为key的待查找记录所在的块号，并返回其块号值
         */
        int low,high,mid;
        low = 1; high = ST.getCurlen();
        while (low <= high) {
            mid = (low + high) / 2;
            if (((ST.getR())[mid].getMaxKey())>key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high+ (high == curlen?0:1);
    }

    public Node findrecord(IndexList ST, int key){
        /*用顺序查找法在索引表的块链中确定关键字值为key的待查找记录的存储位置，如查
        找成功，则函数返回其地址值，否则返回空指针
        */
        int Bno = findblock(ST,key);        //调用函数，确定待查记录所在块号
        Node p = (ST.getR())[Bno].getHead();    //取到待查记录所在块链的头指针
        while (p!=null && p.getKey() != key)    //顺着链指针依次查找
            p = p.getNext();
        return p;
    }


    public IndexNode[] getR() {
        return r;
    }

    public void setR(IndexNode[] r) {
        this.r = r;
    }

    public int getCurlen() {
        return curlen;
    }

    public void setCurlen(int curlen) {
        this.curlen = curlen;
    }
}
