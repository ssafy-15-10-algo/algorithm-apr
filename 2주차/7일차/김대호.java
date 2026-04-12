import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            int N;
            try {
                N = Integer.parseInt(line.trim());
            } catch (NumberFormatException e) {
                break;
            }

            int[] prices = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                prices[i] = Integer.parseInt(st.nextToken());
            }

            int[] lis = new int[N];
            int len = 0;

            for (int i = 0; i < N; i++) {
                int key = prices[i];

                int low = 0;
                int high = len;

                while (low < high) {
                    int mid = (low + high) / 2;
                    if (lis[mid] < key) {
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                }

                lis[low] = key;
                
                if (low == len) {
                    len++;
                }
            }

            System.out.println(len);
        }
    }
}