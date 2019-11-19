package task1;

public class Student {
    private String number;
    private String name;
    private float English;
    private float math;
    private float grade;

    public Student(String number, String name, float english, float math) {
        this.number = number;
        this.name = name;
        English = english;
        this.math = math;
        this.grade = this.English + this.math;
    }

    @Override
    public String toString() {
        return "Student{" +
                "number=" + number +
                ", name='" + name + '\'' +
                ", English=" + English +
                ", math=" + math +
                ", grade=" + grade +
                '}';
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public float getEnglish() {
        return English;
    }

    public void setEnglish(float english) {
        English = english;
    }

    public float getMath() {
        return math;
    }

    public void setMath(float math) {
        this.math = math;
    }

    public float getGrade() {
        return grade;
    }

    public void setGrade(float grade) {
        this.grade = grade;
    }
}

