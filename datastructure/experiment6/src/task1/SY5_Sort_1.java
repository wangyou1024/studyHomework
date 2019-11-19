package task1;

public class SY5_Sort_1 extends SeqList {
    static int maxSize = 20;
    public SY5_Sort_1(int maxSize){
        super(maxSize);
    }
    private static SeqList createList(int[] d) throws Exception{
        SeqList SL = new SY5_Sort_1(maxSize+1);
        //建立顺序表，若使用带监视哨的算法，需要多一个单元、
        for (int i = 0; i < d.length; i++){
            RecordNode r = new RecordNode(d[i]);
            SL.insert(SL.length(),r);
        }
        SL.insert(0,new RecordNode(0)); //在0号单元插入一个元素
        return SL;
    }

    public void display(){
        for (int i = 1; i < this.getCurlen()-1; i++){
            System.out.print(" " + getRecord()[i].getKey().toString());
        }
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        int[] d = new int[maxSize];
        for (int i = 0; i < maxSize; i++) {
            d[i] = (int) (Math.random() * 100);
        }
        SeqList L = createList(d);
        System.out.println("排序前：");
        L.display();
        L.insertSortWithGuard();
        System.out.println("排序后：");
        L.display();
    }
}
