public class Problem10
{
    public static void main(String[] args){
        long sum = 2;
        int[] arr = new int[600000];
        int j = 0;
        for(int i = 3; i < 2000000; i += 2){
            while(arr[j] != 0){
                if(i%arr[j] == 0)
                    break;
                j++;
            }
            if (arr[j] == 0){
                sum += i;
                arr[j] = i;
            }
            j = 0;
        }
        System.out.println(sum);
        while(arr[j] != 0){
            j++;
        }
        System.out.println(j);
    }
    
    public static boolean isPrime(long num){
        if(num == 2)
            return true;
        if(num%2 == 0)
            return false;
        for(int i = 3; i < num/2; i += 2){
            if(num%i == 0)
                return false;
        }
        return true;
    }
}
