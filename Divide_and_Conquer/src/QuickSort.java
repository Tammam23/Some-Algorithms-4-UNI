class QuickSort{
    int []array;
    public QuickSort(int []array){
        this.array = array;
    }
    public static int []sort(int[] array){
        QuickSort prob = new QuickSort(array);
        prob.quick_sort(0, array.length-1);
        return prob.array;
    }
    private void quick_sort(int low, int high){
        if (low < high){
            int pivot = partition(low, high);
            quick_sort(low, pivot-1);
            quick_sort(pivot+1, high);
        }
    }
    private int partition(int low, int high){
        int pivot = array[high];
        int j = low-1;
        int temp;
        for(int i = low ; i < high ; i ++){
            if(array[i] < pivot){
                j++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[j+1];
        array[j+1] = pivot;
        array[high] = temp;
        return j+1;
    }

}