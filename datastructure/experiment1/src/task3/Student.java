package task3;

public class Student {
    private String number;
    private String name;
    private char sex;
    private String tel;
    private String address;
    private float grade = -1;

    public Student(){
    }

    public Student(String number, String name, char sex, String tel, String address) {
        this.number = number;
        this.name = name;
        this.sex = sex;
        this.tel = tel;
        this.address = address;
    }

    public Student(String number, String name, char sex, String tel, String address, int grade) {
        this.number = number;
        this.name = name;
        this.sex = sex;
        this.tel = tel;
        this.address = address;
        this.grade = grade;
    }

    @Override
    public String toString() {
        return "Student{" +
                "number='" + number + '\'' +
                ", name='" + name + '\'' +
                ", sex=" + sex +
                ", tel='" + tel + '\'' +
                ", address='" + address + '\'' + (grade != -1? (",grade='" + grade + '\''):"")+
                '}';
    }

    public float getGrade() {
        return grade;
    }

    public void setGrade(float grade) {
        this.grade = grade;
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) throws Exception {
        if(number.matches("[\\d]{7}")){
            this.number = number;
        }
        else
            throw new Exception("学号格式错误！！！七位数字");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) throws Exception {
        if(name.matches("[A-Z][a-z]+"))
            this.name = name;
        else
            throw new Exception("格式错误，首字母大写");
    }

    public char getSex() {
        return sex;
    }

    public void setSex(char sex) throws Exception {
        if(sex == 'F' || sex == 'M')
            this.sex = sex;
        else
            throw new Exception("性别：F/M !!!");

    }

    public String getTel() {
        return tel;
    }

    public void setTel(String tel) throws Exception {
        if(tel.matches("[\\d]{11}") || tel.matches("[\\d]{4}-[\\d]{8}"))
            this.tel = tel;
        else
            throw new Exception("格式错误！11位数字或（4位数字-8位数字）");
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) throws Exception {
        if(address.matches("[\\u4e00-\\u9fa5]+"))
        this.address = address;
        else{
            throw new Exception("中文！");
        }
    }
}
