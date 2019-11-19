package task2;

public class test {

    //求k阶斐波那契序列的前n+1项
    private static void GetFib_CyQueue(int k,int n){
        int i,m,sum;
        CircleSqQueue Q = new CircleSqQueue(k);     //创建一个容量为K的空队列
        for(i = 0; i < k-1; i++)
            Q.offer(0);
        Q.offer(1);                             //给前k项入队
        System.out.println(k+"阶斐波那契序列的前"+n+"+1项值为：");
        for(i = 0; i < k; i++){
            System.out.print(Q.getElem(i) + " ");
        }
        for (i = k; i <= n; i++){                   //求得并输出第k+1项到n+1项值
            m = i % k;                              //第i项在循环顺序队列中的位置
            sum = 0;
            for(int j = 0; j < k; j++)              //求第i项的值
                sum = sum + Q.getElem((m+j)%k);
            Q.offer(sum);                           //将第i项的值存入队列中并取代已无用的第1项
            System.out.print(sum + " ");
        }
    }

    public static void main(String[] args) {
        GetFib_CyQueue(2,5);
    }
}
