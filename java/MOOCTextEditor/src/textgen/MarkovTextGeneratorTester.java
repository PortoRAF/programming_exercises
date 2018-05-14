package textgen;

import static org.junit.Assert.*;

import java.util.Random;

import org.junit.Before;
import org.junit.Test;

public class MarkovTextGeneratorTester {

	 //TODO Declare global variables to test methods
	MarkovTextGeneratorLoL gen;
	String shortText;
	Random generator;
	
	@Before
	public void setUp() throws Exception
	{
		//TODO Initialize variables
		generator = new Random(42);
		gen = new MarkovTextGeneratorLoL(generator);
		shortText = "I eat cookies. I smell nice.";		
	}
	
	@Test
	public void testTrain()
	{
		try {	gen.train(null);	}		
		catch (NullPointerException e) { }
		
		try {	gen.train("");	}
		catch (IllegalArgumentException e) { }
		
		gen.getWordList().clear();
		gen.train(shortText);
		assertEquals("", 5, gen.getWordList().size());
		assertEquals("", "I", gen.getWordList().get(0).getWord());
		assertEquals("", "nice.", gen.getWordList().get(4).getWord());
		assertEquals("", "cookies.", gen.getWordList().get(1).getRandomNextWord(generator));
		
		gen.train(shortText);
		assertEquals("", 5, gen.getWordList().size());
	}
	
	@Test
	public void testRetrain()
	{
		
	}
	
	@Test
	public void testGenerateText()
	{
		
	}
	
	@Test
	public void testGetRandomNextWord()
	{
		
	}
}
