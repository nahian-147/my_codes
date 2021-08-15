import java.util.Vector;
class ReverseVector{
	public static void main(String arg[]){

		Vector<String> vColors = new Vector<String>();
 
		vColors.add("Red");
		vColors.add("Green");
		vColors.add("Blue");
 
		/*
		 * Start iterating from index (vector size - 1)
 		* to 0 and decrement counter by 1 using the
 		* for loop
 		*/
		for( int index = vColors.size() - 1 ; index >= 0 ; index-- ){
    			System.out.println( vColors.get(index) );
		}
	}
}
