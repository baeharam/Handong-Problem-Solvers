import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;



public class Main {
	public static void main(String[] args) {

		Scanner scanner=new Scanner(System.in);
		int n=1000001;
		boolean visit[]=new boolean[n];
		ArrayList<Integer> prime=new ArrayList<Integer>();


		for(int i=2;i<n;i++){
			if(!visit[i]){
				prime.add(i);
				for(int j=2;i*j<n;j++)
					visit[i*j]=true;
			}
		}



		while(true) {
			int L,U;
			int x=0,y=0;


			L=scanner.nextInt();
			U=scanner.nextInt();
			if(L==-1&&U==-1)break;

			for(int i: prime) {
				if(i>=L&&i<=U)x++;
				else continue;
				if(i==2)y++;
				if(i%4==1)y++;
			}

			System.out.println(L+" "+U+" "+x+" "+y);
			}
		}
}
