package task3;

public class SqStack {
    private Object[] stackElem; //对象数组
    private int top;    //当栈非空时，top始终指向栈顶元素的下一个存储位置;当栈为空时，top值为0;

    public SqStack() {
        top = 0;
    }

    public SqStack(int capacity) {
        stackElem = new Object[capacity];
        top = 0;
    }

    void push(Object e) throws Exception{   //将元素e压入栈顶
        if(top == stackElem.length)         //栈满
            throw new Exception("栈已满");   //输出异常
        else                                 //栈未满
            stackElem[top++] = e;           //e赋给栈顶元素后，top增1
    }

    Object pop(){
        if (top == 0)                       //移除栈顶对象并对象并作为此函数的值返回该对象
            return null;                    //栈为空
        else{                               //栈非空
            return stackElem[--top];        //修改栈顶指针，并返回栈顶元素
        }
    }

    Object getTopData() throws Exception {
        if (top == 0)
            return null;
        else {
            Object temp = pop();
            push(temp);
            return temp;
        }
    }

    void display(){
        for(int i = top-1; i >= 0; i--){
            System.out.print(stackElem[i]+" ");
        }
    }

    public void footToTop() {
        for (int i = 0; i < top; i++){
            System.out.print(stackElem[i]+" ");
        }
    }
    public Object[] getStackElem() {
        return stackElem;
    }

    public void setStackElem(Object[] stackElem) {
        this.stackElem = stackElem;
    }

    public int getTop() {
        return top;
    }

    public void setTop(int top) {
        this.top = top;
    }

    public boolean isEmpty() {
        return top == 0;
    }
}
