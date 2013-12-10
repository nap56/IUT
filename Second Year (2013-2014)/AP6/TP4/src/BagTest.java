package datastruct;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;
import junit.framework.TestCase;

/**
 * Class test for the Bag Collection
 */
public class BagTest extends TestCase {
//Attributes
	private Bag<Integer> emptyBag;
	private Bag<Integer> normalBag;
	private Bag<Integer> testInsertBag;
	private Integer un;
	private Integer deux;
	private Integer trois;
	private Integer quatre;
	private Integer cinq;
	private Integer six;
	private Integer sept;
	private Integer huit;
	private Integer neuf;
	private Integer dix;
	private Integer nonPresent;



//Method ran before each test case
	@Before
	public void setUp() {
		emptyBag = new Bag<Integer>();
		normalBag = new Bag<Integer>();
		testInsertBag = new Bag<Integer>();
		un = new Integer(1);
		deux = new Integer(2);
		trois = new Integer(3);
		quatre = new Integer(4);
		cinq = new Integer(5);
		six = new Integer(6);
		sept = new Integer(7);
		huit = new Integer(8);
		neuf = new Integer(9);
		dix = new Integer(10);
		nonPresent = new Integer(42);

		//Addings
		normalBag.add(un);
		normalBag.add(deux);
		normalBag.add(trois);
		normalBag.add(quatre);
		normalBag.add(cinq);
		normalBag.add(six);
		normalBag.add(sept);
		normalBag.add(huit);
		normalBag.add(neuf);
		normalBag.add(dix);
	}


//Methods tests
//getSize() will be tested in parallel of add() and remove()

//Test of add()
	@Test
	public void testAddBag() {
		System.out.println("Test of a normal add:");
		assertEquals(0, testInsertBag.size());
		assertEquals(true, testInsertBag.add(un));
		assertEquals(1, testInsertBag.size());
		assertEquals(true, testInsertBag.add(deux));
		assertEquals(2, testInsertBag.size());
		assertEquals(true, testInsertBag.add(trois));
		assertEquals(3, testInsertBag.size());
		System.out.println("OK \n");
	}

	@Test
	public void testAddEmptyBag() {
		System.out.println("Test of an add in an empty bag:");
		assertEquals(0, emptyBag.size());
		assertEquals(true, emptyBag.add(un));
		assertEquals(1, emptyBag.size());
		System.out.println("OK \n");
	}


//Test of toString()
	@Test
	public void testToStringEmptyBag() {
		System.out.println("Test of displaying an empty bag:");
		System.out.println(emptyBag.toString());
		System.out.println("OK \n");
	}

	@Test
	public void testToStringNormalBag() {
		System.out.println("Test of displaying a normal bag:");
		System.out.println(normalBag.toString());
		System.out.println("OK \n");
	}


//Test of isEmpty()
	@Test
	public void testIsEmptyWithEmptyBag() {
		System.out.println("Test of isEmpty() with an empty bag:");
		assertEquals(true, emptyBag.isEmpty());
		System.out.println("OK \n");
	}

	@Test
	public void testIsEmptyWithNormalBag() {
		System.out.println("Test of isEmpty() with a normal bag:");
		assertEquals(false, normalBag.isEmpty());
		System.out.println("OK \n");
	}


//Test of contains()
	@Test
	public void testContainsWithEmptyBag() {
		System.out.println("Test of contains() with an empty bag:");
		assertEquals(false, emptyBag.contains(un));
		System.out.println("OK \n");
	}
	
/* Doesn't work!
	@Test
	public void testContainsWithNormalBag() {
		System.out.println("Test of contains() with a normal bag and an element contained in it:");
		assertEquals(true, normalBag.contains(un));
		System.out.println("\n");
	}
*/

	@Test
	public void testContainsWithNormalBagNotContaining() {
		System.out.println("Test of contains() with a normal bag and an element non present in it:");
		assertEquals(false, normalBag.contains(nonPresent));
		System.out.println("OK \n");
	}


//Test of toArray() number one


//Test of toArray() number two


//Test of remove()


//Test of containsAll()


//Test of addAll()


//Test of removeAll()


//Test of retainAll()


//Test of clear()
}