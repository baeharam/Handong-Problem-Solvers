import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;




public class Main {
	public static void main(String[] args) {

		Scanner scanner=new Scanner(System.in);
		
		Stack<Integer> answer=new Stack<Integer>();	//모든 case를 확인하기 윈한 code
		Stack <Stack<Integer>> final_answer=new Stack <Stack<Integer>> ();	// 조건에 알맞은 stack을 모두 저장하는 stack
		int length;	//첫 번째 input 
		String task[];	//질문지 

	

		length=Integer.parseInt(scanner.nextLine());
		task=new String  [length];
		
		for(int i=0;i<length;i++) 
			task[i]=scanner.next();	//next로 해주어 문자 단위로 읽는다 

		check(final_answer,answer,length,task);	//calculating......
		
		

		
		for(int i=0 ; i<=length;i++)
			System.out.print(final_answer.peek().get(i));
		
		System.out.println("");
		
		for(int i=0 ; i<=length;i++)
			System.out.print(final_answer.get(0).get(i));

	}
	
	
	//directly check
	public static void check (Stack<Stack<Integer>> final_answer,Stack<Integer> answer,int length,String []task)
	{
		
		
		if(answer.size()>=length+1)
		{
			Stack<Integer> a= (Stack<Integer>) answer.clone();	//saving for final stack
			final_answer.push(a);
			answer.pop();
			return;
		}
		
		for(int i=0;i<10;i++)
		{
			
			if(answer.empty()||(answer.search(i)==-1&&questioning(answer.peek(),task[answer.size()-1],i)))
			{
				answer.push(i);
				check(final_answer,answer,length,task);
			}	

		}
		if(!answer.empty())
			answer.pop();
		return;
	
		
	}
	
	//b "a" c 
	public static boolean questioning( int b,String a,int c)
	{
		switch (a)
		{
			case "<": 
			{
				if(b<c)return true;
				else return false;
			}
			case ">":
			{
				if(b>c)return true;
				else return false;
			}
			default: return false;
		}
		
	}
}

