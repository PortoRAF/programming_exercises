package textgen;

import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Random;

/** 
 * An implementation of the MTG interface that uses a list of lists.
 * @author UC San Diego Intermediate Programming MOOC team 
 */
public class MarkovTextGeneratorLoL implements MarkovTextGenerator {

	// The list of words with their next words
	private List<ListNode> wordList; 
	
	// The starting "word"
	private String starter;
	
	// The random number generator
	private Random rnGenerator;
	
	public MarkovTextGeneratorLoL(Random generator)
	{
		wordList = new LinkedList<ListNode>();
		starter = "";
		rnGenerator = generator;		
	}
	
	public List<ListNode> getWordList()
	{
		return wordList;
	}
	
	
	/** Train the generator by adding the sourceText */
	@Override
	public void train(String sourceText)
	{
		// TODO: Implement this method
		//if (wordList.size() > 0) throw new IllegalArgumentException();
		String[] words = checkExceptions(sourceText);
		processText(words);
	}

	
	/** 
	 * Generate the number of words requested.
	 */
	@Override
	public String generateText(int numWords) {
	    // TODO: Implement this method
		if (numWords < 0) {
			throw new IndexOutOfBoundsException();
		}
		if (numWords == 0 || wordList.size() == 0) {
			return "";
		}
		
		int listIndex = rnGenerator.nextInt(wordList.size());
		String toReturn = "";
		String newWord = wordList.get(listIndex).getWord();
		String randomWord = null;
		
		for (int i = 0; i < numWords - 1; i++) {
			toReturn += newWord + " ";
			for (ListNode n : wordList) {
				if (newWord.equals(n.getWord())) {
					randomWord = n.getRandomNextWord(rnGenerator);
				}
			}			
			newWord = randomWord;
		}				
		return toReturn + newWord + "\n";
	}
	
	
	// Can be helpful for debugging
	@Override
	public String toString()
	{
		String toReturn = "";
		for (ListNode n : wordList)
		{
			toReturn += n.toString();
		}
		return toReturn;
	}
	
	/** Retrain the generator from scratch on the source text */
	@Override
	public void retrain(String sourceText)
	{
		// TODO: Implement this method.
		String[] words = checkExceptions(sourceText);
		wordList.clear();		
		processText(words);
	}
	
	
	// TODO: Add any private helper methods you need here.
	private String[] checkExceptions(String sourceText)
	{
		if (sourceText == null) {
			throw new NullPointerException();
		}
		
		String [] words = sourceText.split(" +");	
		
		if (words.length == 0) {
			throw new IllegalArgumentException();
		}
		
		return words;
	}
	
	private void processText(String[] words)
	{
		boolean wordExistsInList = false;
		
		for (int wordIndex = 0; wordIndex < words.length; wordIndex++) {
			for (ListNode n : wordList) {
				if (words[wordIndex].equals(n.getWord())) {
					wordExistsInList = true;					
					if (wordIndex < words.length-1)
						n.addNextWord(words[wordIndex+1]);
					else
						n.addNextWord(words[0]);
				}
			}
			if (!wordExistsInList) {
				wordList.add(new ListNode(words[wordIndex]));
				ListNode n = wordList.get(wordList.size()-1);
				if (wordIndex < words.length-1)
					n.addNextWord(words[wordIndex+1]);
				else
					n.addNextWord(words[0]);
			}
			wordExistsInList = false;
		}
	}
	
	/**
	 * This is a minimal set of tests.  Note that it can be difficult
	 * to test methods/classes with randomized behavior.   
	 * @param args
	 */
	public static void main(String[] args)
	{
		// feed the generator a fixed random value for repeatable behavior
		MarkovTextGeneratorLoL gen = new MarkovTextGeneratorLoL(new Random(42));
		String textString = "Hello.  Hello there.  This is a test.  Hello there.  Hello Bob.  Test again.";
		System.out.println(textString);
		gen.train(textString);
		System.out.println(gen);
		System.out.println(gen.generateText(20));
		String textString2 = "You say yes, I say no, "+
				"You say stop, and I say go, go, go, "+
				"Oh no. You say goodbye and I say hello, hello, hello, "+
				"I don't know why you say goodbye, I say hello, hello, hello, "+
				"I don't know why you say goodbye, I say hello. "+
				"I say high, you say low, "+
				"You say why, and I say I don't know. "+
				"Oh no. "+
				"You say goodbye and I say hello, hello, hello. "+
				"I don't know why you say goodbye, I say hello, hello, hello, "+
				"I don't know why you say goodbye, I say hello. "+
				"Why, why, why, why, why, why, "+
				"Do you say goodbye. "+
				"Oh no. "+
				"You say goodbye and I say hello, hello, hello. "+
				"I don't know why you say goodbye, I say hello, hello, hello, "+
				"I don't know why you say goodbye, I say hello. "+
				"You say yes, I say no, "+
				"You say stop and I say go, go, go. "+
				"Oh, oh no. "+
				"You say goodbye and I say hello, hello, hello. "+
				"I don't know why you say goodbye, I say hello, hello, hello, "+
				"I don't know why you say goodbye, I say hello, hello, hello, "+
				"I don't know why you say goodbye, I say hello, hello, hello,";
		System.out.println(textString2);
		gen.retrain(textString2);
		System.out.println(gen);
		System.out.println(gen.generateText(20));
	}

}

/** Links a word to the next words in the list 
 * You should use this class in your implementation. */
class ListNode
{
    // The word that is linking to the next words
	private String word;
	
	// The next words that could follow it
	private List<String> nextWords;
	
	ListNode(String word)
	{
		this.word = word;
		nextWords = new LinkedList<String>();
	}
	
	public String getWord()
	{
		return word;
	}

	public void addNextWord(String nextWord)
	{
		nextWords.add(nextWord);
	}
	
	public String getRandomNextWord(Random generator)
	{
		// TODO: Implement this method
	    // The random number generator should be passed from 
	    // the MarkovTextGeneratorLoL class
		return nextWords.get(generator.nextInt(nextWords.size()));
	    //return null;
	}

	public String toString()
	{
		String toReturn = word + ": ";
		for (String s : nextWords) {
			toReturn += s + "->";
		}
		toReturn += "\n";
		return toReturn;
	}
	
}


