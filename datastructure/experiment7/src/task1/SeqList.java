package task1;

public class SeqList {
    private RecordNode[] r;         //顺序表记录结点数组
    private int curlen;             //顺序表长度，即记录个数

    public SeqList(int length) {
        this.r = new RecordNode[length];
    }

    public void insert(int position, RecordNode recordNode) {
        this.r[position] = recordNode;
        this.curlen++;
    }

    public SeqList(RecordNode[] r) {
        this.r = r;
        this.curlen = r.length;
    }

    public int length(){
        return this.curlen;
    }


    public int seqSearch(Comparable key) {
        int i = 0,n = length();
        while (i < n && r[i].getKey().compareTo(key) != 0){
            i++;
        }
        if(i < n) {     //若查找成功，则返回该记录的下标i;否则，返回-1
            return i;
        }
        else{
            return -1;
        }
    }

    public int binarySearch(Comparable key) {
        if (length() > 0) {
            int low = 0,high = length()-1;                  //查找范围的下界和上界
            while (low <= high) {
                int mid = (low+high)/2;                     //中间位置，当前比较的记录位置
                if (r[mid].getKey().compareTo(key) == 0) {
                    return mid;                             //查找成功
                }
                else if (r[mid].getKey().compareTo(key)>0){ //给定值更小
                    high = mid -1;                          //查找范围缩小到前半段
                }
                else{
                    low = mid + 1;                          //查找范围缩小到后半段
                }
            }
        }
        return -1;                                          //查找不成功
    }







    public RecordNode[] getRecord() {
        return r;
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
