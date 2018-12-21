import java.util.ArrayList;
import java.util.Scanner;



public class Main {
	public static void main(String[] args) {

		Scanner scanner=new Scanner(System.in);


		int numPeople;
		int mainA;
		int mainB;
		int edge;

		int [] parent;
		int [] child;




		numPeople=scanner.nextInt();
		mainA=scanner.nextInt();
		mainB=scanner.nextInt();
		edge=scanner.nextInt();
		parent=new int[edge];
		child=new int[edge];

		for(int i=0;i<edge;i++)
		{
			parent[i]=scanner.nextInt();
			child[i]=scanner.nextInt();
		}



		System.out.println(check(parent,child,mainA,mainB));


	}





	static int check(int []parent, int []child, int mainA, int mainB)
	{

		ArrayList<Integer> Aparent=new 	ArrayList<Integer>();
		ArrayList<Integer> Bparent=new  ArrayList<Integer>();
		int i=0;
		int j=0;

		Aparent.add(mainA);
		Bparent.add(mainB);

		//mainA에 대한 parent 모으기
		while(i<child.length)
		{
			if(child[i]==mainA)
			{
				Aparent.add(parent[i]);
				mainA=parent[i];
				i=0;
				continue;
			}
			i++;
		}

		//mainB에 대한 parent 모으기
		i=0;
		j=0;
		while(i<child.length)
		{
			if(child[i]==mainB)
			{
				Bparent.add(parent[i]);
				mainB=parent[i];
				i=0;
				continue;
			}
			i++;
		}

		//mainA와 mainB가 공유 되는 parent 구하고, edge 만큼 촌수 출력하
		for(j=0;j<Bparent.size();j++)
		for( i=0;i<Aparent.size();i++)
		{
			if(Aparent.get(i)==Bparent.get(j)&&Aparent.get(i)!=0)
			{


				return i+j;


			}


		}

		return -1;



	}

//저장된 Parent들 print 하기
void debugOfNParent(ArrayList<Integer> Aparent,ArrayList<Integer> Bparent)
{
			for(i=0;i<Aparent.size();i++)
			{
				System.out.print("["+Aparent.get(i)+"] ");

			}
			System.out.println("\n--------------");


			for(i=0;i<Bparent.size();i++)
			{
				System.out.print("["+Bparent.get(i)+"] ");

			}
			System.out.println("\n--------------");



}


}
