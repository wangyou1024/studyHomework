package task2;

public class StackElem {
    public int mval;    //保存m的变化值
    public int nval;    //保存n的变化值

    public StackElem(int m, int n){
        this.mval = m;
        this.nval = n;
    }

    public int getMval() {
        return mval;
    }

    public void setMval(int mval) {
        this.mval = mval;
    }

    public int getNval() {
        return nval;
    }

    public void setNval(int nval) {
        this.nval = nval;
    }
}
