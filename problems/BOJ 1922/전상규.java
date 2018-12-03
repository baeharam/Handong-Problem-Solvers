import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;



public class Main {
	public static void main(String[] args) {

		Scanner scanner=new Scanner(System.in);


		int numE;
		int numV;





		numE=scanner.nextInt();
		numV=scanner.nextInt();
		ArrayList<edge> e=new ArrayList<edge>(numE);

		for(int i=0;i<numV;i++)
		{
			int a=scanner.nextInt();
			int b=scanner.nextInt();
			int c=scanner.nextInt();
			edge w=new edge(a,b,c);

			e.add(w);

		}
		Collections.sort(e);	// kruskal을 하려 weight가 가장 낮은 애들에 접근해야하기 떄문에 sort준다.
		System.out.println(kruskal(numV,numE,e));

	}





	public static int kruskal(int numV, int n,ArrayList<edge>  e)
	{
		union_find_tree uf=new union_find_tree(n+1);
		int sum=0;
		for(int i=0;i<e.size();i++)
		{

			if(!uf.same_set(e.get(i).v1, e.get(i).v2))	//같은 set이 아닌 경우 즉 cycle이 아닌 경우 edge를 연결한다
			{

				if(uf.merge(e.get(i).v1, e.get(i).v2))		//get_root해서 같은 case가 있어서 일단 boolean으로 만들어 놓음 (merg자체 안에서도 root 가 같은지검사)
					sum+=e.get(i).weight;
			}

		}





		return sum;
	}





	static class union_find_tree
	{
		int []parent;

		public union_find_tree(int numV)
		{
			/*
			 *
			 * 초기화 하기 위해서는 edge만큼의 group이(한 요소에 대해서 하나의 set)필요하
			 * 하나의 원소 밖에 없으니 height도 0이고 group size가 1인 것이.
			 */
			parent=new int[numV];

			for(int i=0;i<numV;i++)
			{
				parent[i]=i;
			}
		}

		int get_root(int a)
		{
		/*
		 * set의 구성이 하나 이상인 경우, 우린 그런 set을 tree로 나타내고 있다
		 * 즉,a가 속해 있는 tree의(set)의 root를 출력해주는 함수
		 */

			if(parent[a]==a) return a;
			return parent[a]=get_root(parent[a]);
		}


		boolean same_set(int v1, int v2)
		{
		/*
		 * 두 원소에 대해서 같은 set에 속해 있는지 보려고 하는 함수
		 * 쿠루스칼 알고리즘에서는 이제, cycle이 되는지 안되는 확인 하는 함수로 사용한
		 */


			if (get_root(v1)==get_root(v2))
				return true;
			else
				return false;
		}

		boolean merge(int v1, int v2)
		{
			/*
			 * 같은 cycle혹은 set이 아닌 경우
			 * vertex에 대하여 root를 같은 걸로 표시함으로써
			 * 같은 set에 있는 것으로 설정함
			 */
			v1=get_root(v1);
			v2=get_root(v2);


			if(v1==v2)return false;

			else
				parent[v2]=v1;
			return true;
		}




	}




	static class edge implements Comparable<edge>
	{
		int v1,v2,weight;


		public edge(int a, int b, int c)
		{
			v1=a;
			v2=b;
			weight=c;
		}

		//collection.sort를 사용하기 위한 sort
		@Override
		public int compareTo(edge e) //for collection.sort
		{
			if(this.weight>e.weight) return 1;
			else if(this.weight<e.weight) return -1;
			else return 0;

		}

	}




}
