import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;
import java.util.Vector;



public class Main {
	public static void main(String[] args) {

		Scanner scanner=new Scanner(System.in);


		int num;


		num=scanner.nextInt();

		char[] pattern = new char[2*num-1];
		char[] answer = new char[num];

		for(int i=0;i<num;i++) {
			pattern[i]=scanner.next().trim().charAt(0);
			if(i<num-1)
				pattern[num+i]=pattern[i];
		}
		for(int i=0;i<num;i++) {
			answer [i]=scanner.next().trim().charAt(0);
		}

		int ans=kmp(pattern,answer).size();
		System.out.println(asFraction(ans,num));


	}


	public static int[] getPi(char[] p){

		int m = p.length;
		int j = 0;

		int[] pi = new int[m];
		for(int i=1;i<m;i++) {
			while(j>0 && p[i] != p[j])
				j=pi[j-1];
			if(p[i]==p[j])
				pi[i]=++j;
		}
		return pi;



	}

	public static ArrayList<Integer>  kmp(char[] s, char[] p){
		ArrayList<Integer> ans = new ArrayList<Integer>();
		int [] pi = getPi(p);
		int n=s.length; int m = p.length; int j = 0;

		for(int i = 0; i < n ; i++) {
			while(j>0 && s[i] != p[j])
				j=pi[j-1];
			if(s[i]==p[j]) {
				if(j == m-1) {
					ans.add(i-m+1);
					j = pi[j];
				}
				else {
					j++;
				}
			}
		}
		return ans;

	}

	public static int gcm(int a, int b) {
		return b == 0 ? a : gcm(b, a%b);
	}
	public static String asFraction(int a, int b) {
		int gcm = gcm(a,b);
		return (a/gcm)+"/"+(b/gcm);
	}
}
