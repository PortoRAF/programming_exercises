package demos;

import com.csvreader.CsvReader;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class SearchAirport {
	
	static List<Airport> airportList = new ArrayList<Airport>();
	
	public static void main(String[] args) {
				
		try {
			CsvReader list = new CsvReader("data/airports.dat");
			
			while (list.readRecord()) {
				airportList.add(new Airport(list.get(2),list.get(4)));
			}
			
			list.close();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		String code = findAirportCode("San Diego", airportList);
		System.out.println(code);
	}

	public static String findAirportCode (String toFind, List<Airport> airportList) {
		for (Airport airport : airportList) {
			if ((airport.getCity()).equals(toFind)) {
				return airport.getCode3(); 
			}
		}
		return null;
	}
}
/*
public class SearchAirport {
	
	static Airport[] airportList;
	
	public static void main(String[] args) {
				
		try {
			CsvReader list = new CsvReader("data/airports.dat");
			int index = 0;
			int count = 8108;
			
			airportList = new Airport[count];
			
			while (list.readRecord()) {
				airportList[index] = new Airport(list.get(2),list.get(4));
				index++;
			}
			
			list.close();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		String code = findAirportCode("San Diego", airportList);
		System.out.println(code);
	}

	public static String findAirportCode (String toFind, Airport[] airports) {
		for (Airport airport : airports) {
			if ((airport.getCity()).equals(toFind)) {
				return airport.getCode3(); 
			}
		}
		return null;
	}
}
*/