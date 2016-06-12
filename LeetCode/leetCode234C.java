package Link;

import java.util.Stack;

public class leetCode234C {

	/**
	 * @param args
	 */
	
	    public boolean isPalindrome(ListNode head) {
	    	if (head == null || head.next == null)
	    		return true;
	    	
	       	Stack<Integer> st = new Stack<Integer>();
	    	ListNode next = head;
	    	ListNode pre = head;
	    	
	    	while(next != null && next.next != null) {
	    		st.push(pre.val);
	    		pre = pre.next;
	    		next = next.next.next;
	    	}
	    	if (next != null)
	    		pre = pre.next;//for the difference of odd number and even number of a linked list

	    	while(pre != null) {
	    		if (!st.isEmpty() && st.peek() != pre.val) 
	    			return false;
	    		st.pop();
	    		pre = pre.next;
	    	}
	    	if(st.isEmpty())
	    		return true;
	    	else
	    		return false;
	    	
	        
	    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		leetCode234C test = new leetCode234C();
		ListNode head = new ListNode(1);
		head.next = new ListNode(1);
		//head.next.next = new ListNode(2);
		//head.next.next.next = new ListNode(1);
		
		/*while(head != null) {
			System.out.println("val: " + head.val);
			head = head.next;
		}*/
		
		System.out.println("result:  " + test.isPalindrome(head));
		
	}

}
