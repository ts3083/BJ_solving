import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        int n, score = 0, sum;
        Scanner sc = new Scanner(System.in);
        n = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < n; i++) {
            sum = 0;
            score = 0;
            String str = sc.nextLine();
            char[] arr = str.toCharArray();
            for (char elem : arr) {
                if (elem == 'O') {
                    score++;
                }
                else { // elem == 'X'
                    score = 0;
                }
                sum += score;
            }
            System.out.println(sum);
        }
    }
}
