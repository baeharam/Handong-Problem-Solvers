import java.util.Scanner;

/*
 * http://2youngjae.tistory.com/36
 */



public class Main {

	 static	int dx[] = {1,-1,0,0} ;
	 static	int dy[] = {0,0,1,-1} ;

    public static void main(String[] args){

    	Scanner scanner=new Scanner(System.in);
		int columns,rows;


		columns=scanner.nextInt();
		rows=scanner.nextInt();

		int map[][]=new int [columns][rows];
		int tmp[][]=new int [columns][rows];

		boolean visit[][]=new boolean [columns][rows];
		for(int i=0;i<columns;i++) {
			for(int j=0;j<rows;j++) {
				map[i][j]=scanner.nextInt();
			}
		}
		int answer=0;
		while(true) {

			int	cnt=check(columns,rows,visit,map);
			if(cnt>=2) {
				System.out.println(answer);
				break;
			}
			else if(cnt==0) {
				System.out.println(0);
				break;
			}
			else {
				answer++;
//				System.out.println("________________"+answer+"__________________");
//				show(columns,rows,map);
//				System.out.println("________________###__________________\n");
//
				for(int i = 1; i < columns-1 ; i++){
	                for(int j = 1 ; j < rows-1 ; j++){
	                    if(map[i][j]>0){
	                    tmp[i][j] = melt(i,j,map);

	                    }
	                }
                 }
				 for(int i = 1; i < columns-1 ; i++){
		                for(int j = 1 ; j < rows-1 ; j++){
		                   if(map[i][j]>0){
		                    if(map[i][j]-tmp[i][j]<0)map[i][j]=0;
		                    else map[i][j]-=tmp[i][j];
		                   }
		                }
				 }
			}

		}

    }


    public static int check(int columns, int rows,boolean visit[][], int map[][]) {
    	visit=new boolean[columns][rows];
    	int cnt=0;
    	for(int i=1;i<columns-1;i++) {
    		for(int j=1;j<rows;j++) {
    			if(map[i][j]>0&&!visit[i][j]) {
    				dfs(i,j,visit,map);
    				cnt++;
    			}
    		}
    	}

    	return cnt;
    }
    public static void dfs(int x, int y, boolean visit[][], int map[][]) {
    	visit[x][y]=true;
    	for(int i=0;i<4;i++) {
    		int tx=x+dx[i];
    		int ty=y+dy[i];

    		if(!visit[tx][ty]&&map[tx][ty]>0) {
    			dfs(tx,ty,visit,map);
    		}
    	}

    }

    public static int melt(int x, int y,int map[][]) {
    	int cnt=0;
    	for(int i=0;i<4;i++) {
    		int tx = x+dx[i];
    		int ty = y+dy[i];
    		if(map[tx][ty]==0) {
    			cnt++;
    		}
    	}
    	return cnt;
    }

    public static void show(int n,int m,int map[][]){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                System.out.print(map[i][j]+" ");
            }
            System.out.println();
        }
    }

}
