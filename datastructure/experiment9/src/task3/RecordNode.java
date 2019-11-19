package task3;

/**
 * @author 王游
 * @date 2019/11/17
 */

public class RecordNode {
    private Comparable key = " ";         //关键字
    private Object element;         //数据元素

    public RecordNode(Comparable key) {
        this.key = key;
    }

    public RecordNode(Comparable key, Object element) {
        this.key = key;
        this.element = element;
    }

    public Comparable getKey() {
        return key;
    }

    public void setKey(Comparable key) {
        this.key = key;
    }

    public Object getElement() {
        return element;
    }

    public void setElement(Object element) {
        this.element = element;
    }

    @Override
    public String toString() {
        return this.element.toString();
    }
}
