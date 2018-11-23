import java.lang.* ;
import java.util.Scanner ;
import java.util.StringTokenizer ;

public class Inequality{

   	public static String Inequalitys = new String();
	public static int k ;

	public static int big_k = 0 ;  
	public static int small_k = 0 ;

    public static int score = 9 ; 
	public static int small = 0 ;

    public static void main(String [] args)
    {

        Scanner s = new Scanner(System.in) ;
        
		k = s.nextInt() ;
		
		if((k > 9)||(2 > k)) System.exit(0);
        
        Inequalitys = s.nextLine();

		String [] bigNumbers = new String[10] ;
		String [] smallNumbers = new String[10] ;
        
        for(int i = 0 ; i < 10; i++)
        {
			bigNumbers[i]   = new String() ;
			smallNumbers[i] = new String() ;
        }

		Inequalitys = s.nextLine();
	
		StringTokenizer st = new StringTokenizer(Inequalitys, " ");	
	
		int b_count = 0 ;
		int b_discount = -1 ;	
		int s_count = -1 ;
		int s_discount = 0 ;


		String str = new String() ;

		str = st.nextToken() ;

		try{
        
			for(int i = 0; i < k ; )
			{
				
				if(str.equals("<"))
				{
					b_count = 0 ;

					if((small_k == k)||(small_k == 0)) s_count = 0 ;
					else s_count = -1 ;

					for(; str.equals("<") ;str = st.nextToken())
					{
						b_count++ ;
						s_count++ ;
						i++ ;

						if((!st.hasMoreTokens())&&(s_count >= 1)&&(small_k != k)) s_count++ ;

						if(i >= k) break ;
						
					}
					
					int b_where = b_count + big_k ;
					int s_where = small_k ;
					int first = big_k ;

					if(s_count == k) s_count++ ;

					for(; b_where >= first ; b_where--)
					{
						bigNumbers[b_where] = Integer.toString(score) ;

						score-- ;
						big_k++ ;
						
					}

					first = small_k ;

					for(; s_count > 0 ; s_count--, s_where = small_k)
					{
						smallNumbers[s_where] = Integer.toString(small) ;

						small++ ;
						small_k++ ;
						
					}

									
				}
				else if(str.equals(">"))
				{
					if((big_k == k)||(big_k == 0)) b_discount = 0 ;
					else b_discount = -1 ;

					s_discount = 0 ;

					for(; str.equals(">") ;str = st.nextToken())
					{
						b_discount++ ;
						s_discount++ ;
						i++ ;
						
						if((!st.hasMoreTokens())&&(b_discount >= 1)&&(big_k != k)) b_discount++ ;

						if(i >= k) break ;
				
					}

					int b_where = big_k;
					int s_where = s_discount + small_k ;
					int first = big_k ;

					if(b_discount == k) b_discount++ ;

					for(; b_discount > 0 ; b_discount--, b_where = big_k)
					{
						bigNumbers[b_where] = Integer.toString(score) ;

						score-- ;
						big_k++ ;
						
					}

					first = small_k ;

					for(; s_where >= first ; s_where--)
					{
						smallNumbers[s_where] = Integer.toString(small) ;

						small++ ;
						small_k++ ;
						

					}


				}

			}
			
		}catch(Exception e){



		}
		String big_num = new String() ;
		String small_num = new String() ;
		for(int i = 0; i < big_k ; i++)
		{
			big_num += bigNumbers[i] ;

		}

		for(int i = 0; i < small_k ; i++)
		{
			small_num += smallNumbers[i] ;

		}

		System.out.println(big_num) ;
		System.out.print(small_num) ;

    }


}
