package task1;

public class SeqList {
    private RecordNode[] r;         //顺序表记录结点数组
    private int curlen = 0;             //顺序表长度，即记录个数

    public SeqList(int maxSize) {
        this.r = new RecordNode[maxSize];
    }

    public int length() {
        return this.curlen + 1;       //指向下一个存储空间
    }

    public void insert(int position, RecordNode recordNode) {
        this.r[position] = recordNode;
        this.curlen++;
    }

    public void insertSortWithGuard() {
        int i, j;
        System.out.println("带监视哨的直接插入排序");
        for (i = 2; i < this.curlen; i++) {           //n-1趟扫描
            r[0] = r[i];        //将待插入的第i条记录暂存在r[0]中，同时r[0]为监视哨
            for (j = i - 1; r[0].getKey().compareTo(r[j].getKey()) < 0; j--) {
                r[j + 1] = r[j];
            }
            r[j + 1] = r[0];
        }
    }

    public RecordNode[] getRecord() {
        return r;
    }

    public void display() {
        for (int i = 1; i < this.length(); i++) {
            System.out.print(" " + getRecord()[i].getKey().toString());
        }
        System.out.println();
    }

    public void setRecord(RecordNode[] r) {
        this.r = r;
    }

    public int getCurlen() {
        return curlen;
    }

    public void setCurlen(int curlen) {
        this.curlen = curlen;
    }

}
