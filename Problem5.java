public class Problem5
{
    public static void main(String[] args){
        int num = 2520;
        while(true){
            if(isDivisible(num))
                break;
            num++;
        }
        System.out.println(num);
    }
    public static boolean isDivisible(int n){
        for(int i = 20; i > 10; i--){
            if(n % i != 0)
                return false;
        }
        return true;
    }
}
