package textgen;

import static org.junit.Assert.*;

import java.util.LinkedList;

import org.junit.Before;
import org.junit.Test;

/**
 * @author UC San Diego MOOC team
 *
 */
public class MyLinkedListTester {

	private static final int LONG_LIST_LENGTH =10; 

	MyLinkedList<String> shortList;
	MyLinkedList<Integer> emptyList;
	MyLinkedList<Integer> longerList;
	MyLinkedList<Integer> list1;
	
	/**
	 * @throws java.lang.Exception
	 */
	@Before
	public void setUp() throws Exception {
		// Feel free to use these lists, or add your own
	    shortList = new MyLinkedList<String>();
		shortList.add("A");
		shortList.add("B");
		emptyList = new MyLinkedList<Integer>();
		longerList = new MyLinkedList<Integer>();
		for (int i = 0; i < LONG_LIST_LENGTH; i++)
		{
			longerList.add(i);
		}
		list1 = new MyLinkedList<Integer>();
		list1.add(65);
		list1.add(21);
		list1.add(42);
		
	}

	
	/** Test if the get method is working correctly.
	 */
	/*You should not need to add much to this method.
	 * We provide it as an example of a thorough test. */
	@Test
	public void testGet()
	{
		//test empty list, get should throw an exception
		try {
			emptyList.get(0);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
			
		}
		
		// test short list, first contents, then out of bounds
		assertEquals("Check first", "A", shortList.get(0));
		assertEquals("Check second", "B", shortList.get(1));
		
		try {
			shortList.get(-1);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
		
		}
		try {
			shortList.get(2);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
		
		}
		// test longer list contents
		for(int i = 0; i<LONG_LIST_LENGTH; i++ ) {
			assertEquals("Check "+i+ " element", (Integer)i, longerList.get(i));
		}
		
		// test off the end of the longer array
		try {
			longerList.get(-1);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
		
		}
		try {
			longerList.get(LONG_LIST_LENGTH);
			fail("Check out of bounds");
		}
		catch (IndexOutOfBoundsException e) {
		}
		
	}
	
	
	/** Test removing an element from the list.
	 * We've included the example from the concept challenge.
	 * You will want to add more tests.  */
	@Test
	public void testRemove()
	{
		int a = list1.remove(0);
		assertEquals("Remove: check a is correct ", 65, a);
		assertEquals("Remove: check element 0 is correct ", (Integer)21, list1.get(0));
		assertEquals("Remove: check size is correct ", 2, list1.size());
		
		// TODO: Add more tests here
		try {
			emptyList.remove(0);
			fail("Check out of bonds");
		}
		catch (IndexOutOfBoundsException e) {
			
		}
		
		try {
			shortList.remove(2);
			fail("Check out of bonds");
		}
		catch (IndexOutOfBoundsException e) {
			
		}
		
		try {
			shortList.remove(-1);
			fail("Check out of bonds");
		}
		catch (IndexOutOfBoundsException e) {
			
		}
		
		String t = shortList.remove(1);
		assertEquals("Remove: check t is correct ", "B", t);
		assertEquals("Remove: check element 0 is correct ", "A", shortList.get(0));
		assertEquals("Remove: check size is correct ", 1, shortList.size());
	}

	
	/** Test adding an element into the end of the list, specifically
	 *  public boolean add(E element)
	 * */
	@Test
	public void testAddEnd()
	{
        // TODO: implement this test
		try {
			emptyList.add(null);
			fail("Missing or invalid parameter");
		}
		catch (NullPointerException e) {
			
		}
		
		//test for short array
		assertEquals("Add at end: return true if added ", true, shortList.add("C"));
		assertEquals("Add at end: new size of list ", 3, shortList.size);
		
		//test for longer array
		assertEquals("Add at end: return true if added ", true, longerList.add(11));
		assertEquals("Add at end: new size of list ", LONG_LIST_LENGTH + 1, longerList.size);
	}

	
	/** Test the size of the list */
	@Test
	public void testSize()
	{
		// TODO: implement this test
		assertEquals("Size of empty list ", (Integer) 0, (Integer) emptyList.size());
		assertEquals("Size of short list ", (Integer) 2, (Integer) shortList.size());
		assertEquals("Size of longer list ", (Integer) LONG_LIST_LENGTH, (Integer) longerList.size());
	}

	
	
	/** Test adding an element into the list at a specified index,
	 * specifically:
	 * public void add(int index, E element)
	 * */
	@Test
	public void testAddAtIndex()
	{
        // TODO: implement this test
		try {
			emptyList.add(null);
			fail("Missing or invalid argument");
		}
		catch (NullPointerException e) {
			
		}
		
		try {
			emptyList.add(1, 10);
			fail("Argument index out of bonds");
		}
		catch (IndexOutOfBoundsException e) {
			
		}
		
		try {
			shortList.add(-1, "F");
			fail("Check out of bonds");
		}
		catch (IndexOutOfBoundsException e) {
			
		}
		
		//test shorter list
		shortList.add(1, "D");
		assertEquals("Add at index: get new value ", "A", shortList.get(0));
		assertEquals("Add at index: get new value ", "D", shortList.get(1));
		assertEquals("Add at index: get new value ", "B", shortList.get(2));
		
		//test longer list
		longerList.add(5, 11);
		assertEquals("Add at index: get new value ", (Integer) 4, longerList.get(4));
		assertEquals("Add at index: get new value ", (Integer) 11, longerList.get(5));
		assertEquals("Add at index: get new value ", (Integer) 5, longerList.get(6));
		assertEquals("Add at index: get new value ", (Integer) 9, longerList.get(LONG_LIST_LENGTH));
	}
	
	/** Test setting an element in the list */
	@Test
	public void testSet()
	{
	    // TODO: implement this test
	    try {
	    	emptyList.set(0, 10);
	    	fail("Argument index out of bonds");
	    }
	    catch (IndexOutOfBoundsException e) {
	    	
	    }
	    
	    try {
	    	list1.set(3, 10);
	    	fail("Argument index out of bonds");
	    }
	    catch (IndexOutOfBoundsException e) {
	    	
	    }
	    
	    try {
	    	list1.set(1, null);
	    	fail("Invalid argument");
	    }
	    catch (NullPointerException e) {
	    	
	    }
	    
	    String t = shortList.set(1, "D");
	    assertEquals("Set new data ", "A", shortList.get(0));
	    assertEquals("Set new data ", "B", t);
	    assertEquals("Set new data ", "D", shortList.get(1));
	    assertEquals("Set new data", 2, shortList.size());
	}
	
	
	// TODO: Optionally add more test methods.
	
}
