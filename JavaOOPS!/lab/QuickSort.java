import java.util.Arrays;
import java.util.Scanner;
public class QuickSort{
    public static void QuickSort(int[] nums,int low,int high){
        if (low > high){
            return;
        }
        int mid  = low + (high - low)/2;
        int pivot = nums[mid];
        int s = low;
        int e = high;
        while (s <= e){
            while (nums[s] < pivot){
                s++;
            }
            while (nums[e] > pivot){
                e--;
            }
            if (s <= e){
                int temp = nums[s];
                nums[s] = nums[e];
                nums[e] = temp;
                s++;
                e--;
            }
        }
        QuickSort(nums,low,e);
        QuickSort(nums,s,high);
    }


    public static void main(String[] args) {
        System.out.println("Enter the size of array");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n] ;
        System.out.println("Enter the elements of array");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }   
        QuickSort(arr,0,n-1);
        System.out.println(Arrays.toString(arr));
    }

}
