
public class Main {
    public static void main(String[] args) {
        int []a = {5, 111, 4, 17, 5, 4, 51, 0, 0, 0};
        System.out.println("Quick sort:");
        for(int i :QuickSort.sort(a)){
            System.out.println(i);
        }
        System.out.println("\nMerge sort:");
        for(int i :MergeSort.sort(a)){
            System.out.println(i);
        }
        System.out.println("\nAnother version of merge sort:");
        for(int i :MergeSortV2.sort(a)){
            System.out.println(i);
        }
        System.out.println("\nAnd finally:");
        ArrayFrequencyFinder.run(a);

    }

}

//Extra
class RussianMultiplication{
    public static int mul(int a, int b){
        if (a==0){return 0;}
//                            shift left    right    by one
        if (a%2 == 0){return mul(a>>1, b<<1);}

        else{return b+mul(a>>1, b<<1);}
    }
}