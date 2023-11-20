import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


class ArrayFrequencyFinder{
    private int []input_array;
    private Map<Integer, Integer> frequencies;
    public ArrayFrequencyFinder(int []input_array){
        this.input_array = input_array;
        frequencies = new HashMap<>();

    }
    public static void run(int[] input) {
        ArrayFrequencyFinder problem = new ArrayFrequencyFinder(input);
        problem.solve();

    }

    public void solve(){
        F(0, input_array.length-1);
        print_frequencies();
    }
    private void F(int l, int r){
        if (l != r) {
            int m = (l + r) / 2;
            F(l, m);
            F(m+1, r);
            return;
        }
        if(frequencies.containsKey(input_array[l])){
            frequencies.put(input_array[l], frequencies.get(input_array[l])+1);

        }
        else {
            frequencies.put(input_array[l], 1);
        }
    }

    public void print_frequencies(){
        for (Map.Entry<Integer, Integer> entry : frequencies.entrySet()) {
            System.out.println("Value: " + entry.getKey() + ", Frequency: " + entry.getValue());
        }
    }
}