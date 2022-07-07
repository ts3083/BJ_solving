import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) throws IOException {
        int n;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }

        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (o1.length() > o2.length())
                    return 1;
                else if (o1.length() == o2.length())
                    return o1.compareTo(o2);
                return -1;
            }
        });

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(arr[0] + "\n");
        for (int i = 1; i < n; i++) {
            if (arr[i - 1].compareTo(arr[i]) == 0) {
                continue;
            }
            bw.write(arr[i] + "\n");
        }
        bw.flush();
        bw.close();
    }
}
