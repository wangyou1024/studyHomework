package task2;


public class SY5_Sort_2 extends SeqList {
    static int maxSize = 5;
    public SY5_Sort_2(int maxSize){
        super(maxSize);
    }

    private static SeqList createList(int[] d) throws Exception{
        SeqList L = new SY5_Sort_2(maxSize);
        for (int i = 0; i < d.length; i++){
            RecordNode r = new RecordNode(d[i]);
            L.insert(L.length(), r);
        }
        return L;
    }

    //参数L表示顺序表，sortmethod为排序方法
    public static long testSortTime(SeqList L, int sortmethod) {
        long startTime,endTime,testTime;
        startTime = System.currentTimeMillis();
        switch (sortmethod) {
            case 0:
                L.bubbleSort();     //冒泡排序
                break;
            case 1:
                L.quickSort(0, maxSize-1);      //快速排序
                break;
        }
        endTime = System.currentTimeMillis();
        testTime = endTime - startTime;
        return testTime;
    }
    public void display(){
        for (int i = 0; i < this.getCurlen(); i++){
            System.out.print(" " + getRecord()[i].getKey().toString());
        }
        System.out.println();
    }

    public static void main(String[] args) throws Exception{
        int[] d = new int[maxSize];
        for (int i = 0; i < maxSize; i++) {
            d[i] = (int) (Math.random() * maxSize);
        }
        SeqList L = createList(d);
        System.out.println("排序前：");
        L.display();
        System.out.println("冒泡排序后：");
        L.bubbleSort();
        L.display();
        System.out.println("比较次数：" + L.getCm()[0].getCpn() + " 移动次数：" + L.getCm()[0].getMvn() + " 时间：" + testSortTime(L,0));
        d = new int[maxSize];
        for (int i = 0; i < maxSize; i++) {
            d[i] = (int) (Math.random() * maxSize);
        }
        L = createList(d);
        System.out.println("排序前：");
        L.display();
        System.out.println("快速排序后：");
        L.quickSort(0,maxSize-1);
        L.display();
        System.out.println("比较次数：" + L.getCm()[1].getCpn() + " 移动次数：" + L.getCm()[1].getMvn() + " 时间：" + testSortTime(L,0));
    }
}
