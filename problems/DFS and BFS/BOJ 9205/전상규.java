import java.util.ArrayList;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {

		Scanner scanner=new Scanner(System.in);


		int numCase;
		int sevenEleven=0;
		ArrayList <node> points;
		ArrayList <ArrayList<node>> casePoints;



		numCase=scanner.nextInt();
		casePoints= new ArrayList<ArrayList<node>>(numCase);

		//입력값받기
		for(int j=0;j<numCase;j++)
		{
			sevenEleven=scanner.nextInt();
			points=new ArrayList<node>();


			for(int i=0;i<sevenEleven+2;i++)
			{

				int x=scanner.nextInt();
				int y=scanner.nextInt();
				node point=new node(x,y);

				points.add(point);


			}
			casePoints.add(points);



		}

		//출력
		for(int i=0;i<numCase;i++)
		{
			checkAllCases(casePoints.get(i).get(0),casePoints.get(i));

			//마지막 node를 검사하여 true이면 마지막을 들렸다것이 된다.....
			if(casePoints.get(i).get(casePoints.get(i).size()-1).isEntered)
			{
				System.out.println("happy");
			}
			else
				System.out.println("sad");

		}



		return ;

    }

	public static void checkAllCases(node curPos, ArrayList<node> points)
	{
		curPos.isEntered=true;

		for(int i=0;i<points.size();i++)
		{


			//이미 한번 갔으면 skip, 1000m이상이면 skip
			if(!points.get(i).isEntered&&isAvailable(curPos,points.get(i)))
			{
				checkAllCases(points.get(i),points);
			}


		}



		return ;

	}


	//두 점 사이의 거리가 1000m 미만인 경우
	public static boolean isAvailable(node A, node B)
	{

			if(Math.abs(A.pos_x-B.pos_x)+Math.abs(A.pos_y-B.pos_y)<=1000)
	 		{
	 			return true;
	 		}

	 		else
	 			return false;

	}


	//position
	static class node
	{
		boolean isEntered;
		int pos_x;
		int pos_y;

		public node() {
			isEntered=false;
			pos_x=0;
			pos_y=0;
		}


		public node(int a, int b)
		{
			isEntered=false;
			pos_x=a;
			pos_y=b;
		}


	}



}
