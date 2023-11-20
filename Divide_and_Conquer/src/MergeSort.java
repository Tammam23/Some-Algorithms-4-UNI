
class MergeSort{
    private int []array;
    public MergeSort(int []array) {
        this.array = array;
    }
    public static int []sort(int[] array){
        MergeSort prob = new MergeSort(array);
        prob.split(0, array.length-1);
        return prob.array;
    }
    public void split(int l, int r){
        if(l<r) {
            int m = (l + r) / 2;
            split(l, m); split(m+1, r);
            merge(l, m, r);
        }
    }
    public void merge(int l, int m, int r) {
        int n1 = m-l+1, n2 = r-m;
        int[]L = new int[n1], R = new int[n2];
        for(int i = 0 ; i < n1; i++){
            L[i] = array[i+l];
        }
        for(int i = 0 ; i < n2; i++){
            R[i] = array[i+m+1];
        }

        int i = 0, j = 0, k = l;

        while(i < n1 && j < n2){
            if (L[i] < R[j]){
                array[k] = L[i];
                i++;
            }
            else{
                array[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < n1){
            array[k] = L[i];
            i++;
            k++;
        }
        while(j < n2){
            array[k] = R[j];
            j++;
            k++;
        }
    }
}

class MergeSortV2{
    private int []array;
    public MergeSortV2(int []array) {
        this.array = array;
    }
    public static int []sort(int[] array){
        MergeSortV2 prob = new MergeSortV2(array);
        prob.split(0, array.length-1);
        return prob.array;
    }
    public void split(int l, int r){
        if(l<r) {
            int m = (l + r) / 2;
            split(l, m); split(m+1, r);

            int n1 = m-l+1, n2 = r-m;
            int[]L = new int[n1], R = new int[n2];
            for(int i = 0 ; i < n1; i++){
                L[i] = array[i+l];
            }
            for(int i = 0 ; i < n2; i++){
                R[i] = array[i+m+1];
            }

            merge(l, m, r, L, R);
        }
    }
    public void merge(int l, int m, int r, int[]L, int[]R) {

        int i = 0, j = 0, k = l;

        while(i < L.length && j < R.length){
            if (L[i] < R[j]){
                array[k] = L[i];
                i++;
            }
            else{
                array[k] = R[j];
                j++;
            }
            k++;
        }
        while(true){
            if(i < L.length){
                array[k] = L[i];
                i++;
                k++;
                continue;
            }
            if(j < R.length){
                array[k] = R[j];
                j++;
                k++;
                continue;
            }
            break;
        }
    }
}