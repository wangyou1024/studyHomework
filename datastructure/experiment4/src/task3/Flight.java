package task3;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Flight {
    private String destination;
    private int flightNumber;
    private int flyNumber;
    private int week;//星期一为1-7
    private int capacity;//容量
    public int remainNumber;//客余数
    public FormalPersons formalPersons;
    public WaitPersons waitPersons;

    public Flight(String destination, int flightNumber, int flyNumber, int week, int capacity, int remainNumber, FormalPersons formalPersons, WaitPersons waitPersons) {
        this.destination = destination;
        this.flightNumber = flightNumber;
        this.flyNumber = flyNumber;
        this.week = week;
        this.capacity = capacity;
        this.remainNumber = remainNumber;
        this.formalPersons = formalPersons;
        this.waitPersons = waitPersons;
    }

    @Override
    public String toString() {
        return "{" +
                "终点='" + destination + '\'' +
                ", 航班号=" + flightNumber +
                ", 飞机号=" + flyNumber +
                ", 星期=" + week +
                ", 日期=" + getData(week) +
                ", 余票客=" + remainNumber +
                '}';
    }

    public String getData(int week){
        Calendar calendar = new GregorianCalendar();
        int curWeek = calendar.get(Calendar.DAY_OF_WEEK)-1;
        if(curWeek == 0){
            curWeek = 7;
        }
        int time = week-curWeek;
        if(time < 0){
            time += 7;
        }
        calendar.add(Calendar.DAY_OF_MONTH,time);
        return calendar.get(Calendar.YEAR) + "年" + (calendar.get(Calendar.MONTH)+1) + "月" + calendar.get(Calendar.DAY_OF_MONTH);

    }
    public String getDestination() {
        return destination;
    }

    public void setDestination(String destination) {
        this.destination = destination;
    }

    public int getFlightNumber() {
        return flightNumber;
    }

    public void setFlightNumber(int flightNumber) {
        this.flightNumber = flightNumber;
    }

    public int getFlyNumber() {
        return flyNumber;
    }

    public void setFlyNumber(int flyNumber) {
        this.flyNumber = flyNumber;
    }

    public int getWeek() {
        return week;
    }

    public void setWeek(int week) {
        this.week = week;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getRemainNumber() {
        return remainNumber;
    }

    public void setRemainNumber(int remainNumber) {
        this.remainNumber = remainNumber;
    }

    public FormalPersons getFormalPersons() {
        return formalPersons;
    }

    public void setFormalPersons(FormalPersons formalPersons) {
        this.formalPersons = formalPersons;
    }

    public WaitPersons getWaitPersons() {
        return waitPersons;
    }

    public void setWaitPersons(WaitPersons waitPersons) {
        this.waitPersons = waitPersons;
    }
}
