package spelling;

import java.util.List;
import java.util.Set;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;

/** 
 * An trie data structure that implements the Dictionary and the AutoComplete ADT
 * @author You
 *
 */
public class AutoCompleteDictionaryTrie implements  Dictionary, AutoComplete {

    private TrieNode root;
    private int size;
    

    public AutoCompleteDictionaryTrie()
	{
		root = new TrieNode();
	}
	
	
	/** Insert a word into the trie.
	 * For the basic part of the assignment (part 2), you should ignore the word's case.
	 * That is, you should convert the string to all lower case as you insert it. */
	public boolean addWord(String word)
	{
	    //TODO: Implement this method.
		//if (word == null) {
		//	throw new NullPointerException();
		//}
		if (word.isEmpty()) {
			return false;
		}
		
		int index = 0;
		LinkedList<TrieNode> q = new LinkedList<TrieNode>();
		q.add(root);
		while(!q.isEmpty()) {
			TrieNode curr = q.removeLast();
			if (curr != null) {
				char c = (word.toLowerCase()).charAt(index);
				if (curr.getChild(c) == null) {
					curr.insert(c);
				}
				
				if (index < word.length()-1) {
					q.addFirst(curr.getChild(c));
					index++;
				}
				else {
					if (curr.getChild(c).endsWord()) {
						return false;
					}
					(curr.getChild(c)).setEndsWord(true);
					return true;
				}
			}
		}
		return true;
	}
	
	/** 
	 * Return the number of words in the dictionary.  This is NOT necessarily the same
	 * as the number of TrieNodes in the trie.
	 */
	public int size()
	{
	    //TODO: Implement this method
		size = 0;
		LinkedList<TrieNode> q = new LinkedList<TrieNode>();
		q.add(root);
		while(!q.isEmpty()) {
			TrieNode curr = q.removeLast();
			if (curr != null) {
				if (curr.endsWord()) {
					size++;					
				}
				for (char c : curr.getValidNextCharacters()) {
					q.addFirst(curr.getChild(c));
				}
			}
		}
		return size;
	}
	
	/** Returns whether the string is a word in the trie */
	@Override
	public boolean isWord(String s) 
	{
	    // TODO: Implement this method
		//if (s == null) {
		//	throw new NullPointerException();
		//}
		if (s.isEmpty()) {
			return false;
		}

		LinkedList<TrieNode> q = new LinkedList<TrieNode>();
		q.add(root);
		while(!q.isEmpty()) {
			TrieNode curr = q.removeLast();
			if (curr != null) {
				if ((curr.getText()).equals(s.toLowerCase())) {
					if (curr.endsWord()) return true;
				}
				for (char c : curr.getValidNextCharacters()) {
					q.addFirst(curr.getChild(c));
				}
			}
		}
		
		return false;
	}

	/** 
	 *  * Returns up to the n "best" predictions, including the word itself,
     * in terms of length
     * If this string is not in the trie, it returns null.
     * @param text The text to use at the word stem
     * @param n The maximum number of predictions desired.
     * @return A list containing the up to n best predictions
     */@Override
     public List<String> predictCompletions(String prefix, int numCompletions) 
     {
    	 // TODO: Implement this method
    	 // This method should implement the following algorithm:
    	 // 1. Find the stem in the trie.  If the stem does not appear in the trie, return an
    	 //    empty list
    	 // 2. Once the stem is found, perform a breadth first search to generate completions
    	 //    using the following algorithm:
    	 //    Create a queue (LinkedList) and add the node that completes the stem to the back
    	 //       of the list.
    	 //    Create a list of completions to return (initially empty)
    	 //    While the queue is not empty and you don't have enough completions:
    	 //       remove the first Node from the queue
    	 //       If it is a word, add it to the completions list
    	 //       Add all of its child nodes to the back of the queue
    	 // Return the list of completions
    	 /*
    	 if (prefix == null) {
    		 throw new NullPointerException();
    	 }
    	 */
    	 if (numCompletions < 0) {
    		 throw new IllegalArgumentException();
    	 }
    	 
    	 TrieNode child = null;
    	 TrieNode next = root;
    	 List<String> completions = new ArrayList<String>();
    	 LinkedList<TrieNode> queue = new LinkedList<TrieNode>();
    	 
    	 if (numCompletions == 0) {
    		 return completions;
    	 }
    	 
    	 for (int i = 0; i < prefix.length(); i++) {
    		 if (next.getChild(prefix.charAt(i)) != null)
    			 child = next.getChild(prefix.charAt(i));
    		 else
    			 return completions;
    		 next = child;
    	 }
    	     	
     	 queue.addFirst(next);
     	
     	 while(!queue.isEmpty()) {
     	 	 TrieNode curr = queue.removeLast();
     	 	 if (curr != null) {
     			 if (curr.endsWord()) {
     				 if (completions.size() < numCompletions) {
     					 completions.add(curr.getText());
     				 }
     				 else {
     					 return completions;
     				 }
     			 }
     			 for (char c : curr.getValidNextCharacters()) {
     				 queue.addFirst(curr.getChild(c));
     			 }
     		 }
     	 }   	 

    	 return completions;
     }
    
    
 	// For debugging
 	public void printTree()
 	{
 		printNode(root);
 	}
 	
 	/** Do a pre-order traversal from this node down */
 	public void printNode(TrieNode curr)
 	{
 		if (curr == null) 
 			return;
 		
 		System.out.println(curr.getText() + " - " + curr.endsWord());
 		
 		TrieNode next = null;
 		for (Character c : curr.getValidNextCharacters()) {
 			next = curr.getChild(c);
 			printNode(next);
 		}
 	}
 	
 	public void printSize()
 	{
 		System.out.println(this.size());
 	}
	
}