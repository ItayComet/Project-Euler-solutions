public class Problem2
{
    //prints the sum of the even valued Fibonacci numbers whose values fo not exceed 4,000,000
    public static void main(String[] args){
        int sum = 2, fib1 = 1, fib2 = 2, currNum = 3;
        while(currNum <= 4000000){
            if(currNum%2 == 0)
                sum += currNum;
            fib1 = fib2;
            fib2 = currNum;
            currNum = fib1 + fib2;
        }
        System.out.println(sum);
    }
}
