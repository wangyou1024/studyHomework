package task3;

public class StudentManage {
    private Student[] listElem; //线性表存储空间
    private int curLen; //线性表的当前长度
    private int capacity; //线性表容量

    public StudentManage() {
        this.curLen = 0;
        this.capacity = 0;
        listElem = new Student[1];
    }

    public StudentManage(int capacity) {
        this.capacity = capacity;
        this.listElem = new Student[capacity];
        this.curLen = 0;
    }

    public StudentManage(Student[] listElem) {
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

    public Student[] get(String content) throws Exception {
        int i = 0;
        StudentManage temp = new StudentManage();
        if(content.matches("[\\d]{7}") == true) {
            for (i = 0; i < listElem.length; i++) {
                if (listElem[i].getNumber().equals(content)) { //学号是唯一标识
                    temp.insert(listElem[i]);
                    break;
                }
            }
        }
        else{
            for (i = 0; i < listElem.length; i++){      //可能重名导致返回多个信息
                if(listElem[i].getName().equals(content)) {
                    temp.insert(listElem[i]);
                }
            }
        }
        Student[] students = new Student[temp.curLen];
        System.arraycopy(temp.listElem,0,students,0,temp.curLen);
        return students;
    }

    public int length() {
        return curLen;
    }

    public Student editor(String number,float grade){
        int i = 0;
        for(i = 0; i < listElem.length; i++){
            if(listElem[i].getNumber().equals(number)){
                listElem[i].setGrade(grade);
                break;
            }
        }
        return listElem[i];
    }

     public void insert(Student x) throws Exception {
        if (curLen == listElem.length) {     //判断顺序表是否已满
            Student[] temp = new Student[listElem.length * 2];
            System.arraycopy(listElem,0,temp,0,listElem.length);
            listElem=temp;
        }
        listElem[curLen] = x;
        curLen++;                               //表长加1
    }

    public String remove(String num) throws Exception {
        int i = 0;
        for(i = 0; i < listElem.length; i++){
            if (listElem[i].getNumber().equals(num)){
                remove(i);
                break;
            }
        }
        if(i == listElem.length){
            return "没有该学生";
        }
        else
            return "删除成功";
    }

    public void remove(int i) throws Exception {
        if (i < 0 || i > curLen - 1)              //i不合法
            throw new Exception("删除位置不合法");//抛出异常
        for (int j = i; j < curLen - 1; j++)
            listElem[j] = listElem[j + 1];       //被删除元素及其之后的元素左移一个存储位置
        curLen--;                                   //表长减1
    }

    public void display() {
        String contents = "";
        for (int i = 0; i < curLen; i++)
            contents += listElem[i].toString() + "\n";
        System.out.println(contents);
    }

    public Student[] getListElem() {
        return listElem;
    }

    public int getCurLen() {
        return curLen;
    }

    public void setListElem(Student[] listElem) {
        this.listElem = listElem;
    }

    public void setCurLen(int curLen) {
        this.curLen = curLen;
    }
}
