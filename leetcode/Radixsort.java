import java.util.Arrays;

public class Radixsort {

    public static void main(String[] args) {
        int[] arr1 = new int[] { 24, 12, 5, 23, 1, 43, 3, 21, 344, 123, 455, 312 };
        Radixsort radixsort = new Radixsort();
        radixsort.radixsort(arr1);

        System.out.println(Arrays.toString(arr1));
    }

    public void radixsort(int[] arr) {
        int max = arr[0];
        for (int n : arr) {
            max = Math.max(max, n);
        }
        for (int exp = 1; max / exp > 0; exp *= 10) {
            int n = arr.length;
            int[] output = new int[n];
            int[] bucket = new int[10];
            for (int i = 0; i < n; i++) {
                bucket[(arr[i] / exp) % 10]++;
            }
            for (int i = 1; i < 10; i++) {
                bucket[i] += bucket[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                output[bucket[(arr[i] / exp) % 10] - 1] = arr[i];
                bucket[(arr[i] / exp) % 10]--;
            }
            System.arraycopy(output, 0, arr, 0, n);
        }
    }

}