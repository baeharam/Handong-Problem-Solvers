import java.util.ArrayList;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {

		Scanner scanner=new Scanner(System.in);


		int length;	//첫 번째 input


		int input[][];	//image 값
		String line;	//한글자씩 받을 수 없어서 먼저 string으로 받고, charAt으로 다시 int로 한 문자씩받는 다

		length=Integer.parseInt(scanner.nextLine());


		input=new int[length][length];
		//입력값받기
		for(int j=0;j<length;j++)
		{
				line=scanner.nextLine();
				for(int i=0;i<length;i++)
				input[j][i]=line.charAt(i)-'0';

		}


		//image를 축소해주는 함
			check(input, 0, 0, length);



	}

	public static void check(int grid[][],int start_x,int start_y,int n)
	{



		if(!isDigitEqaul_2(grid,start_x,start_y,n))
		{

			System.out.print("(");

			n=n/2;	//줄어들게 되는 경우 grid의 length 재정

			check(grid,start_x,start_y,n);			//1st grid
			check(grid,start_x+n,start_y,n);		//2nd grid
			check(grid,start_x,start_y+n,n);		//3rd grid
			check(grid,start_x+n,start_y+n,n);		//4th grid
		}
		else
		{
			System.out.print(grid[start_y][start_x]);	//grid의 값이 모두 같은 값을 갖을 경우 출력
			return;
		}
		System.out.print(")");
		return;

	}

	//모든grid의 element가 동일한 확인하는 함수
	public static boolean isDigitEqaul_2(int [][]grid,int start_x,int start_y, int length)
	{

		int threshold=grid[start_y][start_x];

		for(int i=start_y;i<start_y+length;i++)
		{
			for(int j=start_x;j<start_x+length;j++)
			{
				if(threshold!=grid[i][j])
				{
					return false;
				}
			}
		}

		return true;

	}


}
