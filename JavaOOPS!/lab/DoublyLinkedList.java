
import java.util.LinkedList;
import java.util.Scanner;
class DLinkedlist<T> {
    private LinkedList<T> list = new LinkedList<>();
    public void insertLast(T element) {
        list.addLast(element);
    }
    public void insertFront(T element) {
        list.addFirst(element);
    }
    public void insertAtAnyPosition(int index, T element) {
        if (index < 0 || index > list.size()) {
            System.out.println("Error: Invalid position.");
        } else {
            list.add(index, element);
        }
    }
    public void removeAtAnyPosition(int index) {
        if (index < 0 || index >= list.size()) {
            System.out.println("Error: Invalid position.");
        } else {
            list.remove(index);
        }
    }
    public void display() {
        for (T element : list) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
}
public class DoublyLinkedList {
    public static void main(String[] args) {
        DLinkedlist<Integer> doublyLinkedlist = new DLinkedlist<>();
        Scanner sc = new Scanner(System.in);
        int choice;
        System.out.println("1. Insert at Front\n2. Insert at Last\n3. Insert at Any Position\n4. Delete from Any Position\n5. Display\n6. Exit\n");
        do {
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            int num, position;
            switch(choice) {
                case 1:
                    System.out.print("Enter number: ");
                    num = sc.nextInt();
                    doublyLinkedlist.insertFront(num);
                    break;
                case 2:
                    System.out.print("Enter number: ");
                    num = sc.nextInt();
                    doublyLinkedlist.insertLast(num);
                    break;
                case 3:
                    System.out.print("Enter number: ");
                    num = sc.nextInt();
                    System.out.print("Enter position: ");
                    position = sc.nextInt();
                    doublyLinkedlist.insertAtAnyPosition(position, num);
                    break;
                case 4:
                    try {
                        System.out.print("Enter position: ");
                        position = sc.nextInt();
                        doublyLinkedlist.removeAtAnyPosition(position - 1);
                    } catch (IndexOutOfBoundsException e) {
                        System.out.println("Error: Invalid position.");
                    }
                    break;
                case 5:
                    System.out.println("The Doubly linked list is:");
                    doublyLinkedlist.display();
                    break;
                case 6:
                    System.out.println("EXITED!");
                    break;
                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        } while (choice != 6);
        sc.close();
    }
}