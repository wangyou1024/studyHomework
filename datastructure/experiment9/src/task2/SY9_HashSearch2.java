package task2;

import java.util.Scanner;

/**
 * @author 王游
 * @date 2019/11/16
 */

public class SY9_HashSearch2 {
    public static void main(String[] args) throws Exception{
        int[] numbers = {19,14,23,01,68,20,84,27,55,11,10};
        HashTable hashTable = new HashTable(13);
        for (int i = 0; i < numbers.length; i++){
            hashTable.insert(new Node(numbers[i]));
        }
        hashTable.display();
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入查找内容：");
        int search = sc.nextInt();
        Node node = hashTable.search(new Node(search));
        System.out.println(node.toString());
    }
}
