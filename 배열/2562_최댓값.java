import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        List<Integer> arr = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int n;
        for (int i = 0; i < 9; i++) {
            n = Integer.parseInt(sc.nextLine());
            arr.add(n);
        }

        int index = 0, max = -1;
        for (int i = 0; i < 9; i++) {
            if (arr.get(i) > max) {
                max = arr.get(i);
                index = i;
            }
        }

        System.out.println(max);
        System.out.println(index + 1);
    }
}
