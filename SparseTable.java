package sept23;

public class SparseTable {

	int[] arr;
	int[][] lookup;
	
	public SparseTable(int[] arr) {
		this.arr = arr;
		int logN = getLog(arr.length);
		this.lookup = new int[arr.length][logN + 1];
		
		for(int i=0; i<arr.length; i++){
			lookup[i][0] = i;
		}
		
		for(int j=1; j<lookup[0].length; j++){
			for(int i=0; i + (1<<j) - 1 < lookup.length; i++){
				lookup[i][j] = arr[lookup[i][j-1]] < 
						       arr[lookup[i + (1 << (j-1))][j-1]] ? 
						       lookup[i][j-1]: lookup[i + (1 << (j-1))][j-1] ;
			}
		}
		
	}
	
	public int query(int l, int r) {
		int count = r - l + 1;
		int log = getLog(count);
		return Math.min(arr[lookup[l][log]], arr[lookup[r - (1 << log) + 1][log]]);
	}

	public int getLog(int n) {
		int log = 0;
		while((1<<log) < n) {
			log++;
		}
		
		if((1 << log) > n){
			log--;
		}
		
		return log;
	    
	}
	public static void main(String[] args) {
		int arr[] = {1, 4, 2, 9, 11, 5, 10, 18, 7, 6};
		SparseTable s = new SparseTable(arr);
		System.out.println(s.query(1, 7));
	}

}
