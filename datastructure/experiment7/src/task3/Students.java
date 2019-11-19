package task3;

import java.util.Scanner;

public class Students {
    public static void main(String[] args){
        Student[] students = new Student[5];
        students[0] = new Student("1001","王小红",88,98);
        students[1] = new Student("1002","李小平",78,67);
        students[2] = new Student("1003","赵一飞",87,86);
        students[3] = new Student("1004","张春江",67,56);
        students[4] = new Student("1005","吴占豪",88,78);

        SeqList L = new SeqList(students.length);
        for (int i = 0; i < students.length; i++){
            L.insert(i,new RecordNode(students[i].getGrade(),students[i]));
        }

        Scanner sc = new Scanner(System.in);
        System.out.print("请输入学号：");
        Student student = L.binarySearch(sc.next());
        if (student != null){
            System.out.println(student.toString());
        }
        else{
            System.out.println("查找失败");
        }
    }
}
