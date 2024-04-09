public class Problem7
{
    public static void main(String[] args){
        long arr[] = new long[10001];
        arr[0] = 2;
        int i = 0, curr = 3;
        while(true){
            while(arr[i] != 0){
                if(curr%arr[i] == 0)
                    break;
                i++;
            }
            if(arr[i] == 0){
                arr[i] = curr;
                if(i == 10000)
                    break;
            }
            i = 0;
            curr++;
        }
        System.out.println(arr[10000]);
    }
}
