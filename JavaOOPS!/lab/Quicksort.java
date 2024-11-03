import java.util.Scanner;
public class Quicksort {
    private static int partition(String[] array, int low, int high) {
        String pivot = array[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (array[j].compareTo(pivot) < 0) {
                i++;
                String temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        String temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        return i + 1;
    }
    private static void quicksort(String[] array, int low, int high) {
        if (low < high) {
            int pi = partition(array, low, high);
            quicksort(array, low, pi - 1);
            quicksort(array, pi + 1, high);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of names: ");
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] names = new String[n];
        System.out.println("Enter the names:");
        for (int i = 0; i < n; i++) names[i] = scanner.nextLine();
        quicksort(names, 0, n - 1);
        System.out.println("Sorted names:");
        for (String name : names) System.out.print(" "+name);
        scanner.close();
    }
}