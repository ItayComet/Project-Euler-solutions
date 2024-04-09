import java.util.*;
public class Problem24
{
    public static void main(String[] args){
        String[] arr = {"0","1","2","3","4","5","6","7","8","9"};
        System.out.print(nthLexiPerm(arr, 1000000));
    }
    //returns the permNum-th lexicographic permutation of the elements in arr
    public static String nthLexiPerm(String[] arr, long permNum){
        ArrayList<String> list = arrayToArrayList(arr);
        Collections.sort(list);
        permNum -= 1;//Since I start counting at 0;
        long currMinPermNum = 0;
        String perm = "";
        /**
         * for every item in the list there are (arr.length-1)! permutations
         * with it as the first one. going by lexicographic order, obviously
         * the first item in the permutation would be item number i, where:
         * i*(arr.length-1)! <= n < (i+1)*(arr.length-1)!
         * The same will be true for the next numbers, and with each iteration
         * the array will be smaller.
         */
        while(!list.isEmpty()){
            int size = list.size();
            long currFactorial = factorial(size-1);
            for(int i = 1; i <= size; i++){
                if(i*currFactorial + currMinPermNum > permNum){
                    currMinPermNum += (i-1) * currFactorial;
                    perm += list.remove(i-1);
                    break;
                }
            }
        }
        return perm;
    }
    //working with an ArrayList would be easier since we can easily remove digits already used
    public static ArrayList arrayToArrayList(String[] arr){
        int length = arr.length;
        ArrayList<String> list = new ArrayList<String>();
        for(int i = 0; i < length; i++){
            list.add(arr[i]);
        }
        return list;
    }
    //a naive factorial function, will be usefull enough because we won't use it on numbers higher than 9
    public static long factorial(int x){
        long result = 1;
        for(int i = 2; i <= x; i++)
            result *= i;
        return result;
    }
}