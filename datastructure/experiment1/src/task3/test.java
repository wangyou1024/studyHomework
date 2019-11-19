package task3;

import java.util.Scanner;

public class test {
    public static void main(String[] args) throws Exception {
        Student[] students = new Student[6];
        students[0] = new Student("2008001", "Alan", 'F', "13305731238", "浙江省嘉兴市");
        students[1] = new Student("2008002", "Danie", 'M', "0573-82283288", "浙江省嘉兴市");
        students[2] = new Student("2008003", "Helen", 'M', "13507942222", "江西省抚州市");
        students[3] = new Student("2008004", "Bill", 'F', "0571-72529911", "浙江省杭州市");
        students[4] = new Student("2008005", "Peter", 'M', "13857354444", "浙江省嘉兴市");
        students[5] = new Student("2008006", "Amy", 'F', "1395637777", "浙江省蚌埠市");
        StudentManage studentManage = new StudentManage(students);
        studentManage.display();
        find(studentManage);
        edit(studentManage);
        insert(studentManage);
        remove(studentManage);


    }

    public static void find(StudentManage studentManage) throws Exception {
        System.out.print("请输入查寻学生的学号或姓名：");
        Scanner sc = new Scanner(System.in);
        String find = "";
        while (true) {
            find = sc.next();
            if (find.matches("[\\d]{7}") || find.matches("[A-Z][a-z]+")) {
                break;
            } else
                System.out.println("请输入正确的格式！！！请重新输入");
        }
        Student[] students1 = studentManage.get(find);
        if (students1.length == 0) {
            System.out.println("无");
        } else {
            for (int i = 0; i < students1.length; i++) {
                System.out.println(students1[i].toString());
            }
        }
    }

    public static void edit(StudentManage studentManage) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入修改学生的学号");
        String number = "";
        while (true) {
            number = sc.next();
            if (number.matches("[\\d]{7}")) {
                break;
            } else
                System.out.println("格式错误，请重新输入：");
        }
        System.out.println("请输入分数：");
        float grade = sc.nextFloat();
        studentManage.editor(number, grade);
        System.out.println("修改后：");
        studentManage.display();
    }

    public static void insert(StudentManage studentManage) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入插入学生的学号（八位数字）：");
        Student student = new Student();
        while (true) {
            String number = sc.next();
            if (number.matches("[\\d]{7}")) {
                if (studentManage.get(number).length != 0) {
                    System.out.println("这个学号已经存在；请重新输入：");
                } else {
                    student.setNumber(number);
                    break;
                }
            } else
                System.out.println("格式错误;请重新输入：");
        }
        System.out.println("请输入姓名（首字母大写）：");
        while (true) {
            String name = sc.next();
            if (name.matches("[A-Z][a-z]+")) {
                student.setName(name);
                break;
            } else {
                System.out.println("格式错误，请重新输入：");
            }
        }
        System.out.println("请输入性别：（F/M）");
        while (true) {
            char sex = sc.next().charAt(0);
            if (sex == 'F' || sex == 'M') {
                student.setSex(sex);
                break;
            } else {
                System.out.println("请重新输入：");
            }
        }
        System.out.println("请输入电话号码（参考已有类型）：");
        while (true) {
            String tel = sc.next();
            if (tel.matches("[\\d]{11}") || tel.matches("[\\d]{4}-[\\d]{8}")) {
                student.setTel(tel);
                break;
            } else {
                System.out.println("格式错误，请重新输入");
            }
        }
        System.out.println("请输入地址（中文）：");
        while (true) {
            String address = sc.next();
            if (address.matches("[\u4e00-\u9fa5]+")) {
                student.setAddress(address);
                break;
            } else {
                System.out.println("请输入中文：");
            }
        }
        studentManage.insert(student);
        System.out.println("加入新学生后：");
        studentManage.display();
    }

    public static void remove(StudentManage studentManage) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.println("请删除输入学号");
        String number = "";
        while (true) {
            number = sc.next();
            if (number.matches("[\\d]{7}")) {
                break;
            } else
                System.out.println("格式错误，请重新输入：");
        }
        studentManage.remove(number);
        System.out.println("删除后：");
        studentManage.display();
    }
}

