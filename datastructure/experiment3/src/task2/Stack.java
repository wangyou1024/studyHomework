package task2;

public class Stack {
    private StackElem[] st;     //栈存储空间
    private int top;            //栈顶指针，指向栈顶元素的位置
    //栈的构造函数，构造一个存储空间容量为maxSize的栈
    public Stack(int maxSize){
        top = -1;               //初始化top为-1
        st = new StackElem[maxSize];    //为栈分配maxSize个存储单元
    }

    //测试栈是否为空
    public boolean isEmpty(){
        return top == -1;
    }

    //读取栈顶元素
    public StackElem getTop() throws Exception{
        if(!isEmpty())          //栈非空
            return st[top];     //栈顶元素
        else
            //栈为空
        throw new Exception("当前栈为空");
    }

    //修改栈顶元素：将栈顶元素的值改为（m,n）
    public void setTop(int m,int n) throws Exception{
        if(!isEmpty()){
            st[top].mval = m;
            st[top].nval = n;
        }
        else
            //栈为空
        throw new Exception("当前栈为空");
    }

    //入栈
    public void push(StackElem o) throws Exception{
        if(top == st.length)
            throw new Exception("栈已满");
        else
            st[++top] = o;
    }

    //出栈
    public StackElem pop() throws Exception{
        if(top == -1)
            throw new Exception("当前栈为空");
        else{
            return st[top--];
        }
    }

    //求栈中的元素个数，并由函数返回其值
    public int length(){
        return top+1;
    }

}
