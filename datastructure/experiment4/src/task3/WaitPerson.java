package task3;

public class WaitPerson {
    private String name;
    private int tickets;
    private WaitPerson next;

    public WaitPerson(String name, int tickets) {
        this.name = name;
        this.tickets = tickets;
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

    public WaitPerson getNext() {
        return next;
    }

    public void setNext(WaitPerson next) {
        this.next = next;
    }
}
