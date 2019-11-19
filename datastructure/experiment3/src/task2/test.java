package task2;

public class test {

    //计算Ack(m,n)的非递归算法
    public static int ack(int m,int n) throws Exception{
        StackElem e;
        Stack s = new Stack(1000); // 创建一个容量为1000的顺序对象
        e = new StackElem(m, n);            //创建一个由（m,n）组成的栈元素对象
        s.push(e);
        do{
            while (s.getTop().getMval() != 0){
                while (s.getTop().getNval() != 0){
                    e =new StackElem(s.getTop().getMval(),s.getTop().nval - 1);
                    s.push(e);
                }
                s.setTop(s.getTop().getMval() -1,1);
            }

            if(!s.isEmpty()){
                e = s.pop();
                s.setTop(s.getTop().getMval()-1,e.getNval()+1);
            }

        }while (s.length()!= 1 || s.getTop().getMval() != 0);
        return s.getTop().getNval()+1;
    }
    public static void main(String[] args) throws Exception {
        System.out.println("The answer of Ack(2,1) is "+ ack(2,1));
    }
}
