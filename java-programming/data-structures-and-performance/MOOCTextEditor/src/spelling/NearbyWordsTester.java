package spelling;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

public class NearbyWordsTester {

	private String dictFile = "data/dict.txt";
	private NearbyWords nw;
	
	@Before
	public void setUp() throws Exception {
		Dictionary d = new DictionaryHashSet();
		DictionaryLoader.loadDictionary(d, dictFile);
		nw = new NearbyWords(d);
	}

	@Test
	public void testSubstitution() {
		String s = "Garaje";
		List<String> currentList = new ArrayList<String>();
		boolean wordsOnly = true;
		
		nw.substitution(s, currentList, wordsOnly);
		System.out.println(currentList);
	}

	@Test
	public void testDeletions() {
		String s = null;
		List<String> currentList = new ArrayList<String>();
		boolean wordsOnly = true;
		
		s = "Garagen";
		nw.deletions(s, currentList, wordsOnly);
		System.out.println(currentList);
		
		String t = "Pranq";
		nw.deletions(t, currentList, wordsOnly);
		System.out.println(currentList);
	}
}
