package task3;

public class FormalPerson {
    private String name;
    private int tickets;
    private int grade;
    private FormalPerson next;

    public FormalPerson(String name, int tickets, int grade) {
        this.name = name;
        this.tickets = tickets;
        this.grade = grade;
    }

    @Override
    public String toString() {
        return "FormalPerson{" +
                "name='" + name + '\'' +
                ", tickets=" + tickets +
                ", grade=" + grade +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getTickets() {
        return tickets;
    }

    public void setTickets(int tickets) {
        this.tickets = tickets;
    }

    public int getGrade() {
        return grade;
    }

    public void setGrade(int grade) {
        this.grade = grade;
    }

    public FormalPerson getNext() {
        return next;
    }

    public void setNext(FormalPerson next) {
        this.next = next;
    }
}
