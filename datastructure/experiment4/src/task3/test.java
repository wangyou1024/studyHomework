package task3;

import jdk.nashorn.internal.ir.WhileNode;

import java.util.Scanner;

public class test {
    public static void main(String[] args) throws Exception {
        FormalPersons formalPersons1 = new FormalPersons();
        formalPersons1.insert(0,new FormalPerson("李杰",4,2));
        WaitPersons waitPersons1 = new WaitPersons();
        waitPersons1.offer(new WaitPerson("张强",47));
        FormalPersons formalPersons2 = new FormalPersons();
        formalPersons2.insert(0,new FormalPerson("赵俊杰",4,2));
        WaitPersons waitPersons2 = new WaitPersons();
        waitPersons2.offer(new WaitPerson("李立",47));
        Flight[] flights = new Flight[2];
        flights[0] = new Flight("重庆",1,1,1,50,46,formalPersons1,waitPersons1);
        flights[1] = new Flight("上海",2,2,2,50,46,formalPersons1,waitPersons1);
        Service service = new Service(flights);
        Scanner sc = new Scanner(System.in);
        while (true){
            System.out.println("1进入查询系统，2进入订票系统，3进入退票系统，0退出");
            int enter = sc.nextInt();
            if(enter == 1){
                service.find();
            }
            else if (enter == 2){
                service.order();
            }
            else if (enter == 3){
                service.back();
            }
            else
                break;

        }
    }
}
