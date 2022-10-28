public class CircularQueue{
	public static void main(String[] args) {
		CQueue nums = new CQueue();
		nums.add(10);
		nums.printQueue();
	}
}

class CQueue{

	protected int[] arr;
	protected int   size  = 0;
	protected int   start = 0;
	protected int   end   = 0;

	public CQueue(){
		this.arr = new int[10];
	}

	public CQueue(int n){
		this.arr = new int[size];
	}

	public int status(){
		if(size == arr.length)return 1;
		if(size == 0)return 0;
		return -1;
	}

	public boolean add(int n){
		if(status() == 1) return false;
		size++;
		arr[end++] = n;
		end = end%arr.length;
		return true;
	}

	public int remove(){
		if(status() == 0) return -1;
		start++;
		size--;
		start=start%arr.length;
		return 1;
	}

	public void printQueue(){
		for (int i=start; i <= end ; i++ ) {
			System.out.print(arr[i] + " ");
		}
	}
}