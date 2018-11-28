import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

//https://m.blog.naver.com/occidere/220786307316


public class Main {
	public static void main(String[] args) {

		Scanner scanner=new Scanner(System.in);



		int caseTest;	//첫 번째 input


		caseTest=scanner.nextInt();
		int []answer=new int[caseTest];

		for(int i=0;i<caseTest;i++)
		{
			int length=scanner.nextInt();
			int [][]sticker=new int[2][length+1];
			int d[][]=new int [2][length+1];
			for(int j=1;j<=length;j++)
				sticker[0][j]=scanner.nextInt();
			for(int j=1;j<=length;j++)
				sticker[1][j]=scanner.nextInt();




			answer[i]=check(d,sticker,length);

		}
		for(int i=0;i<caseTest;i++)
			System.out.println(answer[i]);



	}


	public static int Max(int a, int b) {return (a>b? a:b); }

	public static int check(int d[][],int map[][],int length)
	{

		d[0][0] = d[1][0]=0;
		d[0][1] = map[0][1];
		d[1][1] = map[1][1];

		for(int i=2;i<length+1;i++)
		{
		d[0][i] = Max(d[1][i-1],d[1][i-2])+map[0][i];
		d[1][i] = Max(d[0][i-1],d[0][i-2])+map[1][i];

		}

		return Max(d[0][length],d[1][length]);
	}





}
