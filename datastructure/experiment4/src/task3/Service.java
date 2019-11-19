package task3;

import java.util.Random;
import java.util.Scanner;

public class Service {
    private Flight[] flights;

    public Service(Flight[] flights) {
        this.flights = flights;
    }

    public void find(){
        System.out.println("进入查询系统");
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入查询终点站：");
        String destination = sc.next();
        for(int i = 0; i < flights.length; i++){
            if(flights[i].getDestination().equals(destination)){
                System.out.println("该航班信息如下:");
                System.out.println(flights[i].toString());
                return;
            }
        }
        System.out.println("无相应航班，退出查询");
    }

    public void order() throws Exception {
        System.out.println("进入订票系统");
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入航班号：");
        int flightNumber = sc.nextInt();
        int index = -1;
        for(index = 0; index < flights.length; index++){
            if(flightNumber == flights[index].getFlightNumber()){
                break;
            }
        }
        if (index == -1){
            System.out.println("无航班号");
            return;
        }
        System.out.print("请输入订票数额：");
        int tickets = sc.nextInt();
        if(tickets < flights[index].getRemainNumber()){
            System.out.print("请输入姓名：");
            String name = sc.next();
            System.out.print("请输入舱位等级：");
            int grade = sc.nextInt();
            FormalPerson formalPerson = new FormalPerson(name,tickets,grade);
            flights[index].formalPersons.insert(0,formalPerson);
            flights[index].remainNumber -= tickets;
            System.out.println("加入成功");
            System.out.print("座位号: ");
            for(int i = 0; i < tickets; i++){
                System.out.print(new Random().nextInt(50)+1 + " ");
            }
            System.out.println();
        }
        else{
            System.out.print("客余量少于订票数，是否进入等候队列（1为是，2为否）：");
            int enterWait = sc.nextInt();
            if(enterWait == 1){
                System.out.print("请输入姓名：");
                String name = sc.next();
                flights[index].waitPersons.offer(new WaitPerson(name,tickets));
                System.out.println("进入等候队列");
            }
            else{
                System.out.println("退出订票系统");
            }
        }
    }

    public void back() throws Exception {
        System.out.println("进入退票系统");
        System.out.println("请输入星期数(1-7)：");
        Scanner sc = new Scanner(System.in);
        int week = sc.nextInt();
        if(week > 7 || week < 1){
            System.out.println("输入错误，退出系统");
        }
        System.out.println("请输入航班号：");
        int flightNumber = sc.nextInt();
        int index = -1;
        for (index = 0; index < flights.length; index++){
            if(flights[index].getFlightNumber() == flightNumber && flights[index].getWeek() == week){
                break;
            }
        }
        if(index == -1){
            System.out.println("无航班号");
            return;
        }
        System.out.print("请输入姓名：");
        String deleteName = sc.next();
        int deleteNumber = flights[index].formalPersons.find(deleteName);
        if(deleteNumber == -1){
            System.out.println("查无此人;退出系统");
            return;
        }
        FormalPerson deleteFormalPerson = flights[index].formalPersons.get(deleteNumber);
        flights[index].remainNumber += deleteFormalPerson.getTickets();
        flights[index].formalPersons.remove(deleteNumber);
        WaitPerson p = flights[index].waitPersons.poll();
        while (p != null){
            System.out.println(p.getName()+"你需要的航班现在"+flights[index].getRemainNumber() + "张票，您是否需要重新办理业务（1为是，2为否）：");
            int becameFormal = sc.nextInt();
            if(becameFormal == 1){
                System.out.print("请输入订票量：");
                int tickets = sc.nextInt();
                if(tickets > flights[index].getCapacity()){
                    System.out.print("客余量少于订票数，是否重新进入等候队列（1为是，2为否）：");
                    int enterWait = sc.nextInt();
                    if(enterWait == 1){
                        System.out.print("请输入姓名：");
                        String name = sc.next();
                        flights[index].waitPersons.offer(new WaitPerson(name,tickets));
                        System.out.println("进入等候队列");
                    }
                    else{
                        System.out.println("退出订票系统");
                    }
                }
                System.out.print("请输入舱位等级：");
                int grade = sc.nextInt();
                FormalPerson formalPerson = new FormalPerson(p.getName(),tickets,grade);
                flights[index].formalPersons.insert(0,formalPerson);
                flights[index].remainNumber -= tickets;
                System.out.println("加入成功");
                System.out.print("座位号: ");
                for(int i = 0; i < tickets; i++){
                    System.out.print(new Random().nextInt(50)+1 + " ");
                }
                System.out.println();
            }
            else{
                System.out.println(p.getName() + "不办理业务");
            }
            p = flights[index].waitPersons.poll();
        }

    }


    public Flight[] getFlights() {
        return flights;
    }

    public void setFlights(Flight[] flights) {
        this.flights = flights;
    }
}
