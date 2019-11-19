package task2;

public class SeqList {
    private RecordNode[] r;         //顺序表记录结点数组
    private int curlen = 0;             //顺序表长度，即记录个数
    private CopareMoveNum[] cm = new CopareMoveNum[2];
    public SeqList(int maxSize) {
        this.r = new RecordNode[maxSize];
        cm[0] = new CopareMoveNum();
        cm[1] = new CopareMoveNum();
    }

    public int length() {
        return this.curlen;       //当前长度
    }

    public void insert(int position, RecordNode recordNode) {
        this.r[position] = recordNode;
        this.curlen++;
    }

    public void bubbleSort() {
        RecordNode temp;               //辅助结点
        boolean flag = true;           //是否交换的标记
        for (int i = 1; i < this.length() && flag; i++){
            //有交换时再进行下一趟，最多n-1趟
            flag = false;
            for (int j = 0; j < this.length() -1; j++){
                if (getRecord()[j].getKey().compareTo(getRecord()[j+1].getKey()) > 0){
                    cm[0].setCpn(cm[0].getCpn() + 1);           //比较次数加1
                    temp = getRecord()[j];
                    getRecord()[j] = getRecord()[j+1];
                    getRecord()[j+1] = temp;
                    flag = true;
                    cm[0].setMvn(cm[0].getMvn() + 3);           //移动次数加3
                }
            }
        }
    }

    public int Partition(int i, int j) {
        RecordNode pivot = getRecord()[i];      //第一个记录作为支点记录
        cm[1].setMvn(cm[1].getMvn() + 1);       //移动次数加1
        while (i < j) {
            while (i < j && pivot.getKey().compareTo(getRecord()[j].getKey()) < 0){
                j--;
                cm[1].setCpn(cm[1].getCpn() + 1);
            }
            if (i < j) {
                getRecord()[i] = getRecord()[j];
                i++;
                cm[1].setMvn(cm[1].getMvn() + 1);
            }
            while (i < j && pivot.getKey().compareTo(getRecord()[i].getKey()) > 0){
                i++;
                cm[1].setCpn(cm[1].getCpn() + 1);
            }
            if (i < j) {
                getRecord()[j] = getRecord()[i];
                j--;
                cm[1].setMvn(cm[1].getMvn() + 1);
            }
        }
        getRecord()[i] = pivot;
        cm[1].setMvn(cm[1].getMvn() + 1);
        return i;
    }

    public void quickSort(int i,int j){
        if (i < j && i >=0 && j >= 0){
            int pa = Partition(i,j);
            quickSort(i,pa-1);
            quickSort(pa+1,j);
        }
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
        for (int i = 1; i < this.curlen-1; i++) {
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

    public CopareMoveNum[] getCm() {
        return cm;
    }

    public void setCm(CopareMoveNum[] cm) {
        this.cm = cm;
    }
}
