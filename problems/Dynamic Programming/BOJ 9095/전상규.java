import java.util.Scanner;


public class Main {

	public static void main(String[] args) {

		Scanner scanner=new Scanner(System.in);


		int n;



		n=scanner.nextInt();
		int[] A = new int[n];

		for(int i=0;i<n;i++)
		{
			A[i]=scanner.nextInt();
		}


		for(int i=0;i<n;i++)
		System.out.println(fun(0,A[i]));





    }



	public static int fun(int sum,int n)
	{


		if(n<=0)
		{
			sum++;
			return sum;
		}



		if((n-1)>=0) {
			sum=fun(sum,n-1);

		}


		if((n-2)>=0)
		{


			sum=fun(sum,n-2);

		}

		if((n-3)>=0)
		{

			sum=fun(sum,n-3);


		}



		return sum;



	}




}
