package task1;

public class KeyType implements Comparable<KeyType> {
    private int key;

    public KeyType(int key) {
        this.key = key;
    }

    public int getKey() {
        return key;
    }

    public void setKey(int key) {
        this.key = key;
    }

    @Override
    public int compareTo(KeyType o) {
        if (this.key > o.getKey())
            return 1;
        else if (this.key < o.getKey())
            return -1;
        return 0;
    }
}
