import java.util.Arrays;
public class CodeForQuickSort{
        public static void quickSort(Integer arr[], int small, int big)
        {
            if (arr == null || arr.length == 0){
                return;
            }
            if (small >= big){
                return;
            }
            int middle = small + (big - small) / 2;
            int pivot = arr[middle];
            int i = small, j = big;
            while (i <= j)
            {
                while (arr[i] < pivot)
                {
                    i++;
                }
                while (arr[j] > pivot)
                {
                    j--;
                }
                if (i <= j)
                {
                    swap (arr, i, j);
                    i++;
                    j--;
                }
            }
            if (small < j){
                quickSort(arr, small, j);
            }
            if (big > i){
                quickSort(arr, i, big);
            }
        }
        public static void swap (Integer arr1[], int x, int y)
        {
            int temp = arr1[x];
            arr1[x] = arr1[y];
            arr1[y] = temp;
        }
        public static void main(String[] args)
        {
            Integer arr1[] = new Integer[] {56,12,90,23,76,3,2,43,1};
            quickSort( arr1, 0, arr1.length - 1 );
            System.out.println(Arrays.toString(arr1));
        }
    }
