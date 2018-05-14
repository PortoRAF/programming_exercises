package textgen;

import java.util.AbstractList;


/** A class that implements a doubly linked list
 * 
 * @author UC San Diego Intermediate Programming MOOC team
 *
 * @param <E> The type of the elements stored in the list
 */
public class MyLinkedList<E> extends AbstractList<E> {
	LLNode<E> head;
	LLNode<E> tail;
	int size;

	/** Create a new empty LinkedList */
	public MyLinkedList() {
		// TODO: Implement this method
		size = 0;
		head = new LLNode<E>(null);
		tail = new LLNode<E>(null);
		head.next = tail;
		tail.prev = head;
	}

	/**
	 * Appends an element to the end of the list
	 * @param element The element to add
	 */
	public boolean add(E element ) 
	{
		// TODO: Implement this method
		if (element == null) {
			throw new NullPointerException();
		}
		
		LLNode<E> newNode = new LLNode<E>(element);
		
		if (size == 0) {
			head.next = newNode;
			tail.prev = newNode;
			newNode.prev = head;
			newNode.next = tail;
		}
		else {
			newNode.prev = tail.prev;
			newNode.next = tail;
			tail.prev.next = newNode;
			tail.prev = newNode;			
		}
		
		size++;
		
		return true;
	}

	/** Get the element at position index 
	 * @throws IndexOutOfBoundsException if the index is out of bounds. */
	public E get(int index) 
	{
		// TODO: Implement this method.
		if (index < 0 || index >= size || size == 0) {
			throw new IndexOutOfBoundsException();
		}
		
		LLNode<E> returnNode = new LLNode<E>(null);
		returnNode = head.next;
		
		for (int i = 0; i != index; i++) {
			returnNode = returnNode.next;
		}
		
		return returnNode.data;
	}

	/**
	 * Add an element to the list at the specified index
	 * @param The index where the element should be added
	 * @param element The element to add
	 */
	public void add(int index, E element ) 
	{
		// TODO: Implement this method
		if (element == null) {
			throw new NullPointerException();
		}
		if (index < 0 || index > size) {
			throw new IndexOutOfBoundsException();
		}
		
		LLNode<E> newNode = new LLNode<E>(element);
		
		//if (index <= size/2) {
			LLNode<E> tempNode = head.next;
			for (int i = 0; i != index; i++) {
				tempNode = tempNode.next;
			}
			tempNode.prev.next = newNode;
			newNode.prev = tempNode.prev;
			tempNode.prev = newNode;
			newNode.next = tempNode;
		//}
		size++;
	}


	/** Return the size of the list */
	public int size() 
	{
		// TODO: Implement this method		
		return this.size;
	}

	/** Remove a node at the specified index and return its data element.
	 * @param index The index of the element to remove
	 * @return The data element removed
	 * @throws IndexOutOfBoundsException If index is outside the bounds of the list
	 * 
	 */
	public E remove(int index) 
	{
		// TODO: Implement this method
		if (index < 0 || index >= size || size == 0) {
			throw new IndexOutOfBoundsException();
		}
		
		LLNode<E> tempNode = head.next;
		
		for (int i = 0; i != index; i++) {
			tempNode = tempNode.next;
		}
		
		E returnData = tempNode.data;
		tempNode.prev.next = tempNode.next;		
		tempNode.next.prev = tempNode.prev;
		
		size--;
		
		return returnData;
	}

	/**
	 * Set an index position in the list to a new element
	 * @param index The index of the element to change
	 * @param element The new element
	 * @return The element that was replaced
	 * @throws IndexOutOfBoundsException if the index is out of bounds.
	 */
	public E set(int index, E element) 
	{
		// TODO: Implement this method
		if (element == null) {
			throw new NullPointerException();
		}
		if (index < 0 || index >= size || size == 0) {
			throw new IndexOutOfBoundsException();
		}
		
		LLNode<E> newNode = new LLNode<E>(element);
		LLNode<E> tempNode = head.next;
		
		for (int i = 0; i != index; i++) {
			tempNode = tempNode.next;
		}
		
		E returnData = tempNode.data;		
		tempNode.prev.next = newNode; 
		tempNode.next.prev = newNode;
		tempNode.data = newNode.data;
		newNode.prev = tempNode.prev;
		newNode.next = tempNode.next;
		
		return returnData;
	}   
}

class LLNode<E> 
{
	LLNode<E> prev;
	LLNode<E> next;
	E data;

	// TODO: Add any other methods you think are useful here
	// E.g. you might want to add another constructor

	public LLNode(E e) 
	{
		this.data = e;
		this.prev = null;
		this.next = null;
	}

}
