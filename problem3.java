public class problem3
{
    //Prints the largest prime factor of 600,851,475,143
    //Can also print other largest prime factors of course
    public static void main(String[] args){
        long num = 600851475143L;
        System.out.println(findLargestPrimeFactor(num));
    }
    
    public static long findLargestPrimeFactor(long num){
        long currNum = num;
        //It's worth noting that the factor can't be higher than num/2
        for(long i = 2; i < num/2; i++){
            if(isPrime(i)){
                while(currNum % i == 0){
                    currNum = currNum / i;
                }
                if(isPrime(currNum)){
                    break;
                }
            }
        }
        return currNum;
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
