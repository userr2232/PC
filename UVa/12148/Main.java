import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Main {
    public static String output = "";
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n;
        try {
            Solver solver = new Solver();
            while((n = Integer.parseInt(br.readLine().trim())) != 0) {
                int arr[][] = new int [n][4];
                for(int i = 0; i < n; ++i) {
                    String[] line = br.readLine().split(" ");
                    for(int j = 0; j < 4; ++j) {
                        arr[i][j] = Integer.parseInt(line[j]);
                    }
                }
                solver.solve(arr);
            }
        }
        catch (IOException e) {
            e.getStackTrace();
        }
        System.out.print(output);
	}
}

class Solver {
	public void solve(int[][] arr) {
        int count = 0;
        int spent = 0;
        for(int i = 0; i < arr.length - 1; ++i) {
            GregorianCalendar date = new GregorianCalendar(arr[i][2], arr[i][1] - 1, arr[i][0]);
            date.add(Calendar.DAY_OF_MONTH, 1);
            if(date.get(Calendar.DAY_OF_MONTH) == arr[i+1][0] && 
                date.get(Calendar.MONTH) + 1 == arr[i+1][1] && 
                    date.get(Calendar.YEAR) == arr[i+1][2]) {
                count++;
                spent += arr[i+1][3] - arr[i][3];
            }
        }
        Main.output = Main.output.concat(String.format("%d %d\n", count, spent));
	}
}