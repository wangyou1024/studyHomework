package task3;

import java.util.Objects;

/**
 * @author 王游
 * @date 2019/11/17
 */
public class Place {
    private String name;
    private String information;

    public Place(String name) {
        this.name = name;
    }

    public Place(String name, String information) {
        this.name = name;
        this.information = information;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getInformation() {
        return information;
    }

    public void setInformation(String information) {
        this.information = information;
    }

    @Override
    public String toString() {
        return "Place{" +
                "name='" + name + '\'' +
                ", information='" + information + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Place)) return false;
        Place place = (Place) o;
        return Objects.equals(name, place.name);
    }

}
