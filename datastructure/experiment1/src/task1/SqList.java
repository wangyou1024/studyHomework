package task1;

public class SqList {
    private Object[] listElem; //线性表存储空间
    private int curLen; //线性表的当前长度
    private int capacity; //线性表容量

    public SqList() {
        this.curLen = 0;
        this.capacity = 0;
    }

    public SqList(int capacity) {
        this.capacity = capacity;
        this.listElem = new Object[capacity];
        this.curLen = 0;
    }

    public SqList(Object[] listElem) {
        this.listElem = listElem;
        this.curLen = this.listElem.length;
        this.capacity = this.listElem.length;
    }

    public void clear() {
        curLen = 0;
    }

    public boolean isEmpty() {
        return curLen == 0;
    }

    public Object get(int i) {
        return listElem[i];
    }

    public int length() {
        return curLen;
    }

    void insert(int i, Object x) throws Exception {
        if (curLen == listElem.length)           //判断顺序表是否已满
            throw new Exception("顺序表已满");   //抛出异常
        if (i < 0 || i > curLen)
            throw new Exception("插入位置不合法");//i不合法
        for (int j = curLen; j > i; j--)
            listElem[j] = listElem[j - 1];        //插入位置及其之后的所有元素后移一位
        listElem[i] = x;                        //插入x
        curLen++;                               //表长加1
    }

    void remove(int i) throws Exception {
        if (i < 0 || i > curLen - 1)              //i不合法
            throw new Exception("删除位置不合法");//抛出异常
        for (int j = i; j < curLen - 1; j++)
            listElem[j] = listElem[j + 1];       //被删除元素及其之后的元素左移一个存储位置
        curLen--;                                   //表长减1
    }

    int indexOf(Object x) {
        int j = 0;                               //j指示顺序表中待比较的元素，其初始值指示顺序表中的第0个元素
        while (j < curLen && !listElem[j].equals(x))        //依次比较
            j++;
        if (j < curLen)      //判断j的位置是否位于顺序表中
            return j;       //返回值为x的元素在顺序表中的位置
        else
            return -1;      //值为x的元素在顺序表中不存丰
    }

    void display() {
        String contents = "";
        for (int i = 0; i < curLen; i++)
            contents += listElem[i] + " ";
        System.out.println(contents);
    }

    public Object[] getListElem() {
        return listElem;
    }

    public int getCurLen() {
        return curLen;
    }

    public void setListElem(Object[] listElem) {
        this.listElem = listElem;
    }

    public void setCurLen(int curLen) {
        this.curLen = curLen;
    }
}
